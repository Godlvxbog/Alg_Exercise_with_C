#include <stdio.h>
#include <cstring>


//�ɼ��̣�����str1�е����ڣ�str2�����ھʹ�ӡ����Ԫ�أ���if(c1==c2)break;if(j==n2)//��ʾ������һ���㣬�������ɶ����龰��
//����str1�ܿ��ܳ�������ͬ��������if(HashTable[c1]==false)��Ϊ�ж�����

void oldkeyboard(){
	//1���롤
	char str1[120], str2[120];//charʵ������ASCII�룬�����֣�����Hash[c1]�ų���
	gets(str1);
	gets(str2);
	bool HashTable[120] = {false};//��ʼ����c1û����str�г���
	int n1 = strlen(str1);
	int n2 = strlen(str2);
	for (int i = 0; i < n1; i++){
		int j;
		for (j = 0; j < n2; j++){
			//ת��Ϊͳһ�Ĵ�д
			if (str1[i]<='z'&&str1[i]>='a'){
				str1[i] = str1[i] - ('a' - 'A');
			}
			if (str2[j]<='z'&&str2[j]>='a'){
				str2[j] = str2[j] - ('a' - 'A');
			}
			//�����ֵ����仰
			if (str1[i] == str2[j] ){
				break;//���j<n2<��˵��c1�������str2�����Ѿ�������һ�Σ����j==n2����˵��c1��str2������һ��Ҳû�г���
			}			
		}
		if (j == n2&& HashTable[str1[i]] == false){//HashTable[str1[i]] == false������ظ��ǾͲ����ٴ�ӡ��
			printf("%c", str1[i]);
			HashTable[str1[i]] = true;
		}
	}
}

int main(){
	oldkeyboard();
	return 0;
}
