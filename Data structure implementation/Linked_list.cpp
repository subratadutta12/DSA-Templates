#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int val;
	node *next;
};

class Linked_List
{
public:
	node *head;

	Linked_List() {
		head = NULL;
	}

	node *getnode(int n)
	{
		node *r = new node();
		r->val = n;
		r->next = NULL;
		return r;
	}

	void insert(int n, int pos = 1)
	{
		if (head == NULL)
		{
			head = getnode(n);
		}
		else if (pos == 1)
		{
			node *temp = getnode(n);
			temp->next = head;
			head = temp;
		}
		else
		{
			node *temp = head;
			for (int i = 1; i < pos - 1; i++)
			{
				temp = temp->next;
			}
			node *r = getnode(n);
			r->next = temp->next;
			temp->next = r;
		}
	}

	void print()
	{
		node *temp = head;
		while (temp != NULL)
		{
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << "\n";
	}

	void del(int n)
	{
		if (head == NULL)
			return;
		node *temp = head;
		if (temp->val == n)
		{
			head = temp->next;
			delete temp;
		}
		else
		{
			while (temp != NULL && temp->next != NULL)
			{
				if (temp->next->val == n)
				{
					node *r = temp->next;
					temp->next = r->next;
					delete r;
				}
				temp = temp->next;
			}
		}
	}
};

int main()
{
	Linked_List l;
	l.insert(5, 1);
	l.insert(4, 2);
	l.insert(6, 3);
	l.insert(3, 4);
	l.insert(9, 5);
	l.insert(500, 3);
	l.insert(600, 1);
	l.insert(700, 5);
	l.print();
	l.del(500);
	l.print();
	l.del(9);
	l.print();
	l.del(600);
	l.del(700);
	l.del(300000);
	l.del(3);
	l.del(5);
	l.del(4);
	l.print();
	cout << l.head << "\n";
	l.del(6);
	l.print();
	cout << l.head << "\n";
}
