#include <iostream>
using namespace std;

// Function to calculate the minor matrix by excluding a specified row and column
void GetMinor(double matrix[3][3], double minor[3][3], int row, int col, int n) {
	int minorRow = 0, minorCol;
	for (int i = 0; i < n; i++) {
		if (i != row) {
			minorCol = 0;
			for (int j = 0; j < n; j++) {
				if (j != col) {
					minor[minorRow][minorCol] = matrix[i][j];
					minorCol++;
				}
			}
			minorRow++;
		}
	}
}

// Recursive function to calculate the determinant of a matrix
double CalculateDeterminant(double matrix[3][3], int n) {
	double determinant = 0;
	if (n == 1) {
		return matrix[0][0];
	}

	if (n == 2) {
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	}

	double minor[3][3];
	for (int i = 0; i < n; i++) {
		GetMinor(matrix, minor, 0, i, n);
		determinant += (i % 2 == 0 ? 1 : -1) * matrix[0][i] * CalculateDeterminant(minor, n - 1);
	}

	return determinant;
}

// int main() {
// 	double matrix[3][3] = {
// 		{1, 0, 0},
// 		{0, 1, 1},
// 		{0, 1, 2}
// 	};

// 	cout << "Determinant: " << CalculateDeterminant(matrix, 3) << endl;
// 	return 0;
// }
