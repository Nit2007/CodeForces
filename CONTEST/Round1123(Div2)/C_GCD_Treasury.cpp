#include <bits/stdc++.h> /*https://codeforces.com/contest/2267/problem/C*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int MOD = 1e9+7;const int BIT = 32;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  
#define int ll
    void solve(){
        int n,x;cin>>n>>x;
        vector<int>nums = readVector<int>(n);
        vector<int>factors = primeFactors(x);
        vector<int>score(factors.size(),0);
        for(int f=0;f<factors.size();f++){
            int con = 0;
            for(int i=0;i<n;i++){
                if(nums[i] % factors[f] == 0){
                    con += nums[i];
                }
            }
            score[f] = con;
        }
        score.push_back(0);
        cout<<*max_element(score.begin(),score.end());N();
        // PRINT(score);
    }
/*
gcd(ai,x) = g
ai - g , x = g

a1 - g1 =  a1 - gcd(a1,x)
a2 - g2
a3 - g3
gcd(a3,gcd(a2,gcd(a1,x))) = gcd(a1,a2,a3,x)

Factors of x = x1,x2,x3
Possible ai :
    Pure factors of x    ==== complete kill
    Partial factors of x ==== Individual factor only can kill,but loses other factors
    No factors of x      ==== Nil

2*3,2*5 -> 2,2*4 -> Eat all
2*3,2*7 -> 2,2*6 -> 2,3 (Non factors are given up,factors do remain)
6,15 -> 3,12
6,21 -> 3,18
6,22 -> 2,11
6,45 -> 3,42 -> 3,14
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
    void yn(bool Yes){
        if(Yes)cout<<"YES\n";
        else cout<<"NO\n";
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
        for(int i=2;i*i<=x;i++){
            if(x%i == 0){
                f.push_back(i);
                while((x%i) == 0){
                    x /= i;
                }

            }
        }
        if(x > 1)
            f.push_back(x);
        sort(f.begin(),f.end());
        return f;
    }
};

signed main(void){
    Main OBJ;
    return OBJ.run();
}
