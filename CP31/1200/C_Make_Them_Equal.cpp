#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/1594/C*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){
        int n;cin>>n;
        char c;cin>>c;
        string s;cin>>s;
        if(count(s.begin(),s.end(),c) == n){
            cout<<0;N();return;
        }
        for(int i=2;i<=n;i++){
            bool valid = true;
            for(int j=i;j<=n;j+=i){
                if(s[j-1] != c ){
                    valid = false;
                    break;
                }
            }
            if(valid){
                cout<<1;N();
                cout<<i;N();return;
            }
        }
        cout<<2;N();
        cout<<n<<" "<<n-1;N();
    }
    // void solve(){
    //     int n;cin>>n;
    //     char c;cin>>c;
    //     string s;cin>>s;
    //     if(count(s.begin(),s.end(),c) == n){
    //         cout<<0;N();return;
    //     }
    //     for(int i=n-1;i>=0;i--){
    //         if(s[i] == c){
    //             cout<<1;N();
    //             cout<<i+1;N();return;
    //         }
    //     }
    //     cout<<2;N();
    //     cout<<n<<" "<<n-1;N();
    // }


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
