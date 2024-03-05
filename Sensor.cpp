#include <iostream>
#include <chrono> //? Måske vivado ikke håndtere dette. 
#include "Sensor.h"
#include "RandomGenerator.h"

Sensor::Sensor() {}

//! Function for sensor 1 and 2
int Sensor::Sensors() {
    int S_1 = numberGenerator(6);
    int S_2 = numberGenerator(6);

    return S_1 + S_2;
}

//! Function for camera
void Sensor::Camera(int matrix[9][9]) {
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            matrix[i][j] = numberGenerator(10); // Generate random number between 0 and 9
        }
    }
}

//! Function for generating numbers 
int Sensor::numberGenerator(int N) {
    // Generate a random num between 0 and N
    RandomInt dataNumber;
    int data = dataNumber.next() % N;

    return data;
} 