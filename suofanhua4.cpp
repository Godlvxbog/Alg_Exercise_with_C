#include<cstdio>
#include<cstring>

//PAT˵����
char word[100][100];
void suofanhua(){
	int num=0;
	while (scanf("%s",word[num])!=EOF)//��ζ��뵽����word[],word[num]����&
	{
		num++;
	}
	for (int i = num-1; i >= 0; i--)
	{
		printf("%s",word[i]);
		if(i>0){//�ַ���word[i] ֮����Ҫ����ո��ж������ǣ��������i>0 
			printf(" ");
		}
	}
}

int main(){
	suofanhua();
	return 0;
}
