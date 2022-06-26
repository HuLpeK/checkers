cmake_minimum_required(VERSION 3.22)
project(checkers)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Wextra -pedantic -Werror -fno-inline -Wunused)
add_executable(checkers main.cpp src/pieces.cpp src/pieces.hpp src/board.cpp src/board.hpp src/game.cpp src/game.hpp src/Participant.cpp src/Participant.hpp src/logic.cpp src/logic.hpp utils/clear.cpp utils/clear.h)

add_library(implement src/pieces.cpp src/pieces.hpp src/board.cpp src/board.hpp src/game.cpp src/game.hpp src/Participant.cpp src/Participant.hpp src/logic.cpp src/logic.hpp utils/clear.cpp utils/clear.h)
#Doxy Gen
option(BUILD_DOC "Build documentation" ON)

# check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ./docs/Doxyfile.in)
    set(DOXYGEN_OUT ./docs/Doxyfile)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doc_doxygen ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM )
else (DOXYGEN_FOUND)
    message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)



include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        checkers_test
        tst/board_test.cc tst/pieces_test.cc tst/Participant_test.cc tst/logic_test.cc)

target_link_libraries(
        checkers_test
        gtest_main
        gtest
        gmock
        implement
)
include(GoogleTest)
gtest_discover_tests(checkers_test implement)

add_custom_target(tests
        COMMAND "./checkers_test"
        DEPENDS checkers_test)
#add_test(
#        NAME checkers_test
#        COMMAND checkers_test
#)
