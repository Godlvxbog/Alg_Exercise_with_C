
#include <cstdio>
#include <vector>
#include <algorithm>

#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>

#include <iostream>

using namespace std;

//PAT   set的用法
//输入多个集合a,b,c  找出a,b某两个的中的数字相同的数字的比率，，思路：  c（交集）/该集合的长度
const int N = 51;


//求两个  集合  总相同的元素
set<int> a[N];
void compare(int x, int y){
	int totalNum = a[y].size();//初始时候，只有y集合的长度，如果有不相同的元素，在此基础上加1，否则，总数不会增加，但是same增加
	int same = 0;
	for (set<int>::iterator it = a[x].begin(); it != a[x].end();it++)
	{
		if (a[y].find(*it) != a[y].end()){
			same++;
		}
		else{
			totalNum++;
		}
	}
	
	printf("%.1f%\n", (float)same * 100.0 / totalNum);
}

void set_similarity(){
	int num_tang;
	scanf("%d", &num_tang);
	for (int i = 1; i <= num_tang; i++){
		int num_ge;
		scanf("%d", &num_ge);
		for (int j = 0; j < num_ge; j++){
			int shuzi;
			scanf("%d", &shuzi);
			a[i].insert(shuzi);
		}
	}
	int sq_tang;
	scanf("%d", &sq_tang);
	for (int i = 1; i <= sq_tang; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		compare(x, y);
	}
}

int main(){
	set_similarity();
	return 0;
}
