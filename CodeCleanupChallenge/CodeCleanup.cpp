#define _CRT_SECURE_NO_WARNINGS

#include "CodeCleanup.h"

/* EDIT THE CODE BELOW THIS COMMENT */

// MEMORY

#if INTEGER_TO_BINARY
// Prints the binary value of an integer.
std::string CodeCleanup::IntegerToBinary(int* num)
{
	char* result = nullptr;

	for (int bitIndex = 0; bitIndex < 32; bitIndex++)
	{
		// memory leak here
		char* temp = new char[bitIndex + 2];
		temp[bitIndex + 1] = '\0';
		if (*num & (1 << bitIndex))
		{
			temp[0] = '1';
		}
		else
		{
			temp[0] = '0';
		}
		if (result != nullptr && strlen(result) > 0)
		{
			for (int tempIndex = 1; tempIndex < bitIndex + 1; tempIndex++)
			{
				temp[tempIndex] = result[tempIndex - 1];
			}
		}
		// memory leak here
		int length = (int)strlen(temp);
		result = new char[length + 1];
		for (int resultIndex = 0; resultIndex < length; resultIndex++)
		{
			result[resultIndex] = temp[resultIndex];
		}
		result[length] = '\0';
	}

	return result;
}
#endif

#if COPY_STRING
//Copies a string from a source to a destination
void CodeCleanup::CopyString(const char* source, char*& destination) {
	
	// add delete[] destination to clear the memeory
	
	size_t len = strlen(source) + 1;
	
	// Copy the lenght of the string from the source into
	//The destination to avoid over write

	//Use strcpy_s instead of strcpy to avoid memory over write and 
	//buffer overflow
	
	strcpy(destination, source);

}
#endif

#if CONCATONATE_CHAR_ARRAY
// Concatenates arrTwo to the end of arrOne.
std::string CodeCleanup::ConcatonateCharArray(char* arrOne, char* arrTwo)
{
	char* result = new char[1];
	result[0] = '\0';
	for (int arrIndex = 0; arrIndex < strlen(arrOne); arrIndex++)
	{
		// memory leak here
		char* temp = new char[strlen(result) + 2];
		temp[strlen(result) + 1] = '\0';
		temp[strlen(temp) - 1] = arrOne[arrIndex];
		for (int tempIndex = 0; tempIndex < strlen(result); tempIndex++)
		{
			temp[tempIndex] = result[tempIndex];
		}
		// memory leak here
		result = new char[strlen(temp) + 1];
		result[strlen(temp)] = '\0';
		for (int resultIndex = 0; resultIndex < strlen(result); resultIndex++)
		{
			result[resultIndex] = temp[resultIndex];
		}
	}
	for (int arrIndex = 0; arrIndex < strlen(arrTwo); arrIndex++)
	{
		// memory leak here
		char* temp = new char[strlen(result) + 2];
		temp[strlen(result) + 1] = '\0';
		temp[strlen(temp) - 1] = arrTwo[arrIndex];
		for (int tempIndex = 0; tempIndex < strlen(result); tempIndex++)
		{
			temp[tempIndex] = result[tempIndex];
		}
		// memory leak here
		result = new char[strlen(temp) + 1];
		result[strlen(temp)] = '\0';
		for (int resultIndex = 0; resultIndex < strlen(result); resultIndex++)
		{
			result[resultIndex] = temp[resultIndex];
		}
	}

	return result;
}
#endif

#if REMOVE_ELEMENT
// Removes the element at arr[index]
int* CodeCleanup::RemoveElement(int* arr, int size, int index)
{
	while (index < size)
	{
		int temp = arr[index];
		arr[index] = arr[index + 1];
		arr[index + 1] = temp;
		index++;
	}

	// memory leak here
	int* temp = new int[size - 1];
	for (int tempIndex = 0; tempIndex < size - 1; tempIndex++)
	{
		temp[tempIndex] = arr[tempIndex];
	}

	// memory leak here
	arr = new int[size - 1];
	for (int arrIndex = 0; arrIndex < size - 1; arrIndex++)
	{
		arr[arrIndex] = temp[arrIndex];
	}

	return arr;
}
#endif

