#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/1979/B*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  
#define BIT 64
    void solve(){
        ll x,y;cin>>x>>y;
        bitset<BIT>bx(x) , by(y);
        ll lcs = 0;
        for(int i=0;i<BIT;i++){
            if(bx[i] == by[i])
            {
                lcs++;
            }
            else{break;}
        }
        cout<<(1ll<<lcs);N();
    }
    void WRONG_APPROACH(){
        ll x,y;cin>>x>>y;
        bitset<BIT>bx(x) , by(y);
        ll lcs = 0 , c = 0 , xlz = false , ylz{false};
        for(int i=BIT-1;i>=0;i--){
            if( (bx[i] == 0 && !xlz ) || (by[i] == 0 && !ylz )){
                continue;
            }
            if(bx[i] == 1){ xlz = true; }
            if(by[i] == 1){ ylz = true; }
            if(bx[i] == by[i])
            {
                c++;
            }
            else
            {
                c = 0;
            }
            lcs = max(c,lcs);
        }
        lcs = max(c,lcs);
        cout<<(1<<lcs);N();
    }


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
