#ifndef ARGS_HPP
#define ARGS_HPP

/**/

#include <memory>

/**/

struct Args {
    Args(int argc, char const *const *argv);
    ~Args();

    Args(Args const &) = delete;
    void operator=(Args const &) = delete;
    Args(Args &&) = delete;
    void operator=(Args &&) = delete;

    auto Factories() -> unsigned;
    auto Batteries() -> unsigned;
    auto Storage() -> unsigned;
    auto TimeProduce() -> unsigned;
    auto TimeLaunch() -> unsigned;

   private:
    struct Opaque;
    std::unique_ptr<Opaque> opaque_;
};

/**/

#endif
