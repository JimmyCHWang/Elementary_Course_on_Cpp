#include<bits/stdc++.h>

using namespace std;

// Struct Declaration
struct maxmin {
    int max;
    int min;
};  // Note this comma!

// Function Pre-declaration
maxmin find_maxmin (int A[], int l, int r);


// Main function
int main() {
	int N;
	int arr[1000];
	cin>>N;
	for (int i = 0; i < N; i++) cin>>arr[i];
	maxmin result = find_maxmin (arr, 0, N-1);
	cout<<result.max<<" "<<result.min<<endl;
	return 0;
}

// Function Implementation
maxmin find_maxmin (int A[], int l, int r) {
    if (l == r) {
        return {A[l], A[l]}; // A[l] is the only element in A
    }
	
    int m = (l+r)/2;
    maxmin left = find_maxmin(A, l, m);
	maxmin right = find_maxmin(A, m+1, r);
    int max_of_A = max(left.max, right.max);
	int min_of_A = min(left.min, right.min);
    return {max_of_A, min_of_A};
}