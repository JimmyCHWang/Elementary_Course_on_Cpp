#include<bits/stdc++.h>

using namespace std;

int main() {
	int a,b,c;
	cin>>a>>b>>c;
	
	int t;
	if (a < b) {
		if (b <= c) {
			// Order abc
		} else {
			if (a < c) {
				// Order acb
				t = b;	b = c;	c = t;
			} else {
				// a >= c, order cab
				t = b;	b = a;	a = c;	c = t;
			}
		}
	} else {
		if (a <= c) {
			// order bac
			t = a;	a = b;	b = t;
		} else {
			if (b < c) {
				// order bca
				t = b;	b = c;	c = a;	a = t;
			} else {
				// order cba
				t = a;	a = c;	c = t;
			}
		}
	}
	
	// Now obeys a <= b <= c
	
	if (a + b <= c) {
		cout<<"Not a Triangle"<<endl;
	} else {
		if (a*a + b*b == c*c) {
			cout<<"Right Triangle"<<endl;
		} else {
			cout<<"Triangle"<<endl;
		}
	}
		
	return 0;
}