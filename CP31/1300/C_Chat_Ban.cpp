#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/1612/C*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){
        ll k,x;cin>>k>>x;
        ll low = 0 , high = 2 * k-1;
        ll ans = 2*k-1;
        while(low<=high){
            ll mid = low + (high-low)/2;
            if(compute(mid,k) >= x){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        cout<<ans;N();
    }
    ll compute(ll i,ll k){
        if(i<=k){
            return ((i) * (i+1)) / 2;
        }else{
            ll m = i-k;
            ll l = ((k) * (k+1)) / 2;
            ll r = m * (2 * (k - 1) - (m - 1)) / 2;            
            return l+r;
        }
    }
    // Sn = (n/2) * (2*A0 +(n-1) * d)
    //firstTerm = (2*(k-1))
    //No of terms = m
    // d = -1

    signed run() {
        ios_base::sync_with_stdio(false);   cin.tie(NULL);
        int z;cin>>z;
        while(z--){ solve(); }
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
    template<typename... Args>
    void debugPrint(const string& raw, Args&&... args){
        vector<string> keys;
        stringstream ss(raw);
        string tok;
        while(getline(ss, tok, ',')){
            while(!tok.empty() && tok.front()==' ') tok.erase(tok.begin());
            while(!tok.empty() && tok.back() ==' ') tok.pop_back();
            keys.push_back(tok);
        }
        int i=0;
        cout << " [DEBUG] ";
        ([&](auto&& arg){ cout << keys[i++] << " : " << arg << "  |  "; }(args), ...);
        cout << "\n";
    }

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

signed main(){
    Main OBJ;
    return OBJ.run();
}
