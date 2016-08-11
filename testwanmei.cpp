
#include <cstdio>
#include <math.h>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=100000; 
//PAT完美数列
void testwanmeiB1031(){
	int wanmeinum[maxn] = { 0 }, count[maxn] = {0};
	int n, p;
	scanf("%d %d", &n, &p);
	for (int k = 0; k < n; k++)
	{
		scanf("%d", &wanmeinum[k]);
	}	
	sort(wanmeinum,wanmeinum+n);	
	int m;
	for (int i = 0; i < n; i++){
		int j = i; 
		m = i + 1;
		int temp = wanmeinum[i];
		while (wanmeinum[j]<=p*temp&&j<n)
		{
			j++;
			count[m]++;
		}
		if (count[m]<count[m-1]){
			count[m] = count[m - 1];			
		}
	}
	printf("%d", count[m]);

}

int main(){
	testwanmeiB1031();
	return 0;
	
}

