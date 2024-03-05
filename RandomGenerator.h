#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <iostream>

class RandomInt {
public:
    RandomInt(); //
    void seed(unsigned int seed);
    unsigned int next();

private:
    static const unsigned long a = 1234567;
    static const unsigned long c = 562378443;
    static const unsigned long m = 123654;
    unsigned long current;
    static unsigned int pseudoRandomSeed;
};

#endif // RANDOMGENERATOR_H
