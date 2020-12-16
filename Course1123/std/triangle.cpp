#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin>>N;

	//int M = 2 * N - 1;
	for (int i = 0; i < N; i++) {
		int spaces = N - i - 1;
		for (int j = 0; j < spaces; j++) cout<<" ";
		for (int j = 0; j < 2 * i + 1; j++) cout<<"#";
		for (int j = 0; j < spaces; j++) cout<<" ";
		cout<<endl;
	}
	system("pause");
	return 0;
}
