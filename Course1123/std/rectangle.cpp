#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin>>N;

	//First Line
	for (int i = 0; i < N; i++) cout<<"*";
	cout<<endl;
	
	// Avoid N=1 case
	if (N > 1) {
		
		// Lines in middle
		for (int i = 0; i < N-2; i++) {
			cout<<"*";
			for (int j = 0; j < N-2; j++) cout<<" ";
			cout<<"*"<<endl;
		}
		
		// Last Line
		for (int i = 0; i < N; i++) cout<<"*";
		cout<<endl;
	}
	
	system("pause");
	return 0;
}

/*

N=3
***
* *
***

N=4
****
*  *
*  *
****


*/
