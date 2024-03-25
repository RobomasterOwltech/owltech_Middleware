
# TODO: Investigate which is the best version for this 
cmake_minimum_required(VERSION 3.10)
# Set project name
project(middlewareOwltech)

# Set standarts
    # 
set(CMAKE_C_STANDARD 11)
    # Thisone allows for C/C++ in the same files
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# ===== ===== ===== ===== ===== =====
# = Set Cross Compiler in Linux     =
# ===== ===== ===== ===== ===== =====

# Indicate that we are cross compiling
set(CMAKE_CROSSCOMPILING True)
# Set target build platform
set(CMAKE_SYSTEM_NAME Linux)
# Set target arch 
set(CMAKE_SYSTEM_PROCESSOR arm)



# Set toolchain 
#set(CMAKE_TOOLCHAIN_FILE /opt/gcc-arm-none-eabi-10.3-2021.10/arm-none-eabi) 

# Optional 
#set(CMAKE_SYSROOT /home/devel/rasp-pi-rootfs)
#set(CMAKE_STAGING_PREFIX /home/devel/stage)

# Set C++ and C compiler
    # These lines are equivalent to cmake ... -DCMAKE_C_COMPILER='qcc;--arg1;--arg2'
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)


# Executable syntax is outputFile sourceFile.cxx
#add_executable()

