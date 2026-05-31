#include <bits/stdc++.h>
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){//1832B
        int n,k;cin>>n>>k;
        vector<int>nums = readVector<int>(n);
        sort(nums.begin(),nums.end());
        
        vector<ll>prefixSum(n+1,0);
        for(int i=1;i<=n;i++){
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        }
        // PRINT(nums);PRINT(prefixSum);ND();
        ll ans = LLONG_MIN;
        for(int m=0;m<=k;m++){
            int l = 2*m;
            int r = n-(k-m);
            ll sum = prefixSum[r] - prefixSum[l];
            ans = max(ans,sum);
        }
        cout<<ans;N();
    }

    // void solve(){//1832B
    //     int n,k;cin>>n>>k;
    //     vector<int>nums = readVector<int>(n);
    //     sort(nums.begin(),nums.end());
    //     int l = 0 , r = n-1;
    //     while(k--){
    //         if(nums[r] >= nums[l] + nums[l+1]){
    //             l += 2;
    //         }else{
    //             r -= 1;
    //         }
    //     }
    //     ll ans = accumulate(nums.begin()+l,nums.begin()+r+1,0LL);
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
