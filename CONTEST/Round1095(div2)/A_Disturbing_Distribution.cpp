#include <bits/stdc++.h>
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  
    const ll MOD = 676767677 ;
    void solve(){//2226A
        ll n;cin>>n;
        vector<ll>nums = readVector<ll>(n);

        ll ans = 0LL;
        ll sum = accumulate(nums.begin(),nums.end(),0LL);
        ll valid  = false;
        for(ll i=0;i<n;i++){
            if(i>0 && nums[i-1] == 1){
                valid++;
            }
        }
            
        cout<<sum - valid;N();return;
        

    }
    // ll ans = 0LL;
    // vector<vector<ll>>inc(0);
    // vector<ll>t(1,nums[0]);
    // for(int i=1;i<n;i++){
    //     if(nums[i-1] < nums[i]){
    //         t.push_back(nums[i]);
    //     }else{
    //         inc.push_back(t);
    //         t.clear();
    //         t = {nums[i]};
    //     }
    // }
    // inc.push_back(t);
    // for(auto x:inc){
    //     PRINT(x);
    // }ND();





    int run() {
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

int main(){
    Main OBJ;
    return OBJ.run();
}
