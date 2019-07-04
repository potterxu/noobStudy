add_library(algoLib STATIC
    search.cpp
    search.hpp
    sort.cpp
    sort.hpp
)

target_include_directories(algoLib
    INTERFACE .
)