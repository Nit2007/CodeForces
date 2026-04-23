#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:
    void solve(){//2218D
        int n;cin>>n;
        
        ll x = 3;
        ll i = 1;
        vector<ll>ans(n,1);

        while(i < n){
           ans[i] = x * (x+2);
           i++;
           x += 2;
        }
        PRINT(ans);
        
    }
    //Control GCD from 1 to N to get distinct GCDs
    // Numbers  - gcd of previous N,current n
    // x = 1 (ODD)
    // x   * x+2 - 1
    // x+2 * x+4 - x+2 
    // x+4 * x+6 - x+4
    // x+6 * x+8 - x+6


    // bool isPrime(ll n){
    //     for(int i=2;i*i<=n;i++){
    //         if(n%i == 0)return false;
    //     }
    //     return true;
    // }
    // vector<int> prime(){
    //     vector<int> p(0) ;
    //     for(int i=0;i<1000000;i++){
    //         if(isPrime(i))p.push_back(i);
    //     }
    //     return p;
    // }
    // void solve(vector<int>prime){//2218D
    //     int n;cin>>n;
        
    //     ll index = 1;
    //     ll a = prime[index];
    //     ll div = 2;
    //     vector<ll>ans(0);
    //     while(ans.size() < n){
    //         a *= div;
    //         ans.push_back(a);
    //         if(a > pow(10,16)){
    //             div++;
    //             a = prime[index++];
    //         }
    //     }
    //     // PRINT(prime);
    //     PRINT(ans);

    // }





    int run() {
        ios_base::sync_with_stdio(false);   cin.tie(NULL);
        int z;cin>>z;
        while(z--){ solve();}
        return 0;
    }
    


    template<typename T>
    void PRINT(const vector<T>& v){
        for(int i1=0;i1<(int)v.size();i1++) cout<<v[i1]<<" ";
        cout<<endl;
    }

    template<typename T>
    void PRINTS(const string& s,const vector<T>& v){
        cout<<s<<" : ";
        for(int i1=0;i1<(int)v.size();i1++) cout<<v[i1]<<" ";
        cout<<endl;
    }
    void N(){cout<<"\n";}
    void ND(){cout<<"---DEBUG___";cout<<"\n";}

    template<typename T>
    vector<T> readVector(int n){
        vector<T> v((unsigned int)n);
        for(auto &x : v) cin >> x;
        return v;
    }
    template<typename T>
    vector<T> makeUnique(vector<T>& v){
        unordered_set<T>seen;
        vector<T>unique;
        for(auto &x:v){
            if(seen.insert(x).second)unique.push_back(x);
        }return unique;
    }
};

int main(){
    Main OBJ;
    return OBJ.run();
}
