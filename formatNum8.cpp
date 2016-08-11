#include <cstdio> 
#include <cmath>
//枚举法按照规定格式进行输出，1，得到各个位数字，并用数组存储，（a[i]=sum%10,sum/10）

//枚举法按照规定格式进行输出，1，得到各个位数字，并用数组存储，（a[i]=sum%10,sum/10）

void formatNum(){
	int n, a[10] , num = 0;
	//memset(a,0,sizeof(a));
	scanf("%d", &n);
	while (n!=0){
		a[num++] = n % 10;
		n /= 10;
	}
	for (int k= num-1; k >=0; k--){//遍历数组，上各个数字  k为位号
		if (k == 2){//百位
			for (int i = a[k]; i > 0; i--){
				printf("B");
			}
		}
		else if (k==1){//十位
			for (int i = a[k]; i>0; i--){
				printf("S");
			}
		}
		else if (k==0){
			for (int i = 1; i <= a[k]; i++)
			{
				printf("%d", i);
			}
		}
	}
}

int main(){
	formatNum(); 
	return 0;
}
