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


//������ STLģ�������
//PAT��Ŀ
const int n=40010;
const int M = 26 * 26 * 26 * 10+1;//�����洢�Ѿ�hash��������
vector<int> Course[M];

//�ַ���Hash
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
	
	int n_s, k;//���������ܿγ���
	
	char name[5];//��¼ѧ�����ֵ�����
	scanf_s("%d %d", &n_s, &k);
	//�����ǰ�Ԫ�ض��룬�����ú��ʵ����ݽṹ�洢�����������������ÿ�˵Ķ���
	for (int i = 0; i < k; i++)//ѭ�����ǣ����һ�ˣ�һ�ж�Ӧ�ڱ���һ������
	{
		int cor, mem;//��¼�γ̱���룬�ÿγ̵�����
		scanf_s("%d %d", &cor, &mem);
		for (int j = 0; j < mem; j++)//����ÿ������Ĳ���
		{
			scanf_s("%s", name);
			int id = get_id_from_str(name);//Ԫ�������õ�idҲ��Ϊ����Course[id].push_back(cor)
			Course[id].push_back(cor);//Ԫ����,
		}
	}
	for (int i = 0; i < n_s; i++)//���n�ˣ�ÿ�˾���ѭ����Ĳ���
	{
		scanf_s("%s", name);
		int id_o = get_id_from_str(name);
		//��ÿһ���������У��Ŀγ̽�������
		sort(Course[id_o].begin(), Course[id_o].end());
		printf("%s %d ", name, Course[id_o].size());
		for (int j = 0; j < Course[id_o].size(); j++)
		{
			printf("%d", Course[id_o][j]);
		}
		printf("\n");
	}
}


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


//�����£����ݽṹ����

//���嶨��ṹ��
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
		node[address].data = data;//��������ݽṹ node[p].data
		node[address].next = next;
	}
	//����������˳�ʼ������������˻�������
	int p;
	for (p = s1; p != -1; p = node[p].next)//node[p].next��ʾ��һ�����ĵ�ַ
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

//�����£��������ϰ
//����ṹ��
struct Node2{
	int addr, data, next;
	bool flag=false;
}node2[maxn];


//���ڴ��ڱȽ����ԣ���Ҫ��һ��cmp����

bool cmp(Node2 a,Node2 b){
	if (a.flag == false || b.flag == false){
		return a.flag > b.flag;
	}
	else{
		return a.data < b.data;
	}
}
void linkListSort(){
	//��ʼ������ֵ�Ȳ���
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

	//����������true ����sort����flag��true��������ߣ�����ȡ����Ľڵ���������Ա��ڴ�ӡ���
	int p = head,count=0;
	while (p!=-1){
		node2[p].flag = true;
		count++;//�õ��������ĳ���
		p = node2[p].next;
	}
	//����
	sort(node2, node2 + maxn, cmp);

	int q=node2[0].addr;


	printf("%d %05d\n", count, node2[0].addr);
	for (int j = 0; j < count; j++){
		if (j != count - 1){
			//��ӡ��һ����
			printf("%05d %d %05d\n", node2[j].addr, node2[j].data, node2[j+1].next);
		}
		else{
			printf("%05d %d -1\n", node2[j].addr, node2[j].data);
		}
	}

}

//��������ϰ�⣺���ݽṹ����
//ջ��stack

string str[maxn];
//�������ⲿ����stack������װ��ջ���е�����
int arr[maxn];
stack<int> st;
void popSequence(){
	int m, n, k;
	scanf_s("%d %d %d",&m,&n,&k );	
	int h = 1;
	for (int i = 0; i < k; i++){
		//���Ԫ�أ���ֹ����һ����Ӱ��
		for (int j = 0; j < m; j++){
			if (!st.empty()){
				st.pop();
			}
		}
		//�����ջ�����˳��������ջ��Ԫ���������ж�
		for (int j = 1; j <= n; j++){
			scanf_s("%d", &arr[j]);
		}		
		int current = 1;
		bool flag = true;//�ж��Ƿ�Ϸ�
		for (int j = 1; j <= n; j++){
			//��ջ
			if (st.size()<m){
				st.push(j);
			}
			else{
				flag = false;
				break;
			}
			//����=================
			while (!st.empty()&&st.top() == arr[current]){//***������������Ϊ�����54321������һ�ξ͵�����******
				st.pop();
				current++;
			}
		}
		//���գ�ջӦ��Ϊ�գ������ǺϷ���==========
		
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


//PAT�����£����У��������ķֲ���룬ÿ�㶼��Ҫ������һ���Ĳ�����
//��һ�������ж������ʱ����Զ���ṹ�壬���ʱ����ǽṹ������



int main(){
	//Course_student();

	//set_similarity();

	//sharing();

	//linkListSort();

	//popSequence();

	return 0;
}