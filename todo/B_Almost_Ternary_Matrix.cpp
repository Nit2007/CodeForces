#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/1699/B*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){
        int n,m;cin>>n>>m;
        int a = n/2 , b = m/2;
        vector<vector<int>>mat(a,vector<int>(b,0));
        mat[0][0] = 1;
        for(int i=1;i<b;i++){
            mat[0][i] = mat[0][i-1] ^ 1 ;
        }
        for(int i=1;i<a;i++){
            mat[i][0] = mat[i-1][0] ^ 1 ;
        }
        for(int i=1;i<a;i++){
            for(int j=1;j<b;j++){
                mat[i][j] = mat[i-1][j] ^ mat[i][j-1] ;
            }
        }
        vector<vector<int>>ul(a,vector<int>(b,0));
        int i=0;
        for(auto x:mat){
            reverse(x.begin(),x.end());
            for(auto &e:x)e ^= 1;
            ul[i++] = x;
        }
        for(int i=0;i<mat.size();i++){
            auto x = mat[i];
            PRINT(x);
            auto y = ul[i];
            PRINT(y);
            N();
        }
        for(int i=mat.size()-1;i>=0;i--){
            auto &x = mat[i];
            for(auto&e:x){e ^= 1;}
            PRINT(x);
            auto &y = ul[i];
            for(auto&e:y){e ^= 1;}
            PRINT(y);
            N();
        }
    }
// 1 0 1 0
// 0 0 1 1
// 1 1 0 0
// 0 1 0 1

// 1 0 1 X X X
// 0 0 1 X X X
// 1 1 1 X X X
// X X X X X X
// X X X X X X
// 0 X X X X X


    signed run() {
        ios_base::sync_with_stdio(false);   cin.tie(NULL);
        int z;cin>>z;
        while(z--){ solve(); }
        return 0;
    }

    


    template<typename T>
    void PRINT(const vector<T>& v){
        for(int i1=0;i1<(int)v.size();i1++) cout<<v[i1]<<" ";
        // cout<<endl;
    }

    template<typename T>
    void PRINTS(const string& s,const vector<T>& v){
        cout<<s<<" : ";
        for(int i1=0;i1<(int)v.size();i1++) cout<<v[i1]<<" ";
        // cout<<endl;
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
