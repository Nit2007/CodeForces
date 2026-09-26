#include <bits/stdc++.h> /*https://codeforces.com/gym/106179/problem/C*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int MOD = 1e9+7;const int BIT = 32;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){
        ll a,b,c;cin>>c;
        a = c;
        ll push = 64  - __builtin_clzll(c);
        b = (c<<push);
        cout<<a<<" "<<b;N();

        int x = lcm(a,c) , y = lcm(b,c),lhs = x+y,  rhs = ((a^c) + (b^c));
        assert(lhs == rhs);
    }
    /*
    (a^c) + (b^c) = lcm(a,c) + lcm(b,c)
    (a^c) + (b^c) = a + b
=> x^y = x + y - 2(x AND Y)
    a + c - 2(a AND c) + c + b - 2(b AND c) = a + b
    2c = 2(a AND c) + 2(b AND c)
    c = (a AND c) + (b AND c)
=> make a to give exactly c and b to give exactly c , also a,b are multiples of c

    (a^c) + (b^c) = lcm(a,c) + lcm(b,c)
    (a^c) - lcm(a,c) = lcm(b,c) - (b^c)
    (a^c) - lcm(a,c) = - ( (b^c) - lcm(b,c) )
    
    (a^c) + (b^c) = 2*lcm(b,c)
    (a^c) + (b^c) = max(a,b,c) to M*c
    
(a^c) + (b^c) = lcm(3c,c) + lcm(2c,c)
 2c^c + 3c^c = 3c + 2c

 c - even = c+1 + c+1 = 2c

88 71
80 62
1 35

87 + 70 = 88 + 71
82 + 60 = 80 + 62
6  + 36 = 7 + 35

c=2 
11 13
9 + 15 = 22 + 26

10 12
8 + 14 = 10 + 12

2 4
0 + 6 = 2 + 4

4 6
6 + 4 = 4 + 6

c=3
6 9
5 + 10 = 6 + 9

c=1
2 3
3 + 2 = 2 + 3

// assert( ((2*c)^c + (3*c)^c )== 5 * c);
P((2*c)^c , (3*c)^c ,5*c);
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
