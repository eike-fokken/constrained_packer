add_executable(main main.cpp)

target_link_libraries(main casadi)


set(my_debug_options -O0 -Werror -Wconversion -pedantic-errors -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wundef
  -Wdisabled-optimization -Wformat=2 -Winit-self -Wmissing-declarations -Wmissing-include-dirs -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-overflow=5 -Wswitch-default -Wunused -Wno-error=unused-parameter -Wno-error=unused -Wno-error=unused-variable -Wno-error=unused-value -Wdelete-non-virtual-dtor -Wno-error=undef)
set(debug_clang_options "-Wunreachable-code;-fcolor-diagnostics;-Wno-error=unused-private-field;-Wmissing-prototypes;-Wdocumentation;-Wno-error=unknown-warning-option")

set(debug_gcc_options "-Wsuggest-override;-fdiagnostics-color;-Wno-error=strict-overflow;-Wno-error=unused-but-set-variable")

set(release_clang_options "")
set(release_gcc_options "")




if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options("$<$<CONFIG:DEBUG>:${my_debug_options}>")
  add_compile_options("$<$<CONFIG:DEBUG>:${debug_clang_options}>"
    "$<$<NOT:$<CONFIG:Debug>>:${release_clang_options}>")
elseif (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  add_compile_options("$<$<CONFIG:DEBUG>:${my_debug_options}>")
   add_compile_options("$<$<CONFIG:DEBUG>:${debug_gcc_options}>"
     "$<$<NOT:$<CONFIG:Debug>>:${release_gcc_options}>")
else()
  message(WARNING "Your compiler, ${CMAKE_CXX_COMPILER_ID}, is untested with Grazer but maybe still works. Tested compilers are gcc and clang.")
endif()


