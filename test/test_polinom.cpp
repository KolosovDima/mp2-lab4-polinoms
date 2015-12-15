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

