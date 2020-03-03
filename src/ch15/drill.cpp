#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"

/*
  In the following, use a separate Shape for each function to be graphed:
  1. Graph the function double one(double x) { return 1; } in the range [–10,11]
      with (0,0) at (300,300) using 400 points and no scaling (in the window).
  2. Change it to use x scale 20 and y scale 20.
  3. From now on use that range, scale, etc. for all graphs.
  4. Add double slope(double x) { return x/2; } to the window.
  5. Label the slope with a Text "x/2" at a point just above its bottom left end
      point.
  6. Add double square(double x) { return x*x; } to the window.
  7. Add a cosine to the window (don’t write a new function).
  8. Make the cosine blue.
  9. Write a function sloping_cos() that adds a cosine to slope() (as defined
      above) and add it to the window.
*/

double one(double x) { return 1; }
double slope(double x) { return x / 2; }
double square(double x) { return x * x; }

void drill_part_2()
{
  using namespace Graph_lib;
  constexpr int xmax = 600;
  constexpr int ymax = 800;
  constexpr int x_orig = 300;
  constexpr int y_orig = 300;
  Point orig{x_orig, y_orig};

  constexpr int r_min = -10;  // range [-10:11)
  constexpr int r_max = 11;
  constexpr int n_points = 400;  // points used in range
  constexpr int x_scale = 20;
  constexpr int y_scale = 20;
  constexpr int xlength = 400;
  constexpr int ylength = 400;

  Text sl{Point{100, y_orig + y_orig / 2 - 80}, "x/2"};
  Simple_window win{Point{100, 100}, xmax, ymax, "Drill Part 2"};
  Function f_one{one, r_min, r_max, orig, n_points, x_scale, y_scale};
  Function f_slope{slope, r_min, r_max, orig, n_points, x_scale, y_scale};
  Function f_square{square, r_min, r_max, orig, n_points, x_scale, y_scale};
  Function cosine{[](double x) { return cos(x); },
                  r_min,
                  r_max,
                  orig,
                  n_points,
                  x_scale,
                  y_scale};
  Function sloped_cosine{[](double x) { return cos(x) + slope(x); },
                         r_min,
                         r_max,
                         orig,
                         n_points,
                         x_scale,
                         y_scale};
  sloped_cosine.set_color(Color::black);
  cosine.set_color(Color::blue);
  f_one.set_color(Color::black);
  f_slope.set_color(Color::black);
  f_square.set_color(Color::black);
  sl.set_color(Color::black);

  win.attach(f_one);
  win.attach(sloped_cosine);
  win.attach(f_slope);
  win.attach(cosine);
  win.attach(f_square);
  win.attach(sl);
  win.wait_for_button();
}

/*
  1. Define a struct Person containing a string name and an int age.
  2. Define a variable of type Person , initialize it with “Goofy” and 63, and
      write it to the screen ( cout ).
  3. Define an input ( >> ) and an output ( << ) operator for Person ; read in a
      Person from the keyboard ( cin ) and write it out to the screen ( cout ).
  4. Give Person a constructor initializing name and age.
  5. Make the representation of Person private, and provide const member
      functions name() and age() to read the name and age.
  6. Modify >> and << to work with the redefined Person.
  7. Modify the constructor to check that age is [0:150) and that name doesn’t
      contain any of the characters ; : " ' [ ] * & ^ % $ # @ ! . Use error() in
      case of error. Test.
  8. Read a sequence of Person s from input ( cin ) into a vector<Person> ;
      write them out again to the screen ( cout ). Test with correct and errone-
      ous input.
  9. Change the representation of Person to have first_name and second_name
      instead of name . Make it an error not to supply both a first and a second
      name. Be sure to fix >> and << also. Test.
*/

struct Person {
  Person() : f_name{""}, l_name{""}, a{1} {}
  Person(string f_name, string l_name, int a);
  string first_name() const { return f_name; }
  string last_name() const { return l_name; }
  int age() const { return a; }

private:
  string f_name;  // first name
  string l_name;  // last name
  int a;          // age
};

