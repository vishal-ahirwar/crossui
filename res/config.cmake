
#Auto Generated Root CMake file by aura CLI
#None
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
option(STATIC_LINK "Enable static linking" ON)
option(ENABLE_TESTS "GTests" OFF)
if(STATIC_LINK)
  if (WIN32)
      set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
  else()
      set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
  endif()
endif()
set(COMPANY "Vishal Ahirwar")
string(TIMESTAMP CURRENT_YEAR "%Y")
set(COPYRIGHT "Copyright(c) ${CURRENT_YEAR} ${COMPANY}.")
include_directories(${CMAKE_BINARY_DIR} ${CMAKE_SOURCE_DIR})
configure_file(res/config.h.in crossuiconfig.h)
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    message(STATUS "Enabling secure coding features for Clang")
    add_compile_options(
        -Wall -Wextra -Wpedantic        # General warnings
        -Wshadow -Wold-style-cast       # Detect potential issues
        -Wcast-align -Wnull-dereference # Runtime safety
        -Wformat=2 -Wformat-security    # Secure formatting
        -fstack-protector-strong        # Stack protection
        -D_FORTIFY_SOURCE=2             # Buffer security
        -fno-common                     # Avoid common symbol issues
        #-Werror                         # Treat warnings as errors
    )
endif()
