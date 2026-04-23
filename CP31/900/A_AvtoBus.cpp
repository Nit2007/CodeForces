#include <bits/stdc++.h>
using namespace std;

int main(){//1679A
    long long t;
    cin>>t;
    while(t){
        long long n;
        cin>>n;
        
        if(n<4 || n%2 == 1){
            cout<<-1<<endl;
        }else{
            long long mi = (n+5)/6;
            long long ma = n/4;
            cout<<mi<<" "<<ma<<endl;
        }
        t--;
    }
}