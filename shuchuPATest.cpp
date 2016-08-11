

#include <cstdio>
#include <cstring>
//输出PATest
//输出PATest
char str[10000];
void shuchuPATest(){
	//两个数组一一对应
	char dict[6] = { 'P', 'A', 'T', 'e', 's', 't' };
	int hashTable2[6] = { 0 };//对应的上面字符出现的个数

	gets(str);
	int len1 = strlen(str), num = 0;
	for (int i = 0; i < 6; i++){
		for (int j = 0; j < len1; j++)
		{
			if (dict[i] == str[j]){
				hashTable2[i]++;//不是hashhashTable2[dic[i]//设置标签
				num++;//总个数
			}
		}
	}
	while (num>0){
		for (int i = 0; i <6; i++){//while循环与for循环  for循环产生一趟完整的，num的while循环表示有num/6趟
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
