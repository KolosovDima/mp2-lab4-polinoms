#include "polinom.h"
using namespace std;
Polinom::Polinom()
{
	Head=&first;
}
Polinom::~Polinom()
{
}
void Polinom::SetListFirst(List<Monom> *list_new)//переделать
{
	List<Monom> *Head_new=new List<Monom>();
	Head_new=list_new;
	(*this).SetListMid(Head,Head);
	first.SetData((*Head_new).GetData());
}
void Polinom::DeletFirst()
{
	List<Monom> *Head_nd2=Head;
	Head=first.GetPointerList();
	first=*Head;
	first.SetPointerList((*Head).GetPointerList());
}
void Polinom::Deletpolinom()
{
	do
	{
		DeletFirst();
	}
	while(Head!=0);
}
void Polinom::DeletMid(List<Monom> *list_old)
{
	List<Monom> *midpoint;
	midpoint=(*list_old).GetPointerList();
	(*list_old).SetPointerList((*(*list_old).GetPointerList()).GetPointerList());
}
void Polinom::SetListMid(List<Monom> *list_new,List<Monom> *list_old)
{
	List<Monom> *Li =new List<Monom>();
	(*Li)=(*list_new);
	(*Li).SetPointerList((*list_old).GetPointerList());
	(*list_old).SetPointerList(Li);
}
void Polinom::SetListMidh(List<Monom> *list_new)
{
	List<Monom> *Lr;
	List<Monom> *Lh;
	List<Monom> *Li =new List<Monom>();
	Lr=Lh=Head;
	(*Li)=(*list_new);
	while ((Lh!=0)&&((*Lh).GetData().GetPower()<(*list_new).GetData().GetPower()))
	{
		if(Lr!=Lh)
			Lr=(*Lr).GetPointerList();
		Lh=(*Lh).GetPointerList();
	}
	if ((*Lr).GetData().GetPower()==(*list_new).GetData().GetPower())
	{
		(*Li)=(*list_new);
		(*Li).GetData().SetFactor((*Li).GetData().GetFactor()+(*Lh).GetData().GetPower());
		if ((*Li).GetData().GetFactor()>0.000000001)
		{
				(*Li).SetPointerList((*Lr).GetPointerList());
				(*Lr).SetPointerList(Li);
		}
	}
	else
	{
	(*Li)=(*list_new);
	(*Li).SetPointerList((*Lr).GetPointerList());
	(*Lr).SetPointerList(Li);
	}
}
Polinom Polinom::operator+( Polinom &PL_Add)
{
	Polinom p_n;
	List<Monom> *k1,*k2,*beta;
	k1=Head;
	beta=p_n.Head;
	k2=PL_Add.Head;
	while ((k1!=0)&&(k2!=0))
	{
		if ((*k1).GetData().GetPower()>(*k2).GetData().GetPower())
		{
			p_n.SetListMid(k2,beta);
			beta=(*beta).GetPointerList();
			k2=(*k2).GetPointerList();
		}
		else if ((*k1).GetData().GetPower()<(*k2).GetData().GetPower())
		{
			p_n.SetListMid(k1,beta);
			beta=(*beta).GetPointerList();
			k1=(*k1).GetPointerList();
		}
		else
		{
			List<Monom> sum(*k1);
			sum.GetData().SetFactor(sum.GetData().GetFactor()+(*k2).GetData().GetFactor());
			if (sum.GetData().GetFactor()<0.000000001)
			{
				k1=(*k1).GetPointerList();
				k2=(*k2).GetPointerList();
			}
			else
			{
				p_n.SetListMid(&sum,beta);
				k1=(*k1).GetPointerList();
				k2=(*k2).GetPointerList();
				beta=(*beta).GetPointerList();
			}
		}
	}
	while (k1!=0)
	{
			p_n.SetListMid(k1,beta);
			beta=(*beta).GetPointerList();
			k1=(*k1).GetPointerList();
	}
	while (k2!=0)
	{	
			p_n.SetListMid(k2,beta);
			beta=(*beta).GetPointerList();
			k2=(*k2).GetPointerList();
	}
	if ((p_n.first.GetData().GetFactor()==0)&&(p_n.first.GetPointerList()!=0))
		p_n.DeletFirst();
	return p_n;
}
Polinom Polinom::operator-( Polinom &PL_Add)
{
	Polinom p_n;
	List<Monom> *k1,*k2,*beta;
	k1=Head;
	beta=p_n.Head;
	k2=PL_Add.Head;
	while ((k1!=0)&&(k2!=0))
	{
		if ((*k1).GetData().GetPower()>(*k2).GetData().GetPower())
		{
			p_n.SetListMid(k2,beta);
			beta=(*beta).GetPointerList();
			k2=(*k2).GetPointerList();
		}
		else if ((*k1).GetData().GetPower()<(*k2).GetData().GetPower())
		{
			p_n.SetListMid(k1,beta);
			beta=(*beta).GetPointerList();
			k1=(*k1).GetPointerList();
		}
		else
		{
			List<Monom> sum(*k1);
			sum.GetData().SetFactor(sum.GetData().GetFactor()-(*k2).GetData().GetFactor());
			if (sum.GetData().GetFactor()<0.000000001)
			{
				k1=(*k1).GetPointerList();
				k2=(*k2).GetPointerList();
			}
			else
			{
				p_n.SetListMid(&sum,beta);
				k1=(*k1).GetPointerList();
				k2=(*k2).GetPointerList();
				beta=(*beta).GetPointerList();
			}
		}
	}
	while (k1!=0)
	{
			p_n.SetListMid(k1,beta);
			beta=(*beta).GetPointerList();
			k1=(*k1).GetPointerList();
	}
	while (k2!=0)
	{	
			p_n.SetListMid(k2,beta);
			beta=(*beta).GetPointerList();
			k2=(*k2).GetPointerList();
	}
	if ((p_n.first.GetData().GetFactor()==0)&&(p_n.first.GetPointerList()!=0))
		p_n.DeletFirst();
	return p_n;
}
Polinom Polinom:: operator*( Polinom &PL_Add)
{
	Polinom p_n;
	List<Monom> *k1,*k2,*beta2,beta;
	k1=Head;
	k2=PL_Add.Head;
	while (k1!=0)
	{
		Polinom sum,sum2;
		sum.first.SetData((*k1).GetData());
		beta2=sum2.Head;
		k2=PL_Add.Head;
			while (k2!=0)
			{
				beta.GetData().SetFactor((*k1).GetData().GetFactor()*(*k2).GetData().GetFactor());
				if (beta.GetData().GetFactor()>0.0000001)
				{
					try
					{
						beta.GetData().SetPower((*k1).GetData().GetPower()/100+(*k2).GetData().GetPower()/100,((*k1).GetData().GetPower()/10)%10+((*k2).GetData().GetPower()/10)%10,(*k1).GetData().GetPower()%10+(*k2).GetData().GetPower()%10);
					}
					catch(...)
					{
						cout << "ошибка сепень выше 9 , полином не корректен"<< endl;
						return p_n;
					}
					sum2.SetListMidh(&beta);
					beta2=&beta;
				}
				k2=(*k2).GetPointerList();
			}
		p_n=p_n+sum2;
		k1=(*k1).GetPointerList();
	}
	if ((p_n.first.GetData().GetFactor()==0)&&(p_n.first.GetPointerList()!=0))
		p_n.DeletFirst();
	return p_n;
}