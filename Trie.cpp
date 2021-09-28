#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define MAXN 100005
#define ll long long
#define pb push_back
#define fr(i,a,b) for(long long i=a;i<b;i++)

class Trienode
{
public:
	char data;
	int wc;  //wc:word_count of no of word ending at this
	int pr;  //pr: prefix count of no of word having this as prefix
	vector<int> order; // to store the order of the string
	Trienode *child[26];
};

class trie {
public:
	Trienode *root;    //Root of Trie

	// constructor
	trie() {
		root = new Trienode();
		root->data = '\0';
		root->wc = 0;
		root->pr = 0;
		for (int i = 0; i < 26; ++i)
		{
			root->child[i] = NULL;
		}
	}

	Trienode *getNode(char c)
	{
		Trienode *newnode = new Trienode();
		newnode->data = c;
		for (register int i = 0; i < 26; ++i)
			newnode->child[i] = NULL;
		newnode->wc = 0;
		newnode->pr = 0;
		return newnode;
	}

	void insert(string s, int ord = -1)
	{
		Trienode *curr = root;
		int index;
		int ln = s.length();
		for (int i = 0; i < ln; ++i)
		{
			index = s[i] - 'a';
			if (curr->child[index] == NULL)
				curr->child[index] = getNode(s[i]);
			curr->child[index]->pr += 1;
			curr = curr->child[index];
		}
		curr->wc += 1;
		if (ord != -1)
			(curr->order).push_back(ord);
	}

	bool search(string s)
	{
		Trienode *curr = root;
		int index;
		int ln = s.length();
		for (int i = 0; i < ln; ++i)
		{
			index = s[i] - 'a';
			if (curr->child[index] == NULL || curr->child[index]->pr == 0)
				return false;
			curr = curr->child[index];
		}
		if (curr->wc == 0)
			return false;
		return true;
	}

	void del(string s)
	{
		if (search(s))
		{
			Trienode *curr = root;
			int index;
			int ln = s.length();
			for (int i = 0; i < ln; ++i)
			{
				index = s[i] - 'a';
				curr->child[index]->pr -= 1;
				curr = curr->child[index];
			}
			curr->wc -= 1;
		}
	}

	int countPrefix(string s)
	{
		Trienode *curr = root;
		int index;
		int ln = s.length();
		for (int i = 0; i < ln; ++i)
		{
			index = s[i] - 'a';
			if (curr->child[index] == NULL || curr->child[index]->pr == 0)
				return 0;   //No string with given prefix is present
			curr = curr->child[index];
		}
		return curr->pr;
	}

	void preorder(Trienode* node, vector<string> &arr , vector<string> &res)
	{
		// if node is empty
		if (node == NULL)
			return;

		for (int i = 0; i < 26; i++) {
			if (node->child[i] != NULL) {

				// if leaf node then print all the strings
				int ln = (node->child[i]->order).size();
				for (int j = 0; j < ln; j++)
					res.push_back(arr[node->child[i]->order[j]]);

				preorder(node->child[i], arr, res);
			}
		}
	}
};

int main()
{
// 	trie t;
// 	t.insert("fhgh");
// 	cout << (t.search("fhgh")) << "\n";
// 	t.insert("fh");
// 	cout << (t.countPrefix("fhgh")) << "\n";
// 	cout << (t.countPrefix("fh")) << "\n";
// 	t.del("fhgh");
// 	cout << (t.search("fhgh")) << "\n";
// 	cout << (t.search("fh")) << "\n";
// 	cout << (t.search("f")) << "\n";
// 	cout << (t.root->child[5]->data) << "\n";
// 	trie t2;
// 	t2.insert("abcdef");
// 	cout << (t2.root->child[0]) << "\n";
// 	cout << (t.root->child[0]) << "\n";

	vector<string>v, ans;
	trie t3;
	v.pb("abcd");
	v.pb("aabc");
	v.pb("bcba");
	v.pb("aab");
	v.pb("x");
	v.pb("bcb");
	v.pb("aab");
	v.pb("x");

	t3.insert("abcd", 0);
	t3.insert("aabc", 1);
	t3.insert("bcba", 2);
	t3.insert("aab", 3);
	t3.insert("x", 4);
	t3.insert("bcb", 5);
	t3.insert("aab", 6);
	t3.insert("x", 7);

	cout << t3.search("abcd") << "\n";
	t3.preorder(t3.root, v, ans); // returns all string in sorted order
	ll ln = ans.size();
	fr(i, 0, ln)
	{
		cout << ans[i] << " ";
	}
	cout << "\n";

	ans.clear();
	t3.preorder(t3.root->child[0]->child[0], v, ans); // returns all string with prefix "aa" in sorted order
	ll ln = ans.size();
	fr(i, 0, ln)
	{
		cout << ans[i] << " ";
	}
	cout << "\n";
}
