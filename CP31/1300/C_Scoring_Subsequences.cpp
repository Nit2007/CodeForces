#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/1794/C*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){
        int n;cin>>n;
        vector<int>nums = readVector<int>(n),res;
        for(int k=0;k<n;k++){
            int l=1 , r = k+1;
            while(l<=r){
                int m = l + (r-l)/2;
                if(nums[k-m+1] >= m){
                    l = m+1;
                }else{
                    r = m-1;
                }
            }
            res.push_back(r);
        }
        PRINT(res);
    }
    // l - first false  {4 5} - l = 4
    // r - last true {1 2 3} - r = 3
    void BRUTE(){
        int n;cin>>n;
        vector<int>nums = readVector<int>(n);
        ll prev = 1;
        for(int k=0;k<n;k++){
            int i=k;
            while(i>=0){
                if((k-i+1) <= nums[i]){
                    i--;
                }
                else   { break; }
            }
            cout<<k-i<<" ";
        }
        N();
    }

    // void solve(){
    //     int n;cin>>n;
    //     vector<int>nums = readVector<int>(n);
    //     ll prev = 1;
    //     for(int k=0;k<n;k++){
    //         ll m = nums[k] , cost = 1 , num = 1;
    //         ll fact = (k+1LL) * prev ;
    //         for(int i=k;i>=0;i--){
    //             num = nums[k] * num;
    //             if(m < (num/fact)){
    //                 m = num / fact;
    //                 cost = (k-i);
    //             }
    //         }
    //         cout<<cost<<" ";
    //         prev = fact;
    //     }
    //     N();
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
