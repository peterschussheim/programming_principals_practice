
#ifndef GRAPH_GUARD
#define GRAPH_GUARD 1

#include "Point.h"
#include <vector>
//#include <string>
//#include <cmath>
#include "fltk.h"
#include "std_lib_facilities.h"

namespace Graph_lib {
// defense against ill-behaved Linux macros:
#undef major
#undef minor

  //---------------------------------------------------------------------------

  const double pi = 3.1415926;

  //---------------------------------------------------------------------------

  struct Color {
    enum Color_type {
      red = FL_RED,
      blue = FL_BLUE,
      green = FL_GREEN,
      yellow = FL_YELLOW,
      white = FL_WHITE,
      black = FL_BLACK,
      magenta = FL_MAGENTA,
      cyan = FL_CYAN,
      dark_red = FL_DARK_RED,
      dark_green = FL_DARK_GREEN,
      dark_yellow = FL_DARK_YELLOW,
      dark_blue = FL_DARK_BLUE,
      dark_magenta = FL_DARK_MAGENTA,
      dark_cyan = FL_DARK_CYAN
    };
    enum Transparency { invisible = 0, visible = 255 };

    Color(Color_type cc) : c(Fl_Color(cc)), v(visible) {}
    Color(Color_type cc, Transparency vv) : c(Fl_Color(cc)), v(vv) {}
    Color(unsigned int cc) : c(Fl_Color(cc)), v(visible) {}
    Color(Transparency vv) : c(Fl_Color()), v(vv) {}

    int as_int() const { return c; }
    char visibility() const { return v; }
    void set_visibility(Transparency vv) { v = vv; }

  private:
    Fl_Color c;
    unsigned char v;  // 0 or 1 for now
  };

  struct Line_style {
    enum Line_style_type {
      solid = FL_SOLID,            // -------
      dash = FL_DASH,              // - - - -
      dot = FL_DOT,                // .......
      dashdot = FL_DASHDOT,        // - . - .
      dashdotdot = FL_DASHDOTDOT,  // -..-..
    };
    Line_style(Line_style_type ss) : s(ss), w(0) {}
    Line_style(Line_style_type lst, int ww) : s(lst), w(ww) {}
    Line_style(int ss) : s(ss), w(0) {}

    int width() const { return w; }
    int style() const { return s; }

  private:
    int s;
    int w;
  };

  class Font {
  public:
    enum Font_type {
      helvetica = FL_HELVETICA,
      helvetica_bold = FL_HELVETICA_BOLD,
      helvetica_italic = FL_HELVETICA_ITALIC,
      helvetica_bold_italic = FL_HELVETICA_BOLD_ITALIC,
      courier = FL_COURIER,
      courier_bold = FL_COURIER_BOLD,
      courier_italic = FL_COURIER_ITALIC,
      courier_bold_italic = FL_COURIER_BOLD_ITALIC,
      times = FL_TIMES,
      times_bold = FL_TIMES_BOLD,
      times_italic = FL_TIMES_ITALIC,
      times_bold_italic = FL_TIMES_BOLD_ITALIC,
      symbol = FL_SYMBOL,
      screen = FL_SCREEN,
      screen_bold = FL_SCREEN_BOLD,
      zapf_dingbats = FL_ZAPF_DINGBATS
    };

    Font(Font_type ff) : f(ff) {}
    Font(int ff) : f(ff) {}

    int as_int() const { return f; }

  private:
    int f;
  };

  template<class T> class Vector_ref {
    vector<T*> v;
    vector<T*> owned;

  public:
    Vector_ref() {}

    Vector_ref(T* a, T* b = 0, T* c = 0, T* d = 0)
    {
      if (a) push_back(a);
      if (b) push_back(b);
      if (c) push_back(c);
      if (d) push_back(d);
    }

    ~Vector_ref()
    {
      for (int i = 0; i < owned.size(); ++i) delete owned[i];
    }

    void push_back(T& s) { v.push_back(&s); }
    void push_back(T* p)
    {
      v.push_back(p);
      owned.push_back(p);
    }

    // ???void erase(???)

    T& operator[](int i) { return *v[i]; }
    const T& operator[](int i) const { return *v[i]; }
    int size() const { return v.size(); }
  };

  typedef double Fct(double);

  class Shape {  // deals with color and style, and holds sequence of lines
  public:
    void draw() const;                  // deal with color and draw_lines
    virtual void move(int dx, int dy);  // move the shape +=dx and +=dy

