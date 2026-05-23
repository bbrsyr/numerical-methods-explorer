cmake_minimum_required(VERSION 3.19)
project(NumericalMethodsExplorer LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets LinguistTools Charts)

qt_standard_project_setup()

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui)

qt_add_executable(NumericalMethodsExplorer
    WIN32 MACOSX_BUNDLE
    src/main.cpp
    src/mainwindow.cpp

    ui/mainwindow.ui

    include/mainwindow.h
    include/NumericalMethod.h
    include/NewtonMethod.h
    include/FunctionEvaluator.h
    include/IterationData.h
    include/PlotWidget.h

    math/NewtonMethod.cpp
    math/FunctionEvaluator.cpp

)

add_subdirectory(external/muparser)

qt_add_translations(
    TARGETS NumericalMethodsExplorer
    TS_FILES NumericalMethodsExplorer_en_US.ts
)

target_link_directories(NumericalMethodsExplorer
    PRIVATE
        include
        external/muparser/include
)

target_include_directories(NumericalMethodsExplorer
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(NumericalMethodsExplorer
    PRIVATE
        Qt6::Core
        Qt6::Widgets
        Qt6::Charts
        muparser
)

install(TARGETS NumericalMethodsExplorer
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET NumericalMethodsExplorer
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
