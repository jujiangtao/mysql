# Copyright (c) 2012, 2016, Oracle and/or its affiliates. All rights reserved.
# 
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; version 2 of the License.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

INCLUDE(CheckCCompilerFlag)
INCLUDE(CheckCXXCompilerFlag)
INCLUDE(cmake/floating_point.cmake)

IF(SIZEOF_VOIDP EQUAL 4)
  SET(32BIT 1)
ENDIF()
IF(SIZEOF_VOIDP EQUAL 8)
  SET(64BIT 1)
ENDIF()
 
# Compiler options
IF(UNIX)  

  # Default GCC flags
  IF(CMAKE_COMPILER_IS_GNUCC)
    SET(COMMON_C_FLAGS               "-g -fno-omit-frame-pointer -fno-strict-aliasing")
    # Disable inline optimizations for valgrind testing to avoid false positives
    IF(WITH_VALGRIND)
      SET(COMMON_C_FLAGS             "-fno-inline ${COMMON_C_FLAGS}")
    ENDIF()
    # Disable optimizations that change floating point results
    IF(HAVE_C_FLOATING_POINT_OPTIMIZATION_PROBLEMS)
      SET(COMMON_C_FLAGS "${COMMON_C_FLAGS} -fno-expensive-optimizations")
    ENDIF()
    SET(CMAKE_C_FLAGS_DEBUG          "${COMMON_C_FLAGS}")
    SET(CMAKE_C_FLAGS_RELWITHDEBINFO "-O3 ${COMMON_C_FLAGS}")
  ENDIF()
  IF(CMAKE_COMPILER_IS_GNUCXX)
    SET(COMMON_CXX_FLAGS               "-g -fno-omit-frame-pointer -fno-strict-aliasing -std=c++11")
    # Disable inline optimizations for valgrind testing to avoid false positives
    IF(WITH_VALGRIND)
      SET(COMMON_CXX_FLAGS             "-fno-inline ${COMMON_CXX_FLAGS}")
    ENDIF()
    # Disable optimizations that change floating point results
    IF(HAVE_CXX_FLOATING_POINT_OPTIMIZATION_PROBLEMS)
      SET(COMMON_CXX_FLAGS "${COMMON_CXX_FLAGS} -fno-expensive-optimizations")
    ENDIF()
    SET(CMAKE_CXX_FLAGS_DEBUG          "${COMMON_CXX_FLAGS}")
    SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O3 ${COMMON_CXX_FLAGS}")
    # -std=c++11 must be set
    SET(CMAKE_CXX_FLAGS_RELEASE        "${CMAKE_CXX_FLAGS_RELEASE} -std=c++11")
  ENDIF()

  # Default Clang flags
  IF(CMAKE_C_COMPILER_ID MATCHES "Clang")
    SET(COMMON_C_FLAGS               "-g -fno-omit-frame-pointer -fno-strict-aliasing")
    SET(CMAKE_C_FLAGS_DEBUG          "${COMMON_C_FLAGS}")
    SET(CMAKE_C_FLAGS_RELWITHDEBINFO "-O3 ${COMMON_C_FLAGS}")
  ENDIF()
  IF(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    SET(COMMON_CXX_FLAGS               "-g -fno-omit-frame-pointer -fno-strict-aliasing -std=c++11")
    SET(CMAKE_CXX_FLAGS_DEBUG          "${COMMON_CXX_FLAGS}")
    SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O3 ${COMMON_CXX_FLAGS}")
    # -std=c++11 must be set
    SET(CMAKE_CXX_FLAGS_RELEASE        "${CMAKE_CXX_FLAGS_RELEASE} -std=c++11")
  ENDIF()

  # Solaris flags
  IF(CMAKE_SYSTEM_NAME MATCHES "SunOS")
    IF(CMAKE_SYSTEM_VERSION VERSION_GREATER "5.9")
      # Link mysqld with mtmalloc on Solaris 10 and later
      SET(WITH_MYSQLD_LDFLAGS "-lmtmalloc" CACHE STRING "")
    ENDIF() 
    # Possible changes to the defaults set above for gcc/linux.
    # Vectorized code dumps core in 32bit mode.
    IF(CMAKE_COMPILER_IS_GNUCC AND 32BIT)
      CHECK_C_COMPILER_FLAG("-ftree-vectorize" HAVE_C_FTREE_VECTORIZE)
      IF(HAVE_C_FTREE_VECTORIZE)
        SET(CMAKE_C_FLAGS_RELWITHDEBINFO "${CMAKE_C_FLAGS_RELWITHDEBINFO} -fno-tree-vectorize")
      ENDIF()
    ENDIF()
    IF(CMAKE_COMPILER_IS_GNUCXX AND 32BIT)
      CHECK_CXX_COMPILER_FLAG("-ftree-vectorize" HAVE_CXX_FTREE_VECTORIZE)
      IF(HAVE_CXX_FTREE_VECTORIZE)
        SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -fno-tree-vectorize")
      ENDIF()
    ENDIF()

    IF(CMAKE_C_COMPILER_ID MATCHES "SunPro")
      SET(COMMON_CXX_FLAGS                  "-std=c++11")
      # -std=c++11 must be set
      SET(CMAKE_CXX_FLAGS_RELEASE           "${CMAKE_CXX_FLAGS_RELEASE} -std=c++11")

      IF(CMAKE_SYSTEM_PROCESSOR MATCHES "i386")
        SET(COMMON_C_FLAGS                   "-g -mt -ftrap=%none -nofstore -xbuiltin=%all -xlibmil -xlibmopt -xtarget=generic")
        SET(COMMON_CXX_FLAGS                 "-g0 -mt -ftrap=%none -nofstore -xbuiltin=%all -xlibmil -xlibmopt -xtarget=generic ${COMMON_CXX_FLAGS}")
        # We have to specify "-xO1" for DEBUG flags here,
        # see http://bugs.sun.com/bugdatabase/view_bug.do?bug_id=6879978
        SET(CMAKE_C_FLAGS_DEBUG              "-xO1 ${COMMON_C_FLAGS}")
        SET(CMAKE_CXX_FLAGS_DEBUG            "-xO1 ${COMMON_CXX_FLAGS}")
        IF(32BIT)
          SET(CMAKE_C_FLAGS_RELWITHDEBINFO   "-xO2 ${COMMON_C_FLAGS}")
          SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-xO2 ${COMMON_CXX_FLAGS}")
        ELSEIF(64BIT)
          SET(CMAKE_C_FLAGS_RELWITHDEBINFO   "-xO3 ${COMMON_C_FLAGS}")
          SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-xO3 ${COMMON_CXX_FLAGS}")
        ENDIF()
      ELSE() 
        # Assume !x86 is SPARC
        SET(COMMON_C_FLAGS                 "-g -xstrconst -mt")
        SET(COMMON_CXX_FLAGS               "-g0 -mt ${COMMON_CXX_FLAGS}")
        IF(32BIT)
          SET(COMMON_C_FLAGS               "${COMMON_C_FLAGS} -xarch=sparc")
          SET(COMMON_CXX_FLAGS             "${COMMON_CXX_FLAGS} -xarch=sparc")
	ENDIF()
        SET(CMAKE_C_FLAGS_DEBUG            "${COMMON_C_FLAGS}")
        SET(CMAKE_CXX_FLAGS_DEBUG          "${COMMON_CXX_FLAGS}")
        SET(CMAKE_C_FLAGS_RELWITHDEBINFO   "-xO3 ${COMMON_C_FLAGS}")
        SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-xO3 ${COMMON_CXX_FLAGS}")
      ENDIF()
    ENDIF()
  ENDIF()
ENDIF()
