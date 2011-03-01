FILE(GLOB CMakeGuiSourceFiles "*.cc")

FIND_PACKAGE(Qt4 REQUIRED)
include(${QT_USE_FILE})

INCLUDE_DIRECTORIES(${MMLTracker_SOURCE_DIR})
ADD_LIBRARY(tracker_gui ${CMakeGuiSourceFiles})
TARGET_LINK_LIBRARIES(tracker_gui ${QT_LIBRARIES} tracker_core)
