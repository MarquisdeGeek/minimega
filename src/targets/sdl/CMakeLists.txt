cmake_minimum_required(VERSION 3.7)
project (minimega VERSION 0.1.0 LANGUAGES C CXX)

# The name 'Ditzy Chess' came much later and, because I like the binaries
# appearing at the end of ls (so I can check datestamps), the target
# remains 'misnamed'
set (EMU_TARGET minimega)
set (CMAKE_CXX_STANDARD 20)
set (CMAKE_BUILD_TYPE Debug)

set (EMF_ROOT ${CMAKE_CURRENT_LIST_DIR}/../..)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)

find_package(SDL2 REQUIRED)
# find_package(SDL2_image REQUIRED)

# Main project
set(TARGET_NAME mega_cpp)
add_executable(${TARGET_NAME})

set_target_properties(${TARGET_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${EMF_ROOT}"
)


target_include_directories (${TARGET_NAME} PUBLIC
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_IMAGE_INCLUDE_DIRS}
    ${EMF_ROOT}
)


target_sources (${TARGET_NAME}
PUBLIC
# ${EMF_ROOT}/targets/common/cpp/click_interface.cpp
# ${EMF_ROOT}/targets/common/cpp/screen.cpp
${EMF_ROOT}/targets/sdl/sdl_main.cpp
${EMF_ROOT}/targets/sdl/sdl_screen.cpp
${EMF_ROOT}/targets/sdl/sdl_joypad.cpp

${EMF_ROOT}/platforms/megaprocessor/common/cpp/memory.cpp
${EMF_ROOT}/platforms/megaprocessor/common/cpp/io.cpp
${EMF_ROOT}/platforms/megaprocessor/common/cpp/keypad.cpp
${EMF_ROOT}/platforms/megaprocessor/common/cpp/mega_update.cpp


# ${EMF_ROOT}/framework/comparator.c
)

target_link_libraries(${TARGET_NAME}
${SDL2_LIBRARIES}
${SDL2_IMAGE_LIBRARIES}
)


target_compile_definitions(${TARGET_NAME}
PUBLIC
EMF_INC_EMU_CPP=1
)

# Premix software with the emulator
target_compile_definitions(${TARGET_NAME}
PUBLIC
MEGA_PREMIX_SNAKE=0
MEGA_PREMIX_TETRIS=1
)

target_sources (${TARGET_NAME}
    PUBLIC
    ${EMF_ROOT}/platforms/megaprocessor/common/cpp/premix_loader.cpp

    ${EMF_ROOT}/platforms/megaprocessor/common/cpp/sw/fonttest.cpp
    ${EMF_ROOT}/platforms/megaprocessor/common/cpp/sw/monalisa.cpp
    ${EMF_ROOT}/platforms/megaprocessor/common/cpp/sw/snake.cpp
    ${EMF_ROOT}/platforms/megaprocessor/common/cpp/sw/tetris.cpp
)

