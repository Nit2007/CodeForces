#include <bits/stdc++.h>
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){//1742E
        ll n,q;cin>>n>>q;
        vector<ll>nums = readVector<ll>(n);
        vector<ll>query = readVector<ll>(q);

        vector<ll>height(n,nums[0]);
        vector<ll>prefixMax(n,nums[0]);
        for(ll i=1;i<n;i++){
            height[i] = height[i-1] + nums[i] ;
            prefixMax[i] = max(prefixMax[i-1],nums[i]);
        }
        // PRINT(height);
        for(auto Q:query){
            ll l = 0;
            ll r = n-1;
            ll ans = -1;
            while(l<=r){
                ll m = (r-l)/2 + l;
                 if(prefixMax[m] <= Q){
                    l = m+1;
                    ans = m;
                }else{//Too BIG
                    r = m-1;
                }
            }
            if(ans == -1){
                cout<<0<<" ";
            }else{
                cout<<height[ans]<<" ";
            }
        }
        N();
    }





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

int main(){
    Main OBJ;
    return OBJ.run();
}
