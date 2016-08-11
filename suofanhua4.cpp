#include<cstdio>
#include<cstring>

//PAT说反话
char word[100][100];
void suofanhua(){
	int num=0;
	while (scanf("%s",word[num])!=EOF)//多次读入到数组word[],word[num]不用&
	{
		num++;
	}
	for (int i = num-1; i >= 0; i--)
	{
		printf("%s",word[i]);
		if(i>0){//字符串word[i] 之间需要输出空格，判定条件是，不到最后即i>0 
			printf(" ");
		}
	}
}

int main(){
	suofanhua();
	return 0;
}
