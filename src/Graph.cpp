#include "Graph.h"
#include <map>

namespace Graph_lib {
  // does two lines (p1,p2) and (p3,p4) intersect?
  // if se return the distance of the intersect point as distances from p1
  inline pair<double, double> line_intersect(Point p1, Point p2, Point p3,
                                             Point p4, bool& parallel)
  {
    double x1 = p1.x;
    double x2 = p2.x;
    double x3 = p3.x;
    double x4 = p4.x;
    double y1 = p1.y;
    double y2 = p2.y;
    double y3 = p3.y;
    double y4 = p4.y;

    double denom = ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));
    if (denom == 0) {
      parallel = true;
      return pair<double, double>(0, 0);
    }
    parallel = false;
    return pair<double, double>(
        ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / denom,
        ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / denom);
  }

  //---------------------------------------------------------------------------

  // intersection between two line segments
  // Returns true if the two segments intersect,
  // in which case intersection is set to the point of intersection
  bool line_segment_intersect(Point p1, Point p2, Point p3, Point p4,
                              Point& intersection)
  {
    bool parallel;
    pair<double, double> u = line_intersect(p1, p2, p3, p4, parallel);
    if (parallel || u.first < 0 || u.first > 1 || u.second < 0 || u.second > 1)
      return false;
    intersection.x = p1.x + u.first * (p2.x - p1.x);
    intersection.y = p1.y + u.first * (p2.y - p1.y);
    return true;
  }

  //---------------------------------------------------------------------------

  Shape::Shape() : lcolor(fl_color()), ls(0), fcolor(Color::invisible) {}

  //---------------------------------------------------------------------------

  void Shape::add(Point p)  // protected
  {
    points.push_back(p);
  }

  //---------------------------------------------------------------------------

  void Shape::set_point(int i, Point p) { points[i] = p; }

  //---------------------------------------------------------------------------

  void Shape::draw_lines() const
  {
    if (color().visibility() && 1 < points.size())  // draw sole pixel?
      for (unsigned int i = 1; i < points.size(); ++i)
        fl_line(points[i - 1].x, points[i - 1].y, points[i].x, points[i].y);
  }

  //---------------------------------------------------------------------------

  void Shape::draw() const
  {
    Fl_Color oldc = fl_color();
    // there is no good portable way of retrieving the current style
    fl_color(lcolor.as_int());
    fl_line_style(ls.style(), ls.width());
    draw_lines();
    fl_color(oldc);  // reset color (to pevious) and style (to default)
    fl_line_style(0);
  }

  //---------------------------------------------------------------------------

  void Shape::move(int dx, int dy)
  {
    for (unsigned int i = 0; i < points.size(); ++i) {
      points[i].x += dx;
      points[i].y += dy;
    }
  }

  //---------------------------------------------------------------------------

  void Shape::clear_points() { points.clear(); }

  //---------------------------------------------------------------------------

  void Polygon::add(Point p)
  {
    int np = number_of_points();

    if (1 < np) {  // check that thenew line isn't parallel to the previous one
      if (p == point(np - 1)) error("polygon point equal to previous point");
      bool parallel;
      line_intersect(point(np - 1), p, point(np - 2), point(np - 1), parallel);
      if (parallel) error("two polygon points lie in a straight line");
    }

    for (int i = 1; i < np - 1;
         ++i) {  // check that new segment doesn't interset and old point
      Point ignore(0, 0);
      if (line_segment_intersect(point(np - 1), p, point(i - 1), point(i),
                                 ignore))
        error("intersect in polygon");
    }

    Closed_polyline::add(p);
  }

  //---------------------------------------------------------------------------

  void Polygon::draw_lines() const
  {
    if (number_of_points() < 3) error("less than 3 points in a Polygon");
    Closed_polyline::draw_lines();
  }

  //---------------------------------------------------------------------------

  void Open_polyline::draw_lines() const
  {
    if (fill_color().visibility()) {
      fl_color(fill_color().as_int());
      fl_begin_complex_polygon();
      for (int i = 0; i < number_of_points(); ++i) {
        fl_vertex(point(i).x, point(i).y);
      }
      fl_end_complex_polygon();
      fl_color(color().as_int());  // reset color
    }

    if (color().visibility()) Shape::draw_lines();
  }

  //---------------------------------------------------------------------------

  void Closed_polyline::draw_lines() const
  {
    Open_polyline::draw_lines();

    if (color().visibility())  // draw closing line:
      fl_line(point(number_of_points() - 1).x, point(number_of_points() - 1).y,
              point(0).x, point(0).y);
  }

  //---------------------------------------------------------------------------
  //---------------------------------------------------------------------------

  void Lines::draw_lines() const
  {
    //	if (number_of_points()%2==1) error("odd number of points in set of
    // lines");
    if (color().visibility())
      for (int i = 1; i < number_of_points(); i += 2)
        fl_line(point(i - 1).x, point(i - 1).y, point(i).x, point(i).y);
  }

  //---------------------------------------------------------------------------

  void Text::draw_lines() const
  {
    int ofnt = fl_font();
    int osz = fl_size();
    fl_font(fnt.as_int(), fnt_sz);
    fl_draw(lab.c_str(), point(0).x, point(0).y);
    fl_font(ofnt, osz);
  }

  void Textbox::draw_lines() const
  {
    Box::draw_lines();
    label.draw();
  }

  void Textbox::move(int dx, int dy)
  {
    Box::move(dx, dy);
    label.move(dx, dy);
  }

  void Textbox::set_color(Color c)
  {
    Box::set_color(c);
    label.set_color(c);
  }

  Function::Function(Fct f, double r1, double r2, Point xy, int count,
                     double xscale, double yscale)
  // graph f(x) for x in [r1:r2) using count line segments with (0,0) displayed
  // at xy x coordinates are scaled by xscale and y coordinates scaled by yscale
  {
    if (r2 - r1 <= 0) error("bad graphing range");
    if (count <= 0) error("non-positive graphing count");
    double dist = (r2 - r1) / count;
    double r = r1;
    for (int i = 0; i < count; ++i) {
      add(Point(xy.x + int(r * xscale), xy.y - int(f(r) * yscale)));
      r += dist;
    }
  }

  Func::Func(Fct f, double rr1, double rr2, Point orig, int count, double xs,
             double ys, double prec)
      : Function{f, rr1, rr2, orig, count, xs, ys},
        fct{f},
        range1{rr2},
        range2{rr2},
        origin{orig},
        c{count},
        xsc{xs},
        ysc{ys},
        precision{prec}
  {
    // reset();
  }

  void Func::reset()
  {
    double dist = (range2 - range1) / c;
    double r = range1;
    clear_points();
    for (int i = 0; i < c; ++i) {
      int x = origin.x + int(int(r * xsc) / precision) * precision;
      int y = origin.y - int(int(fct(r) * ysc) / precision) * precision;
      add(Point{x, y});
      r += dist;
    }
  }

  void Func::reset_fct(Fct f)
  {
    fct = f;
    reset();
  }

  void Func::reset_range(double r1, double r2)
  {
    if (r2 - r1 <= 0) error("bad graphing range");
    range1 = r1;
    range2 = r2;
    reset();
  }

  void Func::reset_origin(Point orig)
  {
    origin = orig;
    reset();
  }

  void Func::reset_count(int count)
  {
    if (count <= 0) error("non-positive graphing count");
    c = count;
    reset();
  }

  void Func::reset_xscale(double xscale)
  {
    if (xscale == 0) error("xscale must not be zero");
    xsc = xscale;
    reset();
  }

  void Func::reset_yscale(double yscale)
  {
    if (yscale == 0) error("yscale must not be zero");
    ysc = yscale;
    reset();
  }

  void Func::reset_precision(double prec)
  {
    precision = prec;
    reset();
  }

  void Rectangle::draw_lines() const
  {
    if (fill_color().visibility()) {  // fill
      fl_color(fill_color().as_int());
      fl_rectf(point(0).x, point(0).y, w, h);
      fl_color(color().as_int());  // reset color
    }

    if (color().visibility()) {  // edge on top of fill
      fl_color(color().as_int());
      fl_rect(point(0).x, point(0).y, w, h);
    }
  }

  void Arrow::draw_lines() const
  {
    Line::draw_lines();

    // add arrowhead: p2 and two points
    double line_len =
        sqrt(double(pow(point(1).x - point(0).x, 2) +
                    pow(point(1).y - point(0).y, 2)));  // length of p1p2

    // coordinates of the a point on p1p2 with distance 8 from p2
    double pol_x = 8 / line_len * point(0).x + (1 - 8 / line_len) * point(1).x;
    double pol_y = 8 / line_len * point(0).y + (1 - 8 / line_len) * point(1).y;

    // pl is 4 away from p1p2 on the "left", pl_pol is orthogonal to p1p2
    double pl_x = pol_x + 4 / line_len * (point(1).y - point(0).y);
    double pl_y = pol_y + 4 / line_len * (point(0).x - point(1).x);

    // pr is 4 away from p1p2 on the "right", pr_pol is orthogonal to p1p2
    double pr_x = pol_x + 4 / line_len * (point(0).y - point(1).y);
    double pr_y = pol_y + 4 / line_len * (point(1).x - point(0).x);

    // draw arrowhead - is always filled in line color
    if (color().visibility()) {
      fl_begin_complex_polygon();
      fl_vertex(point(1).x, point(1).y);
      fl_vertex(pl_x, pl_y);
      fl_vertex(pr_x, pr_y);
      fl_end_complex_polygon();
    }
  }

  Axis::Axis(Orientation d, Point xy, int length, int n, string lab)
      : label(Point(0, 0), lab)
  {
    if (length < 0) error("bad axis length");
    switch (d) {
      case Axis::x: {
        Shape::add(xy);                          // axis line
        Shape::add(Point(xy.x + length, xy.y));  // axis line
        if (1 < n) {
          int dist = length / n;
          int x = xy.x + dist;
          for (int i = 0; i < n; ++i) {
            notches.add(Point(x, xy.y), Point(x, xy.y - 5));
            x += dist;
          }
        }
        // label under the line
        label.move(length / 3, xy.y + 20);
        break;
      }
      case Axis::y: {
        Shape::add(xy);  // a y-axis goes up
        Shape::add(Point(xy.x, xy.y - length));
        if (1 < n) {
          int dist = length / n;
          int y = xy.y - dist;
          for (int i = 0; i < n; ++i) {
            notches.add(Point(xy.x, y), Point(xy.x + 5, y));
            y -= dist;
          }
        }
        // label at top
        label.move(xy.x - 10, xy.y - length - 10);
        break;
      }
      case Axis::z:
        error("z axis not implemented");
    }
  }

  void Axis::draw_lines() const
  {
    Shape::draw_lines();  // the line
    notches.draw();  // the notches may have a different color from the line
    label.draw();    // the label may have a different color from the line
  }

  void Axis::set_color(Color c)
  {
    Shape::set_color(c);
    notches.set_color(c);
    label.set_color(c);
  }

  void Axis::move(int dx, int dy)
  {
    Shape::move(dx, dy);
    notches.move(dx, dy);
    label.move(dx, dy);
  }

  void Circle::draw_lines() const
  {
    if (fill_color().visibility()) {  // fill
      fl_color(fill_color().as_int());
      fl_pie(point(0).x, point(0).y, r + r - 1, r + r - 1, 0, 360);
      fl_color(color().as_int());  // reset color
    }

    if (color().visibility()) {
      fl_color(color().as_int());
      fl_arc(point(0).x, point(0).y, r + r, r + r, 0, 360);
    }
  }

  void Immobile_circle::draw_lines() const { Circle::draw_lines(); }

  void Ellipse::draw_lines() const
  {
    if (fill_color().visibility()) {  // fill
      fl_color(fill_color().as_int());
      fl_pie(point(0).x, point(0).y, w + w - 1, h + h - 1, 0, 360);
      fl_color(color().as_int());  // reset color
    }

    if (color().visibility()) {
      fl_color(color().as_int());
      fl_arc(point(0).x, point(0).y, w + w, h + h, 0, 360);
    }
  }

  void Box::draw_lines() const
  {
    if (fill_color().visibility()) {
      fl_color(fill_color().as_int());

      // rectangles
      fl_rectf(point(0).x + rad, point(0).y, w - 2 * rad, rad);
      fl_rectf(point(0).x, point(0).y + rad, w, h - 2 * rad);
      fl_rectf(point(0).x + rad, point(0).y + h - rad, w - 2 * rad, rad);

      // corners
      fl_pie(point(0).x, point(0).y, 2 * rad, 2 * rad, 90, 180);
      fl_pie(point(0).x + w - 2 * rad, point(0).y, 2 * rad, 2 * rad, 0, 90);
      fl_pie(point(0).x, point(0).y + h - 2 * rad, 2 * rad, 2 * rad, 180, 270);
      fl_pie(point(0).x + w - 2 * rad, point(0).y + h - 2 * rad, 2 * rad,
             2 * rad, 270, 360);

      fl_color(color().as_int());  // reset color
    }

    if (color().visibility()) {
      fl_color(color().as_int());
      fl_line(point(0).x + rad, point(0).y, point(0).x + w - rad - 1,
              point(0).y);
      fl_line(point(0).x, point(0).y + rad, point(0).x,
              point(0).y + h - rad - 1);
      fl_line(point(0).x + rad, point(0).y + h - 1, point(0).x + w - rad,
              point(0).y + h - 1);
      fl_line(point(0).x + w - 1, point(0).y + rad, point(0).x + w - 1,
              point(0).y + h - rad);

      // draw arcs
      fl_arc(point(0).x, point(0).y, 2 * rad, 2 * rad, 90, 180);
      fl_arc(point(0).x + w - 2 * rad, point(0).y, 2 * rad, 2 * rad, 0, 90);
      fl_arc(point(0).x, point(0).y + h - 2 * rad, 2 * rad, 2 * rad, 180, 270);
      fl_arc(point(0).x + w - 2 * rad, point(0).y + h - 2 * rad, 2 * rad,
             2 * rad, 270, 360);
    }
  }

  void draw_mark(Point xy, char c)
  {
    static const int dx = 4;
    static const int dy = 4;
    string m(1, c);
    fl_draw(m.c_str(), xy.x - dx, xy.y + dy);
  }

  void Marked_polyline::draw_lines() const
  {
    Open_polyline::draw_lines();
    for (int i = 0; i < number_of_points(); ++i)
      draw_mark(point(i), mark[i % mark.size()]);
  }

  std::map<string, Suffix::Encoding> suffix_map;

  int init_suffix_map()
  {
    suffix_map["jpg"] = Suffix::jpg;
    suffix_map["JPG"] = Suffix::jpg;
    suffix_map["jpeg"] = Suffix::jpg;
    suffix_map["JPEG"] = Suffix::jpg;
    suffix_map["gif"] = Suffix::gif;
    suffix_map["GIF"] = Suffix::gif;
    suffix_map["bmp"] = Suffix::bmp;
    suffix_map["BMP"] = Suffix::bmp;
    return 0;
  }

  Suffix::Encoding get_encoding(const string& s)
  // try to deduce type from file name using a lookup table
  {
    static int x = init_suffix_map();

    string::const_iterator p = find(s.begin(), s.end(), '.');
    if (p == s.end()) return Suffix::none;  // no suffix

    string suf(p + 1, s.end());
    return suffix_map[suf];
  }

  bool can_open(const string& s)
  // check if a file named s exists and can be opened for reading
  {
    ifstream ff(s.c_str());
    return bool(ff);
  }

  // somewhat overelaborate constructor
  // because errors related to image files can be such a pain to debug
  Image::Image(Point xy, string s, Suffix::Encoding e) : w(0), h(0), fn(xy, "")
  {
    add(xy);

    if (!can_open(s)) {
      fn.set_label("cannot open \"" + s + '\"');
      p = new Bad_image(30, 20);  // the "error image"
      return;
    }

    if (e == Suffix::none) e = get_encoding(s);

    switch (e) {
      case Suffix::jpg:
        p = new Fl_JPEG_Image(s.c_str());
        break;
      case Suffix::gif:
        p = new Fl_GIF_Image(s.c_str());
        break;
        //	case Suffix::bmp:
        //		p = new Fl_BMP_Image(s.c_str());
        //		break;
      default:  // Unsupported image encoding
        fn.set_label("unsupported file type \"" + s + '\"');
        p = new Bad_image(30, 20);  // the "error image"
    }
  }

  void Image::draw_lines() const
  {
    if (fn.label() != "") fn.draw_lines();

    if (w && h)
      p->draw(point(0).x, point(0).y, w, h, cx, cy);
    else
      p->draw(point(0).x, point(0).y);
  }

  //------------------------------------------------------------------------------

  Arc::Arc(Point p, int ww, int hh, double aa1, double aa2)
      : w{ww},
        h{hh},
        a1{aa1},
        a2{aa2}
  {
    if (aa2 <= aa1) {
      error("Second angle in arc must be LARGER than first angle");
    }
    add(Point{p.x - ww, p.y - hh});
  }

  void Arc::draw_lines() const
  {
    if (fill_color().visibility()) {
      fl_color(fill_color().as_int());
      fl_pie(point(0).x, point(0).y, w + w - 1, h + h - 1, a1, a2);
      fl_color(color().as_int());
    }

    if (color().visibility()) {
      fl_color(color().as_int());
      fl_arc(point(0).x, point(0).y, w + w, h + h, a1, a2);
    }
  }

  //------------------------------------------------------------------------------

  Point n(const Rectangle& rect)
  {
    return Point{rect.point(0).x + rect.width() / 2, rect.point(0).y};
  }

  Point s(const Rectangle& rect)
  {
    return Point{rect.point(0).x + rect.width() / 2,
                 rect.point(0).y + rect.height()};
  }

  Point e(const Rectangle& rect)
  {
    return Point{rect.point(0).x + rect.width(),
                 rect.point(0).y + rect.height() / 2};
  }

  Point w(const Rectangle& rect)
  {
    return Point{rect.point(0).x, rect.point(0).y + rect.height() / 2};
  }

  Point center(const Rectangle& rect)
  {
    return Point{rect.point(0).x + rect.width() / 2,
                 rect.point(0).y + rect.height() / 2};
  }

  Point nw(const Rectangle& rect) { return rect.point(0); }

  Point sw(const Rectangle& rect)
  {
    return Point{rect.point(0).x, rect.point(0).y + rect.height()};
  }

  Point ne(const Rectangle& rect)
  {
    return Point{rect.point(0).x + rect.width(), rect.point(0).y};
  }

  Point se(const Rectangle& rect)
  {
    return Point{rect.point(0).x + rect.width(),
                 rect.point(0).y + rect.height()};
  }

  //---------------------------------------------------------------------------

  Point n(const Graph_lib::Box& box)
  {
    return Point(box.point(0).x + box.width() / 2, box.point(0).y);
  }

  //------------------------------------------------------------------------------

  Point s(const Box& box)
  {
    return Point(box.point(0).x + box.width() / 2,
                 box.point(0).y + box.height());
  }

  //------------------------------------------------------------------------------

  Point e(const Box& box)
  {
    return Point(box.point(0).x + box.width(),
                 box.point(0).y + box.height() / 2);
  }

  //------------------------------------------------------------------------------

  Point w(const Box& box)
  {
    return Point(box.point(0).x, box.point(0).y + box.height() / 2);
  }

  //------------------------------------------------------------------------------

  Point center(const Box& box)
  {
    return Point(box.point(0).x + box.width() / 2,
                 box.point(0).y + box.height() / 2);
  }

  //------------------------------------------------------------------------------

  Point ne(const Box& box)
  {
    return Point(box.point(0).x + box.width(), box.point(0).y);
  }

  //------------------------------------------------------------------------------

  Point se(const Box& box)
  {
    return Point(box.point(0).x + box.width(), box.point(0).y + box.height());
  }

  //------------------------------------------------------------------------------

  Point sw(const Box& box)
  {
    return Point(box.point(0).x, box.point(0).y + box.height());
  }

  //------------------------------------------------------------------------------

  Point nw(const Box& box) { return box.point(0); }

  //---------------------------------------------------------------------------

  Face::Face(Point p, int rr)
      : Circle{p, rr},
        mouth(p, rr * 0.66, rr * 0.66, 180, 360),  // init a Smile face
        l_eye(Point{p.x - rr / 5, p.y - rr / 2}, rr / 8, rr / 3),
        r_eye(Point{p.x + rr / 5, p.y - rr / 2}, rr / 8, rr / 3)
  {
    l_eye.set_color(Color::invisible);
    l_eye.set_fill_color(color());
    r_eye.set_color(Color::invisible);
    r_eye.set_fill_color(color());
  }

  void Face::draw_lines() const
  {
    Circle::draw_lines();
    if (color().visibility()) {
      l_eye.draw();
      r_eye.draw();
      mouth.draw();
    }
  }

  void Face::set_color(Color c)
  {
    Shape::set_color(c);
    l_eye.set_fill_color(c);
    r_eye.set_fill_color(c);
    mouth.set_fill_color(c);
  }

  void Face::set_style(Line_style ls)
  {
    Circle::set_style(ls);
    mouth.set_style(ls);
  }

  void Face::move(int dx, int dy)
  {
    Shape::move(dx, dy);
    l_eye.move(dx, dy);
    r_eye.move(dx, dy);
    mouth.move(dx, dy);
  }

  void Face::set_radius(int rr)
  {
    Circle::set_radius(rr);
    l_eye.set_minor(rr / 3);
    l_eye.set_major(rr / 8);
    r_eye.set_minor(rr / 3);
    r_eye.set_major(rr / 8);

    // reposition eyes
    int dx = rr / 5 - (r_eye.center().x - center().x);
    int dy = (center().y - r_eye.center().y) - rr / 2;
    l_eye.move(-dx, dy);
    r_eye.move(dx, dy);

    // scale mouth
    mouth.set_minor(rr * 0.66);
    mouth.set_major(rr * 0.66);
  }

  //---------------------------------------------------------------------------

  Smiley::Smiley(Point p, int rr)  // default constructor
      : Face(p, rr)
  {
  }

  //---------------------------------------------------------------------------

  Hat_smiley::Hat_smiley(Point p, int rr)  // default constructor
      : Smiley(p, rr)
  {
    hat.add(Point(p.x - 0.8 * rr, p.y - 0.8 * rr));
    hat.add(Point(p.x - 0.8 * rr, p.y - 0.9 * rr));
    hat.add(Point(p.x - 0.6 * rr, p.y - 0.9 * rr));
    hat.add(Point(p.x - 0.6 * rr, p.y - 1.9 * rr));
    hat.add(Point(p.x + 0.6 * rr, p.y - 1.9 * rr));
    hat.add(Point(p.x + 0.6 * rr, p.y - 0.9 * rr));
    hat.add(Point(p.x + 0.8 * rr, p.y - 0.9 * rr));
    hat.add(Point(p.x + 0.8 * rr, p.y - 0.8 * rr));
    hat.set_fill_color(color());
  }

  void Hat_smiley::draw_lines() const
  {
    Smiley::draw_lines();
    if (color().visibility()) hat.draw();
  }

  void Hat_smiley::move(int dx, int dy)
  {
    Smiley::move(dy, dy);
    hat.move(dx, dy);
  }

  void Hat_smiley::set_color(Color c)
  {
    Smiley::set_color(c);
    hat.set_color(c);
    hat.set_fill_color(c);
  }

  //---------------------------------------------------------------------------

  Frowny::Frowny(Point p, int rr)  // default constructor
      : Face{p, rr}
  {
    // rotate mouth around
    mouth.set_angles(0, 180);
    mouth.move(0, 0.66 * rr);
  }

  //---------------------------------------------------------------------------

  Hat_frowny::Hat_frowny(Point p, int rr)
      : Frowny{p, rr},
        brim{Point(p.x - 0.8 * rr, p.y - 0.9 * rr),
             Point(p.x + 0.8 * rr, p.y - 0.8 * rr)},
        bowl(Point(p.x, p.y - 0.9 * rr), 0.6 * rr, 0.6 * rr, 0, 180)
  {
    // set hat colors
    brim.set_color(Color::invisible);
    brim.set_fill_color(color());
    bowl.set_color(Color::invisible);
    bowl.set_fill_color(color());
  }

  void Hat_frowny::draw_lines() const
  {
    Frowny::draw_lines();
    if (color().visibility()) {
      brim.draw();
      bowl.draw();
    }
  }

  void Hat_frowny::move(int dx, int dy)
  {
    Frowny::move(dy, dy);
    brim.move(dx, dy);
    bowl.move(dx, dy);
  }

  void Hat_frowny::set_color(Color c)
  {
    Frowny::set_color(c);
    brim.set_fill_color(c);
    bowl.set_fill_color(c);
  }

  //---------------------------------------------------------------------------

  Clock::Clock(Point p, int rr) : Circle{p, rr}, hh{0}, mm{0}, ss{0}
  {
    set_style(Line_style(Line_style::solid, 4));
    set_color(Color::black);
    // calculate ticks
    double inner_radius = 0.8 * r;  // radius of inner end of ticks
    for (int i = 0; i < 12; ++i) {
      double angle = i * pi / 6;
      int tanx1 = p.x + inner_radius * cos(pi / 2 - angle);
      int tanx2 = p.x + r * cos(pi / 2 - angle);
      int tany1 = p.y + inner_radius * sin(pi / 2 - angle);
      int tany2 = p.y + r * sin(pi / 2 - angle);

      markers.add(Point{tanx1, tany1}, Point{tanx2, tany2});
      markers.set_style(Line_style(Line_style::solid, 1));
    }

    // get system time
    time_t t = time(0);
    struct tm* now = localtime(&t);
    hh = now->tm_hour % 12;
    mm = now->tm_min;
    ss = now->tm_sec;

    // calc angles and set hands to proper position
    // angle is zero at 12:00, increases clockwise

    double phi = (hh + mm / 60.0) / 6.0 * phi;
    int hx = round(p.x + 0.6 * r * cos(pi / 2 - phi));   // hour.x
    int hy = round(p.y + 0.6 * r * sin(-pi / 2 + phi));  // hour.y
    hands.push_back(new Line(p, Point(hx, hy)));
    hands[0].set_style(Line_style(Line_style::solid, 3));

    phi = mm / 30.0 * pi;
    hx = round(p.x + 0.9 * r * cos(pi / 2 - phi));   // minute.x
    hy = round(p.y + 0.9 * r * sin(-pi / 2 + phi));  // minute.y
    hands.push_back(new Line(p, Point(hx, hy)));
    hands[1].set_style(Line_style(Line_style::solid, 3));

    phi = ss / 30.0 * pi;
    hx = round(p.x + 0.9 * r * cos(pi / 2 - phi));   // second.x
    hy = round(p.y + 0.9 * r * sin(-pi / 2 + phi));  // second.y
    hands.push_back(new Line(p, Point(hx, hy)));
    hands[2].set_style(Line_style(Line_style::solid, 2));
    hands[2].set_color(Color::red);
  }

  //---------------------------------------------------------------------------

  void Clock::Clock::draw_lines() const
  {
    Circle::draw_lines();  // call Circle's constructor
    markers.draw();
    for (int i = i; i < 3; ++i) { hands[i].draw(); }
  }

  //---------------------------------------------------------------------------

  void Clock::increase_time()
  {
    ++ss;
    if (ss == 60) {
      ss = 0;  // if we are at 60 seconds, reset to zero
      if (mm == 60) {
        ++hh;  // handle minute overflow
        mm = 0;
        if (hh == 12) {
          hh = 0;  // handle hour overflow
        }
      }
    }
  }

  //---------------------------------------------------------------------------

  void Clock::update_hands()
  {
    // move the points at the ENDS of each hand

    // handle hour hand first
    double phi = (hh + mm / 60.0) / 6.0 * pi;
    int hx = round(center().x + 0.6 * r * cos(pi / 2 - phi));   // calc hour.x
    int hy = round(center().y + 0.9 * r * sin(-pi / 2 + phi));  // calc hour.y
    hands[0].set_point(1, Point{hx, hy});

    // update minutes
    phi = mm / 30.0 * phi;
    hx = round(center().x + 0.9 * r * cos(pi / 2 - phi));
    hy = round(center().y + 0.9 * r * sin(-pi / 2 + phi));
    hands[1].set_point(1, Point{hx, hy});

    // update seconds
    phi = ss / 30.0 * phi;
    hx = round(center().x + 0.9 * r * cos(pi / 2 - phi));
    hy = round(center().y + 0.9 * r * sin(-pi / 2 + phi));
    hands[2].set_point(1, Point{hx, hy});
  }

  //---------------------------------------------------------------------------
  //---------------------------------------------------------------------------
  //---------------------------------------------------------------------------
  //---------------------------------------------------------------------------
  //---------------------------------------------------------------------------

  Binary_tree::Binary_tree(Point xy, int levels, string edge_style)
      : lvls(levels)
  {
    if (levels < 0) error("Binary_tree: levels must be at least zero");
    if (levels == 0) return;  // tree ist empty
    add(xy);                  // if levels==1, only root is added
    int dx = 35;              // distance between nodes on lowest level
    int dy = 100;             // distance between levels
    for (int i = 2; i <= levels; ++i) {
      for (int j = 0; j < pow(2, i - 1); ++j) {
        int x = xy.x - ((pow(2, i - 1) - 1) / 2 - j) * pow(2, levels - i) * dx;
        int y = xy.y + (i - 1) * dy;
        add(Point(x, y));
      }
    }

    for (int i = 0; i < number_of_points() / 2; ++i) {
      if (edge_style == "ad") {  // arrow down
        // QUESTION: why do we need to use the new keyword?
        // is this because we want to dynamically allocate memory?
        edges.push_back(new Arrow(
            point(i), Point(point(2 * i + 1).x, point(2 * i + 1).y - 12)));
        edges.push_back(new Arrow(
            point(i), Point(point(2 * i + 2).x, point(2 * i + 2).y - 12)));
      }
      else if (edge_style == "au") {  // arrow up
        edges.push_back(
            new Arrow(point(2 * i + 1), Point(point(i).x, point(i).y + 12)));
        edges.push_back(
            new Arrow(point(2 * i + 2), Point(point(i).x, point(i).y + 12)));
      }
      else {  // normal line
        edges.push_back(new Line(point(i), point(2 * i + 1)));
        edges.push_back(new Line(point(i), point(2 * i + 2)));
      }
    }

    // add label - empty for the moment
    for (int i = 0; i < number_of_points(); ++i)
      labels.push_back(new Text(Point(point(i).x + 13, point(i).y - 13), ""));
  }

  /*
  Binary_tree::Binary_tree(Point xy, int levels) : lvls(levels)
  {
   // check if levels is < 0
   if (levels < 0) error("levels must but a positive integer!", levels);

   // if levels == 0, return
   if (levels == 0) return;

   // add a level
   add(xy);
   int constexpr dx = 35;   // distance between nodes on the lowest level
   int constexpr dy = 100;  // spacing between each level

   for (int i = 2; i <= levels; ++i) {
     // TODO: explain the calculation here
     int level_max = pow(2, i - 1);
     for (int j = 0; j < level_max; ++j) {
       // scale x and y
       int x = xy.x - (pow(2, i - 1) - 1 / 2 - j) * pow(2, levels - i) * dx;
       int y = xy.y + (i - 1) * dy;
       add(Point{x, y});
     }
   }

   // add normal lines
   for (int i = 0; i < number_of_points() / 2; ++i) {
     edges.push_back(new Line(point(i), point(2 * i + 1)));
     edges.push_back(new Line(point(i), point(2 * i + 2)));
   }
  }
  */

  //---------------------------------------------------------------------------

  void Binary_tree::draw_lines() const
  {
    if (color().visibility()) {
      // Shape::draw_lines();
      fl_color(Color::black);
      for (int i = 0; i < edges.size(); ++i) { edges[i].draw(); }
      for (int i = 0; i < labels.size(); ++i) { labels[i].draw(); }

      // Fl_Color default_color = fl_rgb_color(192, 192, 192);

      int constexpr r = 12;
      for (int i = 0; i < number_of_points(); ++i) {
        fl_color(Color::white);
        fl_pie(point(i).x - r, point(i).y - r, r + r - 1, r + r - 1, 0, 360);
      }
      fl_color(color().as_int());  // reset color
      for (int i = 0; i < number_of_points(); ++i) {
        fl_color(Color::red);
        fl_arc(point(i).x - r, point(i).y - r, r + r, r + r, 0, 360);
      }
    }
  }

  //---------------------------------------------------------------------------

  void Binary_tree::set_color(Color c)
  {
    Shape::set_color(c);
    // Shape::set_fill_color(Color::Transparency::invisible);
  }

  //---------------------------------------------------------------------------

  void Binary_tree::move(int dx, int dy)
  {
    Shape::move(dx, dy);
    for (int i = 0; i < edges.size(); ++i) {
      edges[i].move(dx, dy);  // move each edge in our Vector_ref
    }

    for (int i = 0; i < labels.size(); ++i) {
      labels[i].move(dx, dy);  // move each leabel in the label Vector_ref
    }
  }

  //---------------------------------------------------------------------------

  // set label of node specified by string n to lbl. n is a sequence of l and r
  // for navigating left and right in the tree
  void Binary_tree::set_node_label(string n, string lbl)
  {
    if (n.size() < 1 || n.size() > lvls)
      error("set_node_label: illegal node string ", n);
    istringstream iss(n);
    char ch;
    iss.get(ch);  // look at first character
    if (n.size() == 1) {
      switch (ch) {
        case 'l':
        case 'r':
          labels[0].set_label(lbl);
          return;
        default:
          error("set_node_label: illegal character in node string: ",
                string(1, ch));
      }
    }
    int n_idx = 0;  // node index in point list
    while (iss.get(ch)) {
      switch (ch) {
        case 'l':
          n_idx = 2 * n_idx + 1;
          break;
        case 'r':
          n_idx = 2 * n_idx + 2;
          break;
        default:
          error("set_node_label: illegal character in node string: ",
                string(1, ch));
      }
    }
    labels[n_idx].set_label(lbl);
  }

}  // Graph