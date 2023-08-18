# Set the minimum version of cmake
cmake_minimum_required (VERSION 3.10 FATAL_ERROR)

# Set the project name
project (volumetric VERSION "0.0" LANGUAGES CXX)

#set(CMAKE_CXX_STANDARD 11)

#Set flags when -D USE_SYCL is set
IF (USE_SYCL)
    ADD_DEFINITIONS (-DUSE_SYCL)
    IF (USE_FPGA_EMULATOR)
	SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fintelfpga")
	ADD_DEFINITIONS (-DFPGA_EMULATOR)
    ELSEIF (USE_FPGA_REPORT)
	SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fintelfpga -fsycl-link -Xshardware")
	ADD_DEFINITIONS (-DFPGA_EMULATOR)
    ELSEIF (USE_FPGA_BITSTREAM)
	SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fintelfpga -Xshardware")
    ELSEIF (USE_FPGA_PROFILING)
	SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fintelfpga -Xshardware -Xsprofile")
    ELSE () #Use CPU emulation by default
	message("Building for CPU host emulation")
	ADD_DEFINITIONS (-DCPU_HOST)
    ENDIF ()

    SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /opt/intel/oneapi/compiler/2022.2.1/linux/include/sycl/")
    message(${CMAKE_CXX_FLAGS})
ENDIF ()

find_program(CMAKE_CXX_COMPILER icpx)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsycl -Wall")

aux_source_directory (./ DIR_SRCS)

include_directories (

${PROJECT_SOURCE_DIR}/../include
${PROJECT_SOURCE_DIR})

# Add the executable
add_executable (orbital3D.x ${DIR_SRCS})

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin)

# Link the required libraries -lm (math) and -lsycl (SYCL)
target_link_libraries(orbital3D.x PRIVATE m sycl)
