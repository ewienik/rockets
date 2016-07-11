#ifndef BATTERY_HPP
#define BATTERY_HPP

/**/

#include "worker.hpp"
#include "storage.hpp"

/**/

struct Battery : public Worker {
    Battery(Storage & storage, unsigned id, unsigned time);
    virtual ~Battery();

private:
    struct Opaque;
    Opaque * opaque_;

    virtual void Do();
};

/**/

#endif
