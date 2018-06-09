#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct info {
	string UserID;
	string Date;
	string Time;
	string Court;
	string Type;
};
void SplitString(const string& s, info& q, const string& c)
{
	string::size_type pos1, pos2;
	vector<string >v;
	pos2 = s.find(c);
	pos1 = 0;
	while (string::npos != pos2)
	{
		v.push_back(s.substr(pos1, pos2 - pos1));

		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length())
		v.push_back(s.substr(pos1));
	q.UserID = v[0];
	q.Date = v[1];
	q.Time = v[2];
	q.Court = v[3];
	if (v.size() == 5)
		q.Type = v[4];
}

//-------------------------------------------------------------------
//函数名称：IsLeapYear
//功能描述：判断某年是否为闰年
//调用清单：
//被调清单：IsLegal
//参数说明：year,年
//输出说明：是，否
//返回  值：bool
//其    他：
//-------------------------------------------------------------------
bool IsLeapYear(int year)
{
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		return true;
	return false;
}

//-------------------------------------------------------------------
//函数名称：IsLegal
//功能描述：判断年月日是否合法
//调用清单：IsLeapYear
//被调清单：
//参数说明：year,mon,day
//输出说明：是，否
//返回  值：bool
//其    他：
//-------------------------------------------------------------------
bool IsLegal(int year, int mon, int day)
{
	//大：1 3 5 7 8 10 12
	//小：4 6 9 11
	//平：2

	if (year < 0 || mon <= 0 || mon > 12 || day <= 0 || day > 31)return false;

	if (1 == mon || 3 == mon || 5 == mon || 7 == mon || 8 == mon || 10 == mon || 12 == mon) {
		return true;
	}
	if (IsLeapYear(year)) {
		if (2 == mon && (28 == day || 30 == day || 31 == day))return false;
		return true;
	}
	else {
		if (2 == mon && (29 == day || 30 == day || 31 == day))return false;
		return true;
	}
}

/*
语法：result = weekday(int N, int M, int d)
参数：
N, M, d：年月日，例如：2003, 11, 4
返回值：0：星期天，1星期一……
注意：
需要cmath
适用于1582年10月15日之后, 因为罗马教皇格里高利十三世在这一天启用新历法.
*/
//给定年月日，输出当天是星期几
int weekday(int N, int M, int d)
{
	int m, n, c, y, w;
	m = (M - 2) % 12;
	if (M >= 3) n = N; else n = N - 1;
	c = n / 100;
	y = n % 100;
	w = (int)(d + floor(13 * m / 5) + y + floor(y / 4) + floor(c / 4) - 2 * c) % 7;
	while (w < 0) w += 7;
	return w;
}

int DateLegal(string Date) {
	int year, month, day;
	int pos2 = Date.find("-");
	int pos1 = 0;
	year = stoi(Date.substr(pos1, pos2 - pos1));
	pos1 = pos2 + 1;
	pos2 = Date.find("-", pos1);
	month = stoi(Date.substr(pos1, pos2 - pos1));
	pos1 = pos2 + 1;
	pos2 = Date.find("-", pos1);
	day = stoi(Date.substr(pos1, pos2 - pos1));
	if (!IsLegal(year, month, day))
		return 0;
	else {
		int wd = weekday(year, month, day);
		if (wd == 0 || wd == 6)
			return 2;
		else
			return 1;
	}
}

int timeLegal(string time) {
	string time1, time2;
	int pos2 = time.find(":");


}
