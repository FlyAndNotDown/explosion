file(GLOB_RECURSE SOURCES Src/*.cpp)
exp_add_library(
    NAME Math
    TYPE STATIC
    SRCS ${SOURCES}
    PUBLIC_INC_DIRS Include ${glm_INCS}
)
