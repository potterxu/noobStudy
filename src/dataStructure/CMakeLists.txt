add_library(dataStructureLib
    list.cpp
    list.hpp
    stack.cpp
    stack.hpp
    node.cpp
    node.hpp
    queue.cpp
    queue.hpp
)

target_include_directories(dataStructureLib
    INTERFACE .
)