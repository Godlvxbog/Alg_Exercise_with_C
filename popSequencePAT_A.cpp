#include <cstdio>
#include <algorithm>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

//第七章练习题：数据结构基础
//栈，stack
const int maxn=100010;
string str[maxn];
//首先在外部声明stack与用来装出栈序列的数组
int arr[maxn];
stack<int> st;
void popSequence(){
	int m, n, k;
	scanf("%d %d %d",&m,&n,&k );	
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
			scanf("%d", &arr[j]);
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

int main(){
	popSequence(); 
	return 0; 
} 


 

