#include <bits/stdc++.h>
using namespace std;
namespace ds {
	/**
	 * Implemented for lower triangular matrix and
	 * little modification will make it to run with
	 * upper triangular matrix
	 */
	template <class _T>
	class tri_matrix {
		_T *elem;
		int n;
		bool out(int i, int j) {
			return i < 0 || j < 0 || i > n || j > i;
		}
	public:
		tri_matrix(int n): n(n){
			int s = (n + 1) * n / 2;
			elem = new _T[s];
		}

		void set(int i, int j, _T e) {
			if(!out(i, j))
				elem [i * (i + 1) / 2 + j] = e;
		}

		_T get(int i, int j) {
			if(!out(i, j))
				return elem[i * (i + 1) / 2 + j];
			return 0; // find fix
		}

	};
}
