#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/1878/E*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  
const int BIT = 31;
    void solve(){
        int n;cin>>n;
        vector<int>nums = readVector<int>(n);
        int p[n+1][BIT];
        memset(p,0,sizeof(p));
        for(int i=1;i<=n;i++){
            for(int bit=0;bit<BIT;bit++){
                if(nums[i-1] & (1<<bit)){
                    p[i][bit] = p[i-1][bit] + 1;
                }else{
                    p[i][bit] = p[i-1][bit] ;
                }
            }
        }
        int q;cin>>q;
        for(int Q=0;Q<q;Q++){
            int l , k ; cin>>l>>k;
            int low = l , high = n , ans = -1;
            while(low<=high){
                int m = low + (high - low)/2 ;
                int val = 0;
                for(int bit=0;bit<BIT;bit++){
                    if((p[m][bit] - p[l-1][bit]) == (m-l+1)){
                        val |= (1<<bit);
                    }
                } 
                if(val >= k){
                    low = m + 1;
                    ans = max(ans,m);
                }else{
                    high = m-1;
                }
            }
            cout<<ans<<" ";
        }
        N();
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
