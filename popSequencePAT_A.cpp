#include <cstdio>
#include <algorithm>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

//��������ϰ�⣺���ݽṹ����
//ջ��stack
const int maxn=100010;
string str[maxn];
//�������ⲿ����stack������װ��ջ���е�����
int arr[maxn];
stack<int> st;
void popSequence(){
	int m, n, k;
	scanf("%d %d %d",&m,&n,&k );	
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
			scanf("%d", &arr[j]);
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

int main(){
	popSequence(); 
	return 0; 
} 


 

