// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function to input a matrix
void inputMatrix(int grid[10][10], int rowCount, int colCount) {
  for (int r = 0; r < rowCount; r++) {
      for (int c = 0; c < colCount; c++) {
          cout << "Enter element [" << r << "][" << c << "]: ";
          cin >> grid[r][c];
      }
  }
}

// Function to display a matrix
void showMatrix(int grid[10][10], int rowCount, int colCount) {
  for (int r = 0; r < rowCount; r++) {
      for (int c = 0; c < colCount; c++) {
          cout << setw(5) << grid[r][c];
      }
      cout << endl;
  }
}

// Function to transpose a matrix
void transposeMatrix(int source[10][10], int rowCount, int colCount) {
  int flipped[10][10];

  for (int r = 0; r < rowCount; r++) {
      for (int c = 0; c < colCount; c++) {
          flipped[c][r] = source[r][c];
      }
  }

  cout << "\nTransposed Matrix:\n";
  showMatrix(flipped, colCount, rowCount);
}

// Function to add two matrices
void addMatrices(int first[10][10], int second[10][10], int rowCount, int colCount) {
  int total[10][10];

  for (int r = 0; r < rowCount; r++) {
      for (int c = 0; c < colCount; c++) {
          total[r][c] = first[r][c] + second[r][c];
      }
  }

  cout << "\nSum of the Matrices:\n";
  showMatrix(total, rowCount, colCount);
}

// Function to multiply two matrices
void multiplyMatrices(int left[10][10], int right[10][10], int rowsA, int colsA, int colsB) {
  int answer[10][10];

  for (int r = 0; r < rowsA; r++) {
      for (int c = 0; c < colsB; c++) {
          answer[r][c] = 0;

          for (int k = 0; k < colsA; k++) {
              answer[r][c] += left[r][k] * right[k][c];
          }
      }
  }

  cout << "\nProduct of the Matrices:\n";
  showMatrix(answer, rowsA, colsB);
}

int main() {

  // ---------------- PART A ----------------
  int matrix1[10][10];
  int rows, cols;

  cout << "PART A - Transpose Matrix\n";
  cout << "Enter number of rows: ";
  cin >> rows;
  cout << "Enter number of columns: ";
  cin >> cols;

  inputMatrix(matrix1, rows, cols);

  cout << "\nOriginal Matrix:\n";
  showMatrix(matrix1, rows, cols);

  transposeMatrix(matrix1, rows, cols);

  // ---------------- PART B ----------------
  int matrix2[10][10];
  int matrix3[10][10];

  cout << "\nPART B - Add Two Matrices\n";
  cout << "Enter number of rows: ";
  cin >> rows;
  cout << "Enter number of columns: ";
  cin >> cols;

  cout << "\nEnter First Matrix\n";
  inputMatrix(matrix2, rows, cols);

  cout << "\nEnter Second Matrix\n";
  inputMatrix(matrix3, rows, cols);

  addMatrices(matrix2, matrix3, rows, cols);

  // ---------------- PART C ----------------
  int firstMatrix[10][10];
  int secondMatrix[10][10];
  int rowA, colA, rowB, colB;

  cout << "\nPART C - Multiply Two Matrices\n";

  cout << "Enter rows of Matrix A: ";
  cin >> rowA;
  cout << "Enter columns of Matrix A: ";
  cin >> colA;

  cout << "\nEnter Matrix A\n";
  inputMatrix(firstMatrix, rowA, colA);

  cout << "\nEnter rows of Matrix B: ";
  cin >> rowB;
  cout << "Enter columns of Matrix B: ";
  cin >> colB;

  if (colA != rowB) {
      cout << "\nMatrix multiplication cannot be performed." << endl;
      return 0;
  }

  cout << "\nEnter Matrix B\n";
  inputMatrix(secondMatrix, rowB, colB);

  multiplyMatrices(firstMatrix, secondMatrix, rowA, colA, colB);

  return 0;
}