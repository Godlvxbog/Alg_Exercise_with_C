#include <cstdio> 
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
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%s%s%d",s_temp.name,s_temp.id,&s_temp.score);
		if (s_temp.score<s_min.score){
			s_min = s_temp;//������ֱ�Ӱѵ�ǰѧ����Ϊ����ѧ������������������Ȼ�޷��õ��������������id 
		}
		if (s_temp.score>s_max.score){
			s_max = s_temp;
		}

	}
	printf("%s %s\n", s_max.name, s_max.id);
	printf("%s %s\n", s_min.name, s_min.id);

}

int main(){
	structmax(); 
	return 0;
}
