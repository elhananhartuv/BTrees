#include"lending.h"


bool Lending::operator==(const Lending a)const
{
	if (id != a.id || client != a.client || date != a.date || code != a.code)
		return false;
	return true;
}

bool Lending::operator!=(const Lending a)const
{
	return !((*this) == a);
}

bool Lending::operator>=(const Lending a)const
{
	if (this->date > a.date)
		return true;
	if (this->date == a.date)
		if (this->code > a.code)
			return true;
		else
			if (this->code == a.code)
				return id >= a.id;


	return false;
}

bool Lending::operator<=(const Lending a)const
{
	if (this->date < a.date)
		return true;
	if (this->date == a.date)
		if (this->code < a.code)
			return true;
		else
			if (this->code == a.code)
				return id <= a.id;

	return false;
}

bool Lending::operator>(const Lending a)const
{
	if (this->date > a.date)
		return true;
	if (this->date == a.date)
		if (this->code > a.code)
			return true;
		else
			if (this->code == a.code)
				return id > a.id;

	return false;
}

bool Lending::operator<(const Lending a)const
{
	if (this->date < a.date)
		return true;
	if (this->date == a.date)
		if (this->code < a.code)
			return true;
		else
			if (this->code == a.code)
				return id < a.id;

	return false;
}