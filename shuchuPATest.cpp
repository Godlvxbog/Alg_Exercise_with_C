

#include <cstdio>
#include <cstring>
//���PATest
//���PATest
char str[10000];
void shuchuPATest(){
	//��������һһ��Ӧ
	char dict[6] = { 'P', 'A', 'T', 'e', 's', 't' };
	int hashTable2[6] = { 0 };//��Ӧ�������ַ����ֵĸ���

	gets(str);
	int len1 = strlen(str), num = 0;
	for (int i = 0; i < 6; i++){
		for (int j = 0; j < len1; j++)
		{
			if (dict[i] == str[j]){
				hashTable2[i]++;//����hashhashTable2[dic[i]//���ñ�ǩ
				num++;//�ܸ���
			}
		}
	}
	while (num>0){
		for (int i = 0; i <6; i++){//whileѭ����forѭ��  forѭ������һ�������ģ�num��whileѭ����ʾ��num/6��
			if (hashTable2[i]>0){
				printf("%c", dict[i]);
				hashTable2[i]--;
				num--;
			}
		}

	}
}
int main(){
	shuchuPATest();
	return 0;
}
