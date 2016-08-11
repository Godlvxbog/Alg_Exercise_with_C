#include <stdio.h>
#include <math.h>
#include <string>
#include <cstring>

//������PAT����ϰ��Ŀ1

void countCalazNum(){
	int n,count=0;
	scanf_s("%d", &n);
	while (n != 1){//n < 1000 && ��Ҫ������������n
		if (n%2==0)
		{
			n /= 2;
		}
		else{
			n =(n* 3 + 1)/2;
		}
		count++;
	}
	printf(" %d", count);//��Ҫ����ӡ�����һ�а��������ʽ��
}

//������s[i]��ͣ��������s�����ֵ
//���룬���ţ�������
//1���ֱ���ͣ�2�����ֵ

const int stuNum = 100000;
int school[stuNum] = { 0 };//���Ӧ�÷������棬����۷֣�main�в������������ڴ棬10^5Ҫ����
void fenleiAdd(){
	
	int n, schNum, score;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d %d", &schNum, &score);
		school[schNum] += score;

	}
	int max = -1,k;
	for (int i = 0; i < n; i++)
	{
		if (max<school[i]){
			max = school[i];
			k = i;
		}

	}
	printf("%d %d", k, max);

}

void chazaotest(){
	int n,num[200];
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++){//�������ݵ�����
		scanf_s("%d",&num[i]);
	}
	int m,k=0;
	scanf_s("%d", &m);
	for (k = 0; k < n; k++){//����=1��if��2����
		if (m==num[k])
		{
			printf("%d", k);
			break;//�ҵ��˾�����ѭ��
		}
	}
	//���û�м�Ϊ n==i
	if (k == n){
		printf("-1\n");
	}
	
}

//PAT 3��ӡ�����Σ�
void lchartype(char c, int n){
	for (int i = 0; i < n; i++)
	{
		printf("%c", c);
	}
	printf("\n");
}

void schartype(char c, int n){
	printf("%c", c);
	for (int i = 1; i < n - 1; i++)
	{
		printf(" ");
	}
	printf("%c\n", c);
	
}
void typesqaretest(){//���ú����������ǰ�棬��Ȼ����ʾ�Ҳ�����ʶ��
	char c;
	int n,m;
	scanf_s("%d %c", &n,&c );
	if (n % 2 == 0){
		m = n / 2;
	}
	else{
		m = n / 2 + 1;
	}
	
	lchartype(c, n);
	for (int i =1; i < m-1; i++)
	{
		schartype(c, n);
	}

	lchartype(c, n);



}

//PAT ����ת��

void jzchange(){
	int a, b, d,sum=0;
	scanf_s("%d %d %d",&a,&b,&d);
	sum = a + b;
	int ans[31];
	int n = 0;
	do{		
		ans[n] = sum%d;//��������
		sum /= d;
		n++;//����������������

	} while (sum!=0);

	for (int i = n-1; i>=0; i--)
	{
		printf("%d", ans[i]);
	}
}


//PAT��ϰ:������
bool hzwjudge(char str[]){
	int n = strlen(str);
	for (int i = 0; i < n/2; i++){
		if (str[i]!=str[n-1-i]){
			return false;
		}
	}
}


