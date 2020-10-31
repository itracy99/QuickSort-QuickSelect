#ifndef __CHRONOMETER_H__
#define __CHRONOMETER_H__

#include <chrono>

class Chronometer {
  std::chrono::high_resolution_clock::time_point startPoint;
  bool running;
  double totalTime;

public:
  Chronometer();

  /* Starts the chronometer.
   * if the chronometer was already running, the method has no effect
   */
  void start();

  /* Pauses the chronometer.
   * if the chronometer was not running, the method has no effect
   */
  void pause();

  /* Resets the chronometer to zero */
  void reset();

  /* Returns the total amount of time the chronometer has run
   * since the previous reset.
   * If the chronometer is currently running, the current time interval
   * is not taken into account.
   */
  double time();
};
  
#endif
