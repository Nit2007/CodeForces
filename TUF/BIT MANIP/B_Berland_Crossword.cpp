#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/1494/B*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int MOD = 1e9+7;const int BIT = 32;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  
    int valid = false;
    void solve(){
        int n,u,r,d,l;cin>>n>>u>>r>>d>>l;
        int safe = n-2;
        for(int mask=0;mask<=(1<<4);mask++){
            auto [U,R,D,L] = array{u,r,d,l};
            if(mask & (1<<0) ){
                U--;
                R--;
            }
            if(mask & (1<<1) ){
                D--;
                R--;
            }
            if(mask & (1<<2) ){
                D--;
                L--;
            }
            if(mask & (1<<3) ){
                U--;
                L--;
            }
            if((min({U,R,D,L}) >= 0) && (max({U,R,D,L}) <= safe) ){
                cout<<"YES";N();return; 
            }
        }
        cout<<"NO";N();
    }
    // void solve(){
    //     int n,u,r,d,l;cin>>n>>u>>r>>d>>l;
    //     int safe = n-2;
    //     if(u<=safe && r<=safe && d<=safe && l<=safe){
    //         cout<<"YES";N();return;
    //     }
    //     vector<int>sides = {u,r,d,l};
    //     sort(sides.begin(),sides.end(),greater<int>());
    //     if(sides[0] <= safe+1){
    //         cout<<"YES";N();return;
    //     }
    //     sides = {u,r,d,l} ;
    //     vector<int>extras;
    //     for(auto s:sides){
    //         extras.push_back(max(s-safe,0));
    //     }
    //     for(int i=0;i<4;i++){
    //         int s1 = (i+1)%4;
    //         int c = (i+2)%4;
    //         int s2 = (i+3)%4;
    //         if(extras[i] == 1){
    //             if(max(sides[s1],sides[s2]) == 0){
    //                 cout<<"NO";N();return;
    //             }
    //         } 
    //         if(extras[i] == 2){
    //             if(extras[c] == 1){
    //                 if(min(sides[s1],sides[s2]) == 0){
    //                     cout<<"NO";N();return;
    //                 }
    //             }
    //             if(extras[c] == 2){
    //                 if(max(sides[s1],sides[s2]) == 1){
    //                     cout<<"NO";N();return;
    //                 }
    //             }
    //         } 
    //     }
    //     cout<<"YES";N();
    // }

/*
    corners = {ur,dr,dl,ul} 
    EXTARS  = {0,2,0,0}
       u
    #------#
 l  |      |  r
    |      |
    #------#
       d
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
