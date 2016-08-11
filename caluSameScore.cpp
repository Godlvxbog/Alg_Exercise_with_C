
#include <stdio.h>
#include <cstring>
//统计同成绩的人数。成绩作为key HashTable[]保存数据的存储次数
const int maxn=110; //分数个数小于100 
int HashTable[maxn] = {0};//
//int Tscore[10000];
void caluSameScore(){
	int n,score,m,k=0;
	scanf("%d",&n);
	for (int i = 0; i < n; i++){
		scanf("%d", &score);
		HashTable[score]++;
	}
	scanf("%d", &m);
	int Tscore[m];
	for (int j = 0; j < m; j++){		
		scanf("%d", &Tscore[k++]);
	}
	
	for (int i = 0; i < k; i++)
	{	
		printf("%d", HashTable[Tscore[i]]);//空格格式输出常用
		if (i<k-1){
			printf(" ");
		}
	}
}

int main(){
	caluSameScore();
	return 0;
}
