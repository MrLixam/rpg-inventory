#ifndef DATE_HPP
#define DATE_HPP

#include <exception>

class Date
{
	private:
		unsigned int _year;
		unsigned int _month;
		unsigned int _day;
	public:
		Date(void);
		Date(unsigned int year, unsigned int month, unsigned int day);
		~Date();
		Date(const Date& copy);
		Date& operator=(const Date& copy);
		bool operator<(const Date& compare) const;
		bool operator>(const Date& compare) const;
		bool operator<=(const Date& compare) const;
		bool operator>=(const Date& compare) const;
		bool operator==(const Date& compare) const;
		bool operator!=(const Date& compare) const;
		class InvalidMonthException: public std::exception
		{
			virtual const char * what() const throw()
			{
				return ("Invalid month given as Input");
			}
		};
		class InvalidDayException: public std::exception
		{
			virtual const char * what() const throw()
			{
				return ("Invalid day given as Input");
			}
		};
};

#endif