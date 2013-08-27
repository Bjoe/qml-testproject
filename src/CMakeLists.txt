
set(QT_SRCS
    mainuicontroller.cpp

    planet.cpp
    moon.cpp
)

set(RESOURCES ../resources.qrc)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${CMAKE_CURRENT_BINARY_DIR}/config.h"
  )

add_library(qmlTestProjectLib STATIC ${QT_SRCS})
target_link_libraries(qmlTestProjectLib Qt5::Widgets Qt5::Qml)

qt5_add_resources(QRC ${RESOURCES})
add_executable(qmlTest main.cpp ${QRC})
target_link_libraries(qmlTest qmlTestProjectLib Qt5::Core Qt5::Widgets Qt5::Qml Qt5::Quick)
