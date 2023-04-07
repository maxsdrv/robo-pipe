cmake_minimum_required(VERSION 3.15)

set(ROBO_PIPE_VERSION 0.1.0)
project(roboPipe VERSION ${ROBO_PIPE_VERSION} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(PROJECT_SOURCES
        robo_main.cpp
        RoboMoveScene.cpp
        RoboMoveScene.h
        SensorWidget.cpp
        SensorWidget.h)

set(IMAGES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Widget_test/Widget_test)
set(IMAGES_DEST ${CMAKE_CURRENT_BINARY_DIR}/images)
file(COPY ${IMAGES_DIR} DESTINATION ${IMAGES_DEST})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME}
                        Qt5::Core
                        Qt5::Widgets)

