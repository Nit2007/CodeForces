#include <bits/stdc++.h> /*https://codeforces.com/contest/2246/problem/C*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  
    const int MOD = 1e9 + 7 ;
    void solve(){
        int n;cin>>n;
        vector<int>nums = readVector<int>(n);
        int distinct = 1 ;
        int gapIsOne = 1;
        for(int i=0;i<n-1;++i){
            if(nums[i] != nums[i+1]){
                distinct++;
            }
            if(nums[i]+1 == nums[i+1]){
                gapIsOne++;
            }
        }
        ll ans = 0;
        ll base = binPower(2,n-distinct);
        if(nums[0] != -1){
            ans = base;
        }else{
            ans = (base * gapIsOne) % MOD;
        }
        cout<<ans;N();
    }
/*
Number of Odd_Subsets  + Even_subsets = All subsets {where both the even & odd subsets are equal}
s = {A,B,C,D} => {} {A,B} {B,C} {A,C} {A,D} {B,D} {C,D} {A,B,C,D}, 2 POWER (ELE-1) Even_COMBOS POSSIBLE
-1 can seal gap of ONE ,hence multiply the no of such gaps to the base if -1 exist
*/
    ll binPower(ll a,ll b){
        ll res = 1;
        a %= MOD;
        while(b>0){
            if(b&1){
                res = (res*a)%MOD;
                res %= MOD;
            }
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res%MOD;
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
    template<typename A, typename B>
    string TO_STRING(const pair<A,B>& p){
        stringstream ss;
        ss << "(" << p.first << ", " << p.second << ")";
        return ss.str();
    }
    template<typename T>
    string TO_STRING(const T& x){
        stringstream ss;
        ss << x;
        return ss.str();
    }
    template<typename K, typename V>
    void printMap(const string& name, const map<K,V>& mp){
        cout << "\n========== " << name << " ==========\n";
        if(mp.empty()){
            cout << "(empty)\n";
            return;
        }
        cout << "Key\tValue\n";
        cout << "---------------\n";
        for(const auto &x : mp){
            cout << TO_STRING(x.first) << '\t'
                << TO_STRING(x.second) << '\n';
        }
    }
    template<typename T>
    struct is_map : false_type {};
    template<typename K, typename V, typename C, typename A>
    struct is_map<map<K,V,C,A>> : true_type {};
    template<typename T>
    struct is_pair : false_type {};
    template<typename A, typename B>
    struct is_pair<pair<A,B>> : true_type {};
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
        int i = 0;
        ([&](auto&& arg){
            using T = decay_t<decltype(arg)>;
            if constexpr (is_map<T>::value){
                printMap(keys[i++], arg);
            }
            else if constexpr (is_pair<T>::value){
                cout << keys[i++] << " : ("
                    << arg.first << ", "
                    << arg.second << ") | ";
            }
            else{
                cout << keys[i++] << " : "
                    << arg << " | ";
            }
        }(args), ...);
        cout << '\n';
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

/*---------------------NUMBER-THEORY-----------------------*/
vector<int>primeFactors(int x){
    vector<int>f;
    for(int i=1;i*i<=x;i++){
        if(x%i == 0){
            f.push_back(i);
            if(i != (x/i)){
                f.push_back(x/i);
            }
        }
    }
    sort(f.begin(),f.end());
    return f;
}