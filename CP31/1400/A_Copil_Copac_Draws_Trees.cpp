#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/1830/A*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){
        int n;cin>>n;
        vector<vector<int>>adj(n);
        map<pair<int,int>,int>ind;
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
            ind[{u,v}] = i;
            ind[{v,u}] = i;
        }   
        vector<int>dp(n,0);
        ind[{-1,0}] = -1; 
        dp[0] = 1;
        dfs(0,-1,adj,ind,dp);
        // PRINT(dp);
        cout<<*max_element(dp.begin(),dp.end());N();
    }
    void dfs(int curr,int parent,vector<vector<int>>&adj,map<pair<int,int>,int>&ind,vector<int>&dp){
        for(int child:adj[curr]){
            if(child == parent)continue;
            if(ind[{parent,curr}] < ind[{curr,child}]){
                dp[child] = dp[curr];
            }else{
                dp[child] = dp[curr] + 1;
            }
            dfs(child,curr,adj,ind,dp);
        }
    }

    /*
    To visit child, current must be drawn , so similarly 
    for current to be drawn , we need its parent to be drawn
    Parent
     | 
    Current
     | 
    child
    */


    ////TLE on test 4
    // void solve(){
    //     int n;cin>>n;
    //     vector<pair<int,int>>edge;
    //     for(int i=0;i<n-1;i++){
    //         int u,v;
    //         cin>>u>>v;
    //         edge.push_back(make_pair(u,v));
    //     }    
    //     set<int>drawn = {1};
    //     int readings = 0;
    //     while(drawn.size() != n){
    //         readings++;
    //         for(auto [u,v] : edge){
    //             if(drawn.count(u) && !drawn.count(v)) {
    //                 drawn.insert(v);
    //             }
    //             else if(drawn.count(v) && !drawn.count(u)){
    //                 drawn.insert(u);
    //             }
    //         }   
    //     }
    //     cout<<readings;N();
    // }


    // void solve(){
    //     int n;cin>>n;
    //     vector<pair<int,int>>edge;
    //     for(int i=0;i<n-1;i++){
    //         int u,v;
    //         cin>>u>>v;
    //         edge.push_back(make_pair(u,v));
    //     }    
    //     set<int>drawn = {1};
    //     int readings = 0;
    //     for(auto [u,v] : edge){
    //         if(drawn.count(u) && !drawn.count(v)) {
    //             drawn.insert(v);
    //         }
    //         else if(drawn.count(v) && !drawn.count(u)){
    //             drawn.insert(u);
    //         }else if(drawn.count(v) && drawn.count(u)){
    //             continue;
    //         }else{
    //             readings++;
    //         }
    //         if(drawn.size() == n){break;}
    //     }   
    //     cout<<readings;N();
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