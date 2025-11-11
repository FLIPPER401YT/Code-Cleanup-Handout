#include "Tester.h"
#include "MemoryHelper.h"

int main()
{
	Tester tester;
	tester.RunTests();
}

void Tester::RunTests()
{
	SumVecTests();
	IntegerToBinaryTests();
	CopyStringTests();
	ConcatanateCharArrayTests();
	RemoveElementTests();
	InsertElementTests();
	MultiplicationWithPtrTests();
	PushBackTests();
	PushFrontTests();
	SwapTests();
	ReversesArrayTests();
	CompareDataTests();
	HeapSortTests();
	FizzBuzzTests();
	RotateRightTests();
	RotateLeftTests();
	NumberOfWordsInTextTests();
}

void Tester::SumVecTests()
{
#if SUM_VEC
	Console::WriteLine("\SumVec Tests >>>>>>>>>>>>>>>>>>>>\n");
	std::ifstream readFile;
	readFile.open("SumVecTests.bin", std::ios::binary);

	if (readFile.is_open())
	{
		int numTests;
		readFile.read((char*)&numTests, sizeof(numTests));

		for (int i = 1; i <= numTests; i++)
		{
			std::string testName = "Test" + std::to_string(i);
			int size;
			readFile.read((char*)&size, sizeof(size));
			std::vector<int> testVec(size);
			readFile.read((char*)(testVec.data()), sizeof(int) * size);
			int expected;
			readFile.read((char*)&expected, sizeof(expected));
			size_t memoryExpected;
			readFile.read((char*)&memoryExpected, sizeof(memoryExpected));
			size_t startingMemory = memoryInUse;
			int input = submission.SumVec(testVec);
			size_t memoryUsed = memoryInUse - startingMemory;

			CheckTest(input, expected, memoryUsed, memoryExpected, testName);
		}
	}
	readFile.close();
#endif
}

void Tester::IntegerToBinaryTests()
{
#if INTEGER_TO_BINARY
	Console::WriteLine("\nIntegerToBinary Tests >>>>>>>>>>>>>>>>>>>>\n");

	std::ifstream readFile;
	readFile.open("IntegerToBinaryTests.bin", std::ios::binary);

	if (readFile.is_open())
	{
		int numTests;
		readFile.read((char*)&numTests, sizeof(numTests));

		for (int i = 1; i <= numTests; i++)
		{
			std::string testName = "Test" + std::to_string(i);
			int* testNum = new int[1];
			size_t memoryExpected;
			int expectedLength;
			std::string expected;

			readFile.read((char*)testNum, sizeof(int));
			readFile.read((char*)&expectedLength, sizeof(expectedLength));
			expected.resize(expectedLength);
			readFile.read((char*)&expected[0], expectedLength);
			readFile.read((char*)&memoryExpected, sizeof(memoryExpected));
			size_t startingMemory = memoryInUse;
			std::string input = submission.IntegerToBinary(testNum);
			size_t memoryUsed = memoryInUse - startingMemory;

			CheckTest(input, expected, memoryUsed, memoryExpected, testName);
			delete[] testNum;
		}
	}
	readFile.close();
#endif
}

void Tester::CopyStringTests()
{
#if COPY_STRING
	Console::WriteLine("\nCopyString Tests >>>>>>>>>>>>>>>>>>>>\n");

	std::ifstream readFile;
	readFile.open("CopyStringTests.bin", std::ios::binary);

	if (readFile.is_open())
	{
		int numTests;
		readFile.read((char*)&numTests, sizeof(numTests));

		for (int i = 1; i <= numTests; i++)
		{
			std::string testName = "Test" + std::to_string(i);
			size_t memoryExpected;
			int size;

			readFile.read((char*)&size, sizeof(size));
			char* source = new char[size + 1];
			char* expected = new char[size + 1];
			readFile.read((char*)source, size);
			source[size] = '\0';
			readFile.read(expected, size);
			expected[size] = '\0';
			readFile.read((char*)&memoryExpected, sizeof(memoryExpected));
			char* destination = new char[50];

			size_t startingMemory = memoryInUse;
			submission.CopyString((const char*)source, destination);
			size_t memoryUsed = memoryInUse - startingMemory;

			CheckTest(destination, expected, memoryUsed, memoryExpected, testName);
			delete[] source;
			delete[] expected;
		}
	}
	readFile.close();
#endif
}

