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


//第六章 STL模板的运用
//PAT题目
const int n = 40010;
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
	scanf("%d %d", &n_s, &k);
	//以下是吧元素读入，并且用合适的数据结构存储起来，便于输出，到每趟的对象
	for (int i = 0; i < k; i++)//循环体是，完成一趟，一行对应于表格的一个对象
	{
		int cor, mem;//记录课程编号与，该课程的人数
		scanf("%d %d", &cor, &mem);
		for (int j = 0; j < mem; j++)//对于每个对象的操作
		{
			scanf("%s", name);
			int id = get_id_from_str(name);//元操作，得到id也是为了用Course[id].push_back(cor)
			Course[id].push_back(cor);//元操作,
		}
	}
	for (int i = 0; i < n_s; i++)//输出n趟，每趟就是循环体的操作
	{
		scanf("%s", name);
		int id_o = get_id_from_str(name);
		//对每一个的向量中，的课程进行排序
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
