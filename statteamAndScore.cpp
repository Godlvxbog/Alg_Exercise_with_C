#include <cstdio>
#include <cstring>

//运用Hash条件是：找出键值对。键对应的是**，值对应的是XX
//团队编程赛，统计每个队的成绩  队是键，  成绩是值
const int maxn=1010;
int hashTable3[maxn] = { 0 };
void statteamAndScore(){
	int n;
	scanf("%d", &n);
	int team, member, score;
	for (int i = 0; i < n; i++){		
		
		scanf("%d-%d %d", &team, &member, &score);
		hashTable3[team] += score;//得到的类似一个直方图的统计表
	}
	//比较直方图中最大大的一行
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
