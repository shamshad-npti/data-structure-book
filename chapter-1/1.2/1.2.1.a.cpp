#include <bits/stdc++.h>
using namespace std;
namespace mode_median {
	/**
	 * Support all numeric types
	 */
	template <typename _T> float median(_T num[], int size) {
		if(size <= 0) exit(0);
		_T *copy = new _T[size];
		for(int i = 0; i < size; i++) copy[i] = num[i];
		sort(copy, copy + size);
		if((size & 1) == 1) {
			return copy[size >> 1];
		} else {
			int k = size >> 1;
			return 0.5 * (copy[k] + copy[k - 1]);
		}
	}

	/**
	 * Assuming all the element in the list is between 0 and size - 1
	 */
	int mode_simple(int a[], int size) {
		int *b = new int[size], i;
		memset(b, 0, size * sizeof(int));
		for(i = 0; i < size; i++)
			b[a[i]]++;
		bool amb = false;
		int max = -1, maxi;
		for(i = 0; i < size; i++) {
			if(max <= b[i]) {
				if(max == b[i]) amb = true;
				else {
					max = b[i];
					maxi= i;
					amb = false;
				}
			}
		}
		return amb ? -1 : maxi;
	}

	/**
	 * Support all numeric type
	 * It can be improved so that it update mode status
	 * pointer which indicate whether there is an ambiguity
	 */
	template <typename _T> _T mode(_T num[], int size) {
		if(size <= 0) exit(0);
		_T *copy = new _T[size];
		for(int i = 0; i < size; i++) copy[i] = num[i];
		sort(copy, copy + size);
		bool amb = false;
		_T m;
		int c = 0, i = 0;
		do {
			_T mm = copy[i];
			int cc = 1;
			while(++i < size && copy[i] == mm) cc++;
			if(cc >= c) {
				if(cc == c) {
					amb = true;
				} else {
					amb = false;
					m = mm;
					c = cc;
				}
			}
		} while(i < size);
		if(amb) exit(0);
		else return m;
	}
}
