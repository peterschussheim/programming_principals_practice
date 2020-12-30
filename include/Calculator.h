#ifndef CALCULATOR_H
#define CALCULATOR_H

/*
    Original code from
   http://www.stroustrup.com/Programming/calculator08buggy.cpp

    Simple calculator command line program implemented as an excercise in
   building a relatively complex program and making improvements iteratively.

    Features:
      - Supports operators: '+', '-', '*', '/', '%', "'(' expression ')'"
      - User-defined variables: 'let x = 33 + 2;' -> 'x;' = 35
      - System-defined variables: pi, e, etc.

    Example Usage:
      **Use the ';' operator to terminate an expression (ex: '44 * 3;')**
      **Use the 'let' keyword to declare a user-defined variable (ex: 'let y =
   200.094;')**
      **To quit the program, type 'quit' and hit enter**

      '> let s = 100 * 0.75;'
      '> s * (33 + pi) - 2;'
      '> 300 * (33 + 2) / 3;'
      '> (17 + 4) / (5 - 1)'
*/

#include <string>
#include <vector>
#include <iostream>

class Token {
public:
  char kind;
  double value;
  std::string name;
  Token(char ch) : kind{ch}, value{0} {}                // Token{'*'}
  Token(char ch, double val) : kind{ch}, value{val} {}  // Token{number, 4.321}
  Token(char ch, std::string n)
      : kind{ch}, value{0}, name{n} {}  // Token{name, "pi"}
};

class Token_stream {
public:
  Token_stream() : full(0), buffer(0) {}  // initialize a Token_stream
  Token get();                            // Get a Token
  void putback(Token t);                  // Put a Token back
  void ignore(char c);  // discard characters up to and including a c

private:
  bool full{false};  // is there a Token in the buffer?
  Token buffer;      // storage location when we keep a Token using
                     // Token_stream::putback()
};

const char print =
    ';';  // terminates an expression and prints the result on a newline
const char number = '8';  // arbitrary choice to represent numeric literals
const char let = 'L';     // declaration token
const char name = 'a';    // name token
const char quit = 'Q';    // quit token
const std::string declkey = "let";    // declaration keyword
const std::string quit_key = "quit";  // keyword to exit the program

Token Token_stream::get()
{
  // read chars from cin and compose a Token
  if (full) {  // if we already have a Token ready
    full = false;
    return buffer;
  }
  char ch;
  std::cin >> ch;  // remember, >> operator skips ws (space, newline, tab, etc)
  switch (ch) {
    case print:
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    case '=':
    case '%':
      return Token(ch);  // each character represent itself
    case '.':  // a floating-point literal can start with a dot ex: .9483
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9': {
      std::cin.putback(ch);  // put digit back into stream
      double val;
      std::cin >> val;  // read a floating-point
      return Token(number, val);
    }
    default:
      if (isalpha(ch)) {
        std::string s;
        s += ch;
        while (std::cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
        std::cin.putback(ch);                 // should we be using cin.unget??
        if (s == declkey) return Token{let};  // declaration keyword
        if (s == quit_key) return Token{quit};  // quit keyword

        return Token{name, s};
      }
      error("Bad token");
  }
}

void Token_stream::putback(Token t)
{
  buffer = t;
  full = true;
}

void Token_stream::ignore(char c)
{  // c represents the kind of Token
  // first look in buffer
  if (full && c == buffer.kind) {
    full = false;
    return;
  }
  full = false;

  // now search input:
  char ch;
  while (cin >> ch)
    if (ch == c) return;
}

struct Variable {
  string name;
  double value;
  Variable(string n, double v) : name(n), value(v) {}
};

vector<Variable> var_table;

double get_value(string s)
{  // return the value of a Variable names s
  for (int i = 0; i < var_table.size(); ++i)
    if (var_table[i].name == s) return var_table[i].value;
  error("get: undefined name ", s);
}

void set_value(string s, double d)
{
  for (int i = 0; i <= var_table.size(); ++i)
    if (var_table[i].name == s) {
      var_table[i].value = d;
      return;
    }
  error("set: undefined name ", s);
}

bool is_declared(string s)
{
  // is var already in var_table?
  for (int i = 0; i < var_table.size(); ++i)
    if (var_table[i].name == s) return true;
  return false;
}

double define_name(string var, double val)
{
  // add (var,val) to names vector
  if (is_declared(var)) error(var, " declared twice");
  var_table.push_back(Variable(var, val));
  return val;
}

Token_stream ts;

double expression();

double primary()
{
  Token t = ts.get();
  switch (t.kind) {
    case '(': {
      double d = expression();
      t = ts.get();
      if (t.kind != ')') error("'(' expected");
      return d;
    }
    case number:
      return t.value;
    case '-':
      return -primary();
    case '+':
      return primary();
    case name:
      return get_value(t.name);
    default:
      error("primary expected");
  }
}

double term()
{
  double left = primary();
  while (true) {
    Token t = ts.get();
    switch (t.kind) {
      case '*':
        left *= primary();
        break;
      case '/': {
        double d = primary();
        if (d == 0) error("divide by zero");
        left /= d;
        break;
      }
      case '%': {
        double d = primary();
        if (d == 0) error("%: divide by zero");
        left = fmod(left, d);
        t = ts.get();
        break;
        /* int i1 = narrow_cast<int>(left);
         int i2 = narrow_cast<int>(primary());
         if (i2 == 0) error("%: divide by zero");
         left = i1 % i2;
         t = ts.get();
         break;*/
      }
      default:
        ts.putback(t);
        return left;
    }
  }
}

double expression()
{
  double left = term();
  while (true) {
    Token t = ts.get();
    switch (t.kind) {
      case '+':
        left += term();
        break;
      case '-':
        left -= term();
        break;
      default:
        ts.putback(t);
        return left;
    }
  }
}

double declaration()
{
  // assume we have seen "let"
  // handle name = expression
  // declare a variable called "name" with initial val "expression"
  Token t = ts.get();
  if (t.kind != 'a') error("name expected in declaration");
  string name = t.name;

  if (is_declared(name)) error(name, " declared twice");
  Token t2 = ts.get();
  if (t2.kind != '=') error("= missing in declaration of ", name);

  double d = expression();
  var_table.push_back(Variable(name, d));
  return d;
}

double statement()
{
  Token t = ts.get();
  switch (t.kind) {
    case let:
      return declaration();
    default:
      ts.putback(t);
      return expression();
  }
}

void clean_up_mess() { ts.ignore(print); }

const string prompt = "> ";
const string result = "= ";

void calculate()
{
  while (true) try {
      cout << prompt;
      Token t = ts.get();                    // get Token from Token_stream
      while (t.kind == print) t = ts.get();  // discard all print statements
      if (t.kind == quit) return;            // quit program
      ts.putback(t);
      cout << result << statement() << '\n';
    }
    catch (runtime_error& e) {
      cerr << e.what() << '\n';
      clean_up_mess();
    }
}

#endif  // CALCULATOR_H