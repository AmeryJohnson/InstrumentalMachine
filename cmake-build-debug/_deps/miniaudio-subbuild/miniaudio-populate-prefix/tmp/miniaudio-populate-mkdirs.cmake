# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/ameryjohnson/Downloads/project2starter/cmake-build-debug/_deps/miniaudio-src"
  "/Users/ameryjohnson/Downloads/project2starter/cmake-build-debug/_deps/miniaudio-build"
  "/Users/ameryjohnson/Downloads/project2starter/cmake-build-debug/_deps/miniaudio-subbuild/miniaudio-populate-prefix"
  "/Users/ameryjohnson/Downloads/project2starter/cmake-build-debug/_deps/miniaudio-subbuild/miniaudio-populate-prefix/tmp"
  "/Users/ameryjohnson/Downloads/project2starter/cmake-build-debug/_deps/miniaudio-subbuild/miniaudio-populate-prefix/src/miniaudio-populate-stamp"
  "/Users/ameryjohnson/Downloads/project2starter/cmake-build-debug/_deps/miniaudio-subbuild/miniaudio-populate-prefix/src"
  "/Users/ameryjohnson/Downloads/project2starter/cmake-build-debug/_deps/miniaudio-subbuild/miniaudio-populate-prefix/src/miniaudio-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/ameryjohnson/Downloads/project2starter/cmake-build-debug/_deps/miniaudio-subbuild/miniaudio-populate-prefix/src/miniaudio-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/ameryjohnson/Downloads/project2starter/cmake-build-debug/_deps/miniaudio-subbuild/miniaudio-populate-prefix/src/miniaudio-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