const int maxn = 256;
char str[maxn];
void huiziwen(){
	while (gets_s(str))//�������str
	{
		bool flag = hzwjudge(str);
		if (flag){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
}

//PAT˵����
char word[100][100];
void suofanhua(){
	int num=0;
	while (scanf_s("%s",word[num])!=EOF)//��ζ��뵽����word[],word[num]����&
	{
		num++;
	}
	for (int i = num-1; i >= 0; i--)
	{
		printf("%s",word[i]);
	}
}

//PAT�����ж�A+B>C��

void judgeABC(){
	int T,tcase=1;
	long long a, b, c;//����㣺������������Խ��
	scanf_s("%d", &T);
	int rz[20],j=0;
	while (T--){
		scanf_s("%lld%lld%lld",&a,&b,&c);
		if (a + b > c){
			rz[j++] = true;
		}
		else
		{
			rz[j++] =false;
			//printf("Case#%d:false", tcase);
		}
	}
	int i = 0;
	for (i = 0; i < j; i++)
	{
		if (rz[i]==true){
			printf("Case#%d:true\n", i);
		}
		else{
			printf("Case#%d:false\n", i);
		}
	}
}

//PAT a+b�Ĳ��ֺ�
long long bitjudge(long long a, long long da){
	long long pa = 0;
	while (a!=0){
		if (a%10==da){
			pa = pa * 10 + da;
		}
		a /= 10;//����
	}
	return pa;
}


void bitNumAdd(){
	long long a, da, b, db;
	scanf_s("%lld %lld %lld %lld", &a, &da, &b, &db);
	long long pa = bitjudge(a, da);
	long long pb = bitjudge(b, db);
	printf("%lld", pa + pb);

}

//PAT  ��������ʱ��

void calctime(){
	int c1, c2,ans;
	scanf_s("%d %d", &c1, &c2); 
	ans = c2 - c1;
	if (ans % 100 >= 50){
		ans = ans / 100 + 1;
	}
	else{
		ans = ans / 100;//�õ�����
	}

	printf("%d:%d:%d", ans / 3600, (ans % 3600) / 60, ans % 60);


}


//PAT �Ⱦƻ�ȭ

void hejiu(){
	int n,a1,a2,b1,b2,failA=0,failB=0;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++){
		scanf_s("%d %d %d %d",&a1,&a2,&b1,&b2);
		if (a1 + b1 == a2&&a1 + b1!=b2){
			failB++;
		}
		if (a1 + b1 == b2&&a1 + b1 !=a2){
			failA++;
		}
	}
	printf("%d %d\n",failA,failB);
}

void arrayMoveR(){
	int n, m,a[50],count=0;
	scanf_s("%d %d",&n,&m);
	for (int i = 0; i < n; i++){
		scanf_s("%d", &a[i]);
	}
	for (int i = n - m; i < n; i++){
		printf("%d", a[i]);
		if (count < n){
			printf(" ");
		}
		count++;
	}
	for (int i = 0; i < n-m; i++)
	{
		printf("%d", a[i]);
		if (count < n){
			printf(" ");
		}
		count++;
	}
	

}

//����
void qiudao(){
	int a[1000],k,e,count=0;
	while (scanf_s("%d %d",&k,&e)){
		a[e] = k;
	}
	for (int i = 0; i < 1000; i++)
	{
		a[i - 1] = a[i] * i;
		a[i] = 0;
		if (a[i]!=0){
			count++;
		}
	}

	for (int i = 1000; i >= 0; i--)
	{
		if (a[i] != 0){
			printf("%d &d", a[i], i);
			count--;
			if (count>0){
				printf(" ");
			}
		}		
	}
}

//��������Ϊ����ȥ�ң����Ժź�׼��֤��Ϊֵ��
struct  STU{
	long long id;
	int ksnum;
};
const int maxn2 = 1010;
STU stu[maxn2];

void jian2zhichazao(){
	int n;
	scanf_s("%d", &n);
	long long id;
	int csnum, ksnum;
	for (int i = 0; i < n; i++){
		scanf_s("%lld %d %d", &id, &csnum, &ksnum);
		stu[csnum].id = id;
		stu[csnum].ksnum = ksnum;
	}
	int m;
	scanf_s("%d",&m);
	for (int i = 0; i < m; i++){
		scanf_s("%d", &csnum);
		printf("%lld %d\n", stu[csnum].id, stu[csnum].ksnum);
	}
}

//��ṹ�壬s������ĳ�����Ե���ֵ
const int length = 20;
struct STUD{
	char name[length];
	char id[length];
	int score;
};
STUD s_temp,s_min,s_max;//��������ѧ��,����s_temp���ɱ�ģ�����scanf��������

//��Ҫ�������ֵֻ��Ҫ��1max��ʼ����2for��ȡ��ʱ�ɱ�Ķ���

void structmax(){
	s_min.score = 101;//һ��������С����
	s_max.score = -1;//һ��������z������������һ��һ��ʼ�ͻ�����ж����
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++){
		scanf_s("%s %s %d",s_temp.name,s_temp.id,&s_temp.score);
		if (s_temp.score<s_min.score){
			s_min.score = s_temp.score;
		}
		if (s_temp.score>s_max.score){
			s_max.score = s_temp.score;
		}

	}
	printf("%s %s", s_max.name, s_max.id);
	printf("%s %s", s_min.name, s_min.id);

}

void triangleType(){
	int n,bottom;
	char c;
	scanf_s("%d %c",&n,&c);
	bottom = (int)sqrt(2.0*(n + 1)) - 1;
	int used = (bottom + 1)*(bottom + 1) / 2 - 1;
	//��ӡ�����ǣ�ǰ�ո����c����\n����iΪc�ĸ���  i[bottom:1:-2]
	for (int i = bottom; i>=1; i-=2){
		for (int j = 0; j < (bottom - i) / 2; j++){
			printf(" ");
		}
		for (int k = 0; k < i; k++){
			printf("%c", c);
		}
		printf("\n");
	}
	//��ӡ�����ǣ�i[3:bottom:2]
	for (int i = 3; i <=bottom; i+=2){
		for (int j = 0; j < (bottom - i) / 2; j++){
			printf(" ");
		}
		for (int k = 0; k < i; k++){
			printf("%c", c);
		}
		printf("\n");
	}
	//���ʣ�����
	printf("%d", n - used);
}


//PAT���ƻ��� �������ػ�Ǯ  G=29*17 S=29  price=a1*G+b1*S+c1 ����һ���ǻ���ͳһ����С��λ����
//  sum/G*s : (sum%(G*S))/S : sum%S

