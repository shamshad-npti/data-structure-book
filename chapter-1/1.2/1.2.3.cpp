#include <bits/stdc++.h>
using namespace std;
namespace sale {
#define B 20
#define S 10
int d[B + 1][S + 1];
void solve() {
	int s, b, sf; // store, branch, sells figure
	scanf("%d%d%d", &b, &s, &sf);
	// assuming input terminate with b = 0
	while (b != 0) {
		b--;
		s--;
		d[b][s] += sf;
		d[b][S] += sf;
		d[B][s] += sf;
		d[B][S] += sf;
		scanf("%d%d%d", &b, &s, &sf);
	}
	printf("B/S");
	for (s = 1; s <= S; s++)
		printf("%8d", s);
	printf("   TOTAL\n");
	for (b = 0; b <= B; b++) {
		if (b == B)
			printf("TOT");
		else
			printf("%3d", b + 1);
		for (s = 0; s <= S; s++)
			printf("%8d", d[b][s]);
		printf("\n");
	}
}
}
