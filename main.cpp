// Name: Ganta Venkata Kousik
// Roll No: 21pa1a0549

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"

using namespace std;
using namespace rapidjson;

// Function to decode a string in a given base to a long long integer
long long decodeBaseValue(const string& encodedValue, int base) {
    return stoll(encodedValue, nullptr, base);
}

// Function to perform Gaussian elimination on a matrix
vector<double> performGaussianElimination(vector<vector<double>> coefficientMatrix, vector<double> constantsVector) {
    int numEquations = coefficientMatrix.size();
    for (int pivot = 0; pivot < numEquations; ++pivot) {
        // Normalize the pivot row
        double pivotElement = coefficientMatrix[pivot][pivot];
        for (int col = 0; col < numEquations; ++col) {
            coefficientMatrix[pivot][col] /= pivotElement;
        }
        constantsVector[pivot] /= pivotElement;

        // Eliminate the current column in other rows
        for (int row = 0; row < numEquations; ++row) {
            if (row != pivot) {
                double factor = coefficientMatrix[row][pivot];
                for (int col = 0; col < numEquations; ++col) {
                    coefficientMatrix[row][col] -= factor * coefficientMatrix[pivot][col];
                }
                constantsVector[row] -= factor * constantsVector[pivot];
            }
        }
    }
    return constantsVector; // The constantsVector now contains the solution
}

void processTestCase(const char* filename) {
    // Open the JSON file containing the encoded polynomial data
    FILE* filePointer = fopen(filename, "r");
    if (!filePointer) {
        cerr << "Error: Unable to open " << filename << endl;
        return;
    }

    // Read and parse the JSON file
    char buffer[65536];
    FileReadStream inputStream(filePointer, buffer, sizeof(buffer));
    Document jsonDocument;
    jsonDocument.ParseStream(inputStream);
    fclose(filePointer);

    // Extract the number of points and the polynomial degree
    const Value& keyData = jsonDocument["keys"];
    int numPoints = keyData["n"].GetInt();
    int polynomialDegree = keyData["k"].GetInt();

    // Initialize the coefficient matrix and constants vector
    vector<vector<double>> coefficientMatrix(numPoints, vector<double>(polynomialDegree, 0));
    vector<double> constantsVector(numPoints, 0);

    // Populate the matrix and vector with decoded values
    for (int i = 1; i <= numPoints; ++i) {
        string index = to_string(i);
        int xValue = i;
        const Value& rootData = jsonDocument[index.c_str()];
        int base = rootData["base"].GetInt();
        string encodedValue = rootData["value"].GetString();
        long long decodedY = decodeBaseValue(encodedValue, base);
        constantsVector[i - 1] = decodedY;
        for (int j = 0; j < polynomialDegree; ++j) {
            coefficientMatrix[i - 1][j] = pow(xValue, polynomialDegree - j - 1);
        }
    }

    // Solve the system using Gaussian elimination
    vector<double> solutionVector = performGaussianElimination(coefficientMatrix, constantsVector);

    // Output the constant term, which is the last element in the solution vector
    cout << "The secret (constant term c) for " << filename << " is: " << solutionVector.back() << endl;
}

int main() {
    // Process each test case
    processTestCase("input1.json");
    processTestCase("input2.json");

    return 0;
}