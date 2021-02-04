#include <string>

struct Book{
  std::string title{};
  std::string author{};
  int year{};
  int edition{};
};

std::string getAuthor(Book b);
