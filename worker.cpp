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
    unsigned id_;

    Opaque(unsigned id, unsigned time) : id_(id), time_(time) {}
};

/**/

Worker::Worker(unsigned id, unsigned time) : opaque_(new Opaque(id, time)) {}

/**/

Worker::~Worker() = default;

/**/

auto Worker::id() const -> unsigned { return opaque_->id_; }

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
