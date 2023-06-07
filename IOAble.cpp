//Name:-Harsh Shaileshkumar Patel

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "IOAble.h"

namespace sdds
{
	std::ostream& IOAble::write(std::ostream& ostr)const
	{
		return ostr;
	}
	std::istream& IOAble::read(std::istream& istr)
	{
		return istr;
	}
	std::ostream& IOAble::csvWrite(std::ostream& ostr)const
	{
		return ostr;
	}
	std::istream& IOAble::csvRead(std::istream& istr)
	{
		return istr;
	}
	std::istream& operator>>(std::istream& istr, IOAble& obj1)
	{
		obj1.read(istr);
		return istr;
	}
	std::ostream& operator<<(std::ostream& ostr, const IOAble& obj2)
	{
		obj2.write(ostr);
		return ostr;
	}
}