#include<bits/stdc++.h>

using namespace std;

int sum_of_array(int* a, int N) { 
	int result = 0;
	for (int i = 0; i < N; i++) {
		result += a[i];  //result += *(a+i);
	}
	return result;
}


int main() {
    int N; cin>>N;
    int a[5000];
    for (int i = 0; i < N; i++) cin>>a[i];
    cout << sum_of_array(a, N) << endl;
    return 0;
}