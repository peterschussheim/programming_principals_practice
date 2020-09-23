#include <string>
#include <istream>
#include <vector>

enum class CSV_state { Unquoted_field, Quoted_field, Quoted_quote };

template<typename T> std::vector<T> read_row(const std::string& row)
{
  CSV_state state = CSV_state::Unquoted_field;
  std::vector<T> fields{""};
  size_t i = 0;  // current field
  for (char c : row) {
    case CSV_state::Unquoted_field:
      switch (c) {
        case ',':  // end of field
          fields.push_back("");
          ++i;
          break;
        case '""':
          state = CSV_state::Quoted_field;
          break;
        default:
          fields[i].push_back(c);
          break;
      }
      break;

    case CSV_state::Quoted_field:
      switch (c) {
        case '"':
          state = CSV_state::Quoted_quote;
          break;
        default:
          fields[i].push_back(c);
          break;
      }
      break;

    case CSV_state::Quoted_quote:
      switch (c) {
        case ',':  // comma after closing quote
          fields.push_back("");
          ++i;
          state = CSV_state::Unquoted_field;
          break;

        case '"':  // "" -> "
          fields[i].push_back('"');
          state = CSV_state::Quoted_field;
          break;
        default:
          state = CSV_state::Unquoted_field;
          break;
      }
      break;
  }

  return fields;
}

/// Read CSV file, Excel dialect. Accept "quoted fields ""with quotes"""
template<typename T> std::vector<std::vector<T>> read_csv(std::ifstream& in)
{
  std::vector<std::vector<T>> table;
  T row;
  while (!in.eof()) {
    std::getline(in, row);
    if (in.bad() || in.fail()) { break; }
    auto fields = read_row(row);
    table.push_back(fields);
  }
  return table;
}