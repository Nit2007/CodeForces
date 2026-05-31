#include <bits/stdc++.h>
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){//1869B
        ll n,k,a,b;cin>>n>>k>>a>>b;
        vector<vector<ll>>nums(0);
        for(int i=0;i<n;i++){
            ll x,y,Major;
            cin>>x>>y;
            Major = (i<k)? true : false;
            nums.push_back({x,y,Major});
        }
        vector<ll>source = nums[a-1];
        vector<ll>dest = nums[b-1];
        ll ans = llabs(source[0] - dest[0]) + llabs(source[1] - dest[1]);
        ll sourceToNet = LLONG_MAX/2 , netToDest = LLONG_MAX/2;
        for(int i=0;i<k;i++){//MANHATTAN_DIST = (MANHATTAN_DIST of Reaching Major Net from Source) + (MANHATTAN_DIST of Reaching Dest from Major Net)
            sourceToNet = min(sourceToNet, llabs(source[0] - nums[i][0]) + llabs(source[1] - nums[i][1])) ;
            netToDest = min(netToDest, llabs(dest[0] - nums[i][0]) + llabs(dest[1] - nums[i][1])) ;
        }
        cout<<min(ans,sourceToNet + netToDest) ;N();
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
