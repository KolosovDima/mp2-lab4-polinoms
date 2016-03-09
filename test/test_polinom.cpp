#include <gtest.h>
#include "polinom.h"
#include "monom.h"
// тесты мономов и полиномов
TEST(Monom, can_create_Monom_with_power_less_that_9)
{
ASSERT_NO_THROW (Monom st(3,1,2,3));
}
TEST(Monom, can_create_Monom_with_power_more_that_9)
{
ASSERT_ANY_THROW (Monom st(3,1,10,3));
}
TEST(Monom, can_create_Monom_with_power_less_that_0)
{
ASSERT_ANY_THROW (Monom st(3,1,-2,3));
}
TEST(Monom, can_read_factor)
{
	Monom m(3,1,2,3);
	
	EXPECT_EQ(3,m.GetFactor());
}
TEST(Monom, can_set_factor)
{
	Monom m(3,1,2,3);
	m.SetFactor(5.7);
	EXPECT_EQ(5.7 , m.GetFactor());
}
TEST(Monom, can_read_power)
{
	Monom m(3,1,2,3);
	
	EXPECT_EQ(123,m.GetPower());
}
TEST(Monom, can_set_power)
{
	Monom m(3,1,2,3);
	m.SetPower(5,7,2);
	EXPECT_EQ(572 , m.GetPower());
}
TEST(Monom, can_copied_monom)
{
	Monom m(3,1,2,3);
	Monom m2(m);
	EXPECT_EQ(123 , m2.GetPower());
	EXPECT_EQ(3 , m2.GetFactor());
}
TEST(Monom, can_assign_monom)
{
	Monom m(3,1,2,3);
	Monom m2(7.5,4,7,8);
	m2=m;
	EXPECT_EQ(123 , m2.GetPower());
	EXPECT_EQ(3 , m2.GetFactor());
}
TEST(List, can_create_List)
{
	ASSERT_NO_THROW (List<int> st);
}
TEST(List, can_create_List_with_Monom_and_Pointer)
{
	Monom m(3,1,2,3);
	List<Monom> s;
	ASSERT_NO_THROW (List<Monom> st(m,&s));
}
TEST(List, can_Get_pointer_data)
{
	int a;
	a=3;
	List<int>s2;
	List<int> s(a,&s2);
	EXPECT_EQ(3,s.GetData());
}
TEST(List, can_Set_pointer_data)
{
	int a,b;
	b=3;
	a=7;
	List<int>s2;
	List<int>s(b,&s2);
	s.SetData(a);
	EXPECT_EQ(7,s.GetData());
}
TEST(List, can_Get_pointer_List)
{
	int a;
	a=3;
	List<int>s2;
	List<int> s(a,&s2);
	EXPECT_EQ(&s2,s.GetPointerList());
}
TEST(List, can_Set_pointer_List)
{
	int b;
	b=3;
	List<int>s2;
	List<int>s3;
	List<int>s(b,&s2);
	s.SetPointerList(&s3);
	EXPECT_EQ(&s3,s.GetPointerList());
}
TEST(List, can_assign_List)
{
	int b;
	b=3;
	List<int>s2;
	List<int>s3;
	List<int>s(b,&s2);
	s3=s;
	EXPECT_EQ(3,s3.GetData());
}
TEST(List, can_Set_copied_List)
{
	int b;
	b=3;
	List<int>s2;
	List<int>s(b,&s2);
	List<int>s3(s);
	EXPECT_EQ(&s2,s3.GetPointerList());
	EXPECT_EQ(3,s3.GetData());
}
TEST(Polinom, can_create_Polinom)
{
ASSERT_NO_THROW (Polinom st);
}
TEST(Polinom, can_SetListFirst)
{
	Polinom st;
	Monom m(3,1,2,3);
	List<Monom> s2;
	List<Monom> s;
	s.SetData(m);
	s.SetPointerList(&s2);
	st.SetListFirst(&s);
	EXPECT_EQ(3,st.Head->GetData().GetFactor());
}
TEST(Polinom, can_DeletFirst)
{
	Polinom st;
	Monom m(3,1,2,3);
	List<Monom>s2;
	List<Monom>s;
	s.SetData(m);
	s.SetPointerList(&s2);
	st.SetListFirst(&s);
	st.DeletFirst();
	EXPECT_EQ(0,st.Head->GetData().GetFactor());
}
TEST(Polinom, can_SetListMid)
{
	Polinom st;
	Monom m(3,1,2,3);
	Monom m2(2,1,2,3);
	List<Monom>s2;
	List<Monom>s;
	List<Monom>s3;
	List<Monom>*s4;
	s3.SetData(m2);
	s.SetData(m);
	st.SetListFirst(&s);
	st.SetListMid(&s3,st.Head);
	s4=st.Head->GetPointerList();
	EXPECT_EQ(2,(*s4).GetData().GetFactor());
}
TEST(Polinom, can_PolinomAdd)
{
	Polinom st;
	Polinom st2;
	Monom m(3,1,2,3);
	st.Head->SetData(m);
	st2=st+st;
	EXPECT_EQ(6,(st2.Head->GetData().GetFactor()));
}
TEST(Polinom, can_Polinom_no_Add)
{
	Polinom st;
	Polinom st2;
	Monom m(3,1,2,3);
	st.Head->SetData(m);
	st2=st+st-st;
	EXPECT_EQ(3,(st2.Head->GetData().GetFactor()));
}
TEST(Polinom, can_Polinom_ym)
{
	Polinom st;
	Polinom st2;
	Monom m(3,1,2,3);
	st.Head->SetData(m);
	st2=st*st;
	EXPECT_EQ(9,(st2.Head->GetData().GetFactor()));
}
TEST(Polinom, can_destructor)
{
	Polinom st;
	Monom m(3,1,2,3);
	List<Monom> s2;
	List<Monom> s;
	List<Monom> *s3;
	s.SetData(m);
	s.SetPointerList(&s2);
	s.SetPointerList(&s2);
	st.SetListFirst(&s);
	s3=st.Head->GetPointerList();
	st.Deletpolinom();
	EXPECT_EQ(0,s3);
}