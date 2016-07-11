#include <iostream>
#include <thread>
#include <vector>

#include "args.hpp"
#include "battery.hpp"
#include "factory.hpp"
#include "storage.hpp"

/**/

using std::cout;
using std::endl;
using std::ref;
using std::thread;
using std::vector;

/**/

namespace {

/**/

template<class A>
void Run(Storage & storage, unsigned id, unsigned time) {
    A a(storage, id, time);
    a.Run();
}

/**/

}

/**/

int main(int argc, char const * const * argv) {
    cout << "Solution 201607-0 start" << endl;

    Args args(argc, argv);

    cout << "Count of factories: " << args.Factories() << endl;
    cout << "Count of batteries: " << args.Batteries() << endl;
    cout << "Size of storage: " << args.Storage() << endl;
    cout << "Time of produce: " << args.TimeProduce() << endl;
    cout << "Time of launch: " << args.TimeLaunch() << endl;

    Storage storage(args.Storage());
    vector<thread> threads;
    threads.reserve(args.Factories() + args.Batteries());
    for (unsigned i = 0; i < args.Batteries(); i++) {
        threads.push_back(thread(
            Run<Battery>, ref(storage), i, args.TimeLaunch()
        ));
    }
    for (unsigned i = 0; i < args.Factories(); i++) {
        threads.push_back(thread(
            Run<Factory>, ref(storage), i, args.TimeProduce()
        ));
    }
    for (unsigned i = 0; i < threads.size(); i++) {
        threads[i].join();
    }
    cout << "Solution 201607-0 end" << endl;
    return 0;
}

/**/
