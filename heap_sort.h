#include "utils.h"
#include "random.h"

template <typename T>
class heap_sort
{
	public:
		static void sort(T* arr, size_t n, const comparator<T>& comp=fwd_comparator<T>())
		{
			std::cout << "n: " << n << std::endl;

			for(int k = n/2; k >= 1; k--)
			{
				sink(arr, k, n, comp);
			}

			int k = n;
			while (k > 1)
			{
				exch(arr, 1, k--);
				sink(arr, 1, k, comp);
			}
		} 

	private:
		static void sink(T* arr, int k, int n, const comparator<T>& comp=fwd_comparator<T>())
		{
			while(2*k <= n)
			{
				int j = 2*k;

				if(j < n && less(arr, j, j+1, comp))
				{ j++; }
				if(!less(arr, k, j, comp))
				{ break; }

				exch(arr, k, j);
				k = j;
			}
		}

		static bool less(T* arr, int i, int j, const comparator<T>& comp=fwd_comparator<T>())
		{
			return compare(arr[i-1], arr[j-1], comp) < 0;
		}

		static void exch(T* arr, int i, int j)
		{
			exchange(arr, i-1, j-1); //size_t?
		}

		static void show(T* arr)
		{
			for(int i = 0; i < sizeof(arr) ; ++i)
			{
				std::cout << arr[i] << std::endl;
			}
		}
}; // end of Heap class