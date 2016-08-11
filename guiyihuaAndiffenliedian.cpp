#include <stdio.h>
#include <cstring>

//1，有效就输出，  如果是大写（这是主要的分裂点） 需要同时满足‘+’ 也要有效 
//初始化，归一的  标志  容器 HashTable[] 

const int maxn = 100000;
char str1[maxn];
char str2[maxn];
bool hashTable[256];// = { 1 };//如果直接写1，或者0，只会出现首元素被赋值，只有0可以一次全部赋值

void targetAndInit(){
	memset(hashTable, true, sizeof(hashTable));//用sizeof而非strlen区分
	gets(str1);
	int len1 = strlen(str1);
	for (int i = 0; i < len1; i++){
		if (str1[i] >= 'A'&&str1[i] <= 'Z'){//1前置归一化的标签容器  统一成小写字母
			str1[i] = str1[i] + ('a' - 'A');
		}
		hashTable[str1[i]] = false;//2设置Hash对应的键失效
	}
	gets(str2);
	int len2 = strlen(str2);
	for (int j = 0; j < len2; j++){
		if (str2[j] >= 'A'&&str2[j] <= 'Z'){//一次分裂点：因为有效即输出，对应大小写都是成立的， 二次分裂点是当前字符有效吗？ 
			char lower = str2[j] + ('a' - 'A');
			//2大写的话，需要：1）‘+’失效了就不输出，即直接跳过；   2）如果对应字符有效并且‘+’有效才输出
			if (hashTable[lower] == true && hashTable['+'] == true){//hashTable[lower] == true   是指其没有在第一行中出现过				
				
				printf("%c", str2[j]);
			}
		}
		else if (hashTable[str2[j]] == true){//1.小写的话，有效就直接输出
			printf("%c", str2[j]);
		}
	}
}

int main(){
	targetAndInit();
	return 0;
}
