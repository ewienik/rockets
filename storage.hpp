#ifndef STORAGE_HPP
#define STORAGE_HPP

/**/

struct Storage {
    Storage(unsigned size);

    void Push(unsigned idFactory);
    void Pull(unsigned idBattery);

   private:
    struct Opaque;
    Opaque *opaque_;
};

/**/

#endif
