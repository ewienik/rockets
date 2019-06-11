#ifndef ARGS_HPP
#define ARGS_HPP

/**/

struct Args {
    Args(int argc, char const *const *argv);

    unsigned Factories();
    unsigned Batteries();
    unsigned Storage();
    unsigned TimeProduce();
    unsigned TimeLaunch();

   private:
    struct Opaque;
    Opaque *opaque_;
};

/**/

#endif
