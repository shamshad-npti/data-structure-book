#include <bits/stdc++.h>
using namespace std;
namespace ds {
template<class _T>
class Stack {
	_T *elem;
	int c;
	int t;
	void positive(int n) {
		if (n < 0)
			throw runtime_error("Negative Size!");
	}
protected:
	void overflow(int n) {
		positive(n);
		if (t + n == c)
			throw overflow_error("Stack Overflow!");
	}
	void underflow(int n) {
		positive(n);
		if (t - n + 1 < 0)
			throw underflow_error("Stack Underflow!");
	}
public:
	Stack(int capacity) :
			c(capacity), t(-1) {
		this->elem = new _T[capacity];
	}

	Stack() {
		c = 20;
		t = -1;
		this->elem = new _T[c];
	}

	int size() {
		return t + 1;
	}

	void push(_T e) {
		overflow(1);
		elem[++t] = e;
	}

	_T pop() {
		if (empty())
			throw underflow_error("Stack Underflow!");
		return elem[t--];
	}

	_T top() {
		underflow(1);
		return elem[t];
	}

	void push(_T e[], int n) {
		overflow(n);
		for (int i = 0; i < n; i++)
			elem[++t] = e[i];
	}

	_T* pop(int n) {
		underflow(n);
		_T *e = new _T[n];
		for (int i = n - 1; i >= 0; i--)
			e[i] = elem[t--];
		return e;
	}

	_T* top(int n) {
		underflow(n);
		_T *e = new _T[n];
		int i = n - 1, k = t;
		while (i >= 0)
			e[i--] = elem[k--];
		return e;
	}

	bool empty() {
		return t < 0;
	}

	~Stack() {
		delete elem;
	}
};
}
