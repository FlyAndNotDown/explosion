file(GLOB_RECURSE DRIVER_TEST_SOURCES *.cpp)
exp_add_test(
    NAME DriverTest
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    SRCS ${DRIVER_TEST_SOURCES}
    INC_DIRS ${googletest_INCS}
    LIBS Engine ${googletest_LIBS}
)
