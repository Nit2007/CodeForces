#include <bits/stdc++.h> /*https://codeforces.com/gym/102694/problem/A*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int MOD = 1e9+7;const int BIT = 32;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public: 
    void solve(){
        int n;cin>>n;
        vector<vector<int>>adj(n);
        for(int i=1;i<n;i++){
            int u,v;cin>>u>>v;
            u--;v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>dist(n,0);
        dfs(0,-1,adj,dist);
        int A = distance(dist.begin() , max_element(dist.begin(),dist.end()));
        vector<int>distA(n,0);
        dfs(A,-1,adj,distA);
        cout<<3ll * (*max_element(distA.begin(),distA.end()));
    }
    void dfs(int node,int parent,vector<vector<int>>&adj,vector<int>&dist){
        for(auto child:adj[node]){
            if(child == parent)continue;
            dist[child] = dist[node] + 1; 
            dfs(child,node,adj,dist);
        }
    }

    signed run() {
        ios_base::sync_with_stdio(false);   cin.tie(NULL);
        int z=1;
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
