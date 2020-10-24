#include "utils.h"
#include <iostream>
#include <array>
#include <cassert>

const DEFAULT_CAPACITY = 10;

using std::cout;
using std::endl;


template <typename T>
class max_pq_heap<T>
{
	public:

		//contructors
		max_pq_heap()
		{ /*cout << "default constuctor" << endl;*/ }

		max_pq_heap(int capacity):
		arr(new std::array_<T, capacity>()), n(0)
		{}

		max_pq_heap(int capacity, comparator<T> other_comp) :
		max_pq_heap(capacity), comp(other_comp)
		{}

		max_pq_heap(comparator<T> other_comp) :
		max_pq_heap(), comp(other_comp)
		{}

		max_pq_heap(T* keys) 
		{
			int n = sizeof(keys);
			arr = new std::array_<T,n>();

			for(int i = 0; i < n; ++i) 
			{ arr[i+1] = keys[i]; }

			for(int k = n/2; k >= 1; k--) 
			{ sink(k); }
		}

		//member functions

		bool isEmpty()
		{ return arr.size() == 0; }

		int size()
		{ return arr.size(); }

		T max()
		{
			if (isEmpty())
			{
				//throw some error
			}

			return arr[1]];
		}

		void resize(int capacity)
		{
			int n = arr.size()
			assert(capacity > n);
			array<T,capacity> temp;
			for(int i = 1; i < n; ++i)
			{
				temp[i] = arr[i];
			}
			arr = temp; //calls copy constructor?
		}

		void insert(T x)
		{
			int n = arr.size();
			//check if array is full
			if(n == sizeof(arr))
			{
				resize(arr.size() * 2);
			}

			arr[n] = x;
			swim(n);
			assert(isMaxHeap());
		}

		T delMax()
		{
			int n = arr.size();

			if(isEmpty())
			{
				//throw some error
			}

			T max = arr[1];
			exch(1,--n);
			sink(1);
			arr[n+1] = NULL; //?

			if((n > 0)&&(n == (arr.size()-1)/4))
			{
				resize(arr.size() / 2)
			}
			assert(isMaxHeap());
			return max;
		}

	private:
		std::array_<T, DEFAULT_CAPACITY> arr; //use array.h or std::array
		//int n; //omit if using std::array
		comparator<T> comp;

		//member functions
		void swim(int k)
		{
			while(k > 1 && less(k/2,k))
			{
				exch(k,k/2);
				k = k/2;
			}
		}

		void sink(int k)
		{
			int n = arr.size();
			while(2*k <= n)
			{
				int j = 2*k;
				if(j < n && less(j,j+1))
				{ j++; }
				if(!less(k,j))
				{ break; }
				exch(k,j);
				k = j;
			}
		}

		bool less(int i, int j)
		{
			//add comparator later
			return arr[i] < arr[j];
		}

		void exch(int i, int j)
		{
			T swap = arr[i];
			arr[i] = arr[j];
			arr[j] = swap;
		}

		bool isMaxHeap()
		{
			int n = arr.size();

			for(int i = 1; i <= n; ++i)
			{ if(arr[i] == NULL){return false;} }

			for(int i = n+1; i < sizeof(arr); ++i)
			{ if(arr[i] != NULL){return false;} }

			if(arr[0] != NULL)
			{ return false; }

			return isMaxHeapOrdered(1);
		}

		bool isMaxHeapOrdered(int k)
		{
			int n = arr.size();
			if (k > n) return true;
        	int left = 2*k;
        	int right = 2*k + 1;
        	if (left  <= n && less(k, left))  return false;
        	if (right <= n && less(k, right)) return false;
        	return isMaxHeapOrdered(left) && isMaxHeapOrdered(right);
		}

		//i think iterator is operational

}; //end of class