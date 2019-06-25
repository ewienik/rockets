#ifndef FACTORY_HPP
#define FACTORY_HPP

/**/

#include "storage.hpp"
#include "worker.hpp"

/**/

struct Factory : public Worker {
    Factory(Storage &storage, unsigned id, unsigned time);
    ~Factory() override;

    Factory(Factory const &) = delete;
    void operator=(Factory const &) = delete;
    Factory(Factory &&) = delete;
    void operator=(Factory &&) = delete;

   private:
    struct Opaque;
    std::unique_ptr<Opaque> opaque_;

    void Do() override;
};

/**/

#endif
