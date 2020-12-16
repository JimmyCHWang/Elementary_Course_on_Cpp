#include<bits/stdc++.h>

using namespace std;

int main() {
	int head, foot;
	cin>>head>>foot;
	
	int x, y;
	y = (foot - 2 * head) / 2;
	x = head - y;
	cout<<x<<" "<<y<<endl;
	
	return 0;
}

/*
Let chick = x, hare = y
x + y = head => 2x + 2y = 2head
2x + 4y = foot

2y = foot - 2head
y = (foot - 2head) / 2
x = head - y
*/