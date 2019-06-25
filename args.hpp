#ifndef ARGS_HPP
#define ARGS_HPP

/**/

#include <memory>

/**/

struct Args {
    Args(int argc, char const *const *argv);
    ~Args();

    unsigned Factories();
    unsigned Batteries();
    unsigned Storage();
    unsigned TimeProduce();
    unsigned TimeLaunch();

   private:
    struct Opaque;
    std::unique_ptr<Opaque> opaque_;
};

/**/

#endif
