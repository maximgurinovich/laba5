#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

int ans(char* s)
{
	int cur;
	int total = 0;
	int a[1000] = { 0 };
	for (int i = 0; s[i]; i++)
	{
		if (isdigit(s[i])) a[total++] = s[i] - '0';
		if (s[i] == 'i') a[total++] = 10;
		if (s[i] == 'a') a[total++] = 11;
	}
	cur = total - 2;
	while (total!=1 && --cur>=0)
	{
		if (a[cur] >=10)
		{
			if (a[cur] == 10)
				a[cur] = min(a[cur + 1], a[cur + 2]);
			else
				a[cur] = max(a[cur + 1], a[cur + 2]);
			if (cur + 4 == total)
				a[cur + 1] = a[cur + 3];
			total -= 2;
		}
	}
	return a[0];
}
int main()
{
	return 0;
}