#include<bits/stdc++.h>

using namespace std;

int main() {
	int N, b;
	cin>>N>>b;
	if (N == 0) {cout<<"0"<<endl; return 0;}
	
	int arr[100];
	for (int i = 0; i < 100; i++) arr[i] = 0;
	// memset(arr, 0, sizeof(arr));
	
	int pos = 0;
	for (; N > 0; pos++) {
		arr[pos] = N % b;
		N /= b;
	}
	
	for (pos--; pos >= 0; pos--) {
		cout<<arr[pos];
	}
	
	cout<<endl;
	
	return 0;
}