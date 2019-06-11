#include "battery.hpp"

/**/

struct Battery::Opaque {
    Storage &storage_;

    Opaque(Storage &storage) : storage_(storage) {}
};

/**/

Battery::Battery(Storage &storage, unsigned id, unsigned time)
    : Worker(id, time), opaque_(new Opaque(storage)) {}

/**/

Battery::~Battery() { delete opaque_; }

/**/

void Battery::Do() { opaque_->storage_.Pull(id_); }

/**/
