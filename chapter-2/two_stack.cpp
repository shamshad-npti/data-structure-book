#include <bits/stdc++.h>

namespace ds {
template<class T>
class two_stack {
	T *elem;
	int size;
	int l, t;
	bool has_room() {
		return l != t;
	}
public:
	two_stack(int size) :
			size(size), l(-1), t(size) {
		elem = new T[size];
	}

	void push1(T e) {
		if (!has_room()) {
			printf("No more space!!!");
			exit(0);
		}
		elem[++l] = e;
	}

	void push2(T e) {
		if (!has_room()) {
			printf("No more space!!!");
			exit(0);
		}
		elem[--t] = e;
	}

	bool empty1() {
		return l == -1;
	}

	bool empty2() {
		return t == size;
	}

	T pop1() {
		if (empty1()) {
			printf("Stack Underflow!!!");
			exit(0);
		}
		return elem[l--];
	}

	T pop2() {
		if (empty2()) {
			printf("Stack Underflow!!!");
			exit(0);
		}
		return elem[t++];
	}

	T top1() {
		if (empty1()) {
			printf("Stack Underflow!!!");
			exit(0);
		}
		return elem[l];
	}

	T top2() {
		if (empty2()) {
			printf("Stack Underflow!!!");
			exit(0);
		}
		return elem[t];
	}

	int size1() {
		return l + 1;
	}

	int size2() {
		return size - t;
	}

	int free_space() {
		return t - l - 1;
	}
};
}
