#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/1879/C*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
const int MOD = 998244353;
class Main{
public:  

    void solve(){
        string s;
        cin>>s;
        int n = (int)s.length();
        vector<int>same(0);
        int curr = 1;
        for(int i=0;i+1<n;++i){
            if(s[i] == s[i+1]){
                curr++;
            }else{
                same.push_back(curr);
                curr = 1;
            }
        }
        same.push_back(curr);
        // PRINT(same);ND();
        ll minOperation = 0;
        ll ways = 1;
        for(int x:same){ 
            minOperation += x-1;
            ways = (ways * x) %MOD;//Fix the survivor at every Block
        }
        for(ll i=1;i<=minOperation;++i){//Order of deletions matter
            ways = (ways*i) % MOD;
        }
        cout<<minOperation<<" "<<ways;N();
    }

    signed run() {
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
