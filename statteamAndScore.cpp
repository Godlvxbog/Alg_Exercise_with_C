#include <cstdio>
#include <cstring>

//����Hash�����ǣ��ҳ���ֵ�ԡ�����Ӧ����**��ֵ��Ӧ����XX
//�Ŷӱ������ͳ��ÿ���ӵĳɼ�  ���Ǽ���  �ɼ���ֵ
const int maxn=1010;
int hashTable3[maxn] = { 0 };
void statteamAndScore(){
	int n;
	scanf("%d", &n);
	int team, member, score;
	for (int i = 0; i < n; i++){		
		
		scanf("%d-%d %d", &team, &member, &score);
		hashTable3[team] += score;//�õ�������һ��ֱ��ͼ��ͳ�Ʊ�
	}
	//�Ƚ�ֱ��ͼ�������һ��
	int maxIndex = 0;
	for (int i = 0; i < maxn; i++){
		if (hashTable3[maxIndex]<hashTable3[i]){
			maxIndex = i;
		}
	}
	printf("%d %d", maxIndex, hashTable3[maxIndex]);
}

int main(){
	statteamAndScore();
	return 0;
}
