#ifndef STORAGE_HPP
#define STORAGE_HPP

/**/

struct Storage {
    Storage(int size);

    void Push(int idFactory);
    void Pull(int idBattery);

private:
    struct Opaque;
    Opaque * opaque_;
};

/**/

#endif
