#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int;
#define PRINT(v) for(size_t i1=0;i1<(size_t)v.size();i1++)cout<<v[i1]<<" ";cout<<endl;
#define N cout<<endl; 

vector<ll> findUniquePrimeFactors(ll n){
    set<ll>Result;
    
    while(true){//Look for evens
        if(n%2 == 0){
            n/=2;
            Result.insert(2);
        }else break;
    }
    for(int i=3;i*i<=n;i++){//Pull out other prime factors greater than 3
        while(n%i == 0){
            n/= i;
            Result.insert(i);
        }
    }
    if(n > 2){//so now n is already a prime
        Result.insert(n);
    }
    vector<ll> uniqueResult(Result.begin(),Result.end());
    return uniqueResult;
}
void solve(){//2205B
    ll n;cin>>n;
    // (k k k k k)% 5 So if a prime x appers once in k, 
    // it is going to apperaed 'n' times ,making it divisible by n
    vector<ll> uniquePrimes = findUniquePrimeFactors(n);
    // cout<<"Primes: ";    PRINT(uniquePrimes)
    ll answer = accumulate(uniquePrimes.begin(),uniquePrimes.end(),1LL,multiplies<ll>());
    cout<<answer;N
}
int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int z;cin>>z;
    while(z--){ solve();}
}
