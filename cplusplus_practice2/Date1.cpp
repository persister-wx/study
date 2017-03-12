#include"Date1.h"

Date::Date(int year, int month, int day)//���캯��
:m_year(year)
, m_month(month)
, m_day(day)
{
	assert(IsValid(*this) != 0);
}

Date Date::operator+(int day)//ĳ�����ڼ���һ�����������磺d1+100��
{
	Date tmp(*this);
	tmp.m_day += day;
	while (tmp.m_day > GetMonthDays(tmp.m_year, tmp.m_month))
	{
		tmp.m_day -= GetMonthDays(tmp.m_year, tmp.m_month);
		if (tmp.m_month == 12)
		{
			tmp.m_year++;
			tmp.m_month = 1;
		}
		else
		{
			tmp.m_month++;
		}
	}
	return tmp;
}

Date& Date::operator+=(int day)//ע����operator+֮�������һ���������ã�һ������ֵ��
{
	*this = *this + day;
	return *this;
}


Date& Date::operator++()//ǰ��++
{
	*this = *this + 1;
	return *this;
}

Date Date::operator++(int)//����++
{
	Date tmp(*this);
	*this = *this + 1;
	return tmp;
}

Date Date::operator-(int day)//ĳ�����ڼ�ȥĳ�����������磺d1-100��
{
	Date tmp(*this);
	tmp.m_day -= day;
	while (!IsValid(tmp))
	{
		if (tmp.m_month == 1)
		{
			tmp.m_year--;
			tmp.m_month = 12;
		}
		else
		{
			tmp.m_month--;
		}
		tmp.m_day += GetMonthDays(tmp.m_year, tmp.m_month);
	}
	return tmp;
}

Date& Date::operator-=(int day)
{
	*this = *this - day;
	return *this;
}


bool operator>(const Date& d1, const Date& d2)//����>
{
	if ((d1.m_year > d2.m_year) \
		|| (d1.m_year == d2.m_year) && ((d1.m_month > d2.m_month) || ((d1.m_month == d2.m_month) && (d1.m_day > d2.m_day))))
	{
		return true;
	}
	return false;
}

bool operator<(const Date& d1, const Date& d2)//����<
{
	return !((d1 > d2) || (d1 == d2));
}


bool operator!=(const Date&d1, const Date& d2)//���أ�=
{
	return !(d1 == d2);
}

bool operator==(const Date&d1, const Date& d2)//����==
{
	if ((d1.m_year == d2.m_year) && (d1.m_month == d2.m_month) && (d1.m_day == d2.m_day))
	{
		return true;
	}
	return false;
}

//
//int Date::operator-(const Date& d1)//����������������磺d1-d2��
//{
//	int flag = 1;
//	if (d1 > *this)
//	{
//		flag = -flag;
//	}
//	int count = 0;
//	Date minDate = *this;
//	Date maxDate = d1;
//	if (minDate > maxDate)
//	{
//		Swap(minDate, maxDate);
//	}
//	while (minDate != maxDate)
//	{
//		minDate++;
//		count++;
//	}
//	return flag * count;
//	
//}

int Date::operator-(const Date& d1)//����������������磺d1-d2��
{
	int flag = 1;
	if (d1 > *this)
	{
		flag = -flag;
	}
	int remainDays = 0;//С�������ڵ���ʣ�������������ף�
	int dayInYear = 0;//��������ڵ��������
	int d_value = 0;//�������ڵ���֮����������
	Date d2(*this);
	assert(IsValid(d1) != 0);//�ж��������ڵ���Ч��
	assert(IsValid(d2) != 0);
	if ((d1.m_year == d2.m_year) && (d1.m_month == d2.m_month))//������������ͬ����ͬ��
	{
		return d1.m_day - d2.m_day;
	}
	else if (d1.m_year == d2.m_year)//������������ͬ�굫��ͬ��
	{
		return (DayInYear(d1) - DayInYear(d2));
	}
	else//���������ڲ�ͬ��
	{
		Date minDate = d1;
		Date maxDate = d2;
		if (minDate > maxDate)
		{
			Swap(minDate, maxDate);
		}
		if (IsLeapYear(minDate.m_year))
		{
			remainDays = 366 - DayInYear(minDate);
		}
		else
		{
			remainDays = 365 - DayInYear(minDate);
		}
		dayInYear = DayInYear(maxDate);//��ô�������ڵ��������
		//��ȡ�������ڵ���֮��Ĳ�ֵ
		for (int year = minDate.m_year + 1; year < maxDate.m_year; year++)
		{
			if (IsValid(year))
			{
				d_value += 366;
			}
			else
			{
				d_value += 365;
			}
		}
	}
	return flag * (d_value + remainDays + dayInYear);
}


Date& Date::operator--()//ǰ��--
{
	*this = *this - 1;
	return *this;
}

Date Date::operator--(int)//����--
{
	Date tmp(*this);
	*this = *this - 1;
	return tmp;
}

void Swap(Date& d1, Date& d2)//������������
{
	int tmp = d1.m_year;
	d1.m_year = d2.m_year;
	d2.m_year = tmp;
	tmp = d1.m_month;
	d1.m_month = d2.m_month;
	d2.m_month = tmp;
	tmp = d1.m_day;
	d1.m_day = d2.m_day;
	d2.m_day = tmp;
}

int Date::DayInYear(const Date& d)//��ȡ���������
{
	assert(IsValid(d) != 0);
	int days = d.m_day;
	for (int month = 1; month < d.m_month; month++)
	{
		days += GetMonthDays(d.m_year, month);
	}
	return days;
}

bool Date::IsLeapYear(int year)//�ж�����
{
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 100 == 0))
	{
		return true;
	}
	return false;
}

void Date::Dispaly()//�������
{
	cout << m_year << "-" << m_month << "-" << m_day << endl;
}

//����
void Test()
{
	Date d1(2017, 2, 28);
	Date d2;
	d2 = d1 + 100;
	d2.Dispaly();
	d2 = d2 - 100;
	d2.Dispaly();
}

void Test2()
{
	Date d2(2017, 2, 28);
	Date d1(2015, 3, 8);
	int start = clock();
	int day = d1 - d2;
	int end = clock();
	cout << (end - start) << endl;
	cout << day << endl;
}

void Test3()
{
	Date d2(2017, 2, 28);
	d2.Dispaly();
	d2++.Dispaly();
	Date d1(2015, 3, 8);
	d1.Dispaly();
	++d1;
	d1.Dispaly();
}

void Test4()
{
	Date d2(2017, 2, 28);
	d2.Dispaly();
	d2--.Dispaly();
	Date d1(2015, 3, 8);
	--d1;
	d1.Dispaly();
}

void Test5()
{
	Date d1(2015, 3, 8);
	d1 += 100;
	d1.Dispaly();
	d1 -= 100;
	d1.Dispaly();
}

void Test6()
{
	Date d1(2015, 3, 8);
	Date d2(2017, 2, 28);
	cout << (d1 < d2) << endl;
	cout << (d1 > d2) << endl;
	cout << (d1 == d2) << endl;
}

int main()
{
	//Test();
	//Test2();
	//Test3();
	//Test4();
	//Test5();
	Test6();
	return 0;
}





