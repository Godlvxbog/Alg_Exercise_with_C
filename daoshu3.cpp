#include <cstdio> 

//求导数
void qiudao(){
	int a[1010]={0},k,e,count=0;
	while (scanf("%d %d",&k,&e)!=EOF){
		a[e] = k;
	}
	
	a[0] =0;

	for (int i = 1; i <= 1000; i++)//从1到1000,1000包含，与后面一一对应 【1000,0】 
	{
		a[i - 1] = a[i] * i;
		a[i] = 0;
		if (a[i]!=0){
			count++;
		}
	}
	if(count==0){
		printf("0 0");
	}else{
		for (int i = 1000; i >= 0; i--){
			if (a[i] != 0){
				printf("%d &d", a[i], i);
				count--;
				if (count>0){
					printf(" ");
				}
			}		
		}
	}
	
}

int main(){
	qiudao();
	return 0;
}
