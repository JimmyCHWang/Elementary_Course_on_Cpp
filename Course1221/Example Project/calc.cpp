#include <bits/stdc++.h>
#include "calc_methods.h"

using namespace std;

int main() {
	int a,b,c; // a and b are operands.
	cin >> a >> b >> c;
	
	int result = 0;
	switch (c) {
		case (1):
			result = add(a,b);
			break;
		case (2):
			result = sub(a,b);
			break;
		case (3):
			result = mult(a,b);
			break;
		case (4):
			result = divide(a,b);
			break;
		default:
			cerr << "Wrong Operator!" << endl;
			//system("break");
			exit(0);
			break;
	}
	cout<<result<<endl;
	
	//system("break");
	return 0;
}