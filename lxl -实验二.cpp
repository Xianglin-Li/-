#include<iostream>
using namespace std;
#include<cmath>
void jfc(float a, float b, float c)
{
	float s, x1, x2;
	s = b * b - 4 * a*c;
	if (s < 0)
	{
		cout << "�˷����޽�" << endl;
	}
	else if (s == 0)
	{
		x1 = (-1 * b + sqrt(s)) / (2 * a);
		cout << "�˷�����������ͬ��Ϊ��x1=x2=" << x1 << endl;
	}
	else
	{
		x1 = (-1 * b + sqrt(s)) / (2 * a);
		x2 = (-1 * b - sqrt(s)) / (2 * a);
		cout << "�˷�����������ͬ�ĸ��ֱ�Ϊ��x1=" << x1 << "x2=" << x2 << endl;
	}
}
void mj(float m,float r,float p)
{
    float d,q;
	d=(m+r+p)/2;
     q=sqrt(d*(d-m)*(d-r)*(d-p));
	 cout<<"�����ε����Ϊ:"<<q<<endl;
}
void pd(int day,int month,int year)
{
	int sum,l;
	if(year/4==0||year/400==0)
	{
		switch(month)
		{
		case 1:sum=0;break;
		case 2:sum=31;break;
		case 3:sum=60;break;
		case 4:sum=91;break;
		case 5:sum=121;break;
		case 6:sum=152;break;
		case 7:sum=182;break;
		case 8:sum=213;break;
		case 9:sum=244;break;
		case 10:sum=274;break;
		case 11:sum=305;break;
		case 12:sum=335;break;
		}
		sum=sum+day;
	}
	else
	{
           switch(month)
		{
		case 1:sum=0;break;
		case 2:sum=31;break;
		case 3:sum=59;break;
		case 4:sum=90;break;
		case 5:sum=120;break;
		case 6:sum=151;break;
		case 7:sum=181;break;
		case 8:sum=212;break;
		case 9:sum=243;break;
		case 10:sum=273;break;
		case 11:sum=304;break;
		case 12:sum=334;break;
		}
		sum=sum+day;
	}
	cout<<"�����ǽ���ĵ�"<<sum<<"��"<<endl;
    l=(sum/7)+1;
	cout<<"�����ǽ���ĵ�"<<l<<"��"<<endl;
}
int main()
{
	float a, b, c,m,r,p;
	cout << "�����뷽�̵�ϵ��" << endl;
	cin  >> a >>  b >> c;
	jfc(a, b, c);
	cout<<endl<<"�����������εı߳�"<<endl;
	cin>>m>>r>>p;
	mj(m,r,p);
    	int day,month,year;
	cout<<"������Ҫ�жϵ�����:"<<endl;
	cin>>year>>month>>day;
	pd(day,month,year);
	return 0;

}