
#include<cstdio>
#include<cstring>
//PAT  程序运行时间

void calctime(){
	int c1, c2,ans;
	scanf("%d %d", &c1, &c2); 
	ans = c2 - c1;
	if (ans % 100 >= 50){
		ans = ans / 100 + 1;
	}
	else{
		ans = ans / 100;//得到秒数
	}

	printf("%02d:%02d:%02d", ans / 3600, (ans % 3600) / 60, ans % 60);//注意：格式输出为两位整数 


}



int main(){
	
	calctime();
	return 0;
}
