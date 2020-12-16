#include<bits/stdc++.h>

using namespace std;

int main() {
	long long N;
	cin>>N;

	int count = 0;
	while (N > 1) {
		if (N % 2 == 1) {
			// odd number
			N = N * 3 + 1;
		} else {
			// even number
			N = N / 2;
		}
		count++;
	}
	cout<<count<<endl;
	return 0;
}