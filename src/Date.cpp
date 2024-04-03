#include "../includes/Date.hpp"

Date::Date(void): _year(0), _month(1), _day(1) { }

Date::~Date(void) { }

Date::Date(unsigned int year, unsigned int month, unsigned int day)
{
	if (month < 1 || month > 12)
		throw Date::InvalidMonthException();
	if (day < 1)
		throw Date::InvalidDayException();
	_month = month;
	switch (month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (day > 31)
				throw Date::InvalidDayException();
			_day = day;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (day > 30)
				throw Date::InvalidDayException();
			_day = day;
			break;
		case 2:
			if (((year%400==0) || ((year%100!=0)&&(year%4==0))) && day > 29)
				throw Date::InvalidDayException();
			else if (day > 28)
				throw Date::InvalidDayException();
			_day = day;
			break;
	}
}

Date::Date(const Date& copy): _year(copy._year), _month(copy._month), _day(copy._day) {}

Date& Date::operator=(const Date& copy)
{
	if (this != &copy)
	{
		_year = copy._year;
		_month = copy._month;
		_day = copy._day;
	}
	return (*this);
}

bool Date::operator!=(const Date& compare) const
{
	return (_year != compare._year || _month != compare._month || _day != compare._day);
}

bool Date::operator==(const Date& compare) const
{
	return (_year == compare._year && _month == compare._month && _day == compare._day);
}

bool Date::operator<(const Date& compare) const
{
	if (_year != compare._year) 
		return (_year < compare._year);
	if (_month != compare._month) 
		return (_month < compare._month);
	return (_day < compare._day);
}

bool Date::operator>(const Date& compare) const
{
	if (_year != compare._year) 
		return (_year > compare._year);
	if (_month != compare._month) 
		return (_month > compare._month);
	return (_day < compare._day);
}

bool Date::operator<=(const Date& compare) const
{
	return !(*this > compare);
}

bool Date::operator>=(const Date& compare) const
{
	return !(*this < compare);
}