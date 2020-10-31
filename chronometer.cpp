#include "chronometer.h"
using namespace std;
using namespace std::chrono;

Chronometer::Chronometer() {
  this->totalTime = 0;
  this->running = false;
}

void Chronometer::start() {
  if (!this->running) {
    this->running = true;
    this->startPoint = high_resolution_clock::now();
  }
}

void Chronometer::pause() {
  high_resolution_clock::time_point end = high_resolution_clock::now();
  if (this->running) {
    duration<double> time_span = duration_cast<duration<double>>(end - this->startPoint);
    this->totalTime += time_span.count();
    this->running = false;
  }
}

void Chronometer::reset() {
  this->running = false;
  this->totalTime = 0;
}

double Chronometer::time() {
  return totalTime;
}
