# Project definition
cmake_minimum_required(VERSION 3.9)

project(Engine)

include(~/repos/vcpkg/scripts/buildsystems/vcpkg.cmake)

# Source files
#set(CMAKE_BUILD_TYPE Debug)
set(dir ${CMAKE_CURRENT_SOURCE_DIR})
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/source")
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libraries")

#file(COPY ${SRC_DIR}/res DESTINATION ${dir}/build)
file(REMOVE_RECURSE  ${dir}/build/Debug/res)
file(COPY ${dir}/resources DESTINATION ${dir}/build/Debug)


file(GLOB APP_S "${SRC_DIR}/*.cpp")
file(GLOB APP_H "${SRC_DIR}/*.h")

file(GLOB REN_S "${SRC_DIR}/Rendering/*.cpp")
file(GLOB REN_H "${SRC_DIR}/Rendering/*.h")

file(GLOB GUI_S "${SRC_DIR}/GUI/*.cpp")
file(GLOB GUI_H "${SRC_DIR}/GUI/*.h")

file(GLOB FILES 
    "${SRC_DIR}/*.cpp"
    "${SRC_DIR}/*.hpp"
    "${SRC_DIR}/Rendering/*.cpp"
    "${SRC_DIR}/Rendering/*.hpp"
    "${SRC_DIR}/Panel/*.cpp"
    "${SRC_DIR}/Panel/*.hpp"
    "${SRC_DIR}/Scene/*.cpp"
    "${SRC_DIR}/Scene/*.hpp")

find_package(imgui CONFIG REQUIRED)
find_package(imguizmo CONFIG REQUIRED)
find_path(STB_INCLUDE_DIRS "stb.h")
find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(assimp CONFIG REQUIRED)
find_package(yaml-cpp CONFIG REQUIRED)

if (WIN32 AND BUILD_SHARED_LIBS)
  target_compile_definitions (yaml-cpp INTERFACE ${PROJECT_NAME}_DLL)
endif (WIN32 AND BUILD_SHARED_LIBS)


#add_executable(${PROJECT_NAME} ${APP_S} ${APP_H} ${REN_S} ${REN_H} ${GUI_S} ${GUI_H})
# add_executable(${PROJECT_NAME} ${APP_S} ${APP_H} ${REN_S} ${REN_H})

add_executable(${PROJECT_NAME} ${FILES})

target_include_directories(${PROJECT_NAME} PRIVATE "${SRC_DIR}")
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

target_include_directories(${PROJECT_NAME} PRIVATE ${STB_INCLUDE_DIRS})  
target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm)  
target_link_libraries(${PROJECT_NAME} PRIVATE imgui::imgui)
target_link_libraries(${PROJECT_NAME} PRIVATE imguizmo::imguizmo)   
target_link_libraries(${PROJECT_NAME} PRIVATE glad::glad)  
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE assimp::assimp)
target_link_libraries(${PROJECT_NAME} PRIVATE yaml-cpp)
# include_directories("dep/yaml-cpp/include")
# target_link_libraries(${PROJECT_NAME} "dep/yaml-cpp/src")

#add_subdirectory("dep/yaml-cpp")

file(COPY ${dir}/resources DESTINATION ${dir}/build/Debug)


