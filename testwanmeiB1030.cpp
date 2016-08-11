#include <stdio.h>
#include <math.h>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const long long maxn =1e5 ;
long long wanmeinum[maxn] = { 0 };
long long count10[maxn] = {0};
long long n,p; 
//PAT完美数列
void testwanmeiB1030(){
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
			count10[m]++;
		}
		if (count10[m]<count10[m-1]){
			count10[m] = count10[m - 1];			
		}
	}
	printf("%d", count10[m]);

}


int main(){
	testwanmeiB1030();
	return 0;
}
