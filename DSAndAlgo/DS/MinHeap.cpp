
#include<iostream>
#include<conio.h>
#include<vector>

using namespace std;


class Heap
{
	size_t maxSize=0,curSize=0;
	int * heap;
public:
	Heap(size_t mSize ): maxSize(mSize)
	{
		heap = new int[maxSize];
	
	}
	int left(int parent)
	{
		return 2 * parent + 1;
	}
	int right(int parent)
	{
		return 2 * parent + 2;
	}
	int parent(int i)
	{
		return (i - 1) / 2;
	}
	void Heapify(int i )
	{
		int l = left(i);
		int r = right(i);

		int smallest = i;
		if (l < maxSize&& heap[l] < heap[smallest])
			smallest = l;
		if (r < maxSize && heap[r] < heap[smallest])
			smallest = r;
		if (i != smallest)
		{
			swap(i, smallest);
			Heapify(smallest);
		}

	
	}

	void swap(int l, int r)
	{
		int tmp = heap[l];
		heap[l] = heap[r];
		heap[r] = tmp;
	}

	void decrementKey(int key,int value)
	{
	
	
	}

	void add(int value)
	{
		if (curSize == maxSize)
			return;
		curSize++;
		heap[curSize-1] = value;
		int i = curSize-1;

		while (i != 0 && heap[parent(i)] > heap[i])
		{
			swap(i, parent(i));
			i = parent(i);
		}
	
	}

	int extractMin()
	{
		if (curSize == 0)
			return INT_MIN;
		if (curSize == 1)
		{
			curSize--;
			return heap[0];
		}

		int root = heap[0];
		heap[0] = heap[curSize - 1];
		curSize--;
		Heapify(0);
		return root;
	
	}




};


int main()
{

	Heap minHeap(10);
	for (int i = 0; i < 10; i++)
	{
		minHeap.add(rand() % 100);
	}
	for (size_t i = 0; i < 10; i++)
	{
		cout << minHeap.extractMin() << "  ";
	}
	_getch();
	return 0;
}