void Tester::ConcatanateCharArrayTests()
{
#if CONCATONATE_CHAR_ARRAY
	Console::WriteLine("\nConcatonateCharArray Tests >>>>>>>>>>>>>>>>>>>>\n");

	std::ifstream readFile;
	readFile.open("ConcatonateCharArrayTests.bin", std::ios::binary);

	if (readFile.is_open())
	{
		int numTests;
		readFile.read((char*)&numTests, sizeof(numTests));

		for (int i = 1; i <= numTests; i++)
		{
			std::string testName = "Test" + std::to_string(i);
			size_t memoryExpected;
			std::string expected;
			int size;

			readFile.read((char*)&size, sizeof(size));

			char* catCharOne = new char[size + 1];
			char* catCharTwo = new char[size + 1];
			readFile.read(catCharOne, size);
			readFile.read(catCharTwo, size);
			catCharOne[size] = '\0';
			catCharTwo[size] = '\0';

			int expectedSize;
			readFile.read((char*)&expectedSize, sizeof(expectedSize));
			expected.resize(expectedSize);

			readFile.read((char*)&expected[0], expectedSize);
			readFile.read((char*)&memoryExpected, sizeof(memoryExpected));
			size_t startingMemory = memoryInUse;
			std::string output = submission.ConcatonateCharArray(catCharOne, catCharTwo);
			size_t memoryUsed = memoryInUse - startingMemory;

			CheckTest(output, expected, memoryUsed, memoryExpected, testName);
			delete[] catCharOne;
			delete[] catCharTwo;
		}
	}
	readFile.close();
#endif
}

void Tester::RemoveElementTests()
{
#if REMOVE_ELEMENT
	Console::WriteLine("\nRemoveElement Tests >>>>>>>>>>>>>>>>>>>>\n");

	std::ifstream readFile;
	readFile.open("RemoveElementTests.bin", std::ios::binary);

	if (readFile.is_open())
	{
		int numTests;
		readFile.read((char*)&numTests, sizeof(numTests));

		for (int i = 1; i <= numTests; i++)
		{
			std::string testName = "Test" + std::to_string(i);
			size_t memoryExpected;
			int* arr;
			int size;
			int index;
			int* expected;

			readFile.read((char*)&size, sizeof(size));
			
			arr = new int[size];
			readFile.read((char*)arr, size * sizeof(int));

			readFile.read((char*)&index, sizeof(index));

			int expectedSize;
			readFile.read((char*)&expectedSize, sizeof(expectedSize));

			expected = new int[expectedSize];
			readFile.read((char*)expected, expectedSize * sizeof(int));

			readFile.read((char*)&memoryExpected, sizeof(memoryExpected));
			size_t startingMemory = memoryInUse;
			int* output = submission.RemoveElement(arr, size, index);
			size_t memoryUsed = memoryInUse - startingMemory;

			CheckTest(output, expected, size - 1, memoryUsed, memoryExpected, testName);
			delete[] arr;
			delete[] expected;
		}
	}
	readFile.close();
#endif
}

void Tester::InsertElementTests()
{
#if INSERT_ELEMENT
	Console::WriteLine("\nInsertElement Tests >>>>>>>>>>>>>>>>>>>>\n");

	std::ifstream readFile;
	readFile.open("InsertElementTests.bin", std::ios::binary);

	if (readFile.is_open())
	{
		int numTests;
		readFile.read((char*)&numTests, sizeof(numTests));

		for (int i = 1; i <= numTests; i++)
		{
			std::string testName = "Test" + std::to_string(i);
			size_t memoryExpected = 0;
			int* arr;
			int size;
			int index;
			int value;
			int* expected;

			readFile.read((char*)&size, sizeof(size));

			arr = new int[size];
			readFile.read((char*)arr, size * sizeof(int));

			readFile.read((char*)&index, sizeof(index));
			readFile.read((char*)&value, sizeof(value));

			int expectedSize;
			readFile.read((char*)&expectedSize, sizeof(expectedSize));

			expected = new int[expectedSize];
			readFile.read((char*)expected, expectedSize * sizeof(int));

			readFile.read((char*)&memoryExpected, sizeof(memoryExpected));
			size_t startingMemory = memoryInUse;
			int* output = submission.InsertElement(arr, size, index, value);
			size_t memoryUsed = memoryInUse - startingMemory;

			CheckTest(output, expected, size + 1, memoryUsed, memoryExpected, testName);
			delete[] arr;
			delete[] expected;
		}
	}
	readFile.close();
#endif
}

