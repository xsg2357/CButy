cmake_minimum_required(VERSION 3.14)
project(CButy)

set(CMAKE_CXX_STANDARD 14)

add_executable(CButy main.cpp arithmetic.cpp produce_flow_if_switch.cpp produce_flow_round.cpp produce_flow_break.cpp)