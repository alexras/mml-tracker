FILE(GLOB MMLTrackerSourceFiles "*.cc")

FIND_PACKAGE(Qt4 REQUIRED)
include(${QT_USE_FILE})

ADD_LIBRARY(tracker_core ${MMLTrackerSourceFiles})
TARGET_LINK_LIBRARIES(tracker_core ${QT_LIBRARIES})

ADD_SUBDIRECTORY(gui)
