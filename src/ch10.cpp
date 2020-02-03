/*
  Peter Schussheim
  02/03/20

  Chapter 10 Drill

  - [x] Start a program to work with points, discussed in §10.4. Begin by defining the data type
        Point that has two coordinate members x and y.
  - [x] Using the code and discussion in §10.4, prompt the user to input seven (x,y) pairs. As the
        data is entered, store it in a vector of Point s called original_points.
  - [x] Print the data in original_points to see what it looks like.
  - [x] Open an ofstream and output each point to a file named mydata.txt. On
        Windows, we suggest the .txt suffix to make it easier to look at the data
        with an ordinary text editor (such as WordPad).
  - [x] Close the ofstream and then open an ifstream for mydata.txt. Read the
        data from mydata.txt and store it in a new vector called processed_points.
  - [ ] Print the data elements from both vectors.
  - [ ] Compare the two vectors and print "Something's wrong!" if the number of elements
        or the values of elements differ.
*/
#include "std_lib_facilities.h"

struct Point {  // Point to represent cartesian coordinates
  int x, y;
};

istream& operator>>(istream& is, Point& pp) {
  int x, y;
  char ch1, ch2, ch3;
  is >> ch1 >> x >> ch2 >> y >> ch3;
  if (!is) return is;

  if (ch1 != '(' || ch2 != ',' || ch3 != ')') {  // invalid format error
    is.clear(ios_base::failbit);
    return is;
  }

  pp = Point{x, y};  // update pp
  return is;
}

ostream& operator<<(ostream& os, const Point& pp) {
  return os << '(' << pp.x << ',' << pp.y << ')';
}

int main() {
  try {
    cout << "Please enter 7 Points in the format (x,y), seperated by a space\n";
    vector<Point> original_points;

    for (int count = 0; count < 7; ++count) {
      Point p;
      cin >> p;
      original_points.push_back(p);
    }

    string oname = "mypoints.txt";
    cout << "Writing points to mypoints.txt.\n";
    ofstream ost{oname};  // init an ostream named mypoints.txt
    if (!ost) error("can't open output file ", oname);
    for (Point p : original_points) { ost << p << '\n'; }  // loop and write to a file

    ost.close();          // close ofstream
    ifstream ist{oname};  // open ifstream for file named mypoints.txt
    vector<Point> processed_points;
    int x, y;
    if (!ist) error("can't open input file ", oname);
    // read from mydata.txt into a vector processed_points
    while (ist >> x >> y) { processed_points.push_back(Point{x, y}); }

    cout << "original_points: ";
    for (Point p : original_points) { cout << p << ' '; }
    cout << '\n';

    cout << "processed_points: ";
    for (Point pp : processed_points) { cout << pp << ' '; }
    cout << '\n';
    keep_window_open("~");
    return 0;
  } catch (exception& e) {
    cerr << e.what() << '\n';
    keep_window_open("~");
    return 1;
  }
}