    void set_color(Color col) { lcolor = col; }
    void set_style(Line_style sty) { ls = sty; }
    void set_fill_color(Color col) { fcolor = col; }
    int number_of_points() const { return int(points.size()); }

    Color color() const { return lcolor; }
    Line_style style() const { return ls; }
    Color fill_color() const { return fcolor; }
    Point point(int i) const { return points[i]; }

    void set_point(int i, Point p);
    virtual ~Shape() {}

  protected:
    Shape();
    Shape(initializer_list<Point> lst);  // add() the Points to this Shape
    virtual void draw_lines() const;     // simply draw the appropriate lines
    void add(Point p);
    void clear_points();

  private:
    vector<Point> points;  // not used by all shapes
    Color lcolor;
    Line_style ls;
    Color fcolor;

    Shape(const Shape&) = delete;  // prevent copying
    Shape& operator=(const Shape&) = delete;
  };

  struct Function : Shape {
    // the function parameters are not stored
    Function(Fct f, double r1, double r2, Point origin, int count = 100,
             double xscale = 25, double yscale = 25);
  };

  struct Func : Function {
    Func(Fct f, double r1, double r2, Point orig, int count, double xscale,
         double yscale, double prec = 1.0);
    void reset_fct(Fct f);
    void reset_range(double r1, double r2);
    void reset_origin(Point origin);
    void reset_count(int count);
    void reset_xscale(double xscale);
    void reset_yscale(double yscale);
    void reset_precision(double prec);
    void reset();

  private:
    Fct* fct;
    double range1, range2;
    Point origin;  // function origin
    int c;
    double xsc, ysc;  // xscale. yscale
    double precision;
  };

  struct Fill {
    Fill() : no_fill(true), fcolor(0) {}
    Fill(Color c) : no_fill(false), fcolor(c) {}

    void set_fill_color(Color col) { fcolor = col; }
    Color fill_color() { return fcolor; }

  protected:
    bool no_fill;
    Color fcolor;
  };

  struct Line : Shape {
    Line(Point p1, Point p2)
    {
      add(p1);
      add(p2);
    }
  };

  struct Rectangle : Shape {
    Rectangle(Point xy, int ww, int hh) : w{ww}, h{hh}
    {
      if (h <= 0 || w <= 0) error("Bad rectangle: non-positive side");
      add(xy);
    }
    Rectangle(Point x, Point y) : w{y.x - x.x}, h{y.y - x.y}
    {
      if (h <= 0 || w <= 0) error("Bad rectangle: first point is not top left");
      add(x);
    }
    void draw_lines() const;

    int height() const { return h; }
    int width() const { return w; }

  private:
    int w;  // width
    int h;  // height
  };

  Point n(const Rectangle& rect);
  Point s(const Rectangle& rect);
  Point e(const Rectangle& rect);
  Point w(const Rectangle& rect);
  Point center(const Rectangle& rect);
  Point ne(const Rectangle& rect);
  Point se(const Rectangle& rect);
  Point sw(const Rectangle& rect);
  Point nw(const Rectangle& rect);

  bool intersect(Point p1, Point p2, Point p3, Point p4);

  struct Open_polyline : Shape {  // open sequence of lines
    using Shape::Shape;
    void add(Point p) { Shape::add(p); }
    void draw_lines() const;
  };

  //---------------------------------------------------------------------------

  struct Closed_polyline : Open_polyline {  // closed sequence of lines
    using Open_polyline::Open_polyline;
    void draw_lines() const;

    //	void add(Point p) { Shape::add(p); }
  };

  //---------------------------------------------------------------------------

  struct Polygon
      : Closed_polyline {  // closed sequence of non-intersecting lines
    using Closed_polyline::Closed_polyline;
    void add(Point p);
    void draw_lines() const;
  };

  //---------------------------------------------------------------------------

  struct Lines : Shape {  // independent lines
    Lines() {}
    Lines(initializer_list<Point> lst) : Shape{lst}
    {
      if (lst.size() % 2) error("odd number of points for Lines");
    }
    void draw_lines() const;
    void add(Point p1, Point p2)
    {
      Shape::add(p1);
      Shape::add(p2);
    }
  };

  //---------------------------------------------------------------------------

  struct Text : Shape {
    // the point is the bottom left of the first letter
    Text(Point x, const string& s) : lab{s} { add(x); }

    void draw_lines() const;

    void set_label(const string& s) { lab = s; }
    string label() const { return lab; }

    void set_font(Font f) { fnt = f; }
    Font font() const { return Font(fnt); }

    void set_font_size(int s) { fnt_sz = s; }
    int font_size() const { return fnt_sz; }

