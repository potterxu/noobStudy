add_library(dataStructureLib
    list.cpp
    list.hpp
    stack.cpp
    stack.hpp
    node.cpp
    node.hpp
    queue.cpp
    queue.hpp
    tree.cpp
    tree.hpp
)

target_include_directories(dataStructureLib
    INTERFACE .
)