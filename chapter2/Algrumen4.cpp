#include <stdio.h>
#include <math.h>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

//第四章，算法入门

//排序

int num[5] = { 5, 2, 1, 4, 3 };
int n = 5;

void typeTest(int num[],int n){
	for (int i = 0; i < n; i++){
		printf("%d ", num[i]);
	}
}
void typeTest1(char c[], int n){
	for (int i = 0; i < n; i++){
		printf("%c ", c[i]);
	}
}

//交换排序（一趟需要交换n-1-i次）：冒泡排序： 一轮，之后得到最值在最底部，所以顶部，时常需要变动  j=[0:n-1-i]
void bulSort(){
	for (int i = 0; i < n-1; i++){//需要n-1t趟比较:例如n=2，则，只需要比较一次，毕竟取了两点，j与j+1
		for (int j = 0; j <n -1-i; j++){//第i趟需要n-i趟的比较      j=[i,n-1-i)
			if (num[j]>num[j+1]){
				int temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}
	
	typeTest(num, 5);
}

//交换排序（一趟只需要交换 1  次）选择排序：一轮之后顶部（a[i]）得到最值，后面部分为[i+1:n]
void charuSort(){
	for (int i = 0; i < n-1; i++){
		int minIndex = i;//排序一趟前：初始化   之所以设置minIndex，是因为房子temp被覆盖，这是交换排序
		int j;
		for (j = i+1;j < n; j++){//排序一趟：得到该趟的最小数的index j=[i+1:n)
			if (num[minIndex]>num[j]){//类似于哨兵，一路都是
				minIndex = j;//记录当前j需要被交换
			}
		}
		//2/交换
		int temp = num[i];
		num[i] = num[minIndex];
		num[minIndex] = temp;

	}


	for (int i = 0; i < n; i++){
		printf("%d ", num[i]);
	}
}

//插入排序：用当前temp=a[i]与其前面的各个元素比较，后往前推，是的temp为最小；其中a[i]被a[j-1]覆盖
void insertSort(){
	for (int i = 1; i < n; i++){
		//分别得到num[i]和i
		int j = i;
		int temp = num[i];		
		while (j>0 && temp<num[j-1]){	//与前面的数进行比较
			num[j] = num[j-1];//1后移
			j--;
		}
		num[j] = temp;//2吧num[i]插入之前的顺序
	}
}

//sort函数的使用 sort(a,a+4,cmp)
//int num[5] = { 5, 2, 1, 4, 3 };
//int n = 5;
char c[10] = { 'a', 'k', '1', 'h' };
void sortTest(){
	sort(num, num + 5);

	sort(c, c + 4);
	typeTest1(c, 4);

	typeTest(num, 5);
}

struct Node{
	int x;
	int y;
};
bool cmp2(Node a,Node b){
	if (a.x != a.y){
		return a.x > b.x;
	}
	else{//滴水不漏的if else只能去一个
		return a.y > b.y;
	}
	
}


void cmpSortTest(){
	Node node[10];
	for (int i = 0; i < 10; i++){
		node[i].x = i;
		node[i].y =  2* i - 1;
	}

	sort(node, node + 10,cmp2);
	for (int i = 0; i < 10; i++)
	{
		printf("%d %d\n", node[i].x, node[i].y);
	}
	
	

}

void hashTest(){
	int hash[100] = {0};
	int x;//键,自定义的
	
	for (int i = 0; i < 10; i++)
	{
		scanf_s("%d", &x);
		hash[x]++;
	}
	for (int i = 0; i < 4; i++)
	{
		int y;
		scanf_s("%d", &y);
		printf("%d\n", hash[y]);
	}

}


//旧键盘：数组str1中的数在，str2不存在就打印出该元素：用if(c1==c2)break;if(j==n2)//表示【这是一个点，而不是由多重情景】
//其中str1总可能出现有相同的数，用if(HashTable[c1]==false)作为判断条件

void oldkeyboard(){
	//1输入·
	char str1[120], str2[120];//char实际上是ASCII码，是数字，所以Hash[c1]才成立
	gets_s(str1);
	gets_s(str2);
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

//旧键盘，这次失效直接给出，上一题是，给出输入，输出结果；这次是给出 失效键(用HashTable存储失效键)，+作用对象

const int maxn = 100000;
char str1[maxn];
char str2[maxn];
bool hashTable[256];// = { 1 };//如果直接写1，或者0，只会出现首元素被赋值，只有0可以一次全部赋值

void targetAndInit(){
	memset(hashTable, true, sizeof(hashTable));//用sizeof而非strlen区分
	gets_s(str1);
	int len1 = strlen(str1);
	for (int i = 0; i < len1; i++){
		if (str1[i] >= 'A'&&str1[i] <= 'Z'){//1前置归一化的标签容器  统一成小写字母
			str1[i] = str1[i] + ('a' - 'A');
		}
		hashTable[str1[i]] = false;//2设置Hash对应的键失效
	}
	gets_s(str2);
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

//统计同成绩的人数。成绩作为key HashTable[]保存数据的存储次数

int HashTable[maxn] = {0};//这是
int Tscore[200];
void caluSameScore(){
	int n,score,m,k=0;
	scanf_s("%d",&n);
	for (int i = 0; i < n; i++){
		scanf_s("%d", &score);
		HashTable[score]++;
	}
	scanf_s("%d", &m);
	
	for (int j = 0; j < m; j++){		
		scanf_s("%d", &Tscore[k++]);
	}	
	for (int i = 0; i < k; i++)
	{	
		printf("%d", HashTable[Tscore[i]]);//空格格式输出常用  HashTable【（362763273）】索引其实是一个很大的数
		if (i<k-1){
			printf(" ");
		}
	}
}

//字符统计 出现次数最多的字符串

void calumaxtimechar(){
	char str[1010];
	gets_s(str);
	int hashTable[30] = {0};
	int len = strlen(str);
	for ( int i = 0; i < len; i++)
	{
		if (str[i]<'Z'&&str[i]>'A'){
			str[i] += ('a' - 'A'); 
			hashTable[str[i]-'a']++;//str[i]-'a'将其转化成   对齐的数组是的hashTable[]下标是数字，可以索引
		}
		else if (str[i]<'z'&&str[i]>'a'){
			hashTable[str[i]-'a']++;
		}		
	}
	int maxIndex = 0;
	for (int j = 0; j < 30; j++){
		if (hashTable[maxIndex]<hashTable[j]){
			maxIndex = j;
		}
	}
	printf("%c %d", maxIndex+'a', hashTable[maxIndex]);//%c   总给出数字索引—+‘a’得到返回来的  字符
}

//输出PATest
char str[10000];
void shuchuPATest(){
	//两个数组一一对应
	char dict[6] = { 'P', 'A', 'T', 'e', 's', 't' };
	int hashTable2[6] = { 0 };//对应的上面字符出现的个数

	gets_s(str);
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

//运用Hash条件是：找出键值对。键对应的是**，值对应的是XX
//团队编程赛，统计每个队的成绩  队是键，  成绩是值

void statteamAndScore(){
	int n;
	scanf_s("%d", &n);
	int hashTable3[110] = { 0 };
	int team, member, score;
	for (int i = 0; i < n; i++){		
		scanf_s("%d-%d %d", &team, &member, &score);
		hashTable3[team] += score;//得到的类似一个直方图的统计表
	}
	//比较直方图中最大大的一行
	int maxIndex = 0;
	for (int i = 0; i < 110; i++){
		if (hashTable3[maxIndex]<hashTable3[i]){
			maxIndex = i;
		}
	}
	printf("%d %d", maxIndex, hashTable3[maxIndex]);
}

//第二小节：递归理解：1递归边界，递归式
//举例：Fabonacci

int F(int n=5){
	
	if (n==0){
		return 1;
	}
	return F(n - 1)*n;//递归式是小片段分解

}

int Fabonacci(int n=7){
	if (n==1||n==2){
		return 1;
	}
	else {
		return Fabonacci(n - 1) + Fabonacci(n - 2);//实际你要计算应该是从底层市民开始劳动算起。
	}
}

//月饼销售问题，所谓的贪心问题。。。对月饼以单价从高到低排序，ans+月饼总价,需求D减少月饼销售量

struct Moock{
	double num;
	double sale;	
	double price;
}cake[1010];
//比较前准备
bool cmp(Moock a, Moock b){
	return a.price > b.price;
}

void mooncake(){
	int n ;
	double D;
	scanf_s("%d %lf", &n,&D);
	for ( int i = 0; i < n; i++){
		scanf_s("%lf",&cake[i].num);
	}

	for (int i = 0; i < n; i++){
		scanf_s("%lf", &cake[i].sale);//输入的格式一定是%lf long float
		cake[i].price = cake[i].sale / cake[i].num;
	}
	sort(cake, cake + n, cmp);

	double ans=0.0;
	for (int i = 0; i < n; i++){
		if (cake[i].num <= D){
			ans += cake[i].sale;
			D -= cake[i].num;//月饼每卖出一次，需求量也就减少了一次
		}
		else{
			ans += cake[i].price*D;
			break;//此时已经完成了循环
		}
	}

	printf("%.2f", ans);

}

//输出最小数

void minout(){
	int count[10];
	for (int i = 0; i < 10; i++){
		scanf_s("%d", &count[i]);
	}

	for (int i = 1; i < 10; i++){//因为本身其实是有序的  按照i来计算
		if (count[i]>0){
			printf("%d", i);
			count[i]--;//个数需要减少
			break;
		}
	}
	for (int i = 0; i < 10; i++){//打印出数字，10趟，每趟是第i个数，数字本身。
		for (int j = 0; j < count[i]; j++){//count[i]  一趟需要打印次数是count[i]
			printf("%d", i);
		}
	}
}

//区间最大值，  用结构体保存多个属性  贪心算法基本步骤  1 cmp  2 sort  3 先取大的，再取小的
struct qujian
{
	int x;
	int y;
}q[100];

bool cmp1(qujian a,qujian b){
	if (a.x != b.x){
		return a.x < b.x;
	}
	else{
		return a.y < b.y;
	}
}

void qujiansort(){
	int n;
	scanf_s("%d",&n);
	for ( int i = 0; i < n; i++)
	{
		scanf_s("%d %d",&q[i].x,&q[i].y);
	}
	sort(q, q + n, cmp1);
	int lastY = q[0].y;
	int ans = 1;
	for (int i = 1; i < n; i++)//找的过程
	{
		if (q[i].x>=lastY){
			ans++;
			lastY = q[i].x;
		}
	}
	printf("%d\n", ans);

}

//二分法：输入，递增序列，left right x   步骤：中，比，区间
int A[10] = {1,3,4,6,7,8,10,11,12,15};
int binSearch(int num[],int left,int right,int x){
	int mid;
	while (left<=right){	
		mid = (left + right) / 2;
		if (num[mid] == x){
			printf("%d", x);
			return num[mid];//最终一定会是的找到的
		}
		else if (x<num[mid]){
				right = mid - 1;
		}
		else if (x > num[mid]){
				left = mid + 1;
		}	
	}
	return -1;//查找失败
}

///夹逼求aqrt(2);中，比，改区间    二分法是求解方程的利器

double f(double x){
	return x*x;
}


double guji(){
	const double eps = 1e-2;
	double left = 1, right = 2,mid;
	while (right-left>eps)
	{
		mid = (left + right) / 2;
		if (2<f(mid)){
			right=mid;
		}
		else{
			left = mid;
		}
	}
	printf("%.3lf", mid);
	return mid;
}

//快速溟计算，用二分+递归

typedef long long LL;
LL binaryPow(LL a, LL b){
	if (b == 0){
		return 1;
	}
	if (b % 2 == 1){
		
		return a*binaryPow(a,b - 1);
	}
	else{
		LL mul = binaryPow(a, b / 2);
		return mul*mul;
	}
}
//两点法：进行有序充分利用序列递增

void twopoint(int a[],int M){
	int n=10;
	int i = 0, j = n - 1;
	while (i<j){
		if (a[i]+a[j]==M)
		{
			i++;
			j--;
		}
		else if (a[i] + a[j] <M){
			i++;
		}
		else{
			j--;
		}
	}
}
//吧有序的数组a，b中的元素，有序地合并到c数组
void mergeshixian(int a[],int b[],int [],int m,int n){
	int i = 0, j = 0,k=0;
	while (i<m&&j<n){
		if (a[i] < a[j]){
			c[k++] = a[i++];
		}
		else{
			c[k++] = b[j++];
		}
	}
	//将剩下的元素加入c中
	while (i < m){
		c[k++] = a[i++];
	}
	while (j < n){
		c[k++] = b[j++];
	}
}


//归并排序
void merge1(int a[],int l1,int r1,int l2,int r2){
	int temp[100],index=0;
int i = l1, j = l2;
while (i < r1&&j < r2){
	if (a[i] < a[j]){
		temp[index++] = a[i++];
	}
	else{
		temp[index++] = a[j++];
	}
}
while (i < r1){
	temp[index++] = a[i++];
}
while (j < r2){
	temp[index++] = a[j++];
}//以上归并完成存在了，temp数组中
for (int i = 0; i < index; i++){
	a[l1 + i] = temp[i];
}

}

void MergeSort1(int a[], int left, int right){
	//如果left<right就要归并，这里用递归就不需要循环
	if (left < right)
	{
		int mid = (left + right) / 2;
		MergeSort1(a, left, mid);
		MergeSort1(a, mid + 1, right);
		merge1(a, left, mid, mid + 1, right);
	}

}

int a7[11] = { 35, 18, 16, 72, 24, 65, 12, 88, 46, 28, 55 };

//快速排序

//1只要left和right两个指针不相遇，那么指针分别于temp比较，一旦大的（右边）不在右边，那么就与左边换；左边也相同
//当两个相遇时候，就把temp插入其中

int partion(int a[], int left, int right){
	int temp = a[left];
	while (left < right){
		while (left<right&&a[right]>temp)
		{
			right--;
		}
		a[left] = a[right];
		while (left < right&& a[left] < temp)
		{
			left++;
		}
		a[right] = a[left];
	}
	a[left] = temp;
	return left;
}

void qsort1(int a[], int left, int right){
	if (left < right)
	{
		int pos = partion(a, left, right);
		qsort1(a, left, pos - 1);
		qsort1(a, pos + 1, right);
	}

}
/*


int wanmeinum[maxn] = { 0 };
int n, p;
int count10[maxn] = { 0 };
//PAT完美数列
void testwanmei(){
	
	scanf_s("%d %d", &n, &p);
	for (int k = 0; k < n; k++)
	{
		scanf_s("%d", &wanmeinum[k]);
	}
	sort(wanmeinum, wanmeinum + n);
	int m;
	for (int i = 0; i < n; i++){
		int j = i;
		m = i + 1;
		int temp = wanmeinum[i];
		while (wanmeinum[j] <= p*temp&&j < n)
		{
			j++;
			count10[m]++;
		}
		if (count10[m] < count10[m - 1]){
			count10[m] = count10[m - 1];
		}
	}
	printf("%d", count10[m]);

}
*/

//PAT*B30
//用二分法进行查找[i+1,n-1]之中找到第一个大于x的数
int nn,pp;
int a[maxn];
int binarychazao(int i, long long x){
	if (a[nn-1]<=x){
		return nn;
	}
	int l = i + 1, r = nn - 1;//起点是i+1，终点是n-1
	
	while (l<r){
		int mid = (l + r) / 2;//循环减少实现1
		if (a[mid]<=x){//
			l = mid + 1;//循环减少2
		}
		else{
			r = mid;//循环减少2-2
		}
	}
	return r;//结束时候l=r
}

void bincazaoB30(){
	scanf_s("%d %d", &nn, &pp);
	for (int k = 0; k < nn; k++)
	{
		scanf_s("%d", &a[k]);
	}
	sort(a, a + nn);
	int ans = 1;
	for (int k = 0; k < nn; k++)
	{
		int j = binarychazao(k, (long long)a[k] * pp);//起点是a[i]，终点是p*a[i]
		ans = max(ans, j - k);

	}
	printf("%d", ans);
}

int main(){
	//bulSort();

	//insertSort();
	//charuSort();

	//sortTest();

	//cmpSortTest();
	
	//hashTest();

	//oldkeyboard();

	//targetAndInit();
	//caluSameScore();

	//calumaxtimechar();
	//shuchuPATest();

	//statteamAndScore();
	//printf("%d",F());

	//printf("%d", Fabonacci());

	//mooncake();

	//minout();

	//qujiansort();

	//guji();
	//binSearch(A, 0, 9, 10);

	//binaryPow(100, 200);

	//MergeSort1(a7, 0, 9);
	//qsort1(a7, 0, 10);

	//testwanmei();

	bincazaoB30();
	return 0;
}


/*

//二分查找方法
#include <stdio.h>
#include <math.h>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e5;
int nn,pp;
int a[maxn];

void bincazaoB30(){
scanf("%d %d", &nn, &pp);
for (int k = 0; k < nn; k++)
{
scanf("%d", &a[k]);
}
sort(a, a + nn);
int ans = 1;
for (int k = 0; k < nn; k++)
{
int j = upper_bound(a + k, a + nn, (long long)a[k] * pp)-a;//起点是a[i]，终点是p*a[i]
ans = max(ans, j - k);

}
printf("%d", ans);
}

int main(){
bincazaoB30();
return 0;
}


*/

