#include <iostream>

using namespace std;

struct Node
{
	char value;
	Node* next;
};

bool answer;
Node* head = new Node;

void deletehead(Node* &head)
{
	if (!head->value) answer = false;
	else
	{
		if (head->next == NULL)
			head->value = 0;
		else
			head = head->next;
	}
}

void addtohead(Node* &head, char a)
{
	if (head->value == 0)
		head->value = a;
	else
	{
		Node* temp = new Node;
		temp->value = a;
		temp->next = head;
		head = temp;
	}
}

bool check(char* s)
{
	answer = true;
	head->value = 0;
	head->next = NULL;
	for (unsigned int i = 0; i < strlen(s) && answer; i++)
	{
		if (!strchr("([{}])", s[i]));
		else if ((s[i] - head->value) <= 2 && (s[i] - head->value)>0)
			deletehead(head);
		else if (strchr("}])", s[i]))
			answer = false;
		else
			addtohead(head, s[i]);
	}
	if (head->value != 0) answer = false;
	return answer;
}

void test(bool flag, bool ans)
{
	if (flag == ans)
		cout << "OK" << endl;
	else cout << "Fail" << endl;
}

int main()
{


	test(check("()()()(){}{}({}())"), true);
	test(check("((((({}{}[(){}])))))"), true);
	test(check(")"), false);
	test(check("{()}{"), false);
	test(check("}()()(){([])}"), false);
	test(check("{}{}(){}{{{{{{{[]}}}}}}"), false);
	return 0;
}