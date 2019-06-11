#include "worker.hpp"

#include <chrono>
#include <thread>

/**/

using std::chrono::seconds;
using std::this_thread::sleep_for;
using std::this_thread::yield;

/**/

struct Worker::Opaque {
    unsigned time_;

    Opaque(unsigned time) : time_(time) {}
};

/**/

Worker::Worker(unsigned id, unsigned time)
    : id_(id), opaque_(new Opaque(time)) {}

/**/

Worker::~Worker() { delete opaque_; }

/**/

void Worker::Run() {
    while (true) {
        Do();
        if (0 == opaque_->time_) {
            yield();
        } else {
            sleep_for(seconds(opaque_->time_));
        }
    }
}

/**/
