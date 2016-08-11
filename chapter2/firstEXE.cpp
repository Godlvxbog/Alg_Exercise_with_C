#include <stdio.h>
#define pi 3.14
#include <math.h>
#include <string.h>



void add(){
	int a, b;
	scanf_s("%d%d", &a, &b);
	printf("%d", a + b);
}

void chartest(){
	char a, b, c;
	a = 'z', b = 'j', c = 117;
	double d = pi*pi;
	printf("%c%c%c   %f", a, b, c,d);
}

void charstest(){
	char str1[25] = "I am hungry",str2[25]="I feel sad";
	printf("%s,XXX,%s",str1, str2);


}

void booltest(){
	bool flag1 = true, flag2 = 0;
	int a = 12, b = 12;
	printf("%d,%d,%d", flag1, flag1, a == b);
}

void instrtest(){
	char str[20] = "nishiaiwode";
	scanf_s("zju****%s",str);
	printf(str);
}

void mathtest(){
	double in1 = -3.2,in2=4;
	printf("%.0f===%.0f======%.1f\n%f\n%f\n%f", floor(in1),ceil(in1),fabs(in1),pow(in1,in2),sqrt(in2),round(in1));
}

void iftest(){
	int n = 4;
	if (n>10){
		printf("%d", 2 * n);
	}
	else if (n>=2){
		printf("%d", (2 + n));
	}
	else{
		printf("%d",n);
	}
	
}

void continuetest(){
	int sum = 0;
	for (int i = 1; i < 20; i++){
		if (i % 2 == 1){
			continue;
		}
		sum += i;
	}
}

void dituitest(){
	int num[10];
	scanf_s("%d", &num[0]);
	for (int i = 0; i < 10; i++)//for的递归输入
	{
		num[i + 1] = num[i] * 3 + 2;

	}
	for (int i = 0; i < 10; i++)//打印标准，for+格式输出
	{
		printf("num[%d]====%d", i, num[i]);
	}
}

void maopaotest(){
	int a[10] = { 3, 1, 4, 5, 2 };//输入
	int n = 5;
	for (int i = 1; i <=n-1; i++)//i为趟数4,i从1开始
	{
		for (int j = 0; j <= n-i-1; j++)//已经有i个泡冒出，剩余应该是n-i次,j必须从第啊a[0]开始
		{
			if (a[j]>a[j+1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;

			}
		}
	}
	for (int i = 0; i <n; i++)//打印标准，for+格式输出
	{
		printf("%d", a[i]);
	}

	memset(a, 1, sizeof(a));
}

void getchartest(){
	char a[10][10];
	for ( int i = 0; i < 3; i++)
	{
		gets_s(a[i]);
		
	}
	for (int i = 0; i < 3; i++)
	{
		puts(a[i]);
		int n = strlen(a[i]);
		printf("%d", n);
	}


}

int main(){
	//add();
	//chartest();
	//charstest();


	//booltest();

	//instrtest();

	//mathtest();

	//iftest();

	//continuetest();

	//dituitest();

	//maopaotest();

	//getchartest();
	getchar();
	return 0;
	
}