Person::Person(string fn, string ln, int aa)  // construct a person
    : f_name{fn},
      l_name{ln},
      a{aa}
{
  for (int i = 0; i < fn.size(); ++i) {
    if (!isalnum(fn[i]) || !isalpha(fn[i]))
      error(
          "name cannot contain any of the following characters: ; : \" \' \[ ] "
          "\* \& \^ \% \$ \# \@ \! \.    ",
          fn);
  }
  if (!(aa >= 0 && aa <= 150)) error("age must be in the range [0:150) ", aa);
}

ostream& operator<<(ostream& os, const Person& p);
istream& operator>>(istream& is, Person& p);

ostream& operator<<(ostream& os, const Person& p)  // write out a Person to cout
{
  return os << "Name: " << p.first_name() + " " + p.last_name() << "\n"
            << "Age: " << p.age() << "\n";
}

istream& operator>>(istream& is, Person& p)
{
  // assume format: name, age
  // Read in a Person from cin (keyboard)
  string first_name, last_name;
  int age;

  is >> first_name >> last_name >> age;
  if (!is) return is;  // return the stream if we have an error
  // TODO: I couldn't figure out how to throw an error if a user
  // fails to enter BOTH a first and last name.
  // if (first_name.size() <= 1 || last_name.size() <= 1)
  error("please enter a first AND last name");
  p = Person{first_name, last_name, age};
  return is;
}

void drill_part_3()
{
  // Person goofy{"Goofy", 1110};
  // Person goofy{"Goof*y", 11}; // error
  // Person goofy{";Goofy", 11};
  // Person goofy{"G@oofy", 11};
  // Person goofy{"Goofy #", 11};
  // Person goofy{"Goofy!", 11};
  // Person goofy{"Goofy?", 11};

  // cin >> goofy;
  // cout << goofy;
}

int main()
{
  try {
    // drill_part_1();
    drill_part_2();
    // drill_part_3();

    // vector<Person> p;  // read in from cin to p
    // cout << "Enter your first and last name and age, seperated by spaces\n";
    // Person s;
    // while (cin >> s) { p.push_back(s); }
    // cout << '\n';
    // for (Person per : p) { cout << per; }

    keep_window_open("~");
    return 0;
  }
  catch (exception& e) {
    cerr << e.what();
    keep_window_open("~");
    return 1;
  }
  catch (...) {
    cerr << "unhandled exception\n";
    keep_window_open("~");
    return 2;
  }
}

// void drill_part_1()
//{
//  constexpr int xmax = 600;
//  constexpr int ymax = 800;
//  constexpr int x_orig = 300;
//  constexpr int y_orig = 300;
//  Point orig{x_orig, y_orig};
//  string label = "1 = = 20 pixels";
//  constexpr int r_min = -10;  // range [-10:11)
//  constexpr int r_max = 11;
//  constexpr int n_points = 400;  // points used in range
//  constexpr int x_scale = 30;
//  constexpr int y_scale = 30;
//  constexpr int xlength = 400;
//  constexpr int ylength = 400;
//
//  Point tl{100, 100};
//  Simple_window win{tl, xmax, ymax, "Function graphs."};
//  Axis x{Axis::x, Point{20, y_orig}, xlength, xlength / x_scale, label};
//  Axis y{Axis::y, Point{x_orig, ylength + 20}, ylength, ylength / y_scale,
//         label};
//  x.set_color(Color::red);
//  y.set_color(Color::red);
//  win.attach(x);
//  win.attach(y);
//  win.wait_for_button();
//}

/*
  UNUSED....ignore.  I thought the following would help but it made things
  more complicated than necessary.

  accepts an istream reference, a vector of Person objects and
  a char containing the desired terminator char.

  If we receive anything besides the expected Person type,
  we update the stream state and attempt to gracefully
  handle the char first checking if the char is the terminator
  and if not, put the char BACK into the stream so that the
  callee can use it and then we set the stream state to fail.
void fill_vector(vector<Person> v, char terminator)
{
  for (Person p; std::cin >> p;) v.push_back(p);

  // uh-oh, we've failed if we hit this part of fn
  std::cin.clear();  // clear stream state
  char c;
  std::cin >> c;  // read a char

  if (c != terminator) {
    std::cin.unget();  // maybe my caller wants this char
    std::cin.clear(ios_base::failbit);
  }
}
*/
