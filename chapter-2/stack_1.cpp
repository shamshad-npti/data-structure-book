#include <bits/stdc++.h>
/**
 * stack without variable top
 */
class stack_1 {
	static const int s = 2;
	int elem[s + 1];
	void check_underflow() {
		if(empty()) {
			printf("\n<Stack Underflow>");
			exit(0);
		}
	}
public:
	stack_1() {
		elem[0] = 0;
	}

	void push(int e) {
		if(elem[0] == s)
			printf("Stack Overflow");
		else
			elem[++elem[0]] = e;
	}

	bool empty() {
		return elem[0] == 0;
	}

	int pop() {
		check_underflow();
		return elem[elem[0]--];
	}

	int top() {
		check_underflow();
		return elem[elem[0]];
	}
};
