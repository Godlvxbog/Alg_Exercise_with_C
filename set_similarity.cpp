
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

//PAT   set���÷�
//����������a,b,c  �ҳ�a,bĳ�������е�������ͬ�����ֵı��ʣ���˼·��  c��������/�ü��ϵĳ���
const int N = 51;


//������  ����  ����ͬ��Ԫ��
set<int> a[N];
void compare(int x, int y){
	int totalNum = a[y].size();//��ʼʱ��ֻ��y���ϵĳ��ȣ�����в���ͬ��Ԫ�أ��ڴ˻����ϼ�1�����������������ӣ�����same����
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
