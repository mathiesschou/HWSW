#include "CalculationData.cpp"

int main() {
    int test_matrix[9][9] = {{1, 1, 1, 1, 1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 1, 1, 1, 1, 1}};
    int s = 5;
    int expected_sum = 5 * 81; // s * antal elementer i matrixen
    int calculated_sum = calculationData(s, test_matrix);

    if (calculated_sum == expected_sum) {
        std::cout << "Test Passed: " << calculated_sum << std::endl;
    } else {
        std::cout << "Test Failed: Expected " << expected_sum << ", got " << calculated_sum << std::endl;
    }

    return 0;
}