  private:
    string lab;  // label
    Font fnt{fl_font()};
    int fnt_sz{(14 < fl_size()) ? fl_size() : 14};  // at least 14 point
  };

  //---------------------------------------------------------------------------

  struct Axis : Shape {
    // representation left public
    enum Orientation { x, y, z };
    Axis(Orientation d, Point xy, int length, int nummber_of_notches = 0,
         string label = "");

    void draw_lines() const;
    void move(int dx, int dy);

    void set_color(Color c);

    Text label;
    Lines notches;
  };

  //---------------------------------------------------------------------------

  struct Circle : Shape {
    Circle(Point p, int rr)  // center and radius
        : r{rr}
    {
      add(Point{p.x - r, p.y - r});
    }

    void draw_lines() const;
    Point center() const { return {point(0).x + r, point(0).y + r}; }
    void set_radius(int rr) { r = rr; }
    int radius() const { return r; }

  protected:
    int r;
  };

  //---------------------------------------------------------------------------

  class Immobile_circle : public Circle {
  public:
    using Circle::Circle;  // use Circle's constructors
    void draw_lines() const;

  private:
    using Circle::move;  // instruct compiler that Circle::move is not to be
                         // used by Immobile_class
  };

  //---------------------------------------------------------------------------

  struct Ellipse : Shape {
    Ellipse(Point p, int ww,
            int hh)  // center, min, and max distance from center
        : w{ww},
          h{hh}
    {
      add(Point{p.x - ww, p.y - hh});
    }

    void draw_lines() const;

    Point center() const { return {point(0).x + w, point(0).y + h}; }

    Point focus1() const
    {
      return {center().x + int(sqrt(double(w * w - h * h))), center().y};
    }

    Point focus2() const
    {
      return {center().x - int(sqrt(double(w * w - h * h))), center().y};
    }

    void set_major(int ww) { w = ww; }
    int major() const { return w; }
    void set_minor(int hh) { h = hh; }
    int minor() const { return h; }

  private:
    int w;
    int h;
  };

  //---------------------------------------------------------------------------
  struct Marked_polyline : Open_polyline {
    Marked_polyline(const string& m) : mark(m) {}
    void draw_lines() const;

  private:
    string mark;
  };

  //---------------------------------------------------------------------------

  struct Marks : Marked_polyline {
    Marks(const string& m) : Marked_polyline(m)
    {
      set_color(Color(Color::invisible));
    }
  };

  //---------------------------------------------------------------------------

  struct Mark : Marks {
    Mark(Point xy, char c) : Marks(string(1, c)) { add(xy); }
  };

  //---------------------------------------------------------------------------

  struct Bad_image : Fl_Image {
    Bad_image(int h, int w) : Fl_Image(h, w, 0) {}
    void draw(int x, int y, int, int, int, int) { draw_empty(x, y); }
  };

  //---------------------------------------------------------------------------

  struct Suffix {
    enum Encoding { none, jpg, gif, bmp };
  };

  //---------------------------------------------------------------------------

  Suffix::Encoding get_encoding(const string& s);

  struct Image : Shape {
    Image(Point xy, string s, Suffix::Encoding e = Suffix::none);
    ~Image() { delete p; }
    void draw_lines() const;
    void set_mask(Point xy, int ww, int hh)
    {
      w = ww;
      h = hh;
      cx = xy.x;
      cy = xy.y;
    }
    void move(int dx, int dy)
    {
      Shape::move(dx, dy);
      p->draw(point(0).x, point(0).y);
    }

  private:
    int w, h, cx,
        cy;  // define "masking box" within image relative to position (cx,cy)
    Fl_Image* p;
    Text fn;
  };

  //---------------------------------------------------------------------------

  struct Arc : Shape {
    Arc(Point p, int ww, int hh, double a1, double a2);

    void draw_lines() const;
    Point center() const { return Point{point(0).x + w, point(0).y + h}; }
    int major() const { return w; }
    int minor() const { return h; }

    void set_major(int ww)
    {
      set_point(0, Point{center().x - ww, center().y - h});
      w = ww;
    }

    void set_minor(int hh)
    {
      set_point(0, Point{center().x - w, center().y - hh});
      h = hh;
    }

    void set_angle1(double d)
    {
      if (d >= a2) error("first arc angle cannot be bigger than second angle");
      a1 = d;
    }

    void set_angle2(double d)
    {
      if (d <= a1) error("second arc cannot be smaller than first angle");
      a2 = d;
    }

