#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/1714/E*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int MOD = 1e9+7;const int BIT = 32;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){
        int n;cin>>n;
        vector<int>nums = readVector<int>(n);
        for(int &x:nums){
            if(x%2 == 1){
                x = x + (x%10);
            }
        }
        int same = count(nums.begin(),nums.end(),nums[0]);
        if(same == n){ cout<<"Yes";N();return; }
        int struckWithZero = count_if(nums.begin(),nums.end(),[](int n){
            return n%10 == 0;
        });
        if(struckWithZero > 0){ cout<<"No";N();return; }
        for(int &x:nums){ //Normalize every loops
            while(x%10 != 2){
                x = x + (x%10);
            }
            x %= 20;
        }
        same = count(nums.begin(),nums.end(),nums[0]);
        if(same == n){ cout<<"Yes";N();return; }
        else { cout<<"No";N();return; }
    }
/*
Observations :
->Odd turns even in 1 op {2,4,6,8}
->Even cycles {1,3,7,9}
->0 stops , 5 becomes 0
*/
    // void solve(){
    //     int n;cin>>n;
    //     vector<int>nums = readVector<int>(n);
    //     vector<set<int>>last(0);
    //     for(auto x:nums){
    //         set<int>s = {x};
    //         int prev = 0;
    //         while(prev <= 20){
    //             x = x + (x%10);
    //             s.insert(x);
    //             prev++;
    //         }
    //         last.push_back(s);
    //     }
    //     bool ans = false;
    //     map<int,int>series;
    //     for(auto s:last){
    //         for(auto x:s){
    //             // cout<<x<<" ";
    //             series[x]++;
    //         }
    //         // N();
    //     }
    //     for(auto [x,rep] : series){
    //         if(rep == n)ans = true;
    //     }
    //     if(ans){
    //         cout<<"Yes";
    //     }else{
    //         cout<<"No";
    //     }
    //     N();
    // }

/*

6 12 14 18 
26 32 34 38

11 12 14 18 26 
   32 34 38 46

2 4 8 16 22 24
   18 26 32 34 38 46 52 54 58 66 72
         22 24 28 36 42 44 48 56 62 64 68

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