const int G = 29 * 17;
const int S = 29;
void jingzhichange(){

	int a1, b1, c1, a2, b2, c2;
	scanf_s("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2);
	int price = a1*G + b1*S + c1;
	int money = a2*G + b2*S + c2;
	int change = money - price;//����С�ĵ�λ����ͳһ���ڼ���

	if (change <= 0){//Ϊ���ŵĴ���   1���-��2ȡ�෴��Ϊ�����ֵ��Ϊ�����Ϳ��԰�����ǰ����������������
		printf("-");
		//change =(int)fabs((double)change);
		change = -change;
	}
	printf("%d.%d.%d\n", change / G, (change % G) / S, change%S);
}
//ö�ٷ����չ涨��ʽ���������1���õ�����λ���֣���������洢����a[i]=sum%10,sum/10��

void formatNum(){
	int n, a[10] , num = 0;
	memset(a,0,sizeof(a));
	scanf_s("%d", &n);
	while (n!=0){
		a[num++] = n % 10;
		n /= 10;
	}
	for (int k= num-1; k >=0; k--){//�������飬�ϸ�������  kΪλ��

	
		if (k == 2){//��λ
			for (int i = a[k]; i > 0; i--){
				printf("B");
			}
		}
		else if (k==1){//ʮλ
			for (int i = a[k]; i>0; i--){
				printf("S");
			}
		}
		else if (k==0){
			for (int i = 1; i <= a[k]; i++)
			{
				printf("%d", i);
			}
		}
	}
}

//count[str[i]]++,����Ҳ�Ǳ���,ͳ��1��λ��

void tongjisuzhu(){
	char str[1010];
	gets_s(str);
	int len = strlen(str);//str[i]���Եõ���������
	int count[20] = {0};
	for (int i = 0; i < len;i++){
		int bit = str[i]-'0';//������λ  ��Ҫת��Ϊ���֣���ǰstr[i]��char������
		count[bit]++;//����
	}
	for (int j = 0; j < 10;j++){//ö��10��
		if (count[j]!=0){
			printf("%d:%d\n", j, count[j]);
		}
	}
}

using namespace std;
void idcardtest(){
	int n, sum = 0, j = 0;
	char str[20];//����ʱ���ܽ��г�ʼ����
	string s[110];
	int m = 0;


	scanf_s("%d", &n);//ע�⴫�����c ������c-'0';

	int w[20] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
	char jh[15] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2' };

	bool flag = true;

	for (int i = 0; i < n; i++){//��ѭ���������ݾ�ֻ�����һ����
		scanf_s("%s", str);
		for (j = 0; j < 17; j++){
			if (str[j] <= '0'&&str[j] >= '9'){//���䲹������Ϊ�����ж��֣����Ǵ���ʽ��һ��
				flag = false;

				break;//�����;�������룬������ֱ������ѭ������ʱ�����Ĳ�ͬ��  j<16;
			}
			sum += w[j] * (str[j] - '0');//��ȷ��ֻ��һ��  			
		}
		if (j < 16){
			flag = false;
			s[m++] = str;
			//printf("%s\n", str);
		}
		else if (jh[sum % 11] != str[17]){
			flag = false;
			s[m++] = str;
			//printf("%s\n", str);
		}
	}
	for (int k = 0; k<m; k++){
		printf("%s\n", s[k]);
	}
	if (flag){
		printf("All passed\n");
	}
}

//λ--������--��λ��str[i]-'0',����ȡ�࣬bit[num++]���棬Ȼ�������i=[num-1,0:1],if(i>0) ��ӡ�� �� else��ӡ��\n��
char strNum[110];
int sumNum[10];
//ע�������Ӧ���á������ַ����� ���ǡ������ַ���
char change1[10][5] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
void bit2num(){
	int sum=0,j=0;
	gets_s(strNum);//���������ڸ�ֵ
	int len = strlen(strNum);
	for ( int i = 0; i < len; i++){
		sum += strNum[i] - '0';
	}
	while (sum!=0){
		sumNum[j++] = sum % 10;
		sum /= 10;
	}
	for (int k = j-1; k >=0 ;k--){
		int index = sumNum[k];
		printf("%s", change1[index]);
		if (k>0){
			printf(" ");
		}
		else{
			printf("\n");
		}
	}
}

int main(){
	//countCalazNum();
	
	//fenleiAdd();

	//chazaotest();

	//typesqaretest();

	//jzchange();

	//huiziwen();

	//suofanhua();

	//judgeABC();

	//bitNumAdd();

	//calctime();

	//hejiu();

	//arrayMoveR();

	//qiudao();

	//jian2zhichazao();

	//structmax();

	//triangleType();

	//jingzhichange();

	//formatNum();

	//tongjisuzhu();

	//idcardtest();

	bit2num();
	getchar();
	return 0;

}