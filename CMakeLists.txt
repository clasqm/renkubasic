# RenkuBASIC --- a yab-compatible BASIC for Haiku and RenkuOS,
# based on yabasic 2.92.1 by Marc Ihm.
#
# Build as the project rules require:
#
#     mkdir build && cd build && cmake .. && make
#
# and `make clean` in the same directory. No install step is required.

cmake_minimum_required(VERSION 3.16)
project(renkubasic C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build type" FORCE)
endif()

# Haiku ships ncurses with its development package (ncurses_devel). The
# console layer (clear screen, at, colour, inkey) uses it.
set(CMAKE_FIND_PACKAGE_PREFER_CONFIG FALSE)
find_package(Curses REQUIRED)

# Optional: foreign function interface (needs libffi and dlopen).
option(RK_WITH_FFI "Build with the foreign function interface" OFF)

set(RK_SOURCES
  src/main.c
  src/function.c
  src/io.c
  src/symbol.c
  src/foreign.c
  src/flow.c
  src/flex.c
  src/bison.c
  src/rk_platform.c
  src/rk_graphics.c
  src/rk_gui.cpp
  src/yabcompat/rk_yab_cmd.c
  src/yabcompat/rk_yab.cpp
)

add_executable(renkubasic ${RK_SOURCES})

# The interpreter is a POSIX program with a Haiku platform seam. UNIX selects
# the POSIX code paths; it does not mean that X11 is used (see yabasic.h).
target_compile_definitions(renkubasic PRIVATE UNIX)

if(RK_WITH_FFI)
  find_library(FFI_LIBRARY NAMES ffi)
  find_path(FFI_INCLUDE_DIR NAMES ffi.h)
  if(NOT FFI_LIBRARY OR NOT FFI_INCLUDE_DIR)
    message(FATAL_ERROR "RK_WITH_FFI was requested, but libffi was not found")
  endif()
  target_compile_definitions(renkubasic PRIVATE USE_DL_FFI=1)
  target_include_directories(renkubasic PRIVATE ${FFI_INCLUDE_DIR})
  target_link_libraries(renkubasic PRIVATE ${FFI_LIBRARY})
endif()

target_include_directories(renkubasic PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${CURSES_INCLUDE_DIRS}
)

# -Wmissing-prototypes only makes sense for the C sources; the C++ backend has
# no C prototypes to miss.
target_compile_options(renkubasic PRIVATE -Wall
  "$<$<COMPILE_LANGUAGE:C>:-Wmissing-prototypes>")

# The graphic window uses the Haiku application kit (BApplication, BWindow,
# BBitmap, BFont) and the translation kit to encode screenshots as PNG.
find_library(HAIKU_BE_LIBRARY NAMES be)
find_library(HAIKU_TRANSLATION_LIBRARY NAMES translation)
# `filepanel` is Tracker's file panel: BFilePanel lives in libtracker, not in
# libbe, so the tracker kit has to be linked too.
find_library(HAIKU_TRACKER_LIBRARY NAMES tracker)
# The audio commands use the game kit (`sound`) and the media kit
# (`mediasound`, `loudness`).
find_library(HAIKU_GAME_LIBRARY NAMES game)
find_library(HAIKU_MEDIA_LIBRARY NAMES media)
if(NOT HAIKU_BE_LIBRARY OR NOT HAIKU_TRANSLATION_LIBRARY
   OR NOT HAIKU_TRACKER_LIBRARY
   OR NOT HAIKU_GAME_LIBRARY OR NOT HAIKU_MEDIA_LIBRARY)
  message(FATAL_ERROR
    "RenkuBASIC needs the Haiku kits: libbe, libtranslation, libtracker, libgame and libmedia")
endif()

target_link_libraries(renkubasic PRIVATE ${CURSES_LIBRARIES} m
  ${HAIKU_BE_LIBRARY} ${HAIKU_TRANSLATION_LIBRARY} ${HAIKU_TRACKER_LIBRARY}
  ${HAIKU_GAME_LIBRARY} ${HAIKU_MEDIA_LIBRARY})

# yabasic's man page and HTML manual are replaced by docs/manual in phase 3;
# until then the original page is installed unchanged so `man renkubasic`
# shows the inherited language.
install(TARGETS renkubasic RUNTIME DESTINATION bin)
install(FILES yabasic/yabasic-2.92.1/yabasic.1 DESTINATION share/man/man1)

# The parser (src/bison.c, src/bison.h, src/flex.c) is checked in, so a normal
# build needs neither bison nor flex. After editing src/yabasic.bison or
# src/yabasic.flex, run `make parser` to regenerate all three; it writes into
# the source tree on purpose, because that is what gets committed.
add_custom_target(parser
  COMMAND bison -d -l -t -v --output-file ${CMAKE_CURRENT_SOURCE_DIR}/src/bison.c
          ${CMAKE_CURRENT_SOURCE_DIR}/src/yabasic.bison
  COMMAND sh -c "flex -i -I -L -s -d -t ${CMAKE_CURRENT_SOURCE_DIR}/src/yabasic.flex > ${CMAKE_CURRENT_SOURCE_DIR}/src/flex.c"
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/yabasic.bison
          ${CMAKE_CURRENT_SOURCE_DIR}/src/yabasic.flex
  COMMENT "Regenerating src/bison.c, src/bison.h and src/flex.c"
  VERBATIM
)

enable_testing()
add_test(NAME cli-suite
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/tests/run-tests.sh
          --interpreter $<TARGET_FILE:renkubasic>
          --suite cli
)
