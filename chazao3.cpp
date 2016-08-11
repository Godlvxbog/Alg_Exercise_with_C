#include <stdio.h>
int n,num[210];
void chazaotest(){

	while(scanf("%d", &n)!=EOF){
	
		for (int i = 0; i < n; i++){//存入数据到数组
			scanf("%d",&num[i]);
		}

		int m,k=0;
		scanf("%d", &m);
		for (k = 0; k < n; k++){//查找=1，if，2返回
			if (m==num[k]){
				printf("%d", k);
				break;
			}
		}
	//如果没有即为 n==i
		if (k == n){
			printf("-1\n");
		}
	}
}

int main(){
	chazaotest();
	return 0;
}
