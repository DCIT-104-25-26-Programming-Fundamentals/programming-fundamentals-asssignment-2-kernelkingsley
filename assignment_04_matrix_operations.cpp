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

void readMatrix(int matrix[10][10], int rows, int columns)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            cout << "Enter element [" << r << "][" << c << "]: ";
            cin >> matrix[r][c];
        }
    }
}

void printMatrix(int matrix[10][10], int rows, int columns)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            cout << setw(5) << matrix[r][c];
        }
        cout << endl;
    }
}

void transposeMatrix(int original[10][10], int result[10][10], int rows, int columns)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            result[c][r] = original[r][c];
        }
    }
}

void addMatrices(int matrixA[10][10], int matrixB[10][10], int result[10][10], int rows, int columns)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            result[r][c] = matrixA[r][c] + matrixB[r][c];
        }
    }
}

void multiplyMatrices(int matrixA[10][10], int matrixB[10][10], int result[10][10], int rowsA, int columnsA, int columnsB)
{
    for (int r = 0; r < rowsA; r++)
    {
        for (int c = 0; c < columnsB; c++)
        {
            int total = 0;

            for (int k = 0; k < columnsA; k++)
            {
                total = total + matrixA[r][k] * matrixB[k][c];
            }

            result[r][c] = total;
        }
    }
}

int main()
{
    int matrixA[10][10];
    int matrixB[10][10];
    int resultMatrix[10][10];


    cout << "Part A: Transpose a Matrix" << endl;

    int rowsA, columnsA;
    cout << "Enter number of rows: ";
    cin >> rowsA;
    cout << "Enter number of columns: ";
    cin >> columnsA;

    readMatrix(matrixA, rowsA, columnsA);

    cout << endl << "Original Matrix:" << endl;
    printMatrix(matrixA, rowsA, columnsA);

    transposeMatrix(matrixA, resultMatrix, rowsA, columnsA);

    cout << endl << "Transposed Matrix:" << endl;
    printMatrix(resultMatrix, columnsA, rowsA);

 
    cout << endl << "Part B: Add Two Matrices" << endl;

    int rowsB, columnsB;
    cout << "Enter number of rows: ";
    cin >> rowsB;
    cout << "Enter number of columns: ";
    cin >> columnsB;

    cout << endl << "Matrix 1:" << endl;
    readMatrix(matrixA, rowsB, columnsB);

    cout << endl << "Matrix 2:" << endl;
    readMatrix(matrixB, rowsB, columnsB);

    addMatrices(matrixA, matrixB, resultMatrix, rowsB, columnsB);

    cout << endl << "Sum Matrix:" << endl;
    printMatrix(resultMatrix, rowsB, columnsB);


    cout << endl << "Part C: Multiply Two Matrices" << endl;

    int rowsC1, columnsC1, rowsC2, columnsC2;

    cout << "Enter rows for Matrix A: ";
    cin >> rowsC1;
    cout << "Enter columns for Matrix A: ";
    cin >> columnsC1;

    cout << "Enter rows for Matrix B: ";
    cin >> rowsC2;
    cout << "Enter columns for Matrix B: ";
    cin >> columnsC2;

    if (columnsC1 != rowsC2)
    {
        cout << "Error: Columns of Matrix A must equal rows of Matrix B." << endl;
        return 0;
    }

    cout << endl << "Matrix A:" << endl;
    readMatrix(matrixA, rowsC1, columnsC1);

    cout << endl << "Matrix B:" << endl;
    readMatrix(matrixB, rowsC2, columnsC2);

    multiplyMatrices(matrixA, matrixB, resultMatrix, rowsC1, columnsC1, columnsC2);

    cout << endl << "Product Matrix (A x B):" << endl;
    printMatrix(resultMatrix, rowsC1, columnsC2);

    return 0;
}