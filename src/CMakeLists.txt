add_library(neoui neoui.cc)

target_include_directories(neoui PUBLIC ${CMAKE_SOURCE_DIR}/vendor
                                        ${CMAKE_SOURCE_DIR}/include)

find_package(PkgConfig REQUIRED)

# GTK4
pkg_check_modules(GTK4 REQUIRED gtk4)
add_definitions(${GTK4_CFLAGS_OTHER})
target_include_directories(neoui PUBLIC ${GTK4_INCLUDE_DIRS})
target_link_directories(neoui PUBLIC ${GTK4_LIBRARY_DIRS})
target_link_libraries(neoui PUBLIC ${GTK4_LIBRARIES})

add_executable(run run.cc)

target_link_libraries(run PUBLIC neoui)
