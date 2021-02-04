#include "Time.h"
#include <iostream>
#include <sstream>
#include <ostream>
using namespace std;

//TODO:->DONE Return the whole statement instead of first checking a boolean explression
//      and then return a new boolean that could be read from the statemnt you
//      just checked. --> Return whats in the if statement.
bool is_Valid (Time const & t){
  return(!(t.hours>23||t.hours<0||t.minutes<0||t.minutes>59||t.seconds<0||t.seconds>59));
}


string to_string(Time t,bool const& twelve){
  std::stringstream ss{};
  std::string p{""};


  //TODO:->DONE As twelve is a boolean you shall remove the ==true.
  if(twelve){
    p="pm";
    if(t.hours>12) {
      t.hours=t.hours-12;
    }
  }
  //TODO:->DONE Is this control needed in combination with twelve?
  else {
    p="am";
  }
  //TODO:->DONE You shall have only one case for each case... One if for am and one for pm.

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

//TODO:->DONE Return the statement condition instead.
bool is_am(Time const & t){
  return(t.hours<12);
}

//TODO: ->DONE Do we need to implement both, they look very much the same.
//      Reimplement by using one of them to implement the other one.

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

//TODO: Comment at line 51.
Time& operator -(Time& t, int secs){
  t = t + (-secs);
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

//TODO: -> DONE You did implement a good function; is_valid. It i very useful.
//TODO: ->DONE Do only change the value of t if the time is valid.
std::istream& operator>>(std::istream& is, Time& t){
  char trash{};
  Time temp{0,0,0};
  is>>temp.hours;
  is>>trash>>temp.minutes;
  is>>trash>>temp.seconds;

  if(!is_Valid(temp)){
    is.setstate(ios_base::failbit);
    return is;
  }

  t=temp;
  return is;
}
