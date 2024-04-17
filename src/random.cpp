#include "random.hpp"

#include <iostream>
#include <random>

std::default_random_engine rng(time(nullptr));

int Random::rand_int(int start_inc, int stop_inc){
    return (int)(rng() % (stop_inc - start_inc + 1)) + start_inc;
}