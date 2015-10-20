#include <iostream>
using namespace std;

int testnum = 1;

bool prog(char* stroka)
{
	char s[100] = { 0 };
	int uk = 0;
	bool flag = false;
	for (int i = 0; i < strlen(stroka); i++)
	{
		if (stroka[i] == '[' || stroka[i] == '(' || stroka[i] == '{')
		{
			s[uk] = stroka[i];
			uk++;
		}
		else
		{
			if (uk == 0 && (stroka[i] == ']' || stroka[i] == ')' || stroka[i] == '}'))
			{
				return false;
				flag = true;
				break;
			}

			if (stroka[i] == ']')
			{
				if (s[uk - 1] == '[')
					uk--;
				else
				{
					return false;
					flag = true;
					break;
				}
			}

			if (stroka[i] == ')')
			{
				if (s[uk - 1] == '(')
					uk--;
				else
				{
					return false;
					flag = true;
					break;
				}
			}

			if (stroka[i] == '}')
			{
				if (s[uk - 1] == '{')
					uk--;
				else
				{
					return false;
					flag = true;
					break;
				}
			}
		}
	}
	if (flag == false)
	if (uk != 0)
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