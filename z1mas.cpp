#include <iostream>
using namespace std;

bool prog(char* stroka)
{
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < strlen(stroka); i++)
	{
		if (stroka[i] == '(')
			a++;
		if (stroka[i] == '[')
			b++;
		if (stroka[i] == '{')
			c++;
		if (stroka[i] == ')')
			a--;
		if (stroka[i] == ']')
			b--;
		if (stroka[i] == '}')
			c--;
		if (a < 0 || b < 0 || c < 0)
		{
			return false;
			break;
		}
	}
	if (a != 0 || b != 0 || c != 0)
		return false;
	else return true;
}


int main()
{
	return 0;
}