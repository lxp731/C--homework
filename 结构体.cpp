//�Զ���һ���µĽṹ�����ͣ�
//Ҫ�����ٰ������³�Ա��ѧ����ѧ�š����������䡢�༶��4�ſγ̵ĳɼ����ܳɼ���
#include<stdio.h>
struct student
{
	int num; 
	char name[20];
	int age,clas;
	int yw,sx,yy,lz,sum;
 }; 
 int main()
 {
 	int i,w;
 	printf("��Ҫ���ܶ��ٸ��˵���Ϣ��\n");
 	scanf("%d",&w);
 	struct student stu[w];
 	for(i=0;i<w;i++)
 	{
 		printf("��ֱ������%d���˵�\n",i+1);
 		printf("ѧ�� ���� ���� �༶ 4�ſγ̵ĳɼ�\n"); 
 	    
		 scanf("%d %s %d %d %d %d %d %d",&stu[i].num,&stu[i].name,
		 &stu[i].age,&stu[i].clas,&stu[i].yw,&stu[i].sx,&stu[i].yy,&stu[i].lz);
	   
	    stu[i].sum=stu[i].yw+stu[i].sx+stu[i].yy+stu[i].lz;
	}
	printf("ѧ�� ����  ����  �༶ 4�ſγ̵ĳɼ� �ܳɼ�\n");
	for(i=0;i<w;i++)
	
	printf("%d    %s  %d    %d  %d  %d  %d  %d   %d\n",stu[i].num,stu[i].name,
	stu[i].age,stu[i].clas,stu[i].yw,stu[i].sx,stu[i].yy,stu[i].lz,stu[i].sum);
 
 	return 0;
 }
 
//#include<stdio.h>
//struct student
//{
//int num;
//char name[20];
//float score1,score2,sum,average;
//};
//int main()
//{
//struct student stu[5];
//int i;
//for(i=0;i<5;i++)
//{
//printf("�����������%d��ѧ����ѧ�ţ������������ųɼ���",i+1);
//scanf("%d%s%f%f",&stu[i].num,stu[i].name,&stu[i].score1,&stu[i].score2);
//stu[i].sum=stu[i].score1+stu[i].score2;
//stu[i].average=stu[i].sum/2;
//}
//printf("ѧ�� ���� �ɼ� �ܳɼ� ƽ���ɼ�\n");
//for(i=0;i<5;i++)
//printf("%d %s %.2f %.2f %.2f %.2f\n",
//stu[i].num,stu[i].name,stu[i].score1,stu[i].score2,stu[i].sum,stu[i].average);
//return 0;
//}



