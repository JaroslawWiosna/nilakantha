#
# @par Licence
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#


cmake_minimum_required(VERSION 2.8)

project( nilakantha )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_executable( 
	nilakantha
	nilakantha.cpp 
	)

set(CMAKE_CXX_STANDARD 11)
set(COMPILE_FLAGS "-Wall -Wno-missing-braces -Wno-write-strings -Wextra -Wpedantic")
set(LINK_FLAGS "")

