#include <cctype>

#include "digit-sum.hh"

int
digitSum(const char* str)
{
	int acc = 0;

	for (const char* p = str; *p; ++p) {
		int c = *p, temp = *(p+1);
		if ((!(isdigit (c))) && c != '+' && c != ' ') break;
		if( ((isdigit (c)) && (isdigit (temp))) || ( c == '+' && temp == '+')) break;
		if(isdigit (c)) acc += *p - '0';
	}
	return acc;
}
