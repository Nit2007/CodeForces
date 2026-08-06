#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/1541/B*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){
        int n;cin>>n;
        vector<int>nums = readVector<int>(n);
        vector<pair<ll,ll>>v(n);
        for(int i=1;i<=n;i++){
            v[i-1].first = nums[i-1];
            v[i-1].second = i;
        }
        sort(v.begin(),v.end());
        ll ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((v[i].first * v[j].first) >= (2 * n))break;
                if((v[i].first * v[j].first) == (v[i].second + v[j].second) ){
                    ans++;
                }
            }
        }
        cout<<ans;N();
    }
    // (i+j) < 2n (as 1<(i,j)<n)
    // 1aj <= 2n 
    // 2aj <= 2n
    // 3aj <= 2n
    // 4aj <= 2n 
    // 2n [(1) + (1/2) + (1/3) + (1/4) + ... + (1/n)]
    // O(2n logn)
    
// ai * aj = i + j
// x * aj = y + j  {x,y - constants}
// 3 * aj = 1 + j
// x  = (y+j) / aj

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
