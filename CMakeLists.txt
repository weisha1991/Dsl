cmake_minimum_required(VERSION 2.8)

SET(FT_PATH "${CMAKE_SOURCE_DIR}/fest")
SET(CODE_PATH "${CMAKE_SOURCE_DIR}/code")
SET(TOOLS_PATH "${FT_PATH}/tools/")

MESSAGE("ft path: ${FT_PATH}")
MESSAGE("code path: ${CODE_PATH}")

project(FtMccDsl)

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3 -std=c++0x" )

INCLUDE_DIRECTORIES(
    "${CODE_PATH}/include/"
    "${TOOLS_PATH}/include/"
    "${TOOLS_PATH}/gtest/include/"
)   

file(GLOB SOURCES 
        "${CODE_PATH}/src/*.cpp"
        "${FT_PATH}/*.cpp"
        "${FT_PATH}/surpport-ft/*.cpp"
)

LINK_DIRECTORIES("${TOOLS_PATH}/gtest/lib/")

add_executable(FtMccDsl ${SOURCES})

TARGET_LINK_LIBRARIES(FtMccDsl gtest pthread)





