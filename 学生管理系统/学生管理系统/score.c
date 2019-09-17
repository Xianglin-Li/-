/*************************************************
** Դ�ļ�   : score.c
** ����˵�� : Function Definitions
** �����汾 : V1.0
/**************************************************/

/*----------------ͷ�ļ�--------------*/
#define  _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "SCORE.h"

/*----------------��������-------------*/

//1.1�ֶ�����ѧ����������
void readData(SS stu[], int N)
{

	printf("�밴�����¸�ʽ����ѧ����Ϣ��ѧ��,����,ƽʱ�ɼ�,��ĩ�ɼ�\n");

	for (int i = 0; i < N; i++)
	{
		printf("��%d��ѧ��:", i + 1);
		scanf("%s %s %f %f", &stu[i].number, &stu[i].name, &stu[i].dailyScore, &stu[i].finalScore);
		printf("\n");
	}

	printf("------�ɼ�¼�����!--------\n");

}

//1.2���ļ����ȡѧ����������
SS* readDataFromFile(int *N)
{

	printf("\n\n------��һ��: ���ļ���ȡѧ���ĳɼ���Ϣ--------\n\n");

	SS *stu;// �����¿ռ�,��ȡ�ļ��е�ÿ��ѧ����Ϣ

	FILE *fp = NULL;
	int count = 0;
	int index = 0;

	fp = fopen("data.txt", "r");

	//1.��ȡѧ����Ŀ
	if (fp != NULL)
	{
		fscanf(fp, "%d", &count);
		*N = count;
	}
	else
	{
		printf("failed to open the info file\n");
		getchar();
	}

	printf("ѧ����ĿΪ:%d\n", count);


	//2.������ѧ������洢�ռ�
	stu = (SS*)malloc(count * sizeof(SS));


	//3.��ȡÿ��ѧ������Ϣ
	while ((!feof(fp)))
	{

		//�����ļ����ݵ��ڴ�	
		fscanf(fp, "%s%s%f%f%f\n", (stu[index].number), (stu[index].name), &stu[index].dailyScore,&stu[index].experiScore, &stu[index].finalScore);

		//���������ѧ����Ϣ
		printf("* ѧ�ţ�%s	����:%s		ƽʱ�ɼ���%4.2f��		��ĩ�ɼ�:%4.2f��\n", (stu[index].number), (stu[index].name), stu[index].dailyScore, stu[index].finalScore);

		index++;
	}

	getchar();

	fclose(fp);

	return stu;
}
//2.����N��ѧ�����Ե������ɼ�
void calcuScore(SS stu[], int N)
{


	printf("\n\n------�ڶ���: ����ÿ��ѧ���������ɼ�--------\n\n");

	for (int i = 0; i < N; i++)
	{

		stu[i].generalScore = 0.2*stu[i].dailyScore + 0.8*stu[i].finalScore;
		printf("* ѧ�ţ�%s	����:%s		�ܳɼ�:%4.2f��\n", (stu[i].number), (stu[i].name), stu[i].generalScore);

	}

	getchar();
}


//3.���������ɼ�����
int cmpBigtoSmall(const void *a, const void *b)
{

	SS *aa = (SS *)(a);
	SS *bb = (SS *)(b);



	if ((*aa).generalScore < (*bb).generalScore)  return 1;

	else if ((*aa).generalScore > (*bb).generalScore)  return -1;

	else
		return 0;

}

void sortScore(SS stu[], int N)
{

	qsort(&(stu[0]), N, sizeof(stu[0]), cmpBigtoSmall);

}

//4.����һ���ĸ�ʽ���N��ѧ������Ϣ
void printOut(SS stu[], int N)
{

	printf("\n------������: �����ܳɼ����ѧ��������Ϣ!------\n\n");

	for (int i = 0; i < N; i++)
	{

		printf("��%d����Ϣ ѧ�ţ�%s	 ����:%s		�ܳɼ�:%4.2f��\n", i + 1, &(stu[i].number[0]), &(stu[i].name[0]), stu[i].generalScore);
	}

	getchar();

}
//5.����ѧ�Ų�ѯѧ���ɼ�
void cx(SS stu[], int N)
{
	printf("\n------���Ĳ�: ����ѧ�Ų�ѯѧ���ɼ�!------\n\n");
	char a[10];
	printf("������Ҫ��ѯ��ѧ��ѧ��:\n");
	scanf("%s",a);
	for (int i = 0; i < N; i++)
	{
		if (strcmp(a, stu[i].number) == 0)
			printf("ѧ�ţ�%s ����:%s	ƽʱ�ɼ���%4.2f��	ʵ��ɼ���%4.2f�� ��ĩ�ɼ�:%4.2f��\n", stu[i].number, stu[i].name, stu[i].dailyScore, stu[i].experiScore, stu[i].finalScore);
	}
}
//6.������ֵ������
void average(SS stu[], int N)
{
	printf("\n------���岽:����ȫ��ѧ���ĳɼ���ֵ������------\n\n");
	double a1=0,b1,c1=0,d1,
		a2=0,b2,c2=0,d2,
		a3=0,b3,c3=0,d3,
		a4=0,b4,c4=0,d4;
	for (int i = 0; i < N; i++)
	{
		a1= a1 + stu[i].dailyScore;
		a2 = a2 + stu[i].experiScore;
		a3 = a3+ stu[i].finalScore;
		a4= a4 + stu[i].generalScore;
	}
	b1 = a1 / N;
	b2= a2 / N;
	b3 = a3 / N;
	b4= a4 / N;
	for (int i = 0; i < N; i++)
	{
		c1 = c1 + ((stu[i].dailyScore - b1)*(stu[i].dailyScore - b1));
		c2 = c2 + ((stu[i].experiScore - b2)*(stu[i].experiScore - b2));
		c3 = c3 + ((stu[i].finalScore - b3)*(stu[i].finalScore - b3));
		c4 = c4 + ((stu[i].generalScore - b4)*(stu[i].generalScore - b4));
	}
	d1 = c1 / N;
	d2 = c2 / N;
	d3 = c3 / N;
	d4 = c4 / N;
	printf("ȫ��ѧ����ƽ���ճ��ɼ���%f��ȫ��ѧ���ճ��ɼ��ķ�����%f\nȫ��ѧ����ƽ��ʵ��ɼ���%f��ȫ��ѧ��ʵ��ɼ��ķ�����%f \nȫ��ѧ����ƽ����ĩ�ɼ���%f��ȫ��ѧ����ĩ�ɼ��ķ�����%f \nȫ��ѧ����ƽ���ۺϳɼ���%f��ȫ��ѧ���ۺϳɼ��ķ�����%f ", b1,d1,b2,d2,b3,d3,b4,d4);
	printf("�Ըð༶�ĳɼ��ֲ�����Ҫ������\n");
	printf("�ð༶ͬѧ��ĩ�ɼ��ϸߣ�ʵ��ɼ��ϵͣ�\n");
	printf("�ð༶ͬѧ����ĩ�ɼ��ֲ����ȶ����ϴ�ʵ��ɼ����ۺϳɼ����ȶ����ճ��ɼ���Ϊ�ȶ���\n");
}
