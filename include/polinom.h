// класс Полином - упорядоченный односвязный список Мономов
// поддерживает операции Печать, Вставка монома, Удаление монома,  
// Поиск монома, Сложение полиномов(слияние упорядоченных списков), 
// Умножение полиномов

#include "monom.h"
#ifndef __LIST_H__
#define __LIST_H__
template <class T>
class List
{
	private:
		T *pData;
		List *nextpList;
	public:
		List(){pData=NULL;nextpList=NULL;};
		List(List<T> &now);
		List(T *pData_new,List *nextpList_new){pData=pData_new; nextpList=nextpList_new;};
		T* GetPointerData(){return pData;};
		void SetPointerData(T *pData_new){pData=pData_new;};
		List<T>* GetPointerList(){return nextpList;};
		void SetPointerList(List *nextpList_new){nextpList=nextpList_new;};
		List<T>& operator=( List &List_new);
		
};
template <class T>
List<T>::List(List<T> &now)
{
	pData=now.GetPointerData();
	nextpList=now.GetPointerList();
}
template <class T>
List<T>& List<T>::operator =(List<T> &List_new)
{
	pData=List_new.GetPointerData();
	nextpList=List_new.GetPointerList();
	return *this;
}
#endif

