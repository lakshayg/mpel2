cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic")

project(mpel)

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost REQUIRED
  COMPONENTS
    log
    log_setup)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DBOOST_LOG_DYN_LINK")

find_package(OpenCV REQUIRED)

include_directories(${Boost_INCLUDE_DIRS}) 
include_directories("include")

SET(SRC "${CMAKE_SOURCE_DIR}/src")
set(CORE_DIR "${SRC}/core")
SET(PRIMITIVES_DIR "${CORE_DIR}/primitives")

set(MPEL_CORE_SRC
    "${PRIMITIVES_DIR}/path.cpp"
    "${PRIMITIVES_DIR}/point.cpp"
    "${PRIMITIVES_DIR}/graph.cpp"
    "${PRIMITIVES_DIR}/problem_definition.cpp"
    "${PRIMITIVES_DIR}/workspace.cpp"
    "${CORE_DIR}/planner.cpp"
    "${CORE_DIR}/interpolator.cpp")

add_library(mpel_core "${MPEL_CORE_SRC}")
target_link_libraries(mpel_core ${OpenCV_LIBS} ${Boost_LIBRARIES} pthread)

set(BUILTINS_DIR "${SRC}/builtins")
set(GRAPH_BUILDERS_DIR "${BUILTINS_DIR}/graph_builders")
set(MPEL_GRAPH_BUILDERS
    "${GRAPH_BUILDERS_DIR}/none.cpp"
    "${GRAPH_BUILDERS_DIR}/probabilistic_roadmap.cpp"
    "${GRAPH_BUILDERS_DIR}/random_trees.cpp"
    "${GRAPH_BUILDERS_DIR}/voronoi_roadmap.cpp")

set(GRAPH_SEARCH_DIR "${BUILTINS_DIR}/graph_search")
set(MPEL_GRAPH_SEARCH
    "${GRAPH_SEARCH_DIR}/none.cpp"
    "${GRAPH_SEARCH_DIR}/a_star.cpp"
    "${GRAPH_SEARCH_DIR}/breadth_first_search.cpp"
    "${GRAPH_SEARCH_DIR}/bidirectional_breadth_first_search.cpp")

set(INTERPOLATORS_DIR "${BUILTINS_DIR}/interpolators")
set(MPEL_INTERPOLATORS
    "${INTERPOLATORS_DIR}/none.cpp"
    "${INTERPOLATORS_DIR}/bug.cpp"
    "${INTERPOLATORS_DIR}/bug2.cpp"
    "${INTERPOLATORS_DIR}/potential_field.cpp")

set(MPEL_BUILTINS_SRC
    "${MPEL_GRAPH_BUILDERS}"
    "${MPEL_GRAPH_SEARCH}"
    "${MPEL_INTERPOLATORS}")

add_library(mpel_builtins "${MPEL_BUILTINS_SRC}")
target_link_libraries(mpel_builtins mpel_core)

set(MPEL_VISUALIZATION_DIR "${SRC}/visualization")
set(MPEL_VISUALIZATION_SRC
    "${MPEL_VISUALIZATION_DIR}/canvas.cpp"
    "${MPEL_VISUALIZATION_DIR}/opencv_support.cpp")

add_library(mpel_full "${MPEL_VISUALIZATION_SRC}")
target_link_libraries(mpel_full mpel_builtins)

# build demos
add_subdirectory("${CMAKE_SOURCE_DIR}/demo")