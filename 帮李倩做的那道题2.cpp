#include<stdio.h>
int main()
{
	int a;

	printf("1.��ӻ�Ա��Ϣ\n");
	printf("2.��ѯ��Ա��Ϣ\n");
	printf("3.ɾ����Ա��Ϣ\n");
	printf("4.��Աͳ��\n");
	printf("5.�޸Ļ�Ա��Ϣ\n");
	printf("\n");
	printf("������еĲ���"); 
	scanf("%d",&a); 
	struct VIP
	{
		int num;
		char name[20],type;
	};	
	struct VIP lq;
	switch(a)
	{
		case 1:	
			const char* filename "E:\VIP\��ٻ.txt";
			FILE* xp = fopen(filename,"wb");
		if(xp==NULL)
		{
			printf("failed to open file!\n");
			return -1;
		}
		char x[];
		scanf("%s",&x);
		fwrite(x,1,25,xp);
		
		fclose(xp);
		break;
		case 2:  ;//������� �������ļ���Ϣ�� 
		break;
		case 3:  ;//���� ��ɾ����Ӧ���ļ���
		break;
		case 4:  ;// ��forѭ������ 
		break;
		case 5:  ;//�ʱ��˰� ��ûѧ���� 
		break;    
	}
	return 0;
}

