#ifndef STORAGE_HPP
#define STORAGE_HPP

/**/

#include <memory>

/**/

struct Storage {
    Storage(unsigned size);
    ~Storage();

    void Push(unsigned idFactory);
    void Pull(unsigned idBattery);

   private:
    struct Opaque;
    std::unique_ptr<Opaque> opaque_;
};

/**/

#endif
