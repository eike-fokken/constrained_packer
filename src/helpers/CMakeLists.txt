add_library(classes STATIC classes.cpp)

target_link_libraries(classes PUBLIC casadi)
target_include_directories(classes PUBLIC include)
