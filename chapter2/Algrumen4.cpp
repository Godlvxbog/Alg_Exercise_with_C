#include <stdio.h>
#include <math.h>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

//�����£��㷨����

//����

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

//��������һ����Ҫ����n-1-i�Σ���ð������ һ�֣�֮��õ���ֵ����ײ������Զ�����ʱ����Ҫ�䶯  j=[0:n-1-i]
void bulSort(){
	for (int i = 0; i < n-1; i++){//��Ҫn-1t�˱Ƚ�:����n=2����ֻ��Ҫ�Ƚ�һ�Σ��Ͼ�ȡ�����㣬j��j+1
		for (int j = 0; j <n -1-i; j++){//��i����Ҫn-i�˵ıȽ�      j=[i,n-1-i)
			if (num[j]>num[j+1]){
				int temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}
	
	typeTest(num, 5);
}

//��������һ��ֻ��Ҫ���� 1  �Σ�ѡ������һ��֮�󶥲���a[i]���õ���ֵ�����沿��Ϊ[i+1:n]
void charuSort(){
	for (int i = 0; i < n-1; i++){
		int minIndex = i;//����һ��ǰ����ʼ��   ֮��������minIndex������Ϊ����temp�����ǣ����ǽ�������
		int j;
		for (j = i+1;j < n; j++){//����һ�ˣ��õ����˵���С����index j=[i+1:n)
			if (num[minIndex]>num[j]){//�������ڱ���һ·����
				minIndex = j;//��¼��ǰj��Ҫ������
			}
		}
		//2/����
		int temp = num[i];
		num[i] = num[minIndex];
		num[minIndex] = temp;

	}


	for (int i = 0; i < n; i++){
		printf("%d ", num[i]);
	}
}

//���������õ�ǰtemp=a[i]����ǰ��ĸ���Ԫ�رȽϣ�����ǰ�ƣ��ǵ�tempΪ��С������a[i]��a[j-1]����
void insertSort(){
	for (int i = 1; i < n; i++){
		//�ֱ�õ�num[i]��i
		int j = i;
		int temp = num[i];		
		while (j>0 && temp<num[j-1]){	//��ǰ��������бȽ�
			num[j] = num[j-1];//1����
			j--;
		}
		num[j] = temp;//2��num[i]����֮ǰ��˳��
	}
}

//sort������ʹ�� sort(a,a+4,cmp)
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
	else{//��ˮ��©��if elseֻ��ȥһ��
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
	int x;//��,�Զ����
	
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


//�ɼ��̣�����str1�е����ڣ�str2�����ھʹ�ӡ����Ԫ�أ���if(c1==c2)break;if(j==n2)//��ʾ������һ���㣬�������ɶ����龰��
//����str1�ܿ��ܳ�������ͬ��������if(HashTable[c1]==false)��Ϊ�ж�����

void oldkeyboard(){
	//1���롤
	char str1[120], str2[120];//charʵ������ASCII�룬�����֣�����Hash[c1]�ų���
	gets_s(str1);
	gets_s(str2);
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

//�ɼ��̣����ʧЧֱ�Ӹ�������һ���ǣ��������룬������������Ǹ��� ʧЧ��(��HashTable�洢ʧЧ��)��+���ö���

const int maxn = 100000;
char str1[maxn];
char str2[maxn];
bool hashTable[256];// = { 1 };//���ֱ��д1������0��ֻ�������Ԫ�ر���ֵ��ֻ��0����һ��ȫ����ֵ

void targetAndInit(){
	memset(hashTable, true, sizeof(hashTable));//��sizeof����strlen����
	gets_s(str1);
	int len1 = strlen(str1);
	for (int i = 0; i < len1; i++){
		if (str1[i] >= 'A'&&str1[i] <= 'Z'){//1ǰ�ù�һ���ı�ǩ����  ͳһ��Сд��ĸ
			str1[i] = str1[i] + ('a' - 'A');
		}
		hashTable[str1[i]] = false;//2����Hash��Ӧ�ļ�ʧЧ
	}
	gets_s(str2);
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

//ͳ��ͬ�ɼ����������ɼ���Ϊkey HashTable[]�������ݵĴ洢����

int HashTable[maxn] = {0};//����
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
		printf("%d", HashTable[Tscore[i]]);//�ո��ʽ�������  HashTable����362763273����������ʵ��һ���ܴ����
		if (i<k-1){
			printf(" ");
		}
	}
}

//�ַ�ͳ�� ���ִ��������ַ���

void calumaxtimechar(){
	char str[1010];
	gets_s(str);
	int hashTable[30] = {0};
	int len = strlen(str);
	for ( int i = 0; i < len; i++)
	{
		if (str[i]<'Z'&&str[i]>'A'){
			str[i] += ('a' - 'A'); 
			hashTable[str[i]-'a']++;//str[i]-'a'����ת����   ����������ǵ�hashTable[]�±������֣���������
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
	printf("%c %d", maxIndex+'a', hashTable[maxIndex]);//%c   �ܸ�������������+��a���õ���������  �ַ�
}

//���PATest
char str[10000];
void shuchuPATest(){
	//��������һһ��Ӧ
	char dict[6] = { 'P', 'A', 'T', 'e', 's', 't' };
	int hashTable2[6] = { 0 };//��Ӧ�������ַ����ֵĸ���

	gets_s(str);
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

//����Hash�����ǣ��ҳ���ֵ�ԡ�����Ӧ����**��ֵ��Ӧ����XX
//�Ŷӱ������ͳ��ÿ���ӵĳɼ�  ���Ǽ���  �ɼ���ֵ

void statteamAndScore(){
	int n;
	scanf_s("%d", &n);
	int hashTable3[110] = { 0 };
	int team, member, score;
	for (int i = 0; i < n; i++){		
		scanf_s("%d-%d %d", &team, &member, &score);
		hashTable3[team] += score;//�õ�������һ��ֱ��ͼ��ͳ�Ʊ�
	}
	//�Ƚ�ֱ��ͼ�������һ��
	int maxIndex = 0;
	for (int i = 0; i < 110; i++){
		if (hashTable3[maxIndex]<hashTable3[i]){
			maxIndex = i;
		}
	}
	printf("%d %d", maxIndex, hashTable3[maxIndex]);
}

//�ڶ�С�ڣ��ݹ���⣺1�ݹ�߽磬�ݹ�ʽ
//������Fabonacci

int F(int n=5){
	
	if (n==0){
		return 1;
	}
	return F(n - 1)*n;//�ݹ�ʽ��СƬ�ηֽ�

}

int Fabonacci(int n=7){
	if (n==1||n==2){
		return 1;
	}
	else {
		return Fabonacci(n - 1) + Fabonacci(n - 2);//ʵ����Ҫ����Ӧ���Ǵӵײ�����ʼ�Ͷ�����
	}
}

//�±��������⣬��ν��̰�����⡣�������±��Ե��۴Ӹߵ�������ans+�±��ܼ�,����D�����±�������

struct Moock{
	double num;
	double sale;	
	double price;
}cake[1010];
//�Ƚ�ǰ׼��
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
		scanf_s("%lf", &cake[i].sale);//����ĸ�ʽһ����%lf long float
		cake[i].price = cake[i].sale / cake[i].num;
	}
	sort(cake, cake + n, cmp);

	double ans=0.0;
	for (int i = 0; i < n; i++){
		if (cake[i].num <= D){
			ans += cake[i].sale;
			D -= cake[i].num;//�±�ÿ����һ�Σ�������Ҳ�ͼ�����һ��
		}
		else{
			ans += cake[i].price*D;
			break;//��ʱ�Ѿ������ѭ��
		}
	}

	printf("%.2f", ans);

}

//�����С��

void minout(){
	int count[10];
	for (int i = 0; i < 10; i++){
		scanf_s("%d", &count[i]);
	}

	for (int i = 1; i < 10; i++){//��Ϊ������ʵ�������  ����i������
		if (count[i]>0){
			printf("%d", i);
			count[i]--;//������Ҫ����
			break;
		}
	}
	for (int i = 0; i < 10; i++){//��ӡ�����֣�10�ˣ�ÿ���ǵ�i���������ֱ���
		for (int j = 0; j < count[i]; j++){//count[i]  һ����Ҫ��ӡ������count[i]
			printf("%d", i);
		}
	}
}

//�������ֵ��  �ýṹ�屣��������  ̰���㷨��������  1 cmp  2 sort  3 ��ȡ��ģ���ȡС��
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
	for (int i = 1; i < n; i++)//�ҵĹ���
	{
		if (q[i].x>=lastY){
			ans++;
			lastY = q[i].x;
		}
	}
	printf("%d\n", ans);

}

//���ַ������룬�������У�left right x   ���裺�У��ȣ�����
int A[10] = {1,3,4,6,7,8,10,11,12,15};
int binSearch(int num[],int left,int right,int x){
	int mid;
	while (left<=right){	
		mid = (left + right) / 2;
		if (num[mid] == x){
			printf("%d", x);
			return num[mid];//����һ�����ǵ��ҵ���
		}
		else if (x<num[mid]){
				right = mid - 1;
		}
		else if (x > num[mid]){
				left = mid + 1;
		}	
	}
	return -1;//����ʧ��
}

///�б���aqrt(2);�У��ȣ�������    ���ַ�����ⷽ�̵�����

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

//��������㣬�ö���+�ݹ�

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
//���㷨�������������������е���

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
//�����������a��b�е�Ԫ�أ�����غϲ���c����
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
	//��ʣ�µ�Ԫ�ؼ���c��
	while (i < m){
		c[k++] = a[i++];
	}
	while (j < n){
		c[k++] = b[j++];
	}
}


//�鲢����
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
}//���Ϲ鲢��ɴ����ˣ�temp������
for (int i = 0; i < index; i++){
	a[l1 + i] = temp[i];
}

}

