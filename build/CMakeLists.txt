cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME Library)
project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_DIR "..")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../${PROJECT_DIR}/bin)
set(EXE_OUTPUT_PATH ${PROJECT_DIR}/bin)
file(GLOB_RECURSE SOURCES
	"${PROJECT_DIR}/src/*.cpp"
	"${PROJECT_DIR}/src/*.h")
	source_group("src" FILES ${SOURCES})
	add_executable(${PROJECT_NAME} ${SOURCES})
	set(CMAKE_CXX_FLAGS_DEBUG "${PROJECT_DIR})")