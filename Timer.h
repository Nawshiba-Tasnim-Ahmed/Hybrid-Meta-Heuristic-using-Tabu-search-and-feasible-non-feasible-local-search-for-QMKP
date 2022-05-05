#ifndef __TIMER_H__
#define __TIMER_H__

using namespace std;

#include <sys/time.h>

#include <sys/resource.h>

#include <stdio.h>

class Timer {
  private:
    struct rusage res;
  struct timeval tp;
  double virtual_time, real_time;

  public:
    enum TYPE {
      REAL,
      VIRTUAL
    };
  Timer(void);
  double elapsed_time(const TYPE & type);

  void reset(); //Carlos García
};
#endif