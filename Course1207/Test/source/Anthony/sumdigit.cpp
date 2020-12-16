#include <iostream>

using namespace std;

int main()
{
    int N;
    int x=0;
    int s=0;
    cin>>N;
    while (N> 0){
       x=N%10;
       s=s+x;
       N=N/10;
    }cout<<s<<endl;
    return 0;
    }

