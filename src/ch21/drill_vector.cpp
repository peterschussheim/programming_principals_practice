// 1. Read some floating-point values (at least 16 values) from a file into a
// vector<double> called vd.
// 2. Output vd to cout.

// 3. Make a vector vi of type vector<int> with the same number of elements
//    as vd; copy the elements from vd into vi.
// 4. Output the pairs of ( vd[i] , vi[i] ) to cout , one pair per line.
// 5. Output the sum of the elements of vd .
// 6. Output the difference between the sum of the elements of vd and the sum
// of the elements of vi.

// 7. There is a standard library algorithm called reverse that takes a sequence
//(pair of iterators) as arguments; reverse vd , and output vd to cout .
// 8. Compute the mean value of the elements in vd ; output it.
// 9. Make a new vector<double> called vd2 and copy all elements of vd with
// values lower than (less than) the mean into vd2 .
// 10. Sort vd ; output it again.

#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>

void fill_vector(std::ifstream& ifs, std::vector<double>& v);
template<typename T> void print_container(T& t);

//------------------------------------------------------------------------------

template<typename T> struct Add {
  constexpr T operator()(const T& lhs, const T& rhs) const { return lhs + rhs; }
};

int main()
{
  try {
    std::string file_name{"floats.txt"};
    std::ifstream is{file_name};
    std::vector<double> vd;

    fill_vector(is, vd);
    print_container(vd);
    std::cout << '\n';
    std::cout << '\n';

    // 3. Make a vector vi of type vector<int> with the same number of elements
    //    as vd; copy the elements from vd into vi.
    std::vector<int> vi(vd.size());
    std::copy(vd.begin(), vd.end(), vi.begin());

    // 4. Output the pairs of ( vd[i] , vi[i] ) to cout , one pair per line.
    auto p = vd.begin();
    auto q = vi.begin();
    while (p != vd.end() && q != vi.end()) {
      std::cout << "(" << *p << ", " << *q << ")\n";
      ++p;
      ++q;
    }
    std::cout << '\n';
    std::cout << '\n';

    // 5. Output the sum of the elements of vd .
    double sum_vd = 0.0;
    sum_vd = std::accumulate(vd.begin(), vd.end(), sum_vd, Add<double>{});
    std::cout << "sum of elements in vd: " << sum_vd << "\n";
    std::cout << '\n';

    // 6. Output the difference between the sum of the elements of vd and the
    // sum of the elements of vi.
    int sum_vi = 0;
    sum_vi = std::accumulate(vi.begin(), vi.end(), sum_vi, Add<int>{});

    auto diff = sum_vd - sum_vi;
    std::cout << "difference of the sum_vd and sum_vi: " << diff << "\n";
    std::cout << '\n';

    // 7. There is a standard library algorithm called reverse that takes a
    //    sequence(pair of iterators) as arguments;
    //    reverse vd, and output vd to cout.

    std::cout << "vd, after reversing:\n";
    std::reverse(vd.begin(), vd.end());
    print_container(vd);
    std::cout << '\n';

    // 8. Compute the mean value of the elements in vd ; output it.
    auto mean_vd = sum_vd / vd.size();
    std::cout << "mean of vd: " << mean_vd << "\n";
    std::cout << "\n";

    // 9. Make a new vector<double> called vd2 and copy all elements of vd with
    // values lower than (less than) the mean into vd2 .
    std::vector<double> vd2;
    std::copy_if(vd.begin(), vd.end(), std::back_inserter(vd2),
                 [&](const double val) { return val < mean_vd; });
    std::cout << "vd2 contents:\n";
    std::cout << '\n';
    print_container(vd2);

    std::cout << '\n';
    std::cout << '\n';

    // 10. Sort vd; output it again.
    std::cout << "vd sorted:\n";
    std::sort(vd.begin(), vd.end());
    print_container(vd);
    std::cout << '\n';

    std::cout << '\n';

    return 0;
  }
  catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << '\n';
    return 1;
  }
  catch (...) {
    std::cerr << "exception\n";
    return 2;
  }
}

//------------------------------------------------------------------------------

void fill_vector(std::ifstream& ifs, std::vector<double>& v)
{
  for (double dd; ifs >> dd;) v.push_back(dd);
}

//------------------------------------------------------------------------------

template<typename T> void print_container(T& t)
{
  std::cout << "{ \n";
  for (auto el : t) std::cout << "\t" << el << ",\n";
  std::cout << "}";
}
