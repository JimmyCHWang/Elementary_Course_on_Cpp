#include<bits/stdc++.h>

using namespace std;

int main() {
	freopen("sumdigit.in", "r", stdin);
	freopen("sumdigit.out", "w", stdout);
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