#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/2242/D*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int MOD = 1e9+7;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){
        string a,b;cin>>a>>b;
        int n = a.length() , m = b.length() ;
        vector<int>pa(n+1,0) , pb(m+1,0);
        for(int i=1;i<=n;i++){
            pa[i] = (pa[i-1] + (a[i-1]-'0'))%10;
        }
        for(int i=1;i<=m;i++){
            pb[i] = (pb[i-1] + (b[i-1]-'0'))%10;
        }
        if(*pa.rbegin() != *pb.rbegin()){
            cout<<-1;N();return;
        }
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(pa[i] == pb[j]){ //New segment
                    dp[i][j] = dp[i-1][j-1] + 1 ;
                }else{ 
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]) ;
                }
            }
        }
        // for(auto v:dp){PRINT(v);}  ND();   
        cout<<dp[n][m];N();
    }
/*
PARITION A,B BASED ON ADJACENT ELEMENTS SUCH 
THAT BOTH OF ITS SUM%10 ARE EQUAL {WITH MAXIMAL NO OF SEGEMENTS}
a - { [0,i1] [i1+1,i2] [i2+1,n] }
a - { [0,j1] [j1+1,j2] [j2+1,n] }
a - [0,i]
b - [0,j]
dp[i][j] = max No of chars
if(pa[i] == pb[j]){
    dp[i][j] = dp[i-1][j-1] + 1
}else{
    dp[i][j] = max(dp[i-1][j],dp[i][j-1])
}

05147-> [0,5,6,1,8]
44441-> [4,8,2,6,7]
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
