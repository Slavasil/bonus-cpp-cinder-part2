cmake_minimum_required(VERSION 3.10)
project(Bonus LANGUAGES CXX)

get_filename_component( CINDER_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Cinder" ABSOLUTE )
get_filename_component( APP_PATH "${CMAKE_CURRENT_SOURCE_DIR}" ABSOLUTE )

include("${CINDER_PATH}/proj/cmake/modules/cinderMakeApp.cmake")

ci_make_app( TARGET Bonus
    CINDER_PATH ${CINDER_PATH}
    APP_PATH ${APP_PATH}
    SOURCES main.cpp app.cpp
)
set_property(TARGET Bonus PROPERTY CXX_STANDARD 23)
set_property(TARGET Bonus PROPERTY CXX_STANDARD_REQUIRED YES)
