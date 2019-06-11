cmake_minimum_required(VERSION 3.14)

project(rockets)

find_package(Threads REQUIRED)

add_executable(rockets args.cpp battery.cpp factory.cpp main.cpp storage.cpp worker.cpp)

target_link_libraries(rockets Threads::Threads)

set_target_properties(rockets PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_CLANG_TIDY "clang-tidy;-header-filter=\".*\";-checks=\",-*,clang*,bugprone*,cppcoreguidelines*,-cppcoreguidelines-avoid-magic-numbers,misc*,-misc-non-private-member-variables-in-classes,modernize*,performance*,-readability-magic-numbers,readability*\""
)
