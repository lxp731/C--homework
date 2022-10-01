//自定义一个新的结构体类型，
//要求至少包含以下成员：学生的学号、姓名、年龄、班级、4门课程的成绩、总成绩。
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
 	printf("你要汇总多少个人的信息？\n");
 	scanf("%d",&w);
 	struct student stu[w];
 	for(i=0;i<w;i++)
 	{
 		printf("请分别输入第%d个人的\n",i+1);
 		printf("学号 姓名 年龄 班级 4门课程的成绩\n"); 
 	    
		 scanf("%d %s %d %d %d %d %d %d",&stu[i].num,&stu[i].name,
		 &stu[i].age,&stu[i].clas,&stu[i].yw,&stu[i].sx,&stu[i].yy,&stu[i].lz);
	   
	    stu[i].sum=stu[i].yw+stu[i].sx+stu[i].yy+stu[i].lz;
	}
	printf("学号 姓名  年龄  班级 4门课程的成绩 总成绩\n");
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
//printf("请依次输入第%d个学生的学号，姓名，和两门成绩：",i+1);
//scanf("%d%s%f%f",&stu[i].num,stu[i].name,&stu[i].score1,&stu[i].score2);
//stu[i].sum=stu[i].score1+stu[i].score2;
//stu[i].average=stu[i].sum/2;
//}
//printf("学号 姓名 成绩 总成绩 平均成绩\n");
//for(i=0;i<5;i++)
//printf("%d %s %.2f %.2f %.2f %.2f\n",
//stu[i].num,stu[i].name,stu[i].score1,stu[i].score2,stu[i].sum,stu[i].average);
//return 0;
//}



