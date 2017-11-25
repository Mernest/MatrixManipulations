//Ernest Majdalani, ID: 40021641
//This programn rotates a matrix by 90 degrees by transposing it then swapping its elements
#include <iostream>
#include <array>
using namespace std;

//General Variables
const size_t n = 6;
array<array<int, n>, n> myArray;
array<array<int, n>, n> myMatrix(const size_t n);
void transpose(array<array<int, n>, n>&myArray);
void swap(array<array<int, n>, n>&myArray);
void printArray(array<array<int, n>, n>&myArray);

int main() {

	array<array<int, n>, n> myArray= myMatrix(n);
	cout << "Printing Matrix:" << endl;
	printArray(myArray);
	cout << endl << "Transposing Matrix: ";
	transpose(myArray);
	cout << endl;
	printArray(myArray);
	cout << endl << "Swapping elements: ";
	cout << endl;
	swap(myArray);
	printArray(myArray);
	cout << endl;

}
//Generates a matrix with increasing numbers
array<array<int, n>, n> myMatrix(const size_t n) {

	int number = 0;
	for (size_t i{ 0 }; i < myArray.size(); ++i)
	{
		for (size_t j{ 0 }; j < myArray.size(); ++j) {

			myArray[i][j] = ++number;
		}
	}
	return myArray;
}

//Transposes the matrix
void transpose(array<array<int, n>, n>&myArray) {

	array <array<int, n>, n> tempArray;
	for (size_t i{ 0 }; i < myArray.size(); ++i) {

		for (size_t j{ 0 }; j < myArray.size(); ++j) {
			tempArray[i][j] = myArray[j][i];
		
		}
	}
	myArray = tempArray;
}

//Swaps elements
void swap(array<array<int, n>, n>&myArray) {

	int temp;
	for (size_t i =0; i < myArray.size(); ++i) {

		for (size_t j{ 0 }; j<myArray.size()/2 ; ++j) {
			temp = myArray[i][j];
			myArray[i][j] = myArray[i][myArray.size() - j - 1];
			myArray[i][myArray.size() - j - 1] = temp;
		}
	}
}
//Prints array
void printArray(array<array<int, n>, n>&myArray) {

	for (size_t i{ 0 }; i < myArray.size(); ++i)
	{
		for (size_t j{ 0 }; j < myArray.size(); ++j) {

			cout << myArray[i][j] << "	";
		}
		cout << endl;
	}
}
