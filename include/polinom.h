// класс Полином - упорядоченный односвязный список Мономов
// поддерживает операции Печать, Вставка монома, Удаление монома,  
// Поиск монома, Сложение полиномов(слияние упорядоченных списков), 
// Умножение полиномов
#include <iostream>
#include "monom.h"
using namespace std;
#ifndef __LIST_H__
#define __LIST_H__
template <class T>
class List
{
	private:
		T pData;
		List *nextpList;
	public:
		~List(){};
		List(){pData=T();nextpList=0;};
		List(List<T> &now);
		List(T &pData_new,List *nextpList_new){pData=pData_new; nextpList=nextpList_new;};
		T& GetData(){return pData;};
		void SetData(T &pData_new){pData=pData_new;};
		List<T>* GetPointerList(){return nextpList;};
		void SetPointerList(List *nextpList_new){nextpList=nextpList_new;};
		List<T>& operator=( List &List_new);
		
};
template <class T>
List<T>::List(List<T> &now)
{
	pData=now.GetData();
	nextpList=now.GetPointerList();
}
template <class T>
List<T>& List<T>::operator =(List<T> &List_new)
{
	pData=List_new.GetData();
	return *this;
}
class Polinom
{
public:
	
	List<Monom> *Head;
	Polinom();
	~Polinom();
	void SetListFirst(List<Monom> *list_new);//+
	void DeletFirst();//+
	void SetListMid(List<Monom> *list_new,List<Monom> *list_old);
	void SetListMidh(List<Monom> *list_new);
	void DeletMid(List<Monom> *list_old);//+
	void Deletpolinom();//+
	Polinom& operator+( Polinom &PL_Add);
	Polinom& operator*( Polinom &PL_Add);
	Polinom& operator-( Polinom &PL_Add);
	Polinom& operator=( Polinom &PL_Add);
friend istream& operator>>(istream &in, Polinom &mt)
  {
	 setlocale(LC_ALL, "Russian");
	bool ToF=false;
	double s;
	int a,b,c,d;
	List<Monom> *h=mt.Head;
	while (ToF!=true)
	{
		List<Monom> nw;
		cout<<" аргупент"<<endl;
		in>>s;
		cout<<" степень х"<<endl;
		in>>a;
		cout<<" степень у"<<endl;
		in>>b;
		cout<<" степень z"<<endl;
		in>>c;
		nw.GetData().SetFactor(s);
		nw.GetData().SetPower(a,b,c);
		mt.SetListMidh(&nw);
		h=(*h).GetPointerList();
		do
		{
		cout<<" добавить моном? 1-да 0-нет"<<endl;
		in>>d;
		}
		while((d!=0)&&(d!=1));
		if (d==0)
			ToF=true;
	}
	if ((*(mt.Head)).GetData().GetFactor()==0)
		mt.DeletFirst();
    return in;
  }
  friend ostream & operator<<( ostream &out, const Polinom &mt)
  {
	   setlocale(LC_ALL, "Russian");
	  List<Monom> *nw;
	  nw=mt.Head;
	  while(nw!=0)
	  {
		  out <<"+("<< (*nw).GetData().GetFactor()<<")"<<"x^"<<(*nw).GetData().GetPower()/100 << "y^"<<(*nw).GetData().GetPower()/10%10 <<"z^"<<(*nw).GetData().GetPower()%10;
		  nw=(*nw).GetPointerList();
	  }
    return out;
  }
};
#endif

