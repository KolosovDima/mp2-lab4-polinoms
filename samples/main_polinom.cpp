#include "polinom.h"

void main()
{
	int a;
	Polinom p1;
	setlocale(LC_ALL, "Russian");
	cout<<"������� �������"<<endl;
	cin>>p1;
	do
	{
		cout<<"��� �������� ������� 1"<<endl;
		cout<<"��� ��������� ������� 2"<<endl;
		cout<<"��� ��������� ������� 3"<<endl;
		Polinom p2,p3;
		do
		{
			cin>>a;
		}
		while((a!=1)&&(a!=2)&&(a!=3));
		cout<<"������� �������"<<endl;
		cin>>p2;
		if (a==1)
		{
			p3=p1;
			p1=p3+p2;
		}
		else if (a==2)
			p1=p1-p2;
		else 
			p1=p1*p2;
		cout<<p1;
		cout<<"��� ����������� �������� � ���������� ��������� ������� 0"<<endl;
		cin>>a;
	}
	while(a!=0);
}