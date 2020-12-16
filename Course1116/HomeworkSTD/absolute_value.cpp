#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	if (N == -2147483648) {
		cout<<"2147483648"<<endl;
	} else {
		if (N > 0) {
			cout<< N <<endl;
		} else {
			cout<< -N <<endl;
		}
	}
	
	return 0;
}

/* Two cheating ways
1. Use "long"
2. Use abs()
*/