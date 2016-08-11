#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>

#include <iostream>

using namespace std;


//第六章 STL模板的运用
//PAT题目
const int n=40010;
const int M = 26 * 26 * 26 * 10+1;//用来存储已经hash化的数字
vector<int> Course[M];

//字符串Hash
int get_id_from_str(char name[]){
	int id = 0;
	for (int  i = 0; i < 3; i++)
	{
		id = id * 26 + (name[i] - 'A');
	}
	id = id + (name[3] - '0');
	return id;

}


void Course_student(){
	
	int n_s, k;//总人数，总课程数
	
	char name[5];//记录学生名字的数组
	scanf_s("%d %d", &n_s, &k);
	//以下是吧元素读入，并且用合适的数据结构存储起来，便于输出，到每趟的对象
	for (int i = 0; i < k; i++)//循环体是，完成一趟，一行对应于表格的一个对象
	{
		int cor, mem;//记录课程编号与，该课程的人数
		scanf_s("%d %d", &cor, &mem);
		for (int j = 0; j < mem; j++)//对于每个对象的操作
		{
			scanf_s("%s", name);
			int id = get_id_from_str(name);//元操作，得到id也是为了用Course[id].push_back(cor)
			Course[id].push_back(cor);//元操作,
		}
	}
	for (int i = 0; i < n_s; i++)//输出n趟，每趟就是循环体的操作
	{
		scanf_s("%s", name);
		int id_o = get_id_from_str(name);
		//对每一个的向量中，的课程进行排序
		sort(Course[id_o].begin(), Course[id_o].end());
		printf("%s %d ", name, Course[id_o].size());
		for (int j = 0; j < Course[id_o].size(); j++)
		{
			printf("%d", Course[id_o][j]);
		}
		printf("\n");
	}
}


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
	scanf_s("%d", &num_tang);
	for (int i = 1; i <= num_tang; i++){
		int num_ge;
		scanf_s("%d", &num_ge);
		for (int j = 0; j < num_ge; j++){
			int shuzi;
			scanf_s("%d", &shuzi);
			a[i].insert(shuzi);
		}
	}
	int sq_tang;
	scanf_s("%d", &sq_tang);
	for (int i = 1; i <= sq_tang; i++){
		int x, y;
		scanf_s("%d %d", &x, &y);
		compare(x, y);
	}
}


//第七章：数据结构基础

//定义定义结构体
const int maxn = 100010;
struct Node {
	char data;
	int next;
	bool flag = false;
}node[maxn];

void sharing(){
	int s1, s2, n;
	scanf_s("%d %d %d", &s1, &s2, &n);
	int address, next;
	char data;
	for (int i = 0; i < n; i++){
		scanf_s("%d %c %d", &address, &data, &next);
		node[address].data = data;//构造的数据结构 node[p].data
		node[address].next = next;
	}
	//以上是完成了初始化工作。完成了基本操作
	int p;
	for (p = s1; p != -1; p = node[p].next)//node[p].next表示下一个数的地址
	{
		node[p].flag = 1;
	}
	for (p = s2; p != -1; p = node[p].next){
		if (node[p].flag==1){
			break;
		}
	}
	if (p != -1){
		printf("%05d", p);
	}
	else
	{
		printf("-1\n");
	}

}

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
	scanf_s("%d %d", &n, &head);
	for (int i = 0; i < n; i++){
		int addr, data, next;
		//scanf_s("%d", &addr);
		scanf_s("%d %d %d", &addr,&data, &next);		
		node2[addr].data = data;
		node2[addr].next = next;
		node2[addr].addr = addr;
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

	int q=node2[0].addr;


	printf("%d %05d\n", count, node2[0].addr);
	for (int j = 0; j < count; j++){
		if (j != count - 1){
			//打印的一定是
			printf("%05d %d %05d\n", node2[j].addr, node2[j].data, node2[j+1].next);
		}
		else{
			printf("%05d %d -1\n", node2[j].addr, node2[j].data);
		}
	}

}

//第七章练习题：数据结构基础
//栈，stack

string str[maxn];
//首先在外部声明stack与用来装出栈序列的数组
int arr[maxn];
stack<int> st;
void popSequence(){
	int m, n, k;
	scanf_s("%d %d %d",&m,&n,&k );	
	int h = 1;
	for (int i = 0; i < k; i++){
		//清空元素，防止对下一次有影响
		for (int j = 0; j < m; j++){
			if (!st.empty()){
				st.pop();
			}
		}
		//读入出栈数组的顺序，用来与栈中元素做条件判断
		for (int j = 1; j <= n; j++){
			scanf_s("%d", &arr[j]);
		}		
		int current = 1;
		bool flag = true;//判断是否合法
		for (int j = 1; j <= n; j++){
			//入栈
			if (st.size()<m){
				st.push(j);
			}
			else{
				flag = false;
				break;
			}
			//弹出=================
			while (!st.empty()&&st.top() == arr[current]){//***反复弹出，因为如果是54321这样的一次就弹出了******
				st.pop();
				current++;
			}
		}
		//最终：栈应该为空，并且是合法的==========
		
		if (st.empty()==true && flag == true){
			str[h] = "YES";
			h++;
		}else{
			str[h] = "NO";
			h++;
			//printf("No\n");
		}
	}
	for (int j = 1; j <h; j++){
		cout << str[j] << endl;
	}
}


//PAT第七章：队列，控制语句的分层剥离，每层都需要你计算出一定的参数，
//当一个对象有多个属性时候可以定义结构体，多个时候就是结构体数组



int main(){
	//Course_student();

	//set_similarity();

	//sharing();

	//linkListSort();

	//popSequence();

	return 0;
}