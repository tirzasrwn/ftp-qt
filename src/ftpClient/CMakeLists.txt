cmake_minimum_required(VERSION 3.5)

project(ftpclient LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

    # Grep all source-code.
    file(GLOB project_sources
        "*.h"
        "*.cpp"
    )

    add_executable(ftpclient
        ${project_sources}
    )

target_link_libraries(ftpclient PRIVATE Qt5::Widgets)
