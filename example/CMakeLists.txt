project(SPRITER_EXAMPLE CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
option(UsePugixml "Use pugixml instead of tinyxml2 for file parsing" OFF)
if(UsePugixml)
    add_definitions(-D__USE_PUGIXML)
endif()

# Setup SDL2
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
include_directories(
        /usr/local/include
        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR}
)

include_directories(${JSON_SOURCE_DIR})

set(SPRITER_EXAMPLE_SRCS
    main.cpp
    override/examplefilefactory.cpp
    override/exampleobjectfactory.cpp)
set(SPRITER_EXAMPLE_HDRS
    override/examplefilefactory.h
    override/exampleobjectfactory.h)

set(SPRITER_PUGIXML_IMPL_SRCS
    override/pugixmlspriterfileattributewrapper.cpp
    override/pugixmlspriterfiledocumentwrapper.cpp
    override/pugixmlspriterfileelementwrapper.cpp)
set(SPRITER_PUGIXML_IMPL_HDRS
    override/pugixmlspriterfileattributewrapper.h
    override/pugixmlspriterfiledocumentwrapper.h
    override/pugixmlspriterfileelementwrapper.h)

set(SPRITER_TINYXML2_IMPL_SRCS
    override/tinyxmlspriterfileattributewrapper.cpp
    override/tinyxmlspriterfiledocumentwrapper.cpp
    override/tinyxmlspriterfileelementwrapper.cpp)
set(SPRITER_TINYXML2_IMPL_HDRS
    override/tinyxmlspriterfileattributewrapper.h
    override/tinyxmlspriterfiledocumentwrapper.h
    override/tinyxmlspriterfileelementwrapper.h)

set(SPRITER_JSON_IMPL_SRCS
    override/jsonspriterfileattributewrapper.cpp
    override/jsonspriterfiledocumentwrapper.cpp
    override/jsonspriterfileelementwrapper.cpp)
set(SPRITER_JSON_IMPL_HDRS
    override/jsonspriterfileattributewrapper.h
    override/jsonspriterfiledocumentwrapper.h
    override/jsonspriterfileelementwrapper.h)

set(SPRITER_SFML_IMPL_SRCS
    override/sfmlboneinstanceinfo.cpp
    override/sfmlimagefile.cpp
    override/sfmlatlasfile.cpp
    override/sfmlsoundfile.cpp
    override/sfmlboxinstanceinfo.cpp
    override/sfmlpointinstanceinfo.cpp
    override/sfmlsoundobjectinforeference.cpp)
set(SPRITER_SFML_IMPL_HDRS
    override/sfmlboneinstanceinfo.h
    override/sfmlimagefile.h
    override/sfmlatlasfile.h
    override/sfmlsoundfile.h
    override/sfmlboxinstanceinfo.h
    override/sfmlpointinstanceinfo.h
    override/sfmlsoundobjectinforeference.h)

set(SPRITER_EXAMPLE_SRCS
    ${SPRITER_EXAMPLE_SRCS}
    ${SPRITER_PUGIXML_IMPL_SRCS}
    ${SPRITER_TINYXML2_IMPL_SRCS}
    ${SPRITER_JSON_IMPL_SRCS}
    ${SPRITER_SFML_IMPL_SRCS})
set(SPRITER_EXAMPLE_HDRS
    ${SPRITER_EXAMPLE_HDRS}
    ${SPRITER_PUGIXML_IMPL_HDRS}
    ${SPRITER_TINYXML2_IMPL_HDRS}
    ${SPRITER_JSON_IMPL_HDRS}
    ${SPRITER_SFML_IMPL_HDRS})

add_executable(SpriterPlusPlus ${SPRITER_EXAMPLE_SRCS})

target_link_libraries (SpriterPlusPlus
        ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES}
        tinyxml2
        pugixml
        spriterengine)
