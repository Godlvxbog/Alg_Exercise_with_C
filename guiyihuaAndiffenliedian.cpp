#include <stdio.h>
#include <cstring>

//1����Ч�������  ����Ǵ�д��������Ҫ�ķ��ѵ㣩 ��Ҫͬʱ���㡮+�� ҲҪ��Ч 
//��ʼ������һ��  ��־  ���� HashTable[] 

const int maxn = 100000;
char str1[maxn];
char str2[maxn];
bool hashTable[256];// = { 1 };//���ֱ��д1������0��ֻ�������Ԫ�ر���ֵ��ֻ��0����һ��ȫ����ֵ

void targetAndInit(){
	memset(hashTable, true, sizeof(hashTable));//��sizeof����strlen����
	gets(str1);
	int len1 = strlen(str1);
	for (int i = 0; i < len1; i++){
		if (str1[i] >= 'A'&&str1[i] <= 'Z'){//1ǰ�ù�һ���ı�ǩ����  ͳһ��Сд��ĸ
			str1[i] = str1[i] + ('a' - 'A');
		}
		hashTable[str1[i]] = false;//2����Hash��Ӧ�ļ�ʧЧ
	}
	gets(str2);
	int len2 = strlen(str2);
	for (int j = 0; j < len2; j++){
		if (str2[j] >= 'A'&&str2[j] <= 'Z'){//һ�η��ѵ㣺��Ϊ��Ч���������Ӧ��Сд���ǳ����ģ� ���η��ѵ��ǵ�ǰ�ַ���Ч�� 
			char lower = str2[j] + ('a' - 'A');
			//2��д�Ļ�����Ҫ��1����+��ʧЧ�˾Ͳ��������ֱ��������   2�������Ӧ�ַ���Ч���ҡ�+����Ч�����
			if (hashTable[lower] == true && hashTable['+'] == true){//hashTable[lower] == true   ��ָ��û���ڵ�һ���г��ֹ�				
				
				printf("%c", str2[j]);
			}
		}
		else if (hashTable[str2[j]] == true){//1.Сд�Ļ�����Ч��ֱ�����
			printf("%c", str2[j]);
		}
	}
}

int main(){
	targetAndInit();
	return 0;
}
