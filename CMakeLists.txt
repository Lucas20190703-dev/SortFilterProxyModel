cmake_minimum_required(VERSION 3.12)



find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)

if (${QT_VERSION_MAJOR} STREQUAL "6")
    set(USE_QT6 ON)
else()
    set(USE_QT6 OFF)
endif()

find_package(Qt${QT_VERSION_MAJOR}
    COMPONENTS
        Quick
        Core
)

message("QT_VERSION_MAJOR = ${QT_VERSION_MAJOR} ${USE_QT6}")

if (USE_QT6)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
else()
set(CMAKE_CXX_STANDARD 11)
endif()

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON) # This is to find generated *.moc and *.h files in build dir

set(SOURCES 
    qqmlsortfilterproxymodel.cpp
    filters/filter.cpp
    filters/filtercontainer.cpp
    filters/rolefilter.cpp
    filters/valuefilter.cpp
    filters/indexfilter.cpp
    filters/rangefilter.cpp
    filters/expressionfilter.cpp
    filters/filtercontainerfilter.cpp
    filters/anyoffilter.cpp
    filters/alloffilter.cpp
    filters/filtersqmltypes.cpp
    sorters/sorter.cpp
    sorters/sortercontainer.cpp
    sorters/rolesorter.cpp
    sorters/stringsorter.cpp
    sorters/expressionsorter.cpp
    sorters/sortersqmltypes.cpp
    proxyroles/proxyrole.cpp
    proxyroles/proxyrolecontainer.cpp
    proxyroles/joinrole.cpp
    proxyroles/switchrole.cpp
    proxyroles/expressionrole.cpp
    proxyroles/proxyrolesqmltypes.cpp   
    proxyroles/singlerole.cpp   
    proxyroles/regexprole.cpp
    sorters/filtersorter.cpp
    proxyroles/filterrole.cpp
)

if (USE_QT6)
    list(APPEND SOURCES 
        filters/regularexpressionfilter.cpp
    )
else()
    list(APPEND SOURCES 
        filters/regexpfilter.cpp
    )
endif()

message(STATUS ${SOURCES})

add_library(SortFilterProxyModel OBJECT ${SOURCES})

target_include_directories(SortFilterProxyModel PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    $<TARGET_PROPERTY:Qt${QT_VERSION_MAJOR}::Core,INTERFACE_INCLUDE_DIRECTORIES>
    $<TARGET_PROPERTY:Qt${QT_VERSION_MAJOR}::Qml,INTERFACE_INCLUDE_DIRECTORIES>
)

if (USE_QT6)
    target_compile_options(SortFilterProxyModel PUBLIC "/Zc:__cplusplus" "/permissive-")
endif()