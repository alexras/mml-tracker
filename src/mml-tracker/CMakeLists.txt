FILE(GLOB MMLTrackerSourceFiles "*.cc")

FIND_PACKAGE(Qt4 REQUIRED)
include(${QT_USE_FILE})

ADD_LIBRARY(tracker ${MMLTrackerSourceFiles})
TARGET_LINK_LIBRARIES(tracker ${QT_LIBRARIES})
