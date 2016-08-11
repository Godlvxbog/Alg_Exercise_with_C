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

void vector_test(){
	vector <int> vi;
	for (int i = 0; i < 5; i++)
	{
		vi.push_back(i);
	}
	vi.pop_back();
	vi.pop_back();

	//vector<int>::iterator it   ������<����> ���� ��̬����it��ָ�룩
	for (vector<int>::iterator it = vi.begin(); it != vi.end();it++)
	{
		printf("%d ", *it);
	}
	printf("\n%d ɾ����", vi.size());
	vi.clear();
	vi.insert(vi.begin() + 2, -1000);
	printf("\n%d ", vi.size());
}

void vector_test2(){
	vector <int> vi;
	for (int i = 0; i < 5; i++)
	{
		vi.push_back(i);
	}
	vi.insert(vi.begin() + 2, -1000);

	//vector<int>::iterator it   ������<����> ���� ��̬����it��ָ�룩
	for (vector<int>::iterator it = vi.begin(); it != vi.end(); it++)
	{
		printf("%d ", *it);
	}

	printf("\n%d ", vi.size());
}


void vector_test3(){
	vector <int> vi;
	for (int i = 0; i < 5; i++)
	{
		vi.push_back(i);
	}
	//vi.erase(vi.begin() + 2);
	vi.erase(vi.begin(), vi.begin() + 3);
	//vector<int>::iterator it   ������<����> ���� ��̬����it��ָ�룩
	for (vector<int>::iterator it = vi.begin(); it != vi.end(); it++)
	{
		printf("%d ", *it);
	}

	printf("\n%d ", vi.size());
}

//set�ĳ����÷�

void set_test(){
	set<int> st;
	st.insert(3);
	st.insert(12);
	st.insert(3);
	st.insert(4);
	for (set<int>::iterator it = st.begin(); it != st.end();it++){
		printf("%d  ", *it);
	}
}



void set_test2(){
	set<int> st;
	for (int i = 0; i < 4; i++)
	{
		st.insert(i);
	}
	set<int>::iterator it = st.find(3);
	printf("%d", *it);
}


//������string���÷�
void string_test(){
	string str = "woshiyigeniubman";
	for (int i = 0; i < str.length(); i++)
	{
		printf("%c  ", str[i]);

	}

}

void str_io(){
	string str;//��������stringֻ����cin ������printf
	cin >> str;
	cout << str << str << endl;


}
void str_fun(){
	string str1="nihao";
	string str2 = "wolaizizhejiangdaxue";
	string str3 = str1 + str2;
	if (str1!=str2)
	{
		cout << "�����";
	}
	str3.insert(str3.begin()+2,str2.begin()+2,str2.end());
	cout << str3 <<"\n" <<endl;
}


//������map�ķ���ʵ��
void map_test(){
	map<char, int> mp;
	mp['a'] = 1;
	mp['b'] = 2;
	mp['c'] = 3;
	map<char, int>::iterator it = mp.find('b');
	mp.erase(it);//ɾ��eraser�Ĳ�����it
	for (map<char, int>::iterator it = mp.begin(); it != mp.end();it++){
		printf("%c %d\n", it->first, it->second);
	}
}


//������queue

void queeu_test(){
	queue<int> q;
	for (int i = 0; i < 5; i++)
	{
		q.push(i);
	}
	for (int i = 0; i < 3; i++)
	{
		q.pop();//ɾ��q�ĵ�һ��Ԫ��   ѭ������
	}
	printf("%d\n", q.front());
	if (!q.empty())
	{
		printf("���ǿյ�\n");
	}
	printf("%d", q.size());
}



void priority_queue_test(){
	priority_queue< int,vector<int>, less<int> > q;
	q.push(4);
	q.push(3);
	q.push(2);
	printf("%d", q.top());

}

struct fruit{
	string name;
	int price;
	friend bool operator < (fruit f1, fruit f2){//  < ������С�ڷ���  ��ʾ�෴��˳��
		return f1.price < f2.price;//�ԴӴ�С��˳�� �� ˮ�� �������� �Ӵ�С����
	}
};

fruit f1, f2, f3;
void priorty_queue_test2(){
	priority_queue<fruit> q; //���������������fruit

	f1.name = "����";
	f1.price = 10;
	f2.name = "ƻ��";
	f2.price = 20;
	f3.name = "����";
	f3.price = 30;


	q.push(f1);
	q.push(f2);
	q.push(f3);

	cout << q.top().name << " " << q.top().price << endl;

}


//������ջ


void stack_test(){

}

int main(){
	//vector_test();
	//vector_test2();
	//vector_test3();

	//set_test();
	//set_test2();

	//string_test();
	//str_io();
	//str_fun();
	//map_test();

	//queeu_test();

	//priority_queue_test();
	priorty_queue_test2();
	return 0;
}






