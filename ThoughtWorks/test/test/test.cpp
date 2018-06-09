#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include "test.h"
using namespace std;

int main() {
	info test;
	string str;
	getline(cin, str);
	SplitString(str, test, " ");

	system("pause");
	return 0;
}

