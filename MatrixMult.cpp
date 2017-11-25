#include <iostream>
#include <vector>
using namespace std;

void matrixmult(int **matrix1, int **matrix2, int **matrix3, int rowA, int colA, int rowB, int colB);

int main() {
	int row_a, col_a;
	int row_b, col_b;
	cout << "Enter number of rows and columns for first matrix:";
	cin >> row_a >> col_a;

	cout << "Enter number of rows and columns for second matrix:";
	cin >> row_b >> col_b;

//	matrix a initialization
	int **a = new int *[row_a];
	for (int i{ 0 }; i < row_a; ++i) {
			a[i] = new int[col_a];
	}
	
	cout << "Enter values for first matrix:" << endl;
	for (int i{ 0 }; i < row_a; ++i) {
		for (int j{ 0 }; j < col_a; ++j) {
			int val;
			cin >> val;
			a[i][j] = val;
		}
	}
//  matrix b initialization
	int **b = new int *[row_b];
	for (int i{ 0 }; i < row_b; ++i) {
			b[i] = new int[col_b];
	}

	cout << "Enter values for second matrix:" << endl;
	for (int i{ 0 }; i < row_b; ++i) {
		for (int j{ 0 }; j < col_b; ++j) {
			int val;
			cin >> val;
			b[i][j] = val;
		}
	}

	int **c = new int *[row_a];
	for (int i{ 0 }; i < row_a; ++i) {
		c[i] = new int[col_b];
	}
	cout << endl;
	matrixmult(a, b, c, row_a, col_a, row_b, col_b);


	for (int i{ 0 }; i < row_a; ++i) {
		delete[] a[i];
	}
		delete[] a;

	for (int i{ 0 }; i < row_b; ++i) {
			delete[] b[i];
		}
		delete[] b;

	for (int i{ 0 }; i < row_a; ++i) {
			delete[] c[i];
		}
		delete[] c;
}

void matrixmult(int **matrix1, int **matrix2, int **matrix3, int rowA, int colA, int rowB, int colB) {
	if (rowA != colB) {
		cout << "Cannot multiply matrices because number of rows of first matrix does not match";
		cout << " the number of columns in second matrix." << endl;
		exit(0);
	}

	else {
		cout << "The new matrix is: " << endl;
		for (int i{ 0 }; i < rowA; ++i) {
			for (int j{ 0 }; j < colB; ++j) {
				matrix3[i][j] = 0;
				for (int k{ 0 }; k < colA; ++k) {
					matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
				}
				cout << matrix3[i][j] << "	";
			}
			cout << endl;
		}
	}
}