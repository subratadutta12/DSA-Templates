#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// All operation that are supported in set can be applied to it the comparator less<int> makes it a set and the comparator less_equal<int> makes it a multiset.

// In case of Ordered multiset lower_bound function and upper_bound function are reversed,i.e. lower_bound works as upper_bound and upper_bound works as lower_bound.find function doesn't work use upper_bound/lower_bound instead.

//For deletion in ordered_multiset follow the below pattern

//Ordered_multiset
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

// In case of ordered_set all functionalities works normally find(), erase() works normally as in set. Properties of upper_bound/lower_bound are also same.


//Ordered_set
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
	ordered_multiset d;
	d.insert(1);
	d.insert(2);
	d.insert(2);
	d.insert(3);
	//To delete a particular occurence use this
	if (d.upper_bound(2) != d.end() && (*d.upper_bound(2)) == 2)
		d.erase(d.upper_bound(2));
	// d.erase(d.lower_bound(2));
	// cout<<d.find(2)<<"\n";
	for (auto i : d) {
		cout << i << endl;
	}




	// There are two new features — it is find_by_order() and order_of_key(). The first returns an iterator to the k-th largest element (counting from zero), the second — the number of items in a set that are strictly smaller than our item. Example of use:

	//This works perfectly for both ordered_set and ordered_multiset

	ordered_set X;
	X.insert(1);
	X.insert(2);
	X.insert(4);
	X.insert(8);
	X.insert(16);

	cout << *X.find_by_order(1) << endl; // 2
	cout << *X.find_by_order(2) << endl; // 4
	cout << *X.find_by_order(4) << endl; // 16
	cout << (end(X) == X.find_by_order(6)) << endl; // true

	cout << X.order_of_key(-5) << endl; // 0
	cout << X.order_of_key(1) << endl; // 0
	cout << X.order_of_key(3) << endl; // 2
	cout << X.order_of_key(4) << endl; // 2
	cout << X.order_of_key(400) << endl; // 5
	return 0;
}

template <
    typename Key, // Key type
    typename Mapped, // Mapped-policy
    typename Cmp_Fn = std::less<Key>, // Key comparison functor
    typename Tag = rb_tree_tag, // Specifies which underlying data structure to use
    template <
        typename Const_Node_Iterator,
        typename Node_Iterator,
        typename Cmp_Fn_,
        typename Allocator_ >
    class Node_Update = null_node_update, // A policy for updating node invariants
    typename Allocator = std::allocator<char> > // An allocator type
class tree;

