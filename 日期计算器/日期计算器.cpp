#include<iostream>
using namespace std;
class Date
{
public:
	int GetMonthDay(int year, int month)
	{
		int monthDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			return 29;
		}
		return monthDay[month];
	}
	Date(int year = 0, int month = 1, int day = 1)
	{
		if (year >= 0 && month >= 1 && month < 12 && day >= 1 && day <= GetMonthDay(year, month))
		{
			this->_year = year;
			this->_month = month;
			this->_day = day;
		}
		else
		{
			cout << "日期非法" << endl;
		}
	}
	Date(const Date& d)
	{
		this->_year = d._year;
		this->_month = d._month;
		this->_day = d._day;
	}
	bool operator==(const Date& d)
	{
		return (this->_year == d._year && this->_month == d._month && this->_day == d._day);
	}
	bool operator!=(const Date& d)
	{
		return (this->_year != d._year || this->_month != d._month || this->_day != d._day);
	}
	bool operator<(const Date& d)
	{
		if (this->_year < d._year)
		{
			return true;
		}
		else if (this->_year == d._year && this->_month < d._month)
		{
			return true;
		}
		else if (this->_year == d._year && this->_month == d._month && this->_day < d._day)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator>(const Date& d)
	{
		if (this->_year > d._year)
		{
			return true;
		}
		else if (this->_year == d._year && this->_month > d._month)
		{
			return true;
		}
		else if (this->_year == d._year && this->_month == d._month && this->_day > d._day)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator<=(const Date& d)
	{
		return *this < d || *this == d;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	bool operator>=(const Date& d)
	{
		return *this > d || *this == d;
	}
	Date operator+(int day)
	{
		Date ret(*this);
		ret._day += day;
		while (ret._day > ret.GetMonthDay(ret._year, ret._month))
		{
			ret._day -= ret.GetMonthDay(ret._year, ret._month);
			ret._month++;
			if (ret._month == 13)
			{
				ret._month = 1;
				ret._year++;
			}
		}
		return ret;
	}
	Date& operator+=(int day)
	{
		if (day < 0)
		{
			return *this -= -day;
		}
		this->_day += day;
		while (this->_day > this->GetMonthDay(this->_year, this->_month))
		{
			this->_month++;
			if (this->_month == 13)
			{
				this->_year++;
				this->_month = 1;
			}
		}
		return *this;
	}
	Date operator-(int day)
	{
		Date ret = *this;
		ret._day -= day;
		while (ret._day <= 0)
		{
			ret._month -= 1;
			ret._day += GetMonthDay(ret._year, ret._month);
			if (ret._month == 0)
			{
				ret._year--;
				ret._month = 12;
			}
		}
		return ret;
	}
	//Date min(const Date& d)
	//{
	//	if (*this < d)
	//	{
	//		return *this;
	//	}
	//	else
	//	{
	//		return d;
	//	}
	//}
	int operator-(const Date& d)
	{
		int num = 0;
		if (*this < d)
		{
			while (*this != d)
			{
				*this += 1;
				num++;
			}
		}
		else
		{
			//int num = 0;
			while (*this != d)
			{
				*this -= 1;
				num++;
			}
		}
		return num;
	}
	Date& operator-=(int day)
	{
		if (day < 0)
		{
			return *this += -day;
		}
		this->_day -= day;

		while (this->_day <= 0)
		{
			--this->_month;
			//this->_day += GetMonthDay(this->_year, this->_month);
			if (this->_month == 0)
			{
				--this->_year;
				this->_month = 12;

				//this->_month = 12;
			}
			this->_day += GetMonthDay(this->_year, this->_month);
		}
		return *this;
	}
	Date& operator++()
	{
		*this += 1;
		return *this;
	}
	Date operator++(int)
	{
		Date temp(*this);
		*this += 1;
		return temp;
	}
	Date& operator--()
	{
		*this += 1;
		return *this;
	}
	Date operator--(int)
	{
		Date temp(*this);
		*this += 1;
		return temp;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;
	d1.Print();
	Date d2(2022, 1, 4);
	d2.Print();
	Date d3 = d2 + 100;
	d3.Print();
	Date d4 = d3 - 100;
	d4.Print();
	Date d5 = d2;
	d5 -= 4;
	d5.Print();
	Date d6(2022, 1, 30);
	int num1 = d6 - d2;
	cout << num1 << endl;
	Date d7(2022, 7, 8);
	int num2 = d7 - d2;
	cout << num2 << endl;
	return 0;
}