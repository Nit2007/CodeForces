#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/1648/A*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int MOD = 1e9+7;const int BIT = 32;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  
    ll FindAllPairs(vector<int>&v){
        sort(v.rbegin(),v.rend());
        ll sum = 0 , small=v.size()-1;
/*      x1 x2 x3 x4 ... xk , k=4
        |x1-x2| + |x1-x3| + |x1-x4| + |x2-x3| + |x2-x4| + |x3-x4|
        cbig = no of bigs than xi
        csmall = no of smalls than xi
        A number xi gets cbig minus contribution and csmall plus contribution , xi contribution (csmall-cbig) * xi
        (k-1)x1 + (k-2-1)x2 + (k-3-2)x3 ...
        Element * (take all rights ,ignore all lefts) as |x1-x2| = x1-x2 where x1>=x2        */
        for(int Element:v){
            sum += 1LL * (small) * Element ;
            small -= 2;
        }
        return sum;
    }
    void solve(){
        int n,m;cin>>n>>m;
        vector<vector<int>>nums;
        for(int i=0;i<n;i++){
            auto x = readVector<int>(m);
            for(auto&ele:x){ele--;}
            nums.push_back(x);
        }
        int MAX_COLOR = 1e5;
        vector<vector<int>>x(MAX_COLOR);
        vector<vector<int>>y(MAX_COLOR);
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                x[nums[i][j]].push_back(i);
                y[nums[i][j]].push_back(j);
            }
        }
        ll sum = 0;
        for(int color=0;color<MAX_COLOR;color++){
            sum += FindAllPairs(x[color]);
            sum += FindAllPairs(y[color]);
        }
        cout<<sum;N();
    }
/*
dist = |x1-x2| + |y1-y2|
as both are independent ,split them 
first find |x1-x2| on a row 
[1,2,3,1,2,1] => 8 + 5 + 7 = 20 ,indexes {1,4,6}
Take only {Xs,Ys} => So the sum is the modulus value of all pairs {Xs,Ys}

***MANHATTAN X,Y ARE INDEPENDENT
***MODULUS IS DEFINED AS |X-Y| = X-Y WHERE X>=Y , x contributes plus if it is big     to the SUM
                                                  x contributes minus if it is small
*/

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
