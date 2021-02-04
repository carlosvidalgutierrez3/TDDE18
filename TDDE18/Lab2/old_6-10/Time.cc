#include "Time.h"
#include <iostream>
#include <sstream>
#include <ostream>
using namespace std;

bool is_Valid (Time const & t){
if(t.hours>23||t.hours<0||t.minutes<0||t.minutes>59||t.seconds<0||t.seconds>59){
  return false;
  }
  else{
  return true;
  }
}


string to_string(Time t,bool const& twelve){
  std::stringstream ss{};
  std::string p{""};
  if(t.hours<12){
    p="am";
  }
  else if(twelve==true){
    p="pm";
    t.hours=t.hours-12;
  }
  else{
    p="pm";
  }
  if(t.hours<=9){
    ss<<0;
  }
  ss<<t.hours<<':';
  if(t.minutes<=9){
    ss<<0;
  }
  ss<<t.minutes<<':';
  if(t.seconds<=9){
    ss<<0;
  }
  ss<<t.seconds<<' '<<p;
  return ss.str();
}


bool is_am(Time const & t){
  if(t.hours<12){
    return true;
  }
  else{
    return false;
  }
}


Time& operator +(Time& t, int secs){
    t.seconds = t.seconds + secs;
    while(t.seconds > 59){
      t.seconds -= 60;
      t.minutes += 1;
      while(t.minutes > 59){
        t.minutes -= 60;
        t.hours += 1;
        if(t.hours > 23){
          t.hours -= 24;
        }
      }
    }
    return t;
}

Time& operator -(Time& t, int secs){
  t.seconds = t.seconds - secs;
  while(t.seconds < 0){
    t.seconds += 60;
    t.minutes -= 1;
    while(t.minutes < 0){
      t.minutes += 60;
      t.hours -= 1;
      if(t.hours < 0){
        t.hours += 24;
      }
    }
  }
  return t;
}

Time& operator ++(Time& t){
  t+1;
  return t;
}
Time operator ++(Time& t, int){
  Time tmp{t};
  tmp+1;
  return tmp;
}
Time& operator --(Time& t){
  t-1;
  return t;
}
Time operator --(Time& t, int){
  Time tmp{t};
  tmp-1;
  return tmp;
}


bool operator>(Time const& a, Time const& b){
  if(a.hours==b.hours&&a.minutes==b.minutes){
    return a.seconds>b.seconds;
  }
  else if(a.hours==b.hours){
    return a.minutes>b.minutes;
  }
  else {
    return a.hours>b.hours;
  }
}

bool operator<(Time const& a, Time const& b){
  return !(a>b);
}

bool operator==(Time const& a, Time const& b){
  if(a.hours==b.hours&&a.minutes==b.minutes){
    return a.seconds==b.seconds;
  }
  else{
    return false;
  }
}

bool operator!=(Time const& a, Time const& b){
  return !(a==b);
}

bool operator>=(Time const& a, Time const& b){
  return (a>b||a==b);
}

bool operator<=(Time const& a, Time const& b){
  return (a<b||a==b);
}


ostream& operator <<(ostream& os, Time const& t)
{
os<<t.hours<<":"<<t.minutes<<":"<<t.seconds<<endl;
return os;
}

std::istream& operator>>(std::istream& is, Time& t){
  char trash{};
  is >> t.hours;
  if(t.hours>23 || t.hours<0){
    is.setstate(ios_base::failbit);
  }
  is >> trash >> t.minutes;
  if(t.minutes>59 || t.minutes<0){
    is.setstate(ios_base::failbit);
  }
  is >> trash >> t.seconds;
  if(t.seconds>59 || t.seconds<0){
    is.setstate(ios_base::failbit);
  }
  return is;
}
