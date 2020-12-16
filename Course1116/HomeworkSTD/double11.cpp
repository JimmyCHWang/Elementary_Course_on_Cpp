#include<bits/stdc++.h>

using namespace std;

int main() {
	int N, M;
	cin>>N>>M;
	
	int x = N / M; // How many groups
	cout << N-x << endl;
	
	return 0;
}