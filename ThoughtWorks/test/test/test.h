#pragma once
#include <iostream>
#include <time.h>
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