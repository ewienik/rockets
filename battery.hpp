#ifndef BATTERY_HPP
#define BATTERY_HPP

/**/

#include "storage.hpp"
#include "worker.hpp"

/**/

struct Battery : public Worker {
    Battery(Storage &storage, unsigned id, unsigned time);
    ~Battery() override;

   private:
    struct Opaque;
    std::unique_ptr<Opaque> opaque_;

    void Do() override;
};

/**/

#endif
