#include "std_lib_facilities.h"

class B1 {
public:
  virtual void vf() const { cout << "B1::vf() "; }
  void f() const { cout << "B1::f() "; }
  virtual void pvf() = 0;  // declare a pure virtual function
};

/*
  Drill part 4: After defining B1::f() and calling each function,
  the output is identical since we haven't overridden B1::f().

  Drill part 5: After adding a pure virtual function pvf() to B1,
  we see new errors explaining that our b and d objects are not allowed
  since they are objects of abstract classes.  Why?  Recall the notion
  of abstract vs concrete classes; the language states that an abstract class
  remains abstract until ALL its members are defined.  As such, B1 is abstract
  and since D1 is derived from B1, D1 is abstract as well.
*/
class D1 : public B1 {
public:
  void vf() const override { cout << "D1::vf() "; }
  void f() const { cout << "D1::f() "; }
};

class D2 : public D1 {
public:
  void pvf() override { cout << "D2::pvf() "; }
};

//--------------------------------------------
// Part 7

class B2 {
public:
  virtual void pvf() = 0;
};

class D21 : public B2 {
public:
  void pvf() override { cout << s; }
  string s;
};

class D22 : public B2 {
public:
  void pvf() override { cout << n; }
  int n;
};

void f(B2& b) { b.pvf(); }

void call(const B1& b)
{
  b.vf();
  b.f();
}

int main()
{
  try {
    // B1 b;
    // D1 d;
    // D2 d_2;
    // B1& b_ref = d;
    D2 d2;
    call(d2);
    d2.pvf();
    // call(b);
    // call(d);
    // call(b_ref);
    // call(d_2);
    D21 d21;
    d21.s = "D21.s ";
    D22 d22;
    d22.n = 33;
    f(d21);
    f(d22);
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