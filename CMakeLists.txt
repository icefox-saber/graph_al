#最低版本限制
cmake_minimum_required(VERSION 3.5)

#工程名 版本名 
project(YourExecutableName VERSION 0.1.0 LANGUAGES C CXX)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)

# 设置源文件目录# 设置头文件目录# 设置资源文件目录
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
#set(RESOURCES_DIR ${CMAKE_SOURCE_DIR}/resources)

# 查找源文件 # 查找头文件 # 查找资源文件
file(GLOB SOURCES ${SOURCE_DIR}/*.cpp)
file(GLOB HEADERS ${INCLUDE_DIR}/*.h)
#file(GLOB RESOURCES ${RESOURCES_DIR}/*)

# 设置可执行文件的输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR})    
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}) 

# 添加可执行文件
add_executable(YourExecutableName ${SOURCES})

# 添加头文件的路径到可执行文件的属性中
target_include_directories(YourExecutableName PRIVATE ${INCLUDE_DIR})

#set CPACK_PROJECT_NAME CPACK_PROJECT_VERSION
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

# 将资源文件从源目录复制到构建目录
#file(COPY ${RESOURCES} DESTINATION ${CMAKE_BINARY_DIR}/debug/resources)

# 添加头文件的路径到可执行文件的属性中
#target_include_directories(YourExecutableName PRIVATE ${INCLUDE_DIR} ${VCPKG_ROOT}/installed/x64-mingw-dynamic/include)
#find_package
#find_package(FLTK CONFIG REQUIRED)
#link
#target_link_libraries(YourExecutableName PRIVATE fltk fltk_gl fltk_forms fltk_images)