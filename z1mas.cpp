#include <iostream>
using namespace std;
int testnum = 1;
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

void assert(char* s, bool realans)
{
	if (prog(s) == realans)
		cout << testnum++ << ":You're right" << endl;
	else
		cout << testnum++ << ":Ooops!" << endl;
}

int main()
{
	assert("(((([)])))", false);
	assert("()()[{}()]({[]})", true);
	assert("", true);
	assert("([{)]}", false);
	assert("((([[[{{{}}}]]])))", true);
	return 0;
}