void Tester::MultiplicationWithPtrTests()
{
#if MULTIPLICATION_WITH_PTR
	Console::WriteLine("\nMultiplicationWithPtr Tests >>>>>>>>>>>>>>>>>>>>\n");

	std::ifstream readFile;
	readFile.open("MultiplicationWithPtrTests.bin", std::ios::binary);

	if (readFile.is_open())
	{
		int numTests;
		readFile.read((char*)&numTests, sizeof(numTests));

		for (int i = 1; i <= numTests; i++)
		{
			std::string testName = "Test" + std::to_string(i);
			size_t memoryExpected = 0;
			int num1;
			int num2;
			int num3;
			int num4;
			int expected;

			readFile.read((char*)&num1, sizeof(num1));
			readFile.read((char*)&num2, sizeof(num2));
			readFile.read((char*)&num3, sizeof(num3));
			readFile.read((char*)&num4, sizeof(num4));
			readFile.read((char*)&expected, sizeof(expected));
			readFile.read((char*)&memoryExpected, sizeof(memoryExpected));

			size_t startingMemory = memoryInUse;
			int output = submission.MultiplicationWithPtr(num1, num2, num3, num4);
			size_t memoryUsed = memoryInUse - startingMemory;

			CheckTest(output, expected, memoryUsed, memoryExpected, testName);
		}
	}
	readFile.close();
#endif
}

void Tester::PushBackTests()
{
#if PUSH_BACK
	Console::WriteLine("\nPushBack Tests >>>>>>>>>>>>>>>>>>>>\n");

	std::ifstream readFile;
	readFile.open("PushBackTests.bin", std::ios::binary);

	if (readFile.is_open())
	{
		int numTests;
		readFile.read((char*)&numTests, sizeof(numTests));

		for (int i = 1; i <= numTests; i++)
		{
			std::string testName = "Test" + std::to_string(i);
			size_t memoryExpected;
			int* arr;
			int value;
			int* expected;
			int size;

			readFile.read((char*)&size, sizeof(size));
			arr = new int[size];
			readFile.read((char*)arr, size * sizeof(int));

			readFile.read((char*)&value, sizeof(value));

			int sizeExpected;
			readFile.read((char*)&sizeExpected, sizeof(sizeExpected));
			expected = new int[sizeExpected];
			readFile.read((char*)expected, sizeof(int) * sizeExpected);

			readFile.read((char*)&memoryExpected, sizeof(memoryExpected));

			size_t startingMemory = memoryInUse;
			int* output = submission.PushBack(arr, 3, value);
			size_t memoryUsed = memoryInUse - startingMemory;

			CheckTest(output, expected, 4, memoryUsed, memoryExpected, testName);
		}
	}
	readFile.close();
#endif
}

void Tester::PushFrontTests()
{
#if PUSH_FRONT
	Console::WriteLine("\nPushFront Tests >>>>>>>>>>>>>>>>>>>>\n");
	
	std::ifstream readFile;
	readFile.open("PushFrontTests.bin", std::ios::binary);

	if (readFile.is_open())
	{
		int numTests;
		readFile.read((char*)&numTests, sizeof(numTests));

		for (int i = 1; i <= numTests; i++)
		{
			std::string testName = "Test" + std::to_string(i);
			size_t memoryExpected;
			int* arr;
			int value;
			int* expected;
			int size;

			readFile.read((char*)&size, sizeof(size));
			arr = new int[size];
			readFile.read((char*)arr, size * sizeof(int));

			readFile.read((char*)&value, sizeof(value));

			int sizeExpected;
			readFile.read((char*)&sizeExpected, sizeof(sizeExpected));
			expected = new int[sizeExpected];
			readFile.read((char*)expected, sizeof(int) * sizeExpected);

			readFile.read((char*)&memoryExpected, sizeof(memoryExpected));

			size_t startingMemory = memoryInUse;
			int* output = submission.PushFront(arr, 3, value);
			size_t memoryUsed = memoryInUse - startingMemory;

			CheckTest(output, expected, 4, memoryUsed, memoryExpected, testName);

			delete[] arr;
			delete[] expected;
		}
	}
	readFile.close();
#endif
}

