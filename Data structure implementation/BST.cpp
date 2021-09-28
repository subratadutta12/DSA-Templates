#include <bits/stdc++.h>
using namespace std;

class node
{
public:
	int val;
	node *left;
	node *right;
};

class BST
{
	node *getnode(int n)
	{
		node *r = new node();
		r->val = n;
		r->left = NULL;
		r->right = NULL;
		return r;
	}

	node *insert(int n, node *r)
	{
		if (r == NULL)
		{
			return getnode(n);
		}

		if (n < r->val)
		{
			r->left = insert(n, r->left);
		}
		else if (n > r->val)
		{
			r->right = insert(n, r->right);
		}
		return r;
	}

	bool search(int n, node *r)
	{
		if (r == NULL)
		{
			return 0;
		}

		if (n < r->val)
		{
			return search(n, r->left);
		}
		else if (n > r->val)
		{
			return search(n, r->right);
		}
		else
		{
			return 1;
		}
	}

	void print(node *r)
	{
		if (r != NULL)
		{
			print(r->left);
			cout << r->val << " ";
			print(r->right);
		}
	}

	int findmax(node *r)
	{
		if (r->right == NULL)
			return r->val;
		return findmax(r->right);
	}

	int findmin(node *r)
	{
		if (r->left == NULL)
			return r->val;
		return findmin(r->left);
	}

	node *del(int n, node *r)
	{
		// cout << "del=== " << r->val << "\n";
		if (r == NULL)
			return r;
		if (n < r->val)
		{
			r->left = del(n, r->left);
		}
		else if (n > r->val)
		{
			r->right = del(n, r->right);
		}
		else
		{
			if (r->left == NULL && r->right == NULL)
			{
				delete r;
				return NULL;
			}
			else if (r->left == NULL)
			{
				node *temp = r->right;
				delete r;
				return temp;
			}
			else if (r->right == NULL)
			{
				node *temp = r->left;
				delete r;
				return temp;
			}
			else
			{
				int mi = findmin(r->right);
				r->val = mi;
				r->right = del(mi, r->right);
			}
		}
		return r;
	}

public:
	node *root;

	BST()
	{
		root = NULL;
	}

	void insert(int n)
	{
		root = insert(n, root);
	}

	void print()
	{
		print(root);
		cout << "\n";
	}

	bool search(int n)
	{
		return search(n, root);
	}

	int findmin()
	{
		return findmin(root);
	}

	int findmax()
	{
		return findmax(root);
	}

	void del(int n)
	{
		root = del(n, root);
	}
};

int main()
{
	BST t;
	t.insert(20);
	t.insert(10);
	t.insert(25);
	t.insert(30);
	t.insert(1);
	t.insert(15);
	t.insert(28);
	t.print();
	cout << t.search(20) << "\n";
	cout << t.search(16) << "\n";
	cout << t.search(15) << "\n";
	cout << t.search(25) << "\n";
	cout << t.search(26) << "\n";
	cout << t.search(1) << "\n";
	cout << t.root->val << " " << t.root->left->right->val << "\n";
	cout << t.findmax() << " " << t.findmin() << "\n";
	t.del(28);
	t.print();
	t.del(25);
	t.print();
	t.del(10);
	t.print();
	t.del(20);
	t.print();
	cout << t.root->val << "\n";
}
