#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  
    void solve(){//1855B
        ll n;cin>>n;

        ll i=1;
        while(n%i == 0)i++;

        cout<<i-1;N();
    }
    //n - odd - ans is 1
    //n - not divisible by 3 - ans is 2
    //n - not divisible by 4 - ans is 3
    
    //TLE
    // void solve(){//1855B
    //     ll n;cin>>n;

    //     vector<ll>factors = uniquePrimeFactors(n);
    //     // PRINT(factors);
    //     ll window_size = 1;
    //     ll max_window_size = 1;
    //     for(int i=1;i<factors.size();i++){
    //         if(factors[i-1] == factors[i] -1){//Track the longest continuous seg out of the factors
    //             cout<<factors[i-1]<<" ";
    //             window_size++;
    //         }else{
    //             if(window_size > max_window_size){
    //                 max_window_size = window_size;
    //             }
    //             window_size = 1;
    //         }
    //     }
    //     if(window_size > max_window_size){
    //         max_window_size = window_size;
    //     }
    //     cout<<max_window_size;N();
    // }
    // vector<ll>uniquePrimeFactors(ll n){
    //     vector<ll>factors;
    //     for(ll i=1;i*i<=n;i++){
    //         if(n%i == 0){
    //             factors.push_back(i);
    //         }
    //     }
    //     return factors;
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
        vector<T> v(n);
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