#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/1826/B*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){
        int n;cin>>n;
        vector<int>nums = readVector<int>(n);
        int ans = 0;
        for(int i=0;i<n;++i){
            int diff = abs(nums[i] - nums[n-i-1]);
            ans = gcd(ans,diff);
        }
        cout<<ans;N();
        // a[0]%x == a[n-1]%x
        // a[0] - a[n-1] %x = 0
        // Find a largest X such that it is divisible ,for every Number needs 
        // this condition  hence take GCD
    }
    // void solve(){
    //     int n;cin>>n;
    //     vector<int>nums = readVector<int>(n);
    //     int ans = 0;
    //     for(int i=1;i<=(*max_element(nums.begin(),nums.end()));++i){
    //         int l = 0 , r = n-1;
    //         bool valid = true;;
    //         while(l <= r){
    //             if(nums[l]%i == nums[r]%i){
    //                 l++;
    //                 r--;
    //             }
    //             else {valid = false;break;}
    //         }
    //         if(valid)ans = max(ans,i);
    //     }
    //     if(ans == *max_element(nums.begin(),nums.end()))ans = 0;
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
