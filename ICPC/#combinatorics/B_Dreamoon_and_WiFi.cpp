#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/476/B*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  
    const int MOD = 1e9 + 7;
    void solve(){
        string cmd , rec ;
        cin>>cmd>>rec;
        int net = 0;
        for(char x:cmd){
            if(x == '+')net++;
            else if(x == '-')net--;
        }
        int cur = 0;
        int superPos = 0;
        for(char x:rec){
            if(x == '+')cur++;
            else if(x == '-')cur--;
            else if(x == '?')superPos++;
        }
        int diff = net - cur;
        if((superPos + diff) %2  || abs(diff) > superPos){
            cout<<fixed<<setprecision(12)<<(double)0;
            return;
        }
        //cmd : +-+-+-
        //rec : ???-+-
        // plus + minus = superPos
        // plus - minus = diff
        int plus = (superPos + diff)/2;
        int minus = superPos - plus;
        double total = 1<<superPos ;
        cout<<fixed<<setprecision(12)<<(nCr(superPos,minus)) / total ;
    }
    int nCr(int n,int r){
        ll num = fact(n) ;
        ll den = fact(n-r) * fact(r);
        ll inv_den = binPower(den,MOD-2);
        return (num * inv_den)%MOD;
    }
    ll binPower(ll a,int b){
        ll res = 1;
        while(b){
            if(b&1){
                res = (res * a) % MOD;
            }
            a = (a * a)%MOD;
            b >>=1;
        }
        return res;
    }
    ll fact(int x){
        ll ans = 1;
        for(int i=1;i<=x;i++){
            ans *= i;
        }
        return ans;
    }
    // void solve(){
    //     string cmd , rec ;
    //     cin>>cmd>>rec;
    //     int net = 0;
    //     for(char x:cmd){
    //         if(x == '+')net++;
    //         else if(x == '+')net--;
    //     }
    //     int cur = 0;
    //     int superPos = 0;
    //     for(char x:rec){
    //         if(x == '+')cur++;
    //         else if(x == '-')cur--;
    //         else superPos++;
    //     }
    //     int diff = net - cur;
    //     if(diff > superPos){
    //         cout<<fixed<<setprecision(12)<<(double)0;
    //         return;
    //     }
    //     cout<<nCr(superPos,diff) ;
    // }
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
