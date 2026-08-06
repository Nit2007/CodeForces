#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/1561/C*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){
        int cave;cin>>cave;
        vector<pair<int,int>>minGain(cave);
        for(int i=0;i<cave;i++){
            int k;cin>>k;
            vector<int>nums = readVector<int>(k);
            int minPower = 0 , gained = 0;
            for(auto power:nums){
                minPower = max(minPower,power-gained+1);
                gained += 1;
            }
            minGain[i] = make_pair(minPower,k);
        }
        sort(minGain.begin(),minGain.end());//Caves in any order ,but monster in given order
        int low = 1;
        int high = 2e9;
        int ans = high;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(check(mid,minGain)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        cout<<ans;N();
        // PRINT(bareMin);
        // PRINT(afterKill);
    }
    bool check(int mid,vector<pair<int,int>>&minGain){
        for(int i=0;i<minGain.size();i++){
            auto [minPower,gain] = minGain[i];
            if(mid < minPower){
                return false;
            }
            mid += gain ;
        }
        return true;
    }

    //Sorted the caves which is prohibited
    // void solve(){
    //     int cave;cin>>cave;
    //     vector<vector<int>>v;
    //     for(int i=0;i<cave;i++){
    //         int k;cin>>k;
    //         vector<int>nums = readVector<int>(k);
    //         sort(nums.begin(),nums.end());
    //         v.push_back(nums);
    //     }
    //     vector<int>bareMin(cave,0);
    //     vector<int>afterKill(cave,0);
    //     int i=0;
    //     for(auto &x:v){
    //         bareMin[i] = *(x.end()-1) - (x.size()-1) + 1;
    //         afterKill[i] = bareMin[i] + x.size() ;
    //         i++;
    //     }
    //     sort(afterKill.begin(),afterKill.end());
    //     int low = *min_element(bareMin.begin(),bareMin.end());
    //     int high = *max_element(bareMin.begin(),bareMin.end());
    //     int ans = high;
    //     while(low <= high){
    //         int mid = low + (high-low)/2;
    //         if(check(mid,afterKill)){
    //             ans = mid;
    //             high = mid - 1;
    //         }else{
    //             low = mid + 1;
    //         }
    //     }
    //     cout<<ans;N();
    //     // PRINT(bareMin);
    //     // PRINT(afterKill);
    // }
    // bool check(int mid,vector<int>&afterKill){
    //     auto it = upper_bound(afterKill.begin(),afterKill.end(),mid);
    //     return it != afterKill.end();
    // }

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
};

signed main(){
    Main OBJ;
    return OBJ.run();
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