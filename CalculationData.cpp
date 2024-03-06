#include <iostream>

int calculationData(int s, int matrix[9][9]) {
    int sum = 0;
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            int Im = (s + .84) * matrix[i][j]; // Beregner I_m(i, j) for det aktuelle element
            sum += Im; // Tilføjer I_m(i, j) til den samlede sum
        }
    }
    return sum;
}
