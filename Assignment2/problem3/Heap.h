#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
class Heap{
    private:
        int * array;
        int MaxSize, Nel;
        void adjust (int a[], int i, int n);
    public:
        Heap(int MSize);
        //Heap(const Heap &item);
        bool insert (int item);
        bool delMax(int & item);
        Heap operator+(Heap item);
		Heap operator+(int item);
		int operator[](int item);
		void operator=(Heap &item);
		Heap operator+=(const Heap &item);
		void operator+=(int item);
		friend std::ostream &operator<<(std::ostream &os, const Heap &item);
        ~Heap(){};
};
#endif
