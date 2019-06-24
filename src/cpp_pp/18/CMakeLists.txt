# implement average_list for main1.cpp
add_executable(1
    average_list.hpp
    main1.cpp
)

# implement the special functions for cpmv struct
add_executable(2
    cpmv.cpp
    cpmv.hpp
    main2.cpp
)

# implement sum_value with variable length parameter
add_executable(3
    main3.cpp
    sum_value.hpp
)