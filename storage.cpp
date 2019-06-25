#include "storage.hpp"

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

/**/

using std::condition_variable;
using std::cout;
using std::endl;
using std::mutex;
using std::queue;
using std::unique_lock;

/**/

struct Storage::Opaque {
    unsigned size_;
    unsigned next_;
    queue<unsigned> queue_;
    mutex mutex_;
    condition_variable condition_;

    Opaque(unsigned size) : size_(size), next_(0) {}
};

/**/

Storage::Storage(unsigned size) : opaque_(new Opaque(size)) {}

/**/

Storage::~Storage() = default;

/**/

void Storage::Push(unsigned idFactory) {
    {
        unique_lock<mutex> lock(opaque_->mutex_);
        opaque_->condition_.wait(
            lock, [&] { return opaque_->queue_.size() < opaque_->size_; });
        cout << "produce rocket " << opaque_->next_;
        cout << " from factory " << idFactory;
        cout << " with storage size " << opaque_->queue_.size();
        cout << endl;
        opaque_->queue_.push(opaque_->next_);
        opaque_->next_++;
    }
    opaque_->condition_.notify_all();
}

/**/

void Storage::Pull(unsigned idBattery) {
    {
        unique_lock<mutex> lock(opaque_->mutex_);
        opaque_->condition_.wait(lock,
                                 [&] { return !opaque_->queue_.empty(); });
        auto rocket = opaque_->queue_.front();
        cout << " launch rocket " << rocket;
        cout << " from battery " << idBattery;
        cout << " with storage size " << opaque_->queue_.size();
        cout << endl;
        opaque_->queue_.pop();
    }
    opaque_->condition_.notify_all();
}

/**/
