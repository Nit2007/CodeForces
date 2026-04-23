#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  
    const int limit = 200005;
    vector<int>factors = vector<int>(limit,0);
    // sum = x + (-y) = x - y
    // sum = K_subarray * sumOfsubarray
    // K_subarray * sumOfsubarray = x - y
    // sumOfsubarray = x - y / K_subarray
    // f(a) = no of valid K , which means what are the possible divisors of abs(x-y)
    void solve(){//2211B
        int x,y; cin>>x>>y;
        int diff = abs(x - y) ;
        
        int ans = factors[diff];
        if(x == y)ans = 1;
        cout<<ans<<endl;//ND();
        for(int i=0;i<x;i++){
            cout<<1<<" ";
        }
        for(int i=0;i<y;i++){
            cout<<-1<<" ";
        }
        N();
    }
    void precompute(){
        for(int i =1 ;i<limit;i++){
            for(int j=i;j<limit;j+=i){
                factors[j] += 1;
            }
        }
    }




    int run() {
        ios_base::sync_with_stdio(false);   cin.tie(NULL);
        int z;cin>>z;
        precompute();
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