#include<bits/stdc++.h>

using namespace std;

int main() {
	long long N;
	cin>>N;
	
	int s = 0;
	while (N != 0) {
		s += N % 10;
		N /= 10;
	}
	
	cout<<s<<endl;
		
	return 0;
}