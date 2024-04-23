#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <vector>

#include <string>

std::vector<std::vector<double>> readData(const std::string& filename);

void printResults(double S, int n, const std::vector<double>& w, const std::vector<double>& r, double rate_of_return, double V);

#endif // UTILS_HPP
