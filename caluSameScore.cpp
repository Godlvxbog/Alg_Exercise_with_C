
#include <stdio.h>
#include <cstring>
//ͳ��ͬ�ɼ����������ɼ���Ϊkey HashTable[]�������ݵĴ洢����
const int maxn=110; //��������С��100 
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
		printf("%d", HashTable[Tscore[i]]);//�ո��ʽ�������
		if (i<k-1){
			printf(" ");
		}
	}
}

int main(){
	caluSameScore();
	return 0;
}
