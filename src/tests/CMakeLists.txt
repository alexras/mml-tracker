FIND_PACKAGE(Qt4 REQUIRED)
include(${QT_USE_FILE})

ADD_EXECUTABLE(sequence_editor_test sequence_editor_test.cc)
TARGET_LINK_LIBRARIES(sequence_editor_test  ${QT_LIBRARIES} tracker_gui tracker_core)
INCLUDE_DIRECTORIES(${MMLTracker_SOURCE_DIR})
