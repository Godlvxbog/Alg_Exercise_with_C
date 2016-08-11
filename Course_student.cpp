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


//������ STLģ�������
//PAT��Ŀ
const int n = 40010;
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
	scanf("%d %d", &n_s, &k);
	//�����ǰ�Ԫ�ض��룬�����ú��ʵ����ݽṹ�洢�����������������ÿ�˵Ķ���
	for (int i = 0; i < k; i++)//ѭ�����ǣ����һ�ˣ�һ�ж�Ӧ�ڱ���һ������
	{
		int cor, mem;//��¼�γ̱���룬�ÿγ̵�����
		scanf("%d %d", &cor, &mem);
		for (int j = 0; j < mem; j++)//����ÿ������Ĳ���
		{
			scanf("%s", name);
			int id = get_id_from_str(name);//Ԫ�������õ�idҲ��Ϊ����Course[id].push_back(cor)
			Course[id].push_back(cor);//Ԫ����,
		}
	}
	for (int i = 0; i < n_s; i++)//���n�ˣ�ÿ�˾���ѭ����Ĳ���
	{
		scanf("%s", name);
		int id_o = get_id_from_str(name);
		//��ÿһ���������У��Ŀγ̽�������
		sort(Course[id_o].begin(), Course[id_o].end());
		printf("%s %d", name, Course[id_o].size());
		for (int j = 0; j < Course[id_o].size(); j++)
		{
			printf(" %d", Course[id_o][j]);
		}
		printf("\n");
	}
}


int main(){
	Course_student();
	return 0;
}
