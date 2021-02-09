#include <iostream>
#include <stdio.h>

#include "my_lib.h"
#include "linalg.h"
#include "boost/version.hpp"

bool print_hello_world()
{
    printf("Printf: Hello World\n");

    return true;
}

void cout_hello_world()
{
    std::cout << "Cout: Hello World" << std::endl;
}

linalg::aliases::float3 print_linalg_vector()
{
    linalg::aliases::float3 my_float { 1, 2, 3 };
    std::cout << my_float[0] << ", " << my_float[1] << ", " << my_float[2] << std::endl;

    return my_float;
}

bool print_boost_version()
{
    std::cout << "Boost version: " << BOOST_VERSION << std::endl;

    return true;
}

int32_t compute_average(int32_t a, int32_t b)
{
    return (a + b) / 2;
}