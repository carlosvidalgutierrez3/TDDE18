#include "Time.h"
using namespace std;

int getHours(Time const & t){
  return t.hours;
}

int getMinutes(Time const & t){
  return t.minutes;
}

int getSeconds(Time const & t){
  return t.seconds;
}

bool is_am(Time const & t){
  if(t.hours<12){
    return true;
  }
  else{
    return false;
  }
}

Time operator +(Time t, int secs){
    t.seconds = t.seconds + secs;

    if(t.seconds > 59){
      t.seconds -= 60;
      t.minutes += 1;

      if(t.minutes > 59){
        t.minutes -= 60;
        t.hours += 1;

        if(t.hours > 23){
          t.hours -= 24;
        }
      }
    }
    return t;
}

Time operator -(Time t, int secs){
  t.seconds = t.seconds - secs;

  if(t.seconds < 0){
    t.seconds += 60;
    t.minutes -= 1;

    if(t.minutes < 0){
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
  t = operator+(t,1);
  return t;
}

Time operator ++(Time& t, int){
  Time tmp{t};
  ++t;
  return tmp;
}

Time& operator --(Time& t){
  t = operator-(t,1);
  return t;
}

Time operator --(Time& t, int){
  Time tmp{t};
  --t;;
  return tmp;
}
