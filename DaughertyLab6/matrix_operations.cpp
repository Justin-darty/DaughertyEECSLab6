#include <iostream>
#include <fstream>
#include <iomanip>

const int N = 3; // Size of the square matrix

// Function to read matrix data from a file
void readMatrix(int matrix[N][N], const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                file >> matrix[i][j]; // Read data from file into the matrix
        file.close();
    } else {
        std::cerr << "Unable to open file.\n"; // Display error if unable to open file
    }
}

// Function to print a matrix
void printMatrix(const int matrix[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << std::setw(4) << matrix[i][j]; // Print each element with width of 4 spaces
        }
        std::cout << '\n'; // Move to the next line after printing each row
    }
}

// Function to add two matrices
void addMatrices(const int matrix1[N][N], const int matrix2[N][N], int result[N][N]) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            result[i][j] = matrix1[i][j] + matrix2[i][j]; // Add corresponding elements of both matrices
}

// Function to multiply two matrices
void multiplyMatrices(const int matrix1[N][N], const int matrix2[N][N], int result[N][N]) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < N; ++k)
                result[i][j] += matrix1[i][k] * matrix2[k][j]; // Perform matrix multiplication
        }
}

// Function to subtract one matrix from another
void subtractMatrices(const int matrix1[N][N], const int matrix2[N][N], int result[N][N]) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            result[i][j] = matrix1[i][j] - matrix2[i][j]; // Subtract corresponding elements of both matrices
}

// Function to update an element of the matrix
void updateElement(int matrix[N][N], int row, int col, int newValue) {
    if (row >= 0 && row < N && col >= 0 && col < N)
        matrix[row][col] = newValue; // Update the specified element with the new value
    else
        std::cerr << "Invalid row or column.\n"; // Display error if row or column is out of bounds
}

// Function to get the max value of the matrix
int getMaxValue(const int matrix[N][N]) {
    int maxVal = matrix[0][0];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (matrix[i][j] > maxVal)
                maxVal = matrix[i][j]; // Find the maximum value in the matrix
    return maxVal;
}

// Function to transpose the matrix
void transposeMatrix(const int matrix[N][N], int transposed[N][N]) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            transposed[j][i] = matrix[i][j]; // Transpose the matrix
}

int main() {
    int matrix1[N][N], matrix2[N][N], result[N][N], transposed[N][N];

    // Read matrix data from file
    readMatrix(matrix1, "matrix_input.txt");
    readMatrix(matrix2, "matrix_input.txt"); // Read the same file for the second matrix

    std::cout << "Matrix 1:\n";
    printMatrix(matrix1);
    std::cout << "\nMatrix 2:\n";
    printMatrix(matrix2);

    // Add matrices
    addMatrices(matrix1, matrix2, result);
    std::cout << "\nMatrix Sum:\n";
    printMatrix(result);

    // Multiply matrices
    multiplyMatrices(matrix1, matrix2, result);
    std::cout << "\nMatrix Product:\n";
    printMatrix(result);

    // Subtract matrices
    subtractMatrices(matrix1, matrix2, result);
    std::cout << "\nMatrix Difference:\n";
    printMatrix(result);

    // Update element
    updateElement(matrix1, 1, 1, 99);
    std::cout << "\nMatrix 1 after updating element (1, 1) to 99:\n";
    printMatrix(matrix1);

    // Get max value
    std::cout << "\nMax value in Matrix 1: " << getMaxValue(matrix1) << std::endl;

    // Transpose matrix
    transposeMatrix(matrix1, transposed);
    std::cout << "\nTransposed Matrix 1:\n";
    printMatrix(transposed);

    return 0;
}
