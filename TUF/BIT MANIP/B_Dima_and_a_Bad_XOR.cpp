#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/1151/B*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int MOD = 1e9+7;const int BIT = 32;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){
        int n,m;cin>>n>>m;
        vector<vector<int>>nums(n);
        for(int i=0;i<n;i++){
            nums[i] = readVector<int>(m);
        }
        int xr = 0;
        for(int i=0;i<n;i++){
            xr = xr ^ nums[i][0] ;
        }
        bool valid = false;
        if(xr){
            valid = true;
        }
        vector<int>d(n,false);
        for(int i=0;i<n;i++){
            set<int>uni;
            for(int j=0;j<m;++j){
                uni.insert(nums[i][j]);
            }
            if(uni.size() > 1){
                d[i] = true;
                valid = true;
            }
        }
        if(!valid){
            cout<<"NIE";
        }else{
            cout<<"TAK"; N();
            if(xr != 0){
                vector<char>Ans(n,'1');
                PRINT(Ans);
            }else{
                for(int i=0;i<n;i++){
                    int fl = 1;
                    if(d[i] == true && valid){
                        valid = false;
                        for(int j=0;j<m;j++){
                            if(nums[i][0] != nums[i][j]){
                                fl = j+1;
                                break;
                            }
                        }
                    }
                    cout<<fl<<" ";
                }
            }
        }
    }
/*
XOR ALL FIRST ELE => NON-ZERO => ANS(N,1)
                  => ZERO => TRY AN UNIQUE ELE IN AN ARRAY , THE REST of the ele are FIRST eles
*/
    // void solve(){
    //     int n,m;cin>>n>>m;
    //     vector<vector<int>>nums(n);
    //     for(int i=0;i<n;i++){
    //         nums[i] = readVector<int>(m);
    //     }
    //     map<int,int>f;
    //     for(auto& row:nums){
    //         set<int>seen;
    //         sort(row.begin(),row.end());
    //         for(auto x:row){
    //             if(seen.count(x) == 0){
    //                 seen.insert(x);
    //                 f[x]++;
    //             }
    //         }
    //     }
    //     bool valid = false;
    //     vector<int>repeat ;
    //     for(auto [val,rep] : f){
    //         repeat.push_back(rep);
    //         if(rep%2 == 0){
    //             valid = true;
    //         }
    //     }
    //     if(f.size() == 1 && ((f.begin()->second) %2 == 1) ){
    //         valid = true;
    //     }
    //     vector<int>parity;
    //     for(auto x:repeat){
    //         parity.push_back(x%2);
    //     }
    //     sort(parity.rbegin(),parity.rend());
    //     if(parity.size()>=2 && parity[0] == 1 && parity[1] == 1){
    //         valid = true;
    //     }
    //     if(!valid){
    //         cout<<"NIE";
    //     }else{
    //         cout<<"TAK"; N();
    //     }
    // }


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
