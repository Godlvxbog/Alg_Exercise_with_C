#include <stdlib.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

struct Student{
	char name[10];
	int age, score;
};//����Student�ǽṹ�������������JavaBean�е��ࣻ

//Student stu1, stu2 = { 89,"zhangshan",23 };//��Ϊ�����½�����Student���ͽ�������
int cmpdemo(Student a, Student b){
	if (a.score == b.score){
		if (strcmp(a.name, b.name) == 0){
			return a.age - b.age;
		}
		return strcmp(a.name, b.name);
	}
	return a.score - b.score;
}

void structsortdemo(){
	Student s[10];
	int n=3;
	for (int i = 0; i < n; i++){
			scanf("%s%d%d",s[i].name,&s[i].score,&s[i].age);
	}
	sort(s, s + 3, cmpdemo);//ֻ��Ҫд���ȽϹ����ͷ����
	for (int j = 0; j < n; j++){
		cout << s[j].name << s[j].score << s[j].age<<endl;
	}
	

}

void main(){
	structsortdemo();
}