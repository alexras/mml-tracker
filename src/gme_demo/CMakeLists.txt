FILE(GLOB GMEPlayerSources "*.cpp")

INCLUDE(FindSDL)

FIND_PACKAGE(SDL REQUIRED)

ADD_EXECUTABLE(gme_demo ${GMEPlayerSources})
INCLUDE_DIRECTORIES(${SDL_INCLUDE_DIR} ${CMAKE_SOURCE_DIR})
TARGET_LINK_LIBRARIES(gme_demo gme ${SDL_LIBRARY})
