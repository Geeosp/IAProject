#pragma once
#ifndef GEEO_HEAP
#define GEEO_HEAP
#include <vector>
#include <iostream>
#include <math.h>
#include "GeeoHeapNode.h"

//template <T>
using namespace std;
class GeeoHeap
{
private:
	GeeoHeapNode** heap;
	int capacity;
	int used;
	int startCapacity = 16;
	void fixUp(const int index);
	void fixDown(const int index);
	void swap(const int index1, const int index2);
	bool isFull();
	bool isBetterThan(const int index1, const int index2);
public:
	GeeoHeap();
	~GeeoHeap();
	void add( GeeoHeapNode* node );
	GeeoHeapNode* pop();
	void clear();
	bool isEmpty();
	void print();
	void getUsed();
};

#endif