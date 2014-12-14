#include <bits/stdc++.h>
using namespace std;
#define alloc(a, n, p) a = new int*[n]; for(int i = 0; i < n; i++) a[i] = new int[p];
#define rep(i, _b, n) for(i = _b;i<n;i++)
namespace triangular {
/**
 * Program to store two lower (n x n) triangular matrix in a single n x (n + 1) matrix
 */
class compact {
	int **p;
public:
	compact(const int n, int **a, int **b) {
		int i, j;
		alloc(p, n, n + 1);
		rep(i, 0, n)
			rep(j, 0, i + 1)
			{
				p[i][j] = a[i][j];
				p[j][i + 1] = b[i][j];
			}
	}

	int a(int i, int j) {
		return p[i][j];
	}

	int b(int i, int j) {
		return p[j][i + 1];
	}

};
}
