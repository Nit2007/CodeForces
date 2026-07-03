#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/2178/C*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){
        ll n;cin>>n;
        vector<ll>nums = readVector<ll>(n);
        vector<ll>prefixSum(n+1,0);
        prefixSum[1] = nums[0] ; 
        for(int i=2;i<=n;i++){
            prefixSum[i] = prefixSum[i-1] + abs(nums[i-1]); 
        }
        vector<ll>suffixSum(n+1,0);
        for(int i=n;i>=1;i--){
            suffixSum[i-1] = suffixSum[i] + nums[i-1];
        }
        ll ans = LLONG_MIN;
        for(int ignore = 0;ignore<n;ignore++){
            ans = max(ans, (prefixSum[ignore] - suffixSum[ignore+1]) );
        }
        cout<<ans;N();
    }

    #define COMPRESS(first,second) ((ll)first<<32 | (second))
    void MLE(){ //O (n ^ 2)
        ll n;cin>>n;
        vector<ll>nums = readVector<ll>(n);
        memo.clear();
        cout<<santa(0,0,1,nums);N();
    }
    unordered_map<ll,ll>memo;
    ll santa(int i,int first,int second,vector<ll>&nums){
        int n = nums.size();
        if(i == n-1){
            return 0;
        }
        auto KEY = COMPRESS(first,second) ;
        if(memo.count(KEY)){
            return memo[KEY];
        }
        ll chooseFirst =  +nums[first] + santa(i+1,second,second+1, nums) ;
        ll chooseSecond = -nums[second] + santa(i+1,first,second+1, nums) ;
        return memo[KEY] = max(chooseFirst,chooseSecond);
    }

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
