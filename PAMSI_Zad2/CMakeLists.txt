cmake_minimum_required(VERSION 3.17)
project(PAMSI_sortowanie)

set(CMAKE_CXX_STANDARD 17)

add_executable(PAMSI_sortowanie main.cpp sortowanie_przez_scalanie.cpp sortowanie_przez_scalanie.h sortowanie_kubelkowe.cpp sortowanie_kubelkowe.h Pakiet.cpp Pakiet.h Lista.cpp Lista.h sortowanie_szybkie.cpp sortowanie_szybkie.h)