void Tester::SwapTests()
{
#if SWAP
	Console::WriteLine("\Swap Tests >>>>>>>>>>>>>>>>>>>>\n");

	std::ifstream readFile;
	readFile.open("SwapTests.bin", std::ios::binary);

	if (readFile.is_open())
	{
		int numTests;
		readFile.read((char*)&numTests, sizeof(numTests));

		for (int i = 1; i <= numTests; i++)
		{
			std::string testName = "Test" + std::to_string(i);
			size_t memoryExpected;
			int a;
			int b;
			int* ptrA = nullptr;
			int* ptrB = nullptr;
			CodeCleanup::SwapPointers expected;

			readFile.read((char*)&a, sizeof(a));
			readFile.read((char*)&b, sizeof(b));
			ptrA = &a;
			ptrB = &b;
			readFile.read((char*)&expected, sizeof(expected));
			readFile.read((char*)&memoryExpected, sizeof(memoryExpected));

			size_t startingMemory = memoryInUse;
			CodeCleanup::SwapPointers output = submission.Swap(ptrA, ptrB);
			size_t memoryUsed = memoryInUse - startingMemory;

			CheckTest(output, expected, memoryUsed, memoryExpected, testName);
		}
	}
	readFile.close();
#endif
}

void Tester::ReversesArrayTests()
{
#if REVERSE_ARRAY
	Console::WriteLine("\ReversesArray Tests >>>>>>>>>>>>>>>>>>>>\n");

	std::ifstream readFile;
	readFile.open("ReversesArrayTests.bin", std::ios::binary);

	if (readFile.is_open())
	{
		int numTests;
		readFile.read((char*)&numTests, sizeof(numTests));

		for (int i = 1; i <= numTests; i++)
		{
			std::string testName = "Test" + std::to_string(i);
			size_t memoryExpected;
			int size;
			int* arr;
			int* expected;

			readFile.read((char*)&size, sizeof(size));

			arr = new int[size];
			readFile.read((char*)arr, size * sizeof(int));
			
			expected = new int[size];
			readFile.read((char*)expected, sizeof(int) * size);

			readFile.read((char*)&memoryExpected, sizeof(memoryExpected));

			size_t startingMemory = memoryInUse;
			int* output = submission.ReversesArray(arr, size);
			size_t memoryUsed = memoryInUse - startingMemory;

			CheckTest(output, expected, size, memoryUsed, memoryExpected, testName);

			delete[] arr;
			delete[] expected;
		}
	}
	readFile.close();
#endif
}

void Tester::CompareDataTests()
{
#if COMPARE_DATA
	Console::WriteLine("\CompareData Tests >>>>>>>>>>>>>>>>>>>>\n");

	std::ifstream readFile;
	readFile.open("CompareDataTests.bin", std::ios::binary);

	if (readFile.is_open())
	{
		int numTests;
		readFile.read((char*)&numTests, sizeof(numTests));

		for (int i = 1; i <= numTests; i++)
		{
			std::string testName = "Test" + std::to_string(i);
			size_t memoryExpected;
			bool expected;

			readFile.read((char*)&expected, sizeof(expected));
			readFile.read((char*)&memoryExpected, sizeof(memoryExpected));

			size_t startingMemory = memoryInUse;
			bool output = submission.CompareData();
			size_t memoryUsed = memoryInUse - startingMemory;

			CheckTest(output, expected, memoryUsed, memoryExpected, testName);
		}
	}
	readFile.close();
#endif
}

void Tester::HeapSortTests()
{
#if HEAP_SORT
	Console::WriteLine("\nHeapSort Tests >>>>>>>>>>>>>>>>>>>>\n");

	std::ifstream readFile;
	readFile.open("HeapSortTests.bin", std::ios::binary);

	if (readFile.is_open())
	{
		int numTests;
		readFile.read((char*)&numTests, sizeof(numTests));

		for (int i = 1; i <= numTests; i++)
		{
			std::string testName = "Test" + std::to_string(i);
			size_t memoryExpected;
			std::vector<int> vec;
			std::vector<int> expected;
			int size;

			readFile.read((char*)&size, sizeof(size));

			vec.resize(size);
			expected.resize(size);
			readFile.read((char*)vec.data(), sizeof(int) * size);
			readFile.read((char*)expected.data(), sizeof(int) * size);

			readFile.read((char*)&memoryExpected, sizeof(memoryExpected));

			size_t startingMemory = memoryInUse;
			std::vector<int> output = submission.HeapSort(expected);
			size_t memoryUsed = memoryInUse - startingMemory;

			CheckTest(output, expected, memoryUsed, memoryExpected, testName);
		}
	}
	readFile.close();
#endif
}

