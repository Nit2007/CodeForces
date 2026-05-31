#include <bits/stdc++.h>
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){//2222B
        ll n,m;cin>>n>>m;
        vector<ll>nums = readVector<ll>(n);
        vector<ll>index = readVector<ll>(m);

        vector<vector<ll>>a(0);
        vector<ll>odd(0),even(0);
        for(int i=0;i<n;i++){
            if(i%2)odd.push_back(nums[i]);
            else even.push_back(nums[i]);
        }
        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end());
        int remove[2] = {false,false};
        for(ll x:index){
            --x;
            ++remove[x%2];
        }
        a.push_back(even);
        a.push_back(odd);
        ll ans = 0LL;
        for(int parity=0;parity<2;parity++){//Either remove one element(if ALL -) ,or remove all positives => Minimize the sum
            bool once = remove[parity];
            while(remove[parity] && (once || (!a[parity].empty() && a[parity].back() > 0) ) ){
                --remove[parity];
                a[parity].pop_back();
                once = false;
            }
            // PRINT(a[parity]);ND();
            ans  += accumulate(a[parity].begin(),a[parity].end(),0LL);
        }
        cout<<ans;N();
    }





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
