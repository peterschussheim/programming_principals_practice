/**
 * Source code from chapter 6, drill section.
 */

#include "std_lib_facilities.h"

class Token {
public:
  char kind;      // type of token
  double value;   // if kind is a number, the number's value
  Token(char ch)  // make a Token from a char
      : kind(ch), value(0) {}
  Token(char ch, double val)  // make a Token from a char and a double
      : kind(ch), value(val) {}
};

class Token_stream {
public:
  Token_stream();         // make a Token_stream that reads from cin
  Token get();            // get a Token (get() is defined later on)
  void putback(Token t);  // put a Token back into the stream
private:
  bool full;     // is there a Token in the buffer?
  Token buffer;  // location where we store the token when calling putback()
};

// The constructor sets full to indicate that the buffer is empty
Token_stream::Token_stream()
    : full(false),
      buffer(0)  // empty buffer
{}

// Places it argument back into the Token_stream's buffer
void Token_stream::putback(Token t) {
  if (full) error("putback() into a full buffer");
  buffer = t;   // copy t into buffer
  full = true;  // buffer is not full
}

Token Token_stream::get() {
  if (full) {  // do we already have a Token ready?
    // remove token from buffer
    full = false;
    return buffer;
  }

  char ch;
  cin >> ch;  // remember that >> skips whitespace (space, neline, tab)

  switch (ch) {
    case ';':  // for "print"
    case 'q':  // for quit
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
      return Token(ch);  // let each character represent itself
    case '.':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '9': {
      cin.putback(ch);  // put digit back into the input stream
      double val;
      cin >> val;              // read a floating-point number
      return Token('8', val);  // use '8' to represent a "number"
    }
    default:
      error("Bad token");
  }
}

Token_stream ts;  // provides get() and ptback()

double expression();  // declaration so that primary() can call expression()

// handle numbers and parentheses
double primary() {
  Token t = ts.get();
  switch (t.kind) {
    case '(':  // handle '(' expression ')'
    {
      double d = expression();
      t = ts.get();
      if (t.kind != ')') error("')' expected");
      return d;
    }
    case '8':
      return t.value;  // '8' was chosen to represent a number type

    default:
      error("primary expected");
  }
}

// handle *, /, and %
double term() {
  double left = primary();
  Token t = ts.get();  // get the next token from the token stream
  while (true) {
    switch (t.kind) {
      case '*':
        left *= primary();
        t = ts.get();
      case '/': {
        double d = primary();
        if (d == 0) error("divide by zero");
        left /= d;
        t = ts.get();
        break;
      }
      default:
        ts.putback(t);  // place t back into the token stream
        return left;
    }
  }
}

// handle + and -
double expression() {
  double left = term();  // read and eval a Term
  Token t = ts.get();    // get the next Token from the Token stream
  while (true) {
    switch (t.kind) {
      case '+':
        left += term();  // eval Term and add
        t = ts.get();
        break;
      case '-':
        left -= term();  // eval Term and subtract
        t = ts.get();
        break;
      default:
        ts.putback(t);
        return left;  // no more + or -, return the answer
    }
  }
}

// int main()
// try
//{
//    while (cin) {
//        Token t = ts.get();
//
//        if (t.kind == 'q') break; // 'q' for quit
//        if (t.kind == ';')        // ';' for "print now"
//            cout << "=" << val << '\n';
//        else
//            ts.putback(t);
//        val = expression();
//    }
//	keep_window_open();
//}
// catch (exception& e) {
//    cerr << "error: " << e.what() << '\n';
//	keep_window_open();
//    return 1;
//}
// catch (...) {
//    cerr << "Oops: unknown exception!\n";
//	keep_window_open();
//    return 2;
//}
