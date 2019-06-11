#ifndef FACTORY_HPP
#define FACTORY_HPP

/**/

#include "storage.hpp"
#include "worker.hpp"

/**/

struct Factory : public Worker {
    Factory(Storage &storage, unsigned id, unsigned time);
    virtual ~Factory();

   private:
    struct Opaque;
    Opaque *opaque_;

    virtual void Do();
};

/**/

#endif
