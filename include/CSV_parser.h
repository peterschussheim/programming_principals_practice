#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

// From: https://stackoverflow.com/a/1120224/6129793
// TODO: make this work! Need to overload in/out streams and test

class CSVRow {
public:
  std::string_view operator[](std::size_t index) const
  {
    return std::string_view(&m_line[m_data[index] + 1],
                            m_data[index + 1] - (m_data[index] + 1));
  }
  std::size_t size() const { return m_data.size() - 1; }
  void readNextRow(std::istream &str)
  {
    std::getline(str, m_line);

    m_data.clear();
    m_data.emplace_back(-1);
    std::string::size_type pos = 0;
    while ((pos = m_line.find(',', pos)) != std::string::npos) {
      m_data.emplace_back(pos);
      ++pos;
    }
    // This checks for a trailing comma with no data after it.
    pos = m_line.size();
    m_data.emplace_back(pos);
  }

private:
  std::string m_line;
  std::vector<int> m_data;
};

//------------------------------------------------------------------------------

std::istream &operator>>(std::istream &str, CSVRow &data)
{
  data.readNextRow(str);
  return str;
}

//------------------------------------------------------------------------------

class CSV_iterator {
public:
  typedef std::input_iterator_tag iterator_category;
  typedef CSVRow value_type;
  typedef std::size_t difference_type;
  typedef CSVRow *pointer;
  typedef CSVRow &reference;

  CSV_iterator(std::istream &str) : m_str(str.good() ? &str : NULL)
  {
    ++(*this);
  }
  CSV_iterator() : m_str(NULL) {}

  // Pre Increment
  CSV_iterator &operator++()
  {
    if (m_str) {
      if (!((*m_str) >> m_row)) { m_str = NULL; }
    }
    return *this;
  }
  // Post increment
  CSV_iterator operator++(int)
  {
    CSV_iterator tmp(*this);
    ++(*this);
    return tmp;
  }
  CSVRow const &operator*() const { return m_row; }
  CSVRow const *operator->() const { return &m_row; }

  bool operator==(CSV_iterator const &rhs)
  {
    return ((this == &rhs) || ((this->m_str == NULL) && (rhs.m_str == NULL)));
  }
  bool operator!=(CSV_iterator const &rhs) { return !((*this) == rhs); }

private:
  std::istream *m_str;
  CSVRow m_row;
};

class CSV_range {
  std::istream &stream;

public:
  CSV_range(std::istream &str) : stream{str} {}

  CSV_iterator begin() const { return CSV_iterator{stream}; }
  CSV_iterator end() const { return CSV_iterator{}; }
};