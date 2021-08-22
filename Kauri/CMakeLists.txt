cmake_minimum_required(VERSION 3.19)
project(Kauri)

set(CMAKE_CXX_STANDARD 17)

add_executable(Kauri main.cpp DecodedBerObject.h Octet.h EncodedBerObject.h Constants.h Util.h OctetClasses.h)