void Tester::FizzBuzzTests()
{
#if FizzBuzz
	Console::WriteLine("\nFizzBuzz Tests >>>>>>>>>>>>>>>>>>>>\n");

	std::ifstream readFile;
	readFile.open("FizzBuzzTests.bin", std::ios::binary);

	if (readFile.is_open())
	{
		int numTests;
		readFile.read((char*)&numTests, sizeof(numTests));

		for (int i = 1; i <= numTests; i++)
		{
			std::string testName = "Test" + std::to_string(i);
			size_t memoryExpected = 0;
			std::vector<std::string> expected;
			int size;

			readFile.read((char*)&size, sizeof(size));
			
			for (int i = 0; i < size; i++)
			{
				int length;
				readFile.read((char*)&length, sizeof(length));

				std::string str;
				str.resize(length);
				readFile.read((char*)str.data(), length);

				expected.push_back(str);
			}

			readFile.read((char*)&memoryExpected, sizeof(memoryExpected));

			size_t startingMemory = memoryInUse;
			std::vector<std::string> output = submission.MakeFizzBuzz();
			size_t memoryUsed = memoryInUse - startingMemory;

			CheckTest(output, expected, memoryUsed, memoryExpected, testName);
		}
	}
	readFile.close();
#endif
}

void Tester::RotateRightTests()
{
#if RotateRight
	Console::WriteLine("\nRotateRight Tests >>>>>>>>>>>>>>>>>>>>\n");

	std::ifstream readFile;
	readFile.open("RotateRightTests.bin", std::ios::binary);

	if (readFile.is_open())
	{
		int numTests;
		readFile.read((char*)&numTests, sizeof(numTests));

		for (int i = 1; i <= numTests; i++)
		{
			std::string testName = "Test" + std::to_string(i);
			size_t memoryExpected;
			std::vector<int> input;
			std::vector<int> expected;
			int size;

			readFile.read((char*)&size, sizeof(size));
			
			input.resize(size);
			expected.resize(size);
			readFile.read((char*)input.data(), size * sizeof(int));
			readFile.read((char*)expected.data(), size * sizeof(int));

			readFile.read((char*)&memoryExpected, sizeof(memoryExpected));

			size_t startingMemory = memoryInUse;
			std::vector<int> output = submission.MakeRotateRight(input);
			size_t memoryUsed = memoryInUse - startingMemory;

			CheckTest(output, expected, memoryUsed, memoryExpected, testName);
		}
	}
	readFile.close();
#endif
}

void Tester::RotateLeftTests()
{
#if RotateLeft
	Console::WriteLine("\nRotateLeft Tests >>>>>>>>>>>>>>>>>>>>\n");

	std::ifstream readFile;
	readFile.open("RotateLeftTests.bin", std::ios::binary);

	if (readFile.is_open())
	{
		int numTests;
		readFile.read((char*)&numTests, sizeof(numTests));

		for (int i = 1; i <= numTests; i++)
		{
			std::string testName = "Test" + std::to_string(i);
			size_t memoryExpected;
			std::vector<int> input;
			std::vector<int> expected;
			int size;
			int amount;

			readFile.read((char*)&amount, sizeof(amount));

			readFile.read((char*)&size, sizeof(size));

			input.resize(size);
			expected.resize(size);
			readFile.read((char*)input.data(), size * sizeof(int));
			readFile.read((char*)expected.data(), size * sizeof(int));

			readFile.read((char*)&memoryExpected, sizeof(memoryExpected));

			size_t startingMemory = memoryInUse;
			std::vector<int> output = submission.MakeRotateLeft(input, amount);
			size_t memoryUsed = memoryInUse - startingMemory;

			CheckTest(output, expected, memoryUsed, memoryExpected, testName);
		}
	}
	readFile.close();
#endif
}

