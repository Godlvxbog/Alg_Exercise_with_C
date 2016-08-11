#include <stdio.h>
void jzchange(){
	int a, b, d,sum=0;
	scanf("%d %d %d",&a,&b,&d);
	sum = a + b;
	int ans[31];
	int n = 0;
	do{		
		ans[n] = sum%d;//接收容器
		sum /= d;
		n++;//接收容器索引增加

	} while (sum!=0);

	for (int i = n-1; i>=0; i--)
	{
		printf("%d", ans[i]);
	}
}

int main(){
	jzchange();
	return 0;
}
