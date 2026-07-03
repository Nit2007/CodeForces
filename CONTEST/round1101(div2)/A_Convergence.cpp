#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/2232/A*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){
        int n;cin>>n;
        vector<int>nums = readVector<int>(n);
        sort(nums.begin(),nums.end());//PRINT(nums);
        int ans = INT_MAX;
        for(int middle=0;middle<n;middle++){
            int l = 0 , r = 0;
            for(int i=0;i<middle;++i){
                if(nums[middle] != nums[i])l++;
            }
            for(int i=middle+1;i<n;++i){
                if(nums[middle] != nums[i])r++;
            }
            int op = max(r,l);
            ans = min(op,ans);
        }
        cout<<ans;N();
    }

    void working(){
        int n;cin>>n;
        vector<int>nums = readVector<int>(n);
        sort(nums.begin(),nums.end());//PRINT(nums);
        ll ans = 0;
        for(int i=0;i<n/2;i++){
           if(nums[i] != nums[n-i-1])ans++;
        }
        cout<<ans;N();
    }
    // void solve(){
    //     int n;cin>>n;
    //     vector<int>nums = readVector<int>(n);
    //     sort(nums.begin(),nums.end());//PRINT(nums);
    //     ll op = 0,ans = INT64_MAX;
    //     for(int i=0;i<n;i++){
    //         op = 0;
    //         int l = i-1 , r = i+1;
    //         while(l >= 0 && r <= n-1){
    //             if(nums[l] == nums[r] && nums[l] == nums[i]){}
    //             else if(nums[l] != nums[r])op++;
    //             l--; r++;
    //         }
    //         while(l >= 0){
    //             if(nums[i] != nums[l]){
    //                 op ++;
    //             }
    //             l--;
    //         }
    //         while(r <= n-1){
    //             if(nums[i] != nums[r]){
    //                 op ++;
    //             }
    //             r++;
    //         }
    //         ans = min(ans,op);
    //     }
    //     cout<<ans;N();
    // }


    signed run() {
        ios_base::sync_with_stdio(false);   cin.tie(NULL);
        int z;cin>>z;
        while(z--){ solve();}
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
        int i=0;
        cout << " [DEBUG] ";
        ([&](auto&& arg){ cout << keys[i++] << " : " << arg << "  |  "; }(args), ...);
        cout << "\n";
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
