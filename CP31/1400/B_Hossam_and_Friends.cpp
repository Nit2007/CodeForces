#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/1771/B*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int MOD = 1e9+7;const int BIT = 32;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){
        ll n,m;cin>>n>>m;
        vector<int>rightEnemy(n+1,n);
        for(int i=1;i<=m;i++){//For every Ai , find the smallest rightmost ending
            int big , small;cin>>big>>small;
            if(small > big)swap(big,small);
            rightEnemy[small] = min(rightEnemy[small],big-1);
        }
        for(int i=n-1;i>=0;i--){//Break segements
            rightEnemy[i] = min(rightEnemy[i+1],rightEnemy[i]);
        }
        // PRINT(rightEnemy);
        ll ans = 0 ;
        for(int i=1;i<=n;i++){
            ans += rightEnemy[i] - i + 1;
        } 
        cout<<ans;N(); 
    }

    //Assuming gangs only dependent on adj ele
    // void solve(){
    //     ll n,m;cin>>n>>m;
    //     map<int,vector<int>>notFriends ;
    //     for(int i=0;i<m;i++){
    //         int u , v;cin>>u>>v;
    //         notFriends[u].push_back(v);
    //         notFriends[v].push_back(u);
    //     }
    //     vector<int>gangs;
    //     ll ans = 0 , size = 1;
    //     for(int i=1;i<=n;i++){
    //         const auto &nf = notFriends[i];
    //         if(i!=n && find(nf.begin(),nf.end(),i+1) == nf.end()){
    //             size++;
    //         }else{
    //             gangs.push_back(size);
    //             size = 1;
    //         }
    //     } 
    //     if(size != 1) gangs.push_back(size);
    //     // PRINT(gangs);
    //     for(ll g:gangs){
    //         ans += ((g) * (g+1)) / 2 ;
    //     }
    //     cout<<ans;N(); 
    // }
/*
5 2
1 2
2 3
1 2 3-4-5

3 1
1 3
1 2 3
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

signed main(){
    Main OBJ;
    return OBJ.run();
}
