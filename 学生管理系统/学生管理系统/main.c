#define  _CRT_SECURE_NO_WARNINGS

/*************************************************
** ���� : ѧ���ɼ�����ϵͳ
** ���� : Qingke Zhang/tsingke@sdnu.edu.cn
** ��Ȩ : GNU General Public License(GNU GPL)
/**************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "score.h"

/*----------------------------------*
		Main Function
*-----------------------------------*/

int main()
{

	printf("******************************\n");
	printf("       ѧ���ɼ��������ϵͳ        \n");
	printf("         Qingke Zhang            \n");
	printf("******************************\n\n");

	/*-1.������ʼ��-*/
	int N = 0;            //ѧ������
	SS  *pstu = NULL;    //ѧ������-�ṹ������ָ��ʵ��

	//2.��ȡѧ����Ϣ
	pstu = readDataFromFile(&N);

	/*-3.����ѧ���ܳɼ����ܳɼ� = 0.3*ƽʱ�ɼ� + 0.8*��ĩ�ɼ�)--*/
	calcuScore(pstu, N);

	/*-4.����ѧ���ɼ�����-*/
	sortScore(pstu, N);

	/*-5.�����������ѧ����Ϣ-*/
	printOut(pstu, N);

	/*-6.����ѧ�Ų�ѯ�ɼ�*/
	cx(pstu, N);

	/*-7����ȫ��ͬѧ��ƽ���ɼ��ͷ���*/
	average(pstu, N);

	/*-8.�ͷŶ�̬�ڴ�ռ�-*/
	free(pstu);


	system("pause");
	return 0;
}
