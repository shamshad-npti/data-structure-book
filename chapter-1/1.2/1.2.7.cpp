#include <bits/stdc++.h>
using namespace std;
namespace offset {
#define SIZE 4
int listoff(int sub[], int range[], int size) {
	if (size == 0 || sub[0] >= range[0])
		return -1;
	int off = sub[0];
	for (int i = 1; i < size; i++)
		if (sub[i] < range[i])
			off = off * range[i] + sub[i];
		else
			return -1; // out of range
	return off * SIZE;
}
}
