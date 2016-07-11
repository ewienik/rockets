#include <string>
#include <vector>

#include "args.hpp"

/**/

using std::back_inserter;
using std::copy;
using std::stoul;
using std::string;
using std::vector;

/**/

namespace {

/**/

unsigned const kFactories = 10;
unsigned const kBatteries = 10;
unsigned const kStorage = 10;
unsigned const kTimeProduce = 1;
unsigned const kTimeLaunch = 3;

/**/

void parse_unsigned(unsigned & value, vector<string> & args) {
    if (!args.size()) {
        return;
    }
    value = stoul(args.front());
    args.erase(args.begin());
}

/**/

}

/**/

struct Args::Opaque {
    unsigned batteries_;
    unsigned factories_;
    unsigned storage_;
    unsigned timeProduce_;
    unsigned timeLaunch_;

    Opaque(int argc, char const * const * argv) :
        batteries_(kBatteries),
        factories_(kFactories),
        storage_(kStorage),
        timeProduce_(kTimeProduce),
        timeLaunch_(kTimeLaunch)
    {
        vector<string> args;
        args.reserve(argc - 1);
        copy(argv + 1, argv + argc, back_inserter(args));
        parse_unsigned(factories_, args);
        parse_unsigned(batteries_, args);
        parse_unsigned(storage_, args);
        parse_unsigned(timeProduce_, args);
        parse_unsigned(timeLaunch_, args);
    }
};

/**/

Args::Args(int argc, char const * const * argv) :
    opaque_(new Opaque(argc, argv))
{ }

/**/

unsigned Args::Batteries() {
    return opaque_->batteries_;
}

/**/

unsigned Args::Factories() {
    return opaque_->factories_;
}

/**/

unsigned Args::Storage() {
    return opaque_->storage_;
}

/**/

unsigned Args::TimeProduce() {
    return opaque_->timeProduce_;
}

/**/

unsigned Args::TimeLaunch() {
    return opaque_->timeLaunch_;
}

/**/
