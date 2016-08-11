#include <stdio.h>
#include <cstring>


//旧键盘：数组str1中的数在，str2不存在就打印出该元素：用if(c1==c2)break;if(j==n2)//表示【这是一个点，而不是由多重情景】
//其中str1总可能出现有相同的数，用if(HashTable[c1]==false)作为判断条件

void oldkeyboard(){
	//1输入·
	char str1[120], str2[120];//char实际上是ASCII码，是数字，所以Hash[c1]才成立
	gets(str1);
	gets(str2);
	bool HashTable[120] = {false};//初始化，c1没有在str中出现
	int n1 = strlen(str1);
	int n2 = strlen(str2);
	for (int i = 0; i < n1; i++){
		int j;
		for (j = 0; j < n2; j++){
			//转换为统一的大写
			if (str1[i]<='z'&&str1[i]>='a'){
				str1[i] = str1[i] - ('a' - 'A');
			}
			if (str2[j]<='z'&&str2[j]>='a'){
				str2[j] = str2[j] - ('a' - 'A');
			}
			//不出现的两句话
			if (str1[i] == str2[j] ){
				break;//如果j<n2<则说明c1这个书在str2容器已经出现了一次，如果j==n2，则说明c1在str2容器中一次也没有出现
			}			
		}
		if (j == n2&& HashTable[str1[i]] == false){//HashTable[str1[i]] == false，多次重复是就不能再打印了
			printf("%c", str1[i]);
			HashTable[str1[i]] = true;
		}
	}
}

int main(){
	oldkeyboard();
	return 0;
}
