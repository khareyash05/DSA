// C++ implementation to find smallest
// subarray with all occurrences of
// a most frequent element
#include <bits/stdc++.h>
using namespace std;

void smallestSubsegment(int a[], int n)
{
	// To store left most occurrence of elements
	unordered_map<int, int> left;

	// To store counts of elements
	unordered_map<int, int> count;

	// To store maximum frequency
	int mx = 0;

	// To store length and starting index of
	// smallest result window
	int mn, strindex;

	for (int i = 0; i < n; i++) {

		int x = a[i];

		// First occurrence of an element,
		// store the index
		if (count[x] == 0) {
			left[x] = i;
			count[x] = 1;
		}

		// increase the frequency of elements
		else
			count[x]++;

		// Find maximum repeated element and
		// store its last occurrence and first
		// occurrence
		if (count[x] > mx) {
			mx = count[x];
			mn = i - left[x] + 1; // length of subsegment
			strindex = left[x];
		}

		// select subsegment of smallest size
		else if (count[x] == mx && i - left[x] + 1 < mn) {
			mn = i - left[x] + 1;
			strindex = left[x];
		}
	}

	// Print the subsegment with all occurrences of
	// a most frequent element
	for (int i = strindex; i < strindex + mn; i++)
		cout << a[i] << " ";
}

// Driver code
int main()
{
	int A[] = { 1, 2, 2, 2, 1 };
	int n = sizeof(A) / sizeof(A[0]);
	smallestSubsegment(A, n);
	return 0;
}
