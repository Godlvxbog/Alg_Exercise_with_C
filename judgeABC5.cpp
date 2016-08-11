//PAT大数判断A+B>C吗？
#include<cstdio>
#include<cstring>

//PAT大数判断A+B>C吗？

void judgeABC(){
	int T,tcase=1;
	long long a, b, c;//考察点：大数操作可能越界
	scanf("%d", &T);
	int rz[20],j=0;
	while (T--){
		scanf("%lld%lld%lld",&a,&b,&c);
		if (a + b > c){
			rz[j++] = true;
		}
		else
		{
			rz[j++] =false;
			//printf("Case#%d:false", tcase);
		}
	}
	int i = 0;
	for (i = 0; i < j; i++)
	{
		if (rz[i]==true){
			printf("Case #%d：true\n", i+1);
		}
		else{
			printf("Case #%d：false\n", i+1);
		}
	}
}

int main(){
	
	judgeABC();
	return 0;
}
