#include <cstdio> 
#include <cmath> 
#include <cstring> 
#include <string>//此使用string 
using namespace std;
void idcardtest(){
	int n,sum=0,j=0;
	char str[20];//输入时不能进行初始化的
	//string s[110];
//	int m=0;
	
	 
	scanf("%d",&n);//注意传入的是c 数字是c-'0';

	int w[20] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
	char jh[15] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2' };

	bool flag = true;

	for (int i = 0; i < n; i++){//此循环所有内容就只是面对一行了
		scanf("%s", str);
		for (j = 0; j < 17; j++){
			if (str[j]<='0'&&str[j]>='9'){//求其补集，因为补集有多种，但是处理方式都一样
				flag = false;
				printf("%s\n", str);
				break;//如果中途其他闯入，则这行直接跳出循环，此时与满的不同是  j<16;
			}
			sum += w[j] * (str[j] - '0');//正确的只有一种  			
		}
		if (j < 16){
			flag = false;
			//s[m++]=str;
			printf("%s\n", str);
		}
		else if (jh[sum % 11]!=str[17]){
			flag = false;
			//s[m++]=str;
			printf("%s\n", str);
		}
	}
//	for(int k=0;k<m;k++){
//		printf("%s\n",s[k]);
//	}
	if (flag){
		printf("All passed\n");
	}
}

int main(){
	idcardtest(); 
	return 0;
}
