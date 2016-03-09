#include "polinom.h"

void main()
{
	int a;
	Polinom p1;
	setlocale(LC_ALL, "Russian");
	cout<<"введите полином"<<endl;
	cin>>p1;
	do
	{
		cout<<"для сложение введите 1"<<endl;
		cout<<"для вычитание введите 2"<<endl;
		cout<<"для умножение введите 3"<<endl;
		Polinom p2,p3;
		do
		{
			cin>>a;
		}
		while((a!=1)&&(a!=2)&&(a!=3));
		cout<<"введите полином"<<endl;
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
		cout<<"для прекращения операции с полученным полиномом введите 0"<<endl;
		cin>>a;
	}
	while(a!=0);
}