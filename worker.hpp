#ifndef WORKER_HPP
#define WORKER_HPP

/**/

struct Worker {
    Worker(unsigned id, unsigned time);

    void Run();

   protected:
    virtual ~Worker();

    unsigned id_;

   private:
    struct Opaque;
    Opaque *opaque_;

    virtual void Do() = 0;
};

/**/

#endif
