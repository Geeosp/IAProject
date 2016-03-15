#include "GeeoHeap.h"
#include <iostream>
#include <math.h>
using namespace std;
//template <class T>
//GeeoHeap<T>::GeeoHeap()
GeeoHeap::GeeoHeap()

{
	capacity = 16;
	heap = new GeeoHeapNode*[capacity];
	memset(heap, (int)nullptr, sizeof(heap));
	used = 0;
		
}



//template <class T>
//GeeoHeap<T>::~GeeoHeap()
GeeoHeap::~GeeoHeap()
{
	delete[] heap;
}

void GeeoHeap::clear(){
	delete[] heap;
	heap = new GeeoHeapNode*[startCapacity];
}

bool GeeoHeap::isFull(){
	return used == capacity;
}

void GeeoHeap::add(GeeoHeapNode* node){
	if (isFull()){
		GeeoHeapNode** tmp = heap;
		const int lastCapacity = capacity;
		capacity *= 4 * capacity;
		heap = new GeeoHeapNode*[capacity];
		memcpy(heap, tmp, sizeof(GeeoHeapNode*)*lastCapacity);
		delete[] tmp;
	}
	heap[used] = node;
	fixUp(used);
	used++;

}
void GeeoHeap::fixUp(const int index){
	if (index != 0){
		const int fatherIndex = (const int)(floor(index - 1) / 2);
		if (isBetterThan(index, fatherIndex)){//if the child is better than the father
			swap(fatherIndex, index);//swap them both
			fixUp(fatherIndex);//and make the same process to the new position
		}
	}
}




GeeoHeapNode* GeeoHeap::pop(){
	GeeoHeapNode* root = heap[0];
	if (!isEmpty()){//is not empty;
		used--;
		heap[0] = heap[used];
		heap[used] = nullptr;
		fixDown(0);
	}
	return root;
}

void GeeoHeap::fixDown(const int index){
	//if index ==0
	const int left = index * 2 + 1;
	int better = index;
	const int right = left + 1;
	if (left < used){
		if (isBetterThan(left, better)){
			better = left;

		}
		if (right < used){
			if (isBetterThan(right, better)){
				better = right;
			}
		}
		if (better != index){
			swap(index, better);
			fixDown(better);
		}
	}

}
bool GeeoHeap::isEmpty(){
	return used == 0;
}
void GeeoHeap::swap(const int index1, const int index2){
	GeeoHeapNode * aux = heap[index1];
	heap[index1] = heap[index2];
	heap[index2] = aux;
}
void GeeoHeap::print(){
	for (int i = 0; i < used; i++){
		cout << heap[i]->getWeight() << " ";
	}
}

bool GeeoHeap::isBetterThan(const int index1,const  int index2){
	return heap[index1]->getWeight() < heap[index2]->getWeight();
}
