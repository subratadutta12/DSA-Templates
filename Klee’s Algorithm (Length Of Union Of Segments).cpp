Klee’s Algorithm (Length Of Union Of Segments of a line)
Last Updated: 06 - 01 - 2017
Given starting and ending positions of segments on a line, the task is to take the union of all given segments and find length covered by these segments.

Examples:

Input : segments[] = {{2, 5}, {4, 8}, {9, 12}}
Output : 9
segment 1 = {2, 5}
            segment 2 = {4, 8}
                        segment 3 = {9, 12}
                                    If we take the union of all the line segments,
	                                    we cover distances [2, 8] and [9, 12]. Sum of
	                                    these two distances is 9 (6 + 3)
	                                    The algorithm was proposed by Klee in 1977. The time complexity of the algorithm is O (N log N). It has been proven that this algorithm is the fastest (asymptotically) and this problem can not be solved with a better complexity.

	                                    filter_none
	                                    edit
	                                    play_arrow

	                                    brightness_4
// C++ program to implement Klee's algorithm
#include<bits/stdc++.h>
using namespace std;

// Returns sum of lengths covered by union of given
// segments
int segmentUnionLength(const vector <pair <int, int> > &seg)
{
	int n = seg.size();

	// Create a vector to store starting and ending
	// points
	vector <pair <int, bool> > points(n * 2);
	for (int i = 0; i < n; i++)
	{
		points[i * 2]     = make_pair(seg[i].first, false);
		points[i * 2 + 1] = make_pair(seg[i].second, true);
	}

	// Sorting all points by point value
	sort(points.begin(), points.end());

	int result = 0; // Initialize result

	// To keep track of counts of current open segments
	// (Starting point is processed, but ending point
	// is not)
	int Counter = 0;

	// Trvaerse through all points
	for (unsigned i = 0; i < n * 2; i++)
	{
		// If there are open points, then we add the
		// difference between previous and current point.
		// This is interesting as we don't check whether
		// current point is opening or closing,
		if (Counter)
			result += (points[i].first - points[i - 1].first);

		// If this is an ending point, reduce, count of
		// open points.
		(points[i].second) ? Counter-- : Counter++;
	}
	return result;
}

// Driver program for the above code
int main()
{
	vector< pair <int, int> > segments;
	segments.push_back(make_pair(3, 15));
	segments.push_back(make_pair(2, 5));
	segments.push_back(make_pair(4, 8));
	segments.push_back(make_pair(9, 12));
	cout << "Length of Union of All segments = ";
	cout << segmentUnionLength(segments) << endl;
	return 0;
}
Output:

Length of Union of All segments = 9
Description :
1) Put all the coordinates of all the segments in an auxiliary array points[].
2) Sort it on the value of the coordinates.
3) An additional condition for sorting – if there are equal coordinates, insert the one which is the left coordinate of any segment instead of a right one.
	4) Now go through the entire array, with the counter “count” of overlapping segments.
	5) If count is greater than zero, then the result is added to the difference between the points[i] – points[i - 1].
	6) If the current element belongs to the left end, we increase “count”, otherwise reduce it.




Illustration:

Lets take the example :
segment 1 : (2, 5)
segment 2 : (4, 8)
segment 3 : (9, 12)

	Counter = result = 0;
	n = number of segments = 3;

	for i = 0,  points[0] = {2, false}
		                        points[1] = {5, true}
		                                    for i = 1,  points[2] = {4, false}
			                                            points[3] = {8, true}
			                                                    for i = 2,  points[4] = {9, false}
				                                                            points[5] = {12, true}

                                                                    Therefore :
				points = {2, 5, 4, 8, 9, 12}
{f, t, f, t, f, t}

after applying sorting :
points = {2, 4, 5, 8, 9, 12}
{f, f, t, t, f, t}

Now,
for i = 0, result = 0;
Counter = 1;

for i = 1, result = 2;
	Counter = 2;

	for i = 2, result = 3;
		Counter = 1;

		for i = 3, result = 6;
			Counter = 0;

			for i = 4, result = 6;
				Counter = 1;

				for i = 5, result = 9;
					Counter = 0;

					Final answer = 9;
Time Complexity : O(n * log n)