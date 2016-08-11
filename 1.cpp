#include <stdlib.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

struct Student{
	char name[10];
	int age, score;
};//其中Student是结构体的类型类似于JavaBean中的类；

//Student stu1, stu2 = { 89,"zhangshan",23 };//此为利用新建立的Student类型进行声明
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
	sort(s, s + 3, cmpdemo);//只需要写出比较规则的头即可
	for (int j = 0; j < n; j++){
		cout << s[j].name << s[j].score << s[j].age<<endl;
	}
	

}

void main(){
	structsortdemo();
}