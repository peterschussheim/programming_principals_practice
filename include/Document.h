#include <vector>
#include <list>

using Line = std::vector<char>;  // a line is a vector of chars

//------------------------------------------------------------------------------

class Text_iterator {  // maintain location of line and char pos
                       // within a line
  std::list<Line>::iterator ln;
  Line::iterator pos;

public:
  // start iterator at line ll's char position pp:
  Text_iterator(std::list<Line>::iterator ll, Line::iterator pp)
      : ln{ll}, pos{pp}
  {
  }

  char& operator*() { return *pos; }
  Text_iterator& operator++();

  bool operator==(const Text_iterator& other) const
  {
    return ln == other.ln && pos == other.pos;
  }

  bool operator!=(const Text_iterator& other) const
  {
    return !(*this == other);
  }
};

//------------------------------------------------------------------------------

Text_iterator& Text_iterator::operator++()
{
  ++pos;  // proceed to the next character
  if (pos == (*ln).end()) {
    ++ln;                 // proceed to the next line
    pos = (*ln).begin();  // bad if ln==line.end()
  }
  return *this;
}

//------------------------------------------------------------------------------

struct Document {
  std::list<Line> line;  // a Document is a list of lines
  Document() { line.push_back(Line{}); }

  Text_iterator begin();  // first character of first line
  Text_iterator end();    // one beyond the last character of the last line
};

Text_iterator Document::begin()
{
  // get the beginning of what line.begin() points to.
  // an alternative to the (*line.begin()).begin()) syntax is
  // the arrow operator: line.begin()->begin();
  return Text_iterator(line.begin(), (*line.begin()).begin());
}

Text_iterator Document::end()
{
  auto last = line.end();
  --last;  // we know the document is not empty
  return Text_iterator(last, (*last).end());
}