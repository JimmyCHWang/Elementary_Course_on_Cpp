#include<bits/stdc++.h>

using namespace std;

int num_of_digits(int N) {
    // Write your program here
	if (N == 0) return 1;
	int result = 0;
	while (N != 0) {
		N /= 10;
		result++;
	}
	return result;
}

int main() {
	int N;
    cin>>N;
    cout<<num_of_digits(N)<<endl;
    return 0;
}