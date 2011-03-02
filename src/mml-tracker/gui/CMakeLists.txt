FILE(GLOB TrackGuiSourceFiles "*.cc")
FILE(GLOB TrackGuiHeaders "*.h")

FIND_PACKAGE(Qt4 REQUIRED)
include(${QT_USE_FILE})

QT4_WRAP_CPP(TrackGuiMocSourceFiles ${TrackGuiHeaders})

INCLUDE_DIRECTORIES(${MMLTracker_SOURCE_DIR})
ADD_LIBRARY(tracker_gui ${TrackGuiMocSourceFiles} ${TrackGuiSourceFiles})
TARGET_LINK_LIBRARIES(tracker_gui ${QT_LIBRARIES} tracker_core)
