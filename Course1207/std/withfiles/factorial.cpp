#include<bits/stdc++.h>

using namespace std;

int main() {
	freopen("factorial.in", "r", stdin);
	freopen("factorial.out", "w", stdout);
	int N;
	cin>>N;
	
	int s = 0;
	long long i = 5;
	while (i <= N) {
		s += N / i;
		i *= 5;
	}
	
	cout<<s<<endl;
	return 0;
}