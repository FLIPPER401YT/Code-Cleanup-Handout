#include <new>
#include <cstdlib>
#include "MemoryHelper.h"
#pragma warning(disable:6011)
#pragma warning(disable:28251)

size_t memoryInUse = 0;

//void* operator new[](std::size_t size)
//{
//	size_t* mem = (size_t*)malloc(size + sizeof(size) - 4);
//	mem[0] = size;
//	memoryInUse += size;
//	return (void*)(&(mem)[1]);
//}
//
//void operator delete[](void* memory) noexcept
//{
//	if (!memory) return;
//
//	size_t* mem = (size_t*)memory;
//	memoryInUse -= mem[-1];
//	void* ptr = (void*)(&mem[-1]);
//	free(ptr);
//}

void* operator new(size_t size)
{
	size_t* mem = (size_t*)malloc(size + sizeof(size_t));
	mem[0] = size;
	memoryInUse += size;
	return mem + 1;//(void*)(&mem[1]);
}

void operator delete(void* memory) noexcept
{
	if (!memory) return;

	size_t* mem = (size_t*)memory;
	memoryInUse -= mem[-1];
	void* ptr = (void*)(&mem[-1]);
	free(ptr);
}