#include <bits/stdc++.h>
using namespace std;
namespace ndiag {
/**
 * Storage implementation for k-diagonal matrix
 * a k-diagonal matrix is a n x n, k <= n matrix with
 * e[i][j] = 0 if |i - j| > k. Hence no more than 2 * k - 1
 * leading diagonal can have none zero element
 * storage structure->
 * a[k-1,0], a[k,1],a[k+1,2]...a[0,0],a[1,1],a[2,2]....a[n-1,n-1].....a[n-k-1,n-2],a[n-k,n-1]
 */
template<class T>
class kdiagonal {
	T *e;
	int k, n;
public:
	kdiagonal(int n, int k) :
			k(k), n(n) {
		int s = n + (k - 1) * (2 * n - k);
		e = new T[s];
	}

	int offset(int i, int j) {
		int x = k + j - i;
		if (x <= k) {
			return (x - 1) * (2 * n - 2 * k + x) / 2 + j;
		} else {
			x = j - i;
			return offset(0, 0) + x * (2 * n - x + 1) / 2 + i;
		}
	}

	T elem(int i, int j) {
		return e[offset(i, j)];
	}

	void elem(int i, int j, T v) {
		e[offset(i, j)] = v;
	}
};
}