void Tester::NumberOfWordsInTextTests()
{
#if WordsInText
	Console::WriteLine("\nNumberOfWordsInText Tests >>>>>>>>>>>>>>>>>>>>\n");

	std::ifstream readFile;
	readFile.open("NumberOfWordsInTextTests.bin", std::ios::binary);

	if (readFile.is_open())
	{
		int numTests;
		readFile.read((char*)&numTests, sizeof(numTests));

		for (int i = 1; i <= numTests; i++)
		{
			std::string testName = "Test" + std::to_string(i);
			size_t memoryExpected;
			int expected;
			std::string words;
			int size;

			readFile.read((char*)&expected, sizeof(expected));

			readFile.read((char*)&size, sizeof(size));
			words.resize(size);
			readFile.read((char*)words.data(), size);

			readFile.read((char*)&memoryExpected, sizeof(memoryExpected));

			size_t startingMemory = memoryInUse;
			int output = submission.NumberOfWordsInText(words);
			size_t memoryUsed = memoryInUse - startingMemory;

			CheckTest(output, expected, memoryUsed, memoryExpected, testName);
		}
	}
	readFile.close();
#endif
}

void Tester::CheckTest(int* input, int* expected, int size, size_t memoryUsed, size_t memoryExpected, std::string testName)
{
	for (int i = 0; i < size; i++)
	{
		if (input[i] != expected[i])
		{
			FailTest(testName, FailType::LOGIC, (int)memoryUsed);
		}
	}

	if (memoryUsed != memoryExpected)
	{
		FailTest(testName, FailType::MEMORY, (int)memoryUsed);
	}
	else
	{
		PassTest(testName);
	}
}

template <typename T>
void Tester::CheckTest(T input, T expected, size_t memoryUsed, size_t memoryExpected, std::string testName)
{
	if (input != expected)
	{
		FailTest(testName, FailType::LOGIC, (int)memoryUsed);
	}
	else if (memoryUsed != memoryExpected)
	{
		FailTest(testName, FailType::MEMORY, (int)memoryUsed);
	}
	else
	{
		PassTest(testName);
	}
}

template <typename T>
void Tester::CheckTest(std::vector<T> input, std::vector<T> expected, size_t memoryUsed, size_t memoryExpected, std::string testName)
{
	bool passed = true;
	if (input.size() != expected.size())
	{
		FailTest(testName, FailType::LOGIC, (int)memoryUsed);
	}
	else if (memoryUsed != memoryExpected)
	{
		FailTest(testName, FailType::MEMORY, (int)memoryUsed);
	}
	else
	{
		for (int i = 0; i < input.size(); i++)
		{
			if (input[i] != expected[i])
			{
				passed = false;
				FailTest(testName, FailType::LOGIC, (int)memoryUsed);
			}
		}
	}
	if (passed) PassTest(testName);
}

void Tester::CheckTest(CodeCleanup::SwapPointers input, CodeCleanup::SwapPointers expected, size_t memoryUsed, size_t memoryExpected, std::string testName)
{
	if (input.ptrA != expected.ptrA || input.ptrB != expected.ptrB)
	{
		FailTest(testName, FailType::LOGIC, (int)memoryUsed);
	}
	else if (memoryUsed != memoryExpected)
	{
		FailTest(testName, FailType::MEMORY, (int)memoryUsed);
	}
	else
	{
		PassTest(testName);
	}
}

void Tester::FailTest(std::string test, FailType type, int memoryUsed)
{
	Console::Write("\nTest " + test + ": ");
	Console::WriteLine("FAIL", (WORD)Console::ConsoleColor::Red, (WORD)Console::ConsoleColor::Black);
	switch (type)
	{
	case FailType::LOGIC:
		Console::WriteLine("LOGIC ERROR\n", (WORD)Console::ConsoleColor::Red, (WORD)Console::ConsoleColor::Black);
		break;
	case FailType::MEMORY:
		Console::WriteLine("MEMORY ERROR", (WORD)Console::ConsoleColor::Red, (WORD)Console::ConsoleColor::Black);
		Console::WriteLine("Memory Still Active From Function: " + std::to_string(memoryUsed) + " bytes\n", (WORD)Console::ConsoleColor::Red, (WORD)Console::ConsoleColor::Black);
		break;
	}
}

void Tester::PassTest(std::string test)
{
	Console::Write("\nTest " + test + ": ");
	Console::WriteLine("PASS", (WORD)Console::ConsoleColor::Green, (WORD)Console::ConsoleColor::Black);
}