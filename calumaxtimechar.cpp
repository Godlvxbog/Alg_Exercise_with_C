
#include <stdio.h>
#include <cstring>
//�ַ�ͳ�� ���ִ��������ַ���

void calumaxtimechar(){
	char str[1010];
	gets(str);
	int hashTable[30] = {0};
	int len = strlen(str);
	for ( int i = 0; i < len; i++)
	{
		if (str[i]<='Z'&&str[i]>='A'){
			str[i] += ('a' - 'A'); 
			hashTable[str[i]-'a']++;//str[i]-'a'����ת����   ���������
		}
		else if (str[i]<='z'&&str[i]>='a'){
			hashTable[str[i]-'a']++;
		}		
	}
	int maxIndex = 0;
	for (int j = 0; j < 30; j++){
		if (hashTable[maxIndex]<hashTable[j]){
			maxIndex = j;
		}
	}
	printf("%c %d", maxIndex+'a', hashTable[maxIndex]);//%c   �ܸ�������������+��a���õ���������  �ַ�
}

int main(){
	calumaxtimechar();
	return 0;
}
