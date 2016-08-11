#include <cstdio> 
#include <cmath> 
#include <cstring> 
//count[str[i]]++,索引也是变量,统计1个位数

void tongjisuzhu(){
	char str[1010];
	gets(str);
	int len = strlen(str);//str[i]可以得到各个数字
	int count[20] = {0};
	for (int i = 0; i < len;i++){
		int bit = str[i]-'0';//索引：位  需要转化为数字，当前str[i]是char的数字
		count[bit]++;//次数
	}
	for (int j = 0; j < 10;j++){//枚举10次
		if (count[j]!=0){
			printf("%d:%d\n", j, count[j]);
		}
	}
}

int main(){
	tongjisuzhu(); 
	return 0;
}