#if INSERT_ELEMENT
// Insterts value at arr[index]
int* CodeCleanup::InsertElement(int* arr, int size, int index, int value)
{
	// memory leak here
	int* temp = new int[size];
	for (int tempIndex = 0; tempIndex < size; tempIndex++)
	{
		temp[tempIndex] = arr[tempIndex];
	}

	// memory leak here
	arr = new int[size + 1];
	if (index > size || index < 0) index = size;
	for (int arrIndex = 0; arrIndex < size; arrIndex++)
	{
		arr[arrIndex] = temp[arrIndex];
	}
	arr[size] = value;

	int curIndex = size;
	while (curIndex != index)
	{
		int temp = arr[curIndex - 1];
		arr[curIndex - 1] = arr[curIndex];
		arr[curIndex] = temp;
		curIndex--;
	}

	return arr;
}
#endif

#if MULTIPLICATION_WITH_PTR
// Returns the multiplcation of four integers.
int CodeCleanup::MultiplicationWithPtr(int numOne, int numTwo, int numThree, int numFour)
{
	int* alpha = &numOne;
	int* beta = &numTwo;
	int* gamma = &numThree;
	int* delta = &numFour;
	int multOne = *alpha * *beta;
	int* epsilon = &multOne;
	int multTwo = *epsilon * *gamma;
	int* zeta = &numFour;
	// deleted data
	delete delta;
	delta = nullptr;
	int* theta = &multTwo;
	int* kappa = &numThree;
	// deleted data
	delete gamma;
	gamma = nullptr;
	int multThree = *theta * *kappa;
	int* iota = &multThree;
	int multFour = *iota * *zeta;
	return multFour;
}
#endif

#if PUSH_BACK
// Add an array element to the end of the arr int array.
int* CodeCleanup::PushBack(int* arr, int size, int value)
{
	int* temp = new int[size];
	for (int tempIndex = 0; tempIndex < size; tempIndex++)
	{
		temp[tempIndex] = arr[tempIndex];
	}
	
	// memory leak here
	arr = new int[size + 1];
	for (int arrIndex = 0; arrIndex < size; arrIndex++)
	{
		arr[arrIndex] = temp[arrIndex];
	}
	arr[size] = value;

	// using free when used new to allocate
	free(temp);

	return arr;
}
#endif

#if PUSH_FRONT
// Add an array element to the front of the arr int array.
int* CodeCleanup::PushFront(int* arr, size_t size, int value)
{
	int* temp = (int*)malloc(size + sizeof(size_t));
	for (int tempIndex = 0; tempIndex < size; tempIndex++)
	{
		temp[tempIndex] = arr[tempIndex];
	}

	// memory leak here
	arr = new int[size + 1];
	for (int arrIndex = 1; arrIndex < size + 1; arrIndex++)
	{
		arr[arrIndex] = ((int*)temp)[arrIndex - 1];
	}
	arr[0] = value;

	// using delete when used malloc() to allocate
	delete[] temp;

	return arr;
}
#endif

// DEBUGGING

// Returns the sum of a vector.
#if SUM_VEC
int CodeCleanup::SumVec(std::vector<int> vec)
{
	// result is a vector
	std::vector<int> result = { 0 };
	for (int vecIndex = 0; vecIndex < vec.size(); vecIndex++)
	{
		// logic error with -= for sum
		result -= vec[vecIndex];
	}
	int numResult = result[0];
	return numResult;
}
#endif

#if SWAP
//PtrA should PtrB and PtrB should be PtrA
CodeCleanup::SwapPointers CodeCleanup::Swap(int* ptrA, int* ptrB)
{
	//All values hold memory addresses instead of int values
	ptrB = ptrA;
	ptrA = ptrB;

	// DO NOT EDIT THIS LINE
	return CodeCleanup::SwapPointers(ptrA, ptrB);
}
#endif

#if REVERSE_ARRAY
//User should copy the data from list into temp 
//And reorder how they code data from temp back into the list
int* CodeCleanup::ReversesArray(int* list, int size)
{

	int* temp = nullptr;
	
	for (int i = 0; i < size; i++)
	{
		temp[size - i] = list[i];
	}

	delete[] temp;

	return list;
}
#endif

#if COMPARE_DATA
//Gives the vector size. We should just hide this function in a header
void CodeCleanup::writeData(std::vector<std::string>& vecData) {
	vecData.resize(10);
	for (int i = 0; i < 10; i++)
	{
		vecData[i] = "Hello world\n";
	}

}


