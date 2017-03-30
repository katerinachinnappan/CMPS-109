#include "Heap.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void Heap::adjust (int a[], int i, int n)
{
    int j = 2*i, item = a[i];
    while ( j <= n )
    {
        if (j<n && (a[j] < a[j+1])) j++;
        // Compare left and right child
        // and let j be the larger child
        if ( item >= a[j] ) break;
        a[j/2] = a[j]; j*=2;
    }
    a[j/2] = item;
}
Heap::Heap(int MSize):MaxSize(MSize)
{
    array = (int *) calloc(MSize+1,sizeof(int));
    Nel = MSize;
}

bool Heap::insert (int item)
{
    int i = ++Nel;
    cout<<"Nel: "<<i<<endl;
    if ( i == MaxSize)
    {
        cout << "heap size exceeded" << endl;
        return false;
    }
    while ( (i > 1 ) && ( array[i/2] < item )) {
        array[i] = array[i/2];
        i/=2;
    }
array[i] = item;
}
bool Heap::delMax(int & item)
{
    if ( !Nel) { cout << "heap is empty" << endl ; return false; }
    item = array[1];
    array [1] = array[Nel--];
    adjust (array,1,Nel);
    cout<<"delMax()"<<endl;
    return true;
}
Heap Heap::operator+(Heap item)
{
   Heap *heap = new Heap(MaxSize + item.MaxSize);

	int max;
	if(MaxSize > item.MaxSize)
    {
        max = MaxSize;
    }
    else
    {
        max = item.MaxSize;
    }

	for (int i = 0; i < max; ++i)
	{
		if(i < MaxSize && item.array[i] != 0)
		{
			heap->insert(array[i]);
		}

		if(i < item.MaxSize && item.array[i] != 0)
		{
			heap->insert(item.array[i]);
		}
	}
	return *heap;
}

Heap Heap::operator+(int item)
{
    Heap heap = *this;
    heap.insert(item);
    return heap;
}

int Heap::operator[](int item)
{
    return array[item];

}
void Heap::operator=(Heap &item)
{
    Nel = item.Nel;
    MaxSize = item.MaxSize;
    array = item.array;
    Heap heap = item;
    *this = heap;

}
Heap Heap::operator+=(const Heap &item)
{
    Heap heap = *this;
    heap += item;
    return heap;
}
void Heap::operator+=(int item)
{
    insert(item);
}
ostream &operator<<(std::ostream &os, const Heap &item)
{
    for (int i = 0; i < item.MaxSize; i++)
    {
        os << item.array[i] << " ";
    }
   return os;
}
int main()
{
    Heap heap(10);
    Heap heap1 = heap + 5;
	heap+=5;
	heap+=15;
	heap+=12;
	cout<<"heap1: "<<heap1<<endl;
	cout<<"heap1[3]: "<<heap1[3]<<endl;

	Heap heap2(10);
	heap2 += 15;
	cout<<"heap2: "<<heap2<<endl;

	Heap heap3 = heap1 + heap2;
	cout<<"heap3: " << heap3;
    cout<<endl;
	cout<<"heap2[1]: "<<heap2[1]<<endl;

	Heap heap4 = heap1;
	cout<<"heap4 (copy of heap1): "<<heap4<<endl;
	int x = 5;
	heap4.delMax(x);
	cout<<"delMax called: "<<heap4<<endl;

    return 0;
}

