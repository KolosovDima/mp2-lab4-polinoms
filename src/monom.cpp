#include "monom.h"
void Monom::SetPower(int pow_x,int pow_y,int pow_z)
{
	if ((pow_x>9)||(pow_y>9)||(pow_z>9))
		throw "Pow more 9";
	else if ((pow_x<0)||(pow_y<0)||(pow_z<0))
		throw "Pow less that 0";
	else
	{
		power=pow_x*100+pow_y*10+pow_z;
	}
}
Monom::Monom(double factor_new,int pow_x,int pow_y,int pow_z)
{
	if ((pow_x>9)||(pow_y>9)||(pow_z>9))
		throw "Pow more 9";
	else if ((pow_x<0)||(pow_y<0)||(pow_z<0))
		throw "Pow less that 0";
	else
	{
		power=pow_x*100+pow_y*10+pow_z;
		factor=factor_new;
	}
}
Monom::Monom( Monom &m2)
{
	factor=m2.GetFactor();
	power=m2.GetPower();
}
Monom::~Monom(){};
Monom& Monom::operator=( Monom &m2)
{
	factor=m2.GetFactor();
	power=m2.GetPower();
	return *this;
}