bool CodeCleanup::CompareData()
{
	bool state = true;
	
	int rightData = 0;
	int wrongData = 0;

	std::vector<std::string> vecData;

	//Writes data to the vector at size
	writeData(vecData);
	
	//Open the file
	std::ofstream writeFile;

	writeFile.open("vector_data.txt", std::ios::out);

	if (writeFile.is_open()) {

		//write data from a vector to file
		for (int i = 0; i < vecData.size() / 2; i++)
		{
			writeFile >> vecData[i];
		}
		writeFile.close();
	}
	
	//temp vector
	std::vector<std::string> temp;
	std::ifstream readFile;
	std::string line;

	readFile.open("vector_data.txt", std::ios::in);

	//open file before reading from it
	if (readFile.is_open()) {

		//Read data from file and push it back into the temp vector
		while (std::getline(readFile, line)) {
		
			for (int i = 0; i < vecData.size(); i++)
			{
				temp.push_back(line);
			}
		}
	}
	readFile.close();

	//Compare data
	for (int i = 0; i < vecData.size(); i++)
	{
		temp[i] == vecData[i] ? rightData++ : wrongData++;
	}

	wrongData > rightData ? state = false : state = true;

	return state;
}
#endif

// CHALLENGES

#if HEAP_SORT
/*
	This challenge is an implementation of the Heap Sort algorithm.

	Explanation of Heap Sort:

	First convert the array into a max heap using heapify, Please note that this happens in-place.
	The array elements are re-arranged to follow heap properties. Then one by one delete the root node of the Max-heap and replace it with the last node and heapify.
	Repeat this process while size of heap is greater than 1.

	Rearrange array elements so that they form a Max Heap.
	Repeat the following steps until the heap contains only one element:
	Swap the root element of the heap (which is the largest element in current heap) with the last element of the heap.
	Remove the last element of the heap (which is now in the correct position). We mainly reduce heap size and do not remove element from the actual array.
	Heapify the remaining elements of the heap.
	Finally we get sorted array.

	returns a vector of ints that is the sorted version of the input vector
*/

std::vector<int> CodeCleanup::HeapSort(std::vector<int> unsortedVector)
{
	return { 1 };
}
#endif

#if FizzBuzz
/*
	This challenge is an implementation of the FizzBuzz problem.

	Explanation:

	Put the numbers from 1 to 100 into a vector of strings.
	Replace each multiple of 3 with "Fizz", each multiple of 5 with "Buzz", and each multiple of both 3 and 5 with "FizzBuzz".
	For example, the sequence starts with 1, 2, Fizz, 4, Buzz, Fizz, 7, 8, Fizz, Buzz, 11, Fizz, 13, 14, FizzBuzz, and so on.

	Do NOT hard code the values. This problem should utilize loops to populate the vector of strings.

	Returns a vector of strings.
*/

std::vector<std::string> CodeCleanup::MakeFizzBuzz()
{
	return std::vector<std::string>({ "epic" });
}
#endif

#if RotateRight
/*
	This challenge is an implementation of the rotate array problem.

	Explanation:

	Rotate the values of the vector to the right by one position.
	The value at the end will wrap back around to the front.

	Example:
	Input: vec = { 1, 2 ,3 }
	Ouput: vec = { 3, 1, 2 }

	Returns the input vector rotated to the right by one position.
*/

std::vector<int> CodeCleanup::MakeRotateRight(std::vector<int> vec)
{
	return vec;
}
#endif

#if RotateLeft
/*
	This challenge is an implementation of the rotate array problem.

	Explanation:

	Rotate the values of the vector to the left by amount positions.
	The value at the front will wrap back around to the back.

	Example:
	Input: vec = { 1, 2 ,3 }, amount = 2
	Ouput: vec = { 3, 2, 1 }

	Returns the input vector rotated to the right by one position.
*/

std::vector<int> CodeCleanup::MakeRotateLeft(std::vector<int> vec, int amount)
{
	return vec;
}
#endif

#if WordsInText
/*
	This challenge is an implementation of the Number Of Words In A Text problem.

	Explanation:

	In the input text, find the number of words and return that as an int.

	Example:
	Input: text = "Happy Happy World"
	Output: 3

	Returns an int for the number of words
*/

int CodeCleanup::NumberOfWordsInText(std::string text)
{
	return -1;
}
#endif