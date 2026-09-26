#include <bits/stdc++.h> /*https://codeforces.com/contest/2128/problem/B*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int MOD = 1e9+7;const int BIT = 32;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  
    void solve(){
        int n;cin>>n;
        vector<int>nums = readVector<int>(n);
        string ans="";
        vector<int>path ;
        int l=0,r=n-1;
        for(int turn=0;turn<n;turn++){
            if(turn%2){
                if(nums[l] > nums[r]){
                    ans += "L";
                    path.push_back(nums[l++]);
                }else{
                    ans += "R";
                    path.push_back(nums[r--]);
                }
            }else{
                if(nums[l] < nums[r]){
                    ans += "L";
                    path.push_back(nums[l++]);
                }else{
                    ans += "R";
                    path.push_back(nums[r--]);
                }
            }
        }
        assert(!isBadArray(path));
        cout<<ans;N();
    }
    /*
    New numbers are either going to be big/small ,then alternate to get an alternating seq
    remove only at L/R
    Resulting array should be GOOD
    https://claude.ai/chat/5eee619e-86ab-46c2-aa94-3c879a34aebb?artifact=5abb4f20-82d7-4cdd-afbd-55d80ec61c30
    */
   void alternating(){
    const int LIMIT = 1;
    int n;cin>>n;
    vector<int>nums = readVector<int>(n);
    string ans="L";
    vector<int>path = {nums[0]};
    int l=1,r=n-1,inc=LIMIT,dec=LIMIT;
    while(ans.size() < n){
        if(path.back() < nums[l]){
            inc--;
            dec = LIMIT;
        }
        if(path.back() > nums[l]){
            dec--;
            inc = LIMIT;
        }
        ans += "L";
        path.push_back(nums[l++]);
        if((inc == 0 || dec == 0) && ans.size()+1 < n){
            ans += "R";
            path.push_back(nums[r--]);
            inc = dec = LIMIT;
        }
    }
    assert(ans.size() == n); 
    assert(!isBadArray(path));
    // PRINT(path);
    cout<<ans;N();
}
bool isBadArray(const std::vector<int>& a) {
    int n = a.size();
    if (n < 5) return false;

    for (int i = 0; i <= n - 5; ++i) {
        // Check strictly increasing: a[i] < a[i+1] < a[i+2] < a[i+3] < a[i+4]
        if (a[i] < a[i+1] && a[i+1] < a[i+2] && a[i+2] < a[i+3] && a[i+3] < a[i+4]) {
            return true;
        }
        // Check strictly decreasing: a[i] > a[i+1] > a[i+2] > a[i+3] > a[i+4]
        if (a[i] > a[i+1] && a[i+1] > a[i+2] && a[i+2] > a[i+3] && a[i+3] > a[i+4]) {
            return true;
        }
    }
    return false;
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
