#include <chrono>
#include <thread>

#include "worker.hpp"

/**/

using std::chrono::seconds;
using std::this_thread::sleep_for;

/**/

struct Worker::Opaque {
    unsigned time_;

    Opaque(unsigned time) : time_(time) { }
};

/**/

Worker::Worker(unsigned id, unsigned time) :
    id_(id),
    opaque_(new Opaque(time))
{ }

/**/

Worker::~Worker() {
    delete opaque_;
}

/**/

void Worker::Run() {
    while (true) {
        Do();
        sleep_for(seconds(opaque_->time_));
    }
}

/**/

