#include <string>

/*
  Peter Schussheim
  02/19/20

  Note: This class is not yet fully designed.  It was started
  during chapter 14 exerise 11 and I am keeping it as a task
  to do later on once I am more experienced with OO design in C++.
*/

/*
  Type for a tree node containing a string value
  and references to its left and right children nodes, if any.
*/
struct Binary_node {
  Binary_node(std::string v, Binary_node& l, Binary_node& r)
      : val{v},
        left{l},
        right{r}
  {
  }

  void set_val(std::string v) const { val = v; }

  void set_left(Binary_node& l) const;
  void set_right(Binary_node& r) const;

private:
  std::string val;
  Binary_node& left;
  Binary_node& right;
};