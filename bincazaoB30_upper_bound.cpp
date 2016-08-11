#include <stdio.h>
#include <math.h>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e5;
int nn,pp;
int a[maxn];

void bincazaoB30(){
	scanf("%d %d", &nn, &pp);
	for (int k = 0; k < nn; k++)
	{
		scanf("%d", &a[k]);
	}
	sort(a, a + nn);
	int ans = 1;
	for (int k = 0; k < nn; k++)
	{
		int j = upper_bound(a + k, a + nn, (long long)a[k] * pp)-a;//起点是a[i]，终点是p*a[i]
		ans = max(ans, j - k);

	}
	printf("%d", ans);
}

int main(){
	bincazaoB30();
	return 0;
}
