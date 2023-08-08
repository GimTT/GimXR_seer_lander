set(AudioMute_SRC mediamute.cpp mutedsessionevents.cpp)
add_library(AudioMute STATIC ${AudioMute_SRC})
target_include_directories(AudioMute INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
