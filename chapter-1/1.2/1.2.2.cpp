#include <bits/stdc++.h>
using namespace std;
namespace lat {
#define L 90
#define N 0
#define S 1
void solve() {
	int l[2][L], c[2][L], a, b, lt;
	float ave[2][L];
	memset(l[N], 0, sizeof(int) * L);
	memset(l[S], 0, sizeof(int) * L);
	memset(c[N], 0, sizeof(int) * L);
	memset(c[S], 0, sizeof(int) * L);
	scanf("%d%d", &a, &b);
	while(a != 0) {
		lt = a < 0 ? N : S;
		a = abs(a) - 1;
		l[lt][a] += b;
		c[lt][a]++;
		scanf("%d%d", &a, &b);
	}
	float ct[2] = {0, 0};
	for(a = 0; a < 2; a++) {
		char n = a == 0 ? 'N' : 'S';
		for(b = 0; b < 90; b++) {
			printf("%4d %c: ", b + 1, n);
			if(c[a][b]) {
				ave[a][b] = 1.0 * l[a][b] / c[a][b];
				ct[a] += (c[!a][b] ? ave[a][b] : 0.0);
				printf("%0.2f\n", ave[a][b]);
			} else {
				printf("NO DATA\n");
			}
		}
	}
	ct[0] /= 90;
	ct[1] /= 90;
	if(ct[0] == ct[1]) {
		printf("Northern hemisphere is as warm as southern");
	} else {
		ct[0] = ct[0] - ct[1];
		if(ct[0] < 0) {
			printf("Southern hemisphere is warmer by %0.4f", -ct[0]);
		} else {
			printf("Northern hemisphere is warmer by %0.4f", ct[0]);
		}
	}
}
}
