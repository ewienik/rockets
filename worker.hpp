#ifndef WORKER_HPP
#define WORKER_HPP

/**/

#include <memory>

/**/

struct Worker {
    Worker(unsigned id, unsigned time);

    Worker(Worker const &) = delete;
    void operator=(Worker const &) = delete;
    Worker(Worker &&) = delete;
    void operator=(Worker &&) = delete;

    void Run();

   protected:
    virtual ~Worker();

    [[nodiscard]] auto id() const -> unsigned;

   private:
    struct Opaque;
    std::unique_ptr<Opaque> opaque_;

    virtual void Do() = 0;
};

/**/

#endif
