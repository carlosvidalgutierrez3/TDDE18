#ifndef BOOK_H
#define BOOK_H
#include <string>

struct Time{
  int hours{};
  int minutes{};
  int seconds{};
};

int getHours(Time const & t);

int getMinutes(Time const & t);

int getSeconds(Time const & t);

bool is_am(Time const & t);

Time operator +(Time t, int secs);

Time operator -(Time t, int secs);

Time& operator ++(Time& t);

Time operator ++(Time& t, int);

Time& operator --(Time& t);

Time operator --(Time& t, int);

#endif
