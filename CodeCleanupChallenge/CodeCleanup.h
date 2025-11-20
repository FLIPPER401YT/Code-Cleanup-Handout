#pragma once

#define INTEGER_TO_BINARY 0
#define COPY_STRING 0
#define CONCATONATE_CHAR_ARRAY 0
#define REMOVE_ELEMENT 0
#define INSERT_ELEMENT 0
#define ADD_WITH_PTR 0
#define SUBTRACT_WITH_PTR 0
#define MULTIPLICATION_WITH_PTR 0
#define PUSH_BACK 0
#define PUSH_FRONT 0
#define SUM_VEC 0
#define SWAP 0
#define REVERSE_ARRAY 0
#define COMPARE_DATA 0
#define HEAP_SORT 0
#define FizzBuzz 0
#define RotateRight 0
#define RotateLeft 0
#define WordsInText 0

#include <fstream>
#include <vector>
#include <cstring>
#include "Console.h"


class CodeCleanup
{
public:
	struct SwapPointers
	{
		int* ptrA;
		int* ptrB;

		SwapPointers(int* a, int* b)
		{
			ptrA = a;
			ptrB = b;
		}

		SwapPointers()
		{
			ptrA = nullptr;
			ptrB = nullptr;
		}
	};

	CodeCleanup() {}

	int SumVec(std::vector<int> vec);

	void CopyString(const char* source, char*& destination);
	
	SwapPointers Swap(int* a, int* b);

	int* ReversesArray(int* list, int size);

	//Write vector data to file
	//and compare data from file to the vector to ensure they match
	bool CompareData();
	void writeData(std::vector<std::string>& vecData);

	std::string IntegerToBinary(int* num);
	std::vector<int> HeapSort(std::vector<int> unsortedVector);
	std::string ConcatonateCharArray(char* arrOne, char* arrTwo);
	int* RemoveElement(int* arr, int size, int index);
	int* InsertElement(int* arr, int size, int index, int value);
	int MultiplicationWithPtr(int numOne, int numTwo, int numThree, int numFour);
	int* PushBack(int* arr, int size, int value);
	int* PushFront(int* arr, size_t size, int value);
	std::vector<std::string> MakeFizzBuzz();
	std::vector<int> MakeRotateRight(std::vector<int> vec);
	std::vector<int> MakeRotateLeft(std::vector<int> vec, int amount);
	int NumberOfWordsInText(std::string text);
};