    void set_angles(double d1, double d2)
    {
      if (d2 <= d1) error("second arc angle must be bigger than first angle");
      a1 = d1;
      a2 = d2;
    }

  private:
    int w, h;
    double a1, a2;
  };

  //---------------------------------------------------------------------------

  struct Box : Shape {
    Box(Point pp, int ww, int hh)  // "normal" Box
        : w{ww},
          h{hh}
    {
      if (h <= 0 || w <= 0) error("Height and width must be postive integers.");
      add(pp);  // add the point
      rad = w < h ? w / 4 : h / 4;
    };

    Box(Point pp, int ww, int hh, int rr)  // Box with rounded corners
        : w{ww},
          h{hh},
          rad{rr}
    {
      if (h <= 0 || w <= 0) error("Height and width must be postive integers.");
      if (rad > (w > h ? h : w) / 2) error("Radius entered is too large");
      add(pp);
    };

    void draw_lines() const;

    int width() const { return w; }
    int height() const { return h; }

  private:
    int w, h, rad;  // width, height, radius
  };

  //---------------------------------------------------------------------------

  Point n(const Box& box);
  Point s(const Box& box);
  Point e(const Box& box);
  Point w(const Box& box);
  Point center(const Box& box);
  Point ne(const Box& box);
  Point se(const Box& box);
  Point sw(const Box& box);
  Point nw(const Box& box);

  //---------------------------------------------------------------------------

  struct Arrow : Line {
    Arrow(Point p1, Point p2) : Line{p1, p2} {}
    void draw_lines() const;
  };

  //---------------------------------------------------------------------------

  Point n(const Rectangle& rect);
  Point s(const Rectangle& rect);
  Point e(const Rectangle& rect);
  Point w(const Rectangle& rect);
  Point center(const Rectangle& rect);
  Point nw(const Rectangle& rect);
  Point sw(const Rectangle& rect);
  Point ne(const Rectangle& rect);
  Point se(const Rectangle& rect);

  struct Textbox : Box {
    Textbox(Point xy, int ww, string s)
        : Box{xy, ww, h_tb},
          label(Point{xy.x + 4, xy.y + 17}, s)
    {
    }
    void draw_lines() const;
    void move(int dx, int dy);
    void set_color(Color c);

    Text label;

  private:
    static const int h_tb = 24;
  };

  //---------------------------------------------------------------------------

  class Face : public Circle {
  public:
    void draw_lines() const;
    void move(int dx, int dy);
    void set_color(Color c);
    void set_style(Line_style ls);
    void set_radius(int rr);

  protected:
    Face(Point p, int rr);
    Arc mouth;

  private:
    Ellipse l_eye;
    Ellipse r_eye;
  };

  //---------------------------------------------------------------------------

  class Smiley : public Face {
  public:
    Smiley(Point p, int rr);
  };

  //---------------------------------------------------------------------------

  class Frowny : public Face {
  public:
    Frowny(Point p, int rr);

  private:
    using Face::set_radius;
  };

  //---------------------------------------------------------------------------

  class Hat_smiley : public Smiley {
  public:
    Hat_smiley(Point p, int rr);

    void draw_lines() const;
    void move(int dx, int dy);
    void set_color(Color c);

  private:
    Polygon hat;
    // Smiley::set_radius;
  };

  class Hat_frowny : public Frowny {
  public:
    Hat_frowny(Point p, int rr);

    void draw_lines() const;
    void move(int dx, int dy);
    void set_color(Color c);

  private:
    Rectangle brim;
    Arc bowl;
  };

  /*
    EX 11: Derive a Binary_tree class from a Shape.

    Design Considerations:
      - class should accept an int representing the number of levels in the tree
      - should we create an abstract class to be used as the base
        of a Binary_tree/N_ary_tree?
          - ex: create a Node class and a Tree class, both abstract
            - derive a Binary_tree from Node and Tree?
  */
  class Binary_tree : public Shape {
  public:
    Binary_tree(Point xy, int levels, string edge_style);
    void draw_lines() const;
    void move(int dx, int dy);
    void set_color(Color c);
    void set_node_label(string n, string lbl);
    int levels() const { return lvls; }

  protected:
    Vector_ref<Shape> edges;
    Vector_ref<Text> labels;

  private:
    int lvls;  // represents the number of levels of this tree
  };

  struct Clock : Circle {
    Clock(Point xy, int rr);
    void draw_lines() const;
    void increase_time();
    void update_hands();

  private:
    Lines markers;
    Vector_ref<Line> hands;
    int hh, mm, ss;
  };
}
#endif
