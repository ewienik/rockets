#ifndef STORAGE_HPP
#define STORAGE_HPP

/**/

#include <memory>

/**/

struct Storage {
    Storage(unsigned size);
    ~Storage();

    Storage(Storage const &) = delete;
    void operator=(Storage const &) = delete;
    Storage(Storage &&) = delete;
    void operator=(Storage &&) = delete;

    void Push(unsigned idFactory);
    void Pull(unsigned idBattery);

   private:
    struct Opaque;
    std::unique_ptr<Opaque> opaque_;
};

/**/

#endif
