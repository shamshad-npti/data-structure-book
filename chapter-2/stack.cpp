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

template <class T>
class array_using_class {
	Stack<T> *first;
	Stack<T> *second;
	int s;
	void check_out(int i) {
		if(i < 0 || i >= s) {
			exit(0);
			printf("\n WTF, oops!");
		}
	}
public:
	array_using_class(int size) : s(size) {
		first = new Stack<T>(size);
		second = new Stack<T>(size);
		T e = NULL;
		while(size != 0) {
			first->push(e);
			size--;
		}
	}

	T get(int i) {
		check_out(i);
		int j = s - 1;
		while(j > i) {
			j--;
			second->push(first->pop());
		}
		T e = first->pop();
		while(!second->empty())
			first->push(second->pop());
		return e;
	}

	void set(int i, T v) {
		check_out(i);
		int j = s - 1;
		while(j != i) {
			second->push(first->pop());
			j--;
		}
		first->pop();
		first->push(v);
		while(!second->empty())
			first->push(second->pop());
	}
};
}
