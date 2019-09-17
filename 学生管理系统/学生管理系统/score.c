/*************************************************
** 源文件   : score.c
** 功能说明 : Function Definitions
** 创建版本 : V1.0
/**************************************************/

/*----------------头文件--------------*/
#define  _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "SCORE.h"

/*----------------函数定义-------------*/

//1.1手动输入学生基本数据
void readData(SS stu[], int N)
{

	printf("请按照如下格式输入学生信息：学号,姓名,平时成绩,期末成绩\n");

	for (int i = 0; i < N; i++)
	{
		printf("第%d个学生:", i + 1);
		scanf("%s %s %f %f", &stu[i].number, &stu[i].name, &stu[i].dailyScore, &stu[i].finalScore);
		printf("\n");
	}

	printf("------成绩录入完毕!--------\n");

}

//1.2从文件里读取学生基本数据
SS* readDataFromFile(int *N)
{

	printf("\n\n------第一步: 从文件读取学生的成绩信息--------\n\n");

	SS *stu;// 开辟新空间,存取文件中的每个学生信息

	FILE *fp = NULL;
	int count = 0;
	int index = 0;

	fp = fopen("data.txt", "r");

	//1.获取学生数目
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

	printf("学生数目为:%d\n", count);


	//2.给所有学生分配存储空间
	stu = (SS*)malloc(count * sizeof(SS));


	//3.读取每条学生的信息
	while ((!feof(fp)))
	{

		//读入文件数据到内存	
		fscanf(fp, "%s%s%f%f%f\n", (stu[index].number), (stu[index].name), &stu[index].dailyScore,&stu[index].experiScore, &stu[index].finalScore);

		//输出排序后的学生信息
		printf("* 学号：%s	姓名:%s		平时成绩：%4.2f分		期末成绩:%4.2f分\n", (stu[index].number), (stu[index].name), stu[index].dailyScore, stu[index].finalScore);

		index++;
	}

	getchar();

	fclose(fp);

	return stu;
}
//2.计算N个学生各自的总评成绩
void calcuScore(SS stu[], int N)
{


	printf("\n\n------第二步: 计算每个学生的总评成绩--------\n\n");

	for (int i = 0; i < N; i++)
	{

		stu[i].generalScore = 0.2*stu[i].dailyScore + 0.8*stu[i].finalScore;
		printf("* 学号：%s	姓名:%s		总成绩:%4.2f分\n", (stu[i].number), (stu[i].name), stu[i].generalScore);

	}

	getchar();
}


//3.根据总评成绩排名
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

//4.按照一定的格式输出N个学生的信息
void printOut(SS stu[], int N)
{

	printf("\n------第三步: 根据总成绩输出学生排名信息!------\n\n");

	for (int i = 0; i < N; i++)
	{

		printf("第%d名信息 学号：%s	 姓名:%s		总成绩:%4.2f分\n", i + 1, &(stu[i].number[0]), &(stu[i].name[0]), stu[i].generalScore);
	}

	getchar();

}
//5.输入学号查询学生成绩
void cx(SS stu[], int N)
{
	printf("\n------第四步: 根据学号查询学生成绩!------\n\n");
	char a[10];
	printf("请输入要查询的学生学号:\n");
	scanf("%s",a);
	for (int i = 0; i < N; i++)
	{
		if (strcmp(a, stu[i].number) == 0)
			printf("学号：%s 姓名:%s	平时成绩：%4.2f分	实验成绩：%4.2f分 期末成绩:%4.2f分\n", stu[i].number, stu[i].name, stu[i].dailyScore, stu[i].experiScore, stu[i].finalScore);
	}
}
//6.分析均值及方差
void average(SS stu[], int N)
{
	printf("\n------第五步:计算全班学生的成绩均值及方差------\n\n");
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
	printf("全班学生的平均日常成绩是%f，全班学生日常成绩的方差是%f\n全班学生的平均实验成绩是%f，全班学生实验成绩的方差是%f \n全班学生的平均期末成绩是%f，全班学生期末成绩的方差是%f \n全班学生的平均综合成绩是%f，全班学生综合成绩的方差是%f ", b1,d1,b2,d2,b3,d3,b4,d4);
	printf("对该班级的成绩分布做简要分析：\n");
	printf("该班级同学期末成绩较高，实验成绩较低；\n");
	printf("该班级同学的期末成绩分布不稳定差距较大，实验成绩与综合成绩较稳定，日常成绩最为稳定！\n");
}
