#include <bits/stdc++.h>
using namespace std;
namespace baseconv {
/**
 * Assuming parameter bit is a string of only 1 and 0
 */
string toternary(string bit) {
	int l = bit.length(), i;
	unsigned int b = 0;
	for (i = 0; i < l; i++)
		b = (b << 1) + (bit[i] - '0');
	string t("");
	while (b != 0) {
		t = (char) ('0' + b % 3) + t;
		b /= 3;
	}
	return t;
}

/**
 * Assuming parameter bit is a string of only 2, 1 and 0
 */
string tobinary(string ternary) {
	int l = ternary.length(), i;
	unsigned int b = 0;
	for (i = 0; i < l; i++)
		b = (b * 3) + (ternary[i] - '0');
	string t("");
	while (b != 0) {
		t = (char) ('0' + b % 2) + t;
		b /= 2;
	}
	return t;
}
}
