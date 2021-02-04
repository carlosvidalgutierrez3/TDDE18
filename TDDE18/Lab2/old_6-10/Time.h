#ifndef TIME_H
#define TIME_H
#include <string>
#include <ostream>

struct Time{
  int hours{};
  int minutes{};
  int seconds{};
};

bool is_Valid(Time const& t);

bool is_am(Time const& t);

std::string to_string(Time t,bool const& twelve);


Time& operator +(Time& t, int secs);
Time& operator -(Time& t, int secs);
Time& operator ++(Time& t);
Time operator ++(Time& t, int);
Time& operator --(Time& t);
Time operator --(Time& t, int);

bool operator==(Time const& a, Time const& b);
bool operator!=(Time const& a, Time const& b);
bool operator<(Time const& a, Time const& b);
bool operator>(Time const& a, Time const& b);
bool operator<=(Time const& a, Time const& b);
bool operator>=(Time const& a, Time const& b);

std::ostream& operator<<(std::ostream& os, Time const& t);
std::istream& operator>>(std::istream& is, Time& t);

#endif
