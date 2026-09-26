#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/2248/D*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int MOD = 1e9+7;const int BIT = 32;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){
        int n,Q;cin>>n>>Q;
        string s,t;cin>>s>>t;
        vector<int>match,mismatch;
        match.push_back(0);
        mismatch.push_back(0);
        for(int i=0;i<n;i++){
            match.push_back(match.back() + (s[i]==t[i]) );
            mismatch.push_back(mismatch.back() + PAIR(s[i],t[i]) );
        }
        for(int q=0;q<Q;q++){
            int l,r;cin>>l>>r;
            int good = match[r] - match[l-1];
            int bad = mismatch[r] - mismatch[l-1];
            if(abs(bad) > good){
                cout<<"NO\n";continue;
            }
            cout<<"YES";N();continue;
        }
    }
    int PAIR(char a,char b){
        if(a == b)return 0;
        if(a == '1')return 1;
        if(b == '1')return -1;
    }
    /*    
Cases : 
N | s t
a   0 0
b   1 1 
c   1 0
d   0 1
a,b are not going to cause no trouble
c,d can be paired with themselves , abs(c-d) is going to cause trouble 
We can pair those abs(c-d) with {a,b}


    00001
    01111
    
    11100
    10000
    
    00011
    01111
    
    0001
    1111
    
    00
    11
    */
void WrongAns_Missed_joint_distribution_of_chars(){ //Missed relative positions matter
    int n,Q;cin>>n>>Q;
    string s,t;cin>>s>>t;
    vector<int>s1,t1;
    s1.push_back(0);
    t1.push_back(0);
    for(int i=0;i<n;i++){
        s1.push_back(s1.back() + s[i]-'0');
        t1.push_back(t1.back() + t[i]-'0');
    }
    // PRINT(s1);
    // PRINT(t1);
    for(int q=0;q<Q;q++){
        int l,r;cin>>l>>r;
        int s_ones = s1[r] - s1[l-1];
        int t_ones = t1[r] - t1[l-1];
        int s_zero = (r-l+1) - s_ones;
        int t_zero = (r-l+1) - t_ones;
        int major = max({s_ones,t_ones,s_zero,t_zero});
        if(major == s_zero || major == t_zero){
            s_ones = s_zero;
            t_ones = t_zero;
        }
        if(s_ones > 2*t_ones){
            cout<<"NO\n";continue;
        }
        if(t_ones > 2*s_ones){
            cout<<"NO\n";continue;
        }
        cout<<"YES";N();continue;
    }
}

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
