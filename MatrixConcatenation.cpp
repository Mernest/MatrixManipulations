//Ernest Majdalani, ID: 40021641
// This program concatenates two NxN matrices to generate a Nx2N matrix

#include <iostream>
#include <array>
#include <vector>

using namespace std;

const size_t arrayColumns = 10;
const size_t arrayRows = 3;
array <int, 10> concatenate(vector<int>&v1, vector<int>&v2);
array <array<int, 10>, 3> horizontalConcatenation(vector<vector<int>>&matrix_1, vector<vector<int>>&matrix_2);


int main() {

	int n = 0;
	vector <int> v1{ 1,2,3,4,5 };
	vector <int> v2 { 6, 7, 8, 9, 10 };
	vector <vector<int>> vector1(3,vector <int>(5));
	vector <vector<int>> vector2(3,vector<int>(5));
	array<array<int, arrayColumns>,	arrayRows> finalMatrix;

	// for loop to generate some vector1 and output it
	for (size_t i{ 0 }; i < vector1.size(); ++i) {
		for (size_t j{ 0 }; j < vector1[i].size(); ++j) {
			vector1[i][j] = ++n;
			cout << vector1[i][j] << "	";
		}
		cout << endl;
	}	
	cout << endl;
	// for loop to generate some vector2 and output it
	for (size_t i{ 0 }; i < vector2.size(); ++i) {
		for (size_t j{ 0 }; j < vector2[i].size(); ++j) {
			vector2[i][j] = ++n;
			cout << vector2[i][j] << "	";
		}
		cout << endl;
	}
	cout << endl;

	finalMatrix = horizontalConcatenation(vector1, vector2); // to generate to concatenated matrix

	for (size_t i{ 0 }; i < finalMatrix.size(); ++i) {	// for loop to output the concatenated final matrix
		for (size_t j{ 0 }; j < finalMatrix[i].size(); ++j) {
			cout << finalMatrix[i][j] << "	";
		}
		cout << endl;
	}
}

// This function takes two 1-D vectors by reference and returns an array that is the concatenation of those two vectors
array <int, arrayColumns> concatenate(vector<int>&v1, vector<int>&v2) {
	
	array <int, arrayColumns>myArray;
	int *myPnt;
	myPnt = &v1.at(0); // This points to the address of the first value in the first vector
	for (size_t i{ 0 }; i < myArray.size(); ++i) {
		myArray[i] = *myPnt; // Each element of the array will equal the value at which *myPnt points to
		if (myPnt == &v1.at(v1.size() - 1)) { // if myPnt has reached the last element of the first vector
			myPnt = &v2.at(0); // myPnt will be initialized to start at the first element of the second vector
			continue; // this continue statement is used so myPnt will not be incremented as soon as the previous statement is satisfied
		}
		++myPnt; // increments the address that myPnt stores so *myPnt can point to the next value in the array
	}

	return myArray;
}

array <array<int, arrayColumns>, arrayRows> horizontalConcatenation(vector<vector<int>>&matrix_1, vector<vector<int>>&matrix_2) {

	array <array<int, arrayColumns>, arrayRows> mat_concat; 

	//for loop that sets each row of the array matrix equal to the concatenation of the rows of the vector matrices
	for (size_t i{ 0 }; i < mat_concat.size(); ++i) {
		mat_concat[i] = concatenate(matrix_1[i], matrix_2[i]);
	}

	return mat_concat;
}

