#include "utils.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

std::vector<std::vector<double>> readData(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::vector<double>> data;

    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return data;
    }

    std::string line;
    int n = 0;
    while (std::getline(file, line)) {
        if (line.find("S;") == 0 || line.find("n;") == 0 || line.find("w;r") == 0)
            continue; // Skip the line containing "S;", "n;" or "w;r"

        std::istringstream iss(line);
        std::string token;
        std::vector<double> row;
        while (std::getline(iss, token, ';')) {
            row.push_back(std::stod(token));
        }
        data.push_back(row);
        n++;
    }

    std::cout << "Number of assets (n): " << n << std::endl; // Debug print
    std::cout << "Data: " << std::endl;
    for (const auto& row : data) {
        for (double value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    return data;
}




void printResults(double S, int n, const std::vector<double>& w, const std::vector<double>& r, double rate_of_return, double V) {
    std::ofstream resultFile("result.txt");

    if (!resultFile.is_open()) {
        std::cerr << "Error opening result file" << std::endl;
        return;
    }

    // Print results to file
    resultFile << "S = " << std::fixed << std::setprecision(2) << S << ", n = " << n << std::endl;

    resultFile << "w = [ ";
    for (double weight : w) {
        resultFile << weight << " ";
    }
    resultFile << "]" << std::endl;

    resultFile << "r = [ ";
    for (double rate : r) {
        resultFile << rate << " ";
    }
    resultFile << "]" << std::endl;

    resultFile << "Rate of return of the portfolio: " << std::fixed << std::setprecision(4) << rate_of_return << std::endl;
    resultFile << "V: " << std::fixed << std::setprecision(2) << V << std::endl;

    resultFile.close();
}
