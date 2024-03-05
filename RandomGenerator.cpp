#include "RandomGenerator.h"

unsigned int RandomInt::pseudoRandomSeed = 0;

RandomInt::RandomInt() {
    seed(pseudoRandomSeed++); 
}

void RandomInt::seed(unsigned int seed) {
    current = seed;
}

unsigned int RandomInt::next() {
    current = (a * current + c) % m;
    return current;
}