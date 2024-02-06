#include "utils.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::vector<std::string>> readCSV(const std::string& filename) {
    std::vector<std::vector<std::string>> data;

    // Open the CSV file
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file " << filename << std::endl;
        return data;
    }

    std::string line;

    // Read data line by line
    while (std::getline(file, line)) {
        // Skip lines start with #
        if (line[0] == '#') {
            std::cout << "Skipping " << line << std::endl;
            continue;
        }

        std::stringstream ss(line);
        std::vector<std::string> row;
        std::string cell;

        // Split line into cells using comma as delimiter
        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
        }

        // Add row to data
        data.push_back(row);
    }

    // Close the file
    file.close();

    return data;
}

// int main() {
//     // Read CSV file
//     std::vector<std::vector<std::string>> csvData = readCSV("./dist/win32/bpm/bpm-data.csv");

//     // Display CSV data
//     for (const auto& row : csvData) {
//         for (const auto& cell : row) {
//             std::cout << cell << "\t";
//         }
//         std::cout << std::endl;
//     }

//     return 0;
// }