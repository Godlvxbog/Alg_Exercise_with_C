
#include <cstring>
#include <cstdio>

using namespace std;
//���嶨��ṹ��
const int maxn = 10010;
struct Node {
	char data;
	int next;
	bool flag = false;
}node[maxn];

void sharing(){
	int s1, s2, n;
	scanf("%d %d %d", &s1, &s2, &n);
	int address, next;
	char data;
	for (int i = 0; i < n; i++){
		scanf("%d %c %d", &address, &data, &next);
		node[address].data = data;//��������ݽṹ node[p].data
		node[address].next = next;
	}
	//����������˳�ʼ������������˻�������
	int p;
	for (p = s1; p != -1; p = node[p].next)//node[p].next��ʾ��һ�����ĵ�ַ
	{
		node[p].flag = true;
	}
	for (p = s2; p != -1; p = node[p].next){
		if (node[p].flag==true){
			break;
		}
	}
	if (p != -1){
		printf("%05d\n", p);
	}
	else
	{
		printf("-1\n");
	}

}

int main(){
	sharing();
	return 0;
} 
