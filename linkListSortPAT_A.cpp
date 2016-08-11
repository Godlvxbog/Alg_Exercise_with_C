#include <cstdio>
#include <algorithm>
#include <cstring>


using namespace std;

using namespace std;
const int maxn=100010;
//第七章，链表的练习
//定义结构体
struct Node2{
	int addr, data, next;
	bool flag=false;
}node2[maxn];


//由于存在比较所以，需要设一个cmp函数

bool cmp(Node2 a,Node2 b){
	if (a.flag == false || b.flag == false){
		return a.flag > b.flag;
	}
	else{
		return a.data < b.data;
	}
}
void linkListSort(){
	//初始化，赋值等操作
	int n, head;
	scanf("%d %d", &n, &head);
	for (int i = 0; i < n; i++){
		int addr, data, next;
		//scanf_s("%d", &addr);
		scanf("%d %d %d", &addr,&data, &next);
		node2[addr].addr = addr;
		node2[addr].data = data;
		node2[addr].next = next;
	}

	//遍历，设置true 用于sort排序，flag是true的排在左边，并获取链表的节点的数量，以便于打印输出
	int p = head,count=0;
	while (p!=-1){
		node2[p].flag = true;
		count++;//得到这个链表的长度
		p = node2[p].next;
	}
	//排序
	sort(node2, node2 + maxn, cmp);
	
	if(count!=0){
		printf("%d %05d\n", count, node2[0].addr);
		for (int j = 0; j < count; j++){
			if (j != count - 1){
				printf("%05d %d %05d\n", node2[j].addr, node2[j].data, node2[j+1].addr);
			}
			else{
				printf("%05d %d -1\n", node2[j].addr, node2[j].data);
			}
		}
	}else{
		printf("0 -1");
	}
	

}

int main(){
	linkListSort();
	return 0;
}



