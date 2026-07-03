#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/300/C*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  
    const int MOD = 1000000007;
    void solve(){
        int a,b,n;cin>>a>>b>>n;
        vector<ll> fact = factorial(n);
        ll res = 0;
        for(int i=0;i<=n;i++){
            int sum = (a * i) + (b * (n-i));
            if(check(a,b,sum)){
                res += nCr(n,i,fact);
                res %= MOD;
            }
        }
        cout<<res;N();
    }
    ll nCr(int n,int i,vector<ll>&fact){
        ll num = fact[n];
        ll den = ( fact[n-i] * fact[i] ) %MOD;
        ll inv_den = binPower(den,MOD-2);
        return ((num % MOD) * (inv_den % MOD)) % MOD;
    }
    ll binPower(ll a,ll b){ 
        ll res = 1;
        while(b){
            if(b&1){
                res = (res * a) % MOD ;
            } 
            a = (a * a ) % MOD;
            b >>= 1;
        }
        return res;
    }
    vector<ll> factorial(int n){
        vector<ll>fact(n+1,1);
        for(int i=1;i<=n;i++){
            fact[i] = (fact[i-1] * i) % MOD;
        }
        return fact;
    }
    bool check(int a,int b,int sum){
        string exe = to_string(sum);
        char A = static_cast<char>(a + '0');
        char B = static_cast<char>(b + '0');
        for(int j=0;j<exe.size();j++){
            if(exe[j] != A && exe[j] != B){
                return 0;
            }
        }
        return true;
    }

    signed run() {
        ios_base::sync_with_stdio(false);   cin.tie(NULL);
        int z=1;
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
