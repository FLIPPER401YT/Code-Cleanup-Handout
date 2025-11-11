#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
//#include "Console.h"
#include "CodeCleanup.h"
#include <cstring>
//#include "DeveloperCleanupAnswers.h"

class Tester
{
	CodeCleanup submission;
	//DeveloperCleanupAnswers devSubmission;

	enum FailType
	{
		LOGIC,
		MEMORY
	};

	void FailTest(std::string test, FailType type, int memoryUsed);
	void PassTest(std::string test);

	template <typename T>
	void CheckTest(T input, T expected, size_t memoryUsed, size_t memoryExpected, std::string testName);
	template <typename T>
	void CheckTest(std::vector<T> input, std::vector<T> expected, size_t memoryUsed, size_t memoryExpected, std::string testName);
	void CheckTest(int* input, int* expected, int size, size_t memoryUsed, size_t memoryExpected, std::string testName);
	void CheckTest(CodeCleanup::SwapPointers input, CodeCleanup::SwapPointers expected, size_t memoryUsed, size_t memoryExpected, std::string testName);

public:
	Tester(){}
	void RunTests();
	void SumVecTests();
	void IntegerToBinaryTests();
	void CopyStringTests();
	void ConcatanateCharArrayTests();
	void RemoveElementTests();
	void InsertElementTests();
	void MultiplicationWithPtrTests();
	void PushBackTests();
	void PushFrontTests();
	void SwapTests();
	void ReversesArrayTests();
	void CompareDataTests();
	void HeapSortTests();
	void FizzBuzzTests();
	void RotateRightTests();
	void RotateLeftTests();
	void NumberOfWordsInTextTests();
};

