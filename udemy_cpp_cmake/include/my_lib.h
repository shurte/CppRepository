#pragma once

#include "linalg.h"

/**
 * @brief The function prints Hello World.
 * 
 */
bool print_hello_world();

/**
 * @brief The function couts Hello World.
 * 
 */
void cout_hello_world();

/**
 * @brief The function prints numbers from a vector.
 * 
 */
linalg::aliases::float3 print_linalg_vector();

/**
 * @brief The function prints the installed boost version.
 * 
 */
bool print_boost_version();

/**
 * @brief The function computes the average of two integers.
 * 
 * @param a The first number.
 * @param b The second number.
 * @return int32_t 
 */
int32_t compute_average(int32_t a, int32_t b);