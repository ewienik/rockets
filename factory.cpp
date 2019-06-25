#include "factory.hpp"

/**/

struct Factory::Opaque {
    Storage &storage_;

    Opaque(Storage &storage) : storage_(storage) {}
};

/**/

Factory::Factory(Storage &storage, unsigned id, unsigned time)
    : Worker(id, time), opaque_(new Opaque(storage)) {}

/**/

Factory::~Factory() = default;

/**/

void Factory::Do() { opaque_->storage_.Push(id_); }

/**/