void MergeSort1(int a[], int left, int right){
	//���left<right��Ҫ�鲢�������õݹ�Ͳ���Ҫѭ��
	if (left < right)
	{
		int mid = (left + right) / 2;
		MergeSort1(a, left, mid);
		MergeSort1(a, mid + 1, right);
		merge1(a, left, mid, mid + 1, right);
	}

}

int a7[11] = { 35, 18, 16, 72, 24, 65, 12, 88, 46, 28, 55 };

//��������

//1ֻҪleft��right����ָ�벻��������ôָ��ֱ���temp�Ƚϣ�һ����ģ��ұߣ������ұߣ���ô������߻������Ҳ��ͬ
//����������ʱ�򣬾Ͱ�temp��������

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
//PAT��������
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
//�ö��ַ����в���[i+1,n-1]֮���ҵ���һ������x����
int nn,pp;
int a[maxn];
int binarychazao(int i, long long x){
	if (a[nn-1]<=x){
		return nn;
	}
	int l = i + 1, r = nn - 1;//�����i+1���յ���n-1
	
	while (l<r){
		int mid = (l + r) / 2;//ѭ������ʵ��1
		if (a[mid]<=x){//
			l = mid + 1;//ѭ������2
		}
		else{
			r = mid;//ѭ������2-2
		}
	}
	return r;//����ʱ��l=r
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
		int j = binarychazao(k, (long long)a[k] * pp);//�����a[i]���յ���p*a[i]
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

//���ֲ��ҷ���
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
int j = upper_bound(a + k, a + nn, (long long)a[k] * pp)-a;//�����a[i]���յ���p*a[i]
ans = max(ans, j - k);

}
printf("%d", ans);
}

int main(){
bincazaoB30();
return 0;
}


*/

