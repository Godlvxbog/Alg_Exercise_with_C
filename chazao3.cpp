#include <stdio.h>
int n,num[210];
void chazaotest(){

	while(scanf("%d", &n)!=EOF){
	
		for (int i = 0; i < n; i++){//�������ݵ�����
			scanf("%d",&num[i]);
		}

		int m,k=0;
		scanf("%d", &m);
		for (k = 0; k < n; k++){//����=1��if��2����
			if (m==num[k]){
				printf("%d", k);
				break;
			}
		}
	//���û�м�Ϊ n==i
		if (k == n){
			printf("-1\n");
		}
	}
}

int main(){
	chazaotest();
	return 0;
}
