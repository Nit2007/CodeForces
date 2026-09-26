#include <bits/stdc++.h> /*https://codeforces.com/contest/2140/problem/c*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int MOD = 1e9+7;const int BIT = 32;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  
#define int ll
    void solve(){
        int n;cin>>n;
        vector<int>nums = readVector<int>(n);
        int base{};
        for(int i=0;i<n;i++){
            if(i%2)base-=nums[i];
            else base+=nums[i];
        }
        int noChangeSwap = (n%2)? (n-1) : (n-2) ; //Swap at same Parity changes nothing
        int l_odd = INT_MAX , l_even = INT_MAX , best{};
        for(int i=0;i<n;i++){
            if(i%2){
                if(l_odd != INT_MAX){ //l_odd & r_even
                    best = max(best, i+2*nums[i]-l_odd);
                }
                l_even = min(l_even,i-2*nums[i]);
            }else{
                if(l_even != INT_MAX){ //l_even & r_odd
                    best = max(best, i-2*nums[i]-l_even);
                }
                l_odd = min(l_odd,i+2*nums[i]);
            }
        }
        best = max(best,noChangeSwap);
        cout<<base+best;N();
    }
/*
If a player seems winning ,the losing player would stop the game immediately (so 10^100 op never happens)
Good to swap the smallest_odd +ve with largest_eve +ve |
                 largest_odd -ve with smallest_eve -ve
                 => then the game would end ,at cost of their different index

Possible:
    Either Alice already has reached the max potential - shuffle the end numbers to inflate cost
    Alice performs the greedy action that increases value
    =>at both scenario Bob ends the game (as even if Bob tries something ,Alice reverses it {final cost increases} )

CASE :      l_odd          |      l_even
Gain = (r-l) + 2(Ar-Al)    |  (r-l) + 2(Ar-Al)
Gain = (r+2Ar) - (l+2Al)   |  (r-2Ar) - (l-2Al)
As we want maximal score,Look for minimal L

[7,1,8,4] => 10
[7,8]
[1,4]
+2 [7,4,8,1] => 12
[7,8]
[4,1]
*/

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
};

signed main(void){
    Main OBJ;
    return OBJ.run();
}
