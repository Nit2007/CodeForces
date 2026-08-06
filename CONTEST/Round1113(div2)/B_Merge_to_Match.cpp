#include <bits/stdc++.h> /*https://codeforces.com/contest/2248/problem/B*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int MOD = 1e9+7;const int BIT = 32;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void Arpa(){
        int n,m;cin>>n>>m;
        vector<int>a = readVector<int>(n);
        vector<int>b = readVector<int>(m);
        if( (n/2) < m){
            cout<<"NO";N();return;
        }
        map<int,int>line;
        for(int i:a){
            line[i]++;
        }
        for(int i:b){
            line[i]--;
        }
        bool ans = true;
        int box{};
        for(auto [val,rep] : line){
            box += rep;
            if(box < 0){
                ans = false;
                break;
            }
        }
        box = 0;
        for (auto it = line.rbegin(); it != line.rend(); ++it) {
            auto [val,rep] = *it;
            box += rep;
            if(box < 0){
                ans = false;
                break;
            }
        }
        if(ans){
            cout<<"YES";
        }else{
            cout<<"NO";
        }
        N();
    }
    void solve(){
        int n,m;cin>>n>>m;
        vector<int>a = readVector<int>(n);
        vector<int>b = readVector<int>(m);
        if( (n/2) < m){
            cout<<"NO";N();return;
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int i=0;
        bool ans = true;
        while(i<m && a[i] <= b[i] && b[i] <= a[n-m+i]){//Interval of [smallest , extra] for b[i]
            i++;
        }
        if(i<m){ans = false;}
        if(ans){
            cout<<"YES";
        }else{
            cout<<"NO";
        }
        N();
    }

    // void solve(){
    //     int n,m;cin>>n>>m;
    //     vector<int>a = readVector<int>(n);
    //     vector<int>b = readVector<int>(m);
    //     sort(a.begin(),a.end());
    //     sort(b.begin(),b.end());
    //     int i{n-1},j{m-1};
    //     bool ans = true;
    //     while(j>=0 && i>=0){
    //         if(i > 0){
    //             if(a[i-1] <= b[j] && b[j] <= a[i]){
    //                 i -= 2;
    //                 j -= 1;
    //                 continue;
    //             }else{
    //                 ans = false;break;
    //             }
    //         }else{
    //             ans = false;break;
    //         }
    //     }
    //     // if(i == 0 && j>=0){ans = false;}
    //     if(ans){
    //         cout<<"YES";
    //     }else{
    //         cout<<"NO";
    //     }
    //     N();
    // }

/*
1 2 6 9 
7 8

4 2
1 3 5 7
4 6

3 2
1 3 5
2 4
*/


    signed run() {
        ios_base::sync_with_stdio(false);   cin.tie(NULL);
        int z;cin>>z;
        while(z--){ Arpa(); }
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
