#include <iostream>
#include <fstream>
#include <string>
#include "utils.hpp"
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <vector>



int main() {
    std::vector<std::vector<double>> data = readData("data.csv");

    if (data.empty()) {
        std::cerr << "Error reading data" << std::endl;
        return 1;
    }

    double S = data[0][1];
    int n = data.size(); // Change to use the size of data
    std::vector<double> w, r;
    for (size_t i = 0; i < data.size(); ++i) { // Fix the loop to iterate over all data
        w.push_back(data[i][0]);
        r.push_back(data[i][1]);
    }

    // Calculate the rate of return and the final value of the portfolio
    double rate_of_return = 0.0;
    double V = 0.0;
    for (size_t i = 0; i < n; ++i) {
        V += (1 + r[i]) * w[i] * S;
        rate_of_return += r[i] * w[i];
    }

    printResults(S, n, w, r, rate_of_return, V);

    std::cout << "Results have been written to result.txt" << std::endl;

    return 0;
}
