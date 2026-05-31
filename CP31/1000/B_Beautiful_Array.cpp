#include <bits/stdc++.h>
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){//1715B
        ll n,k,b,s;
        cin>>n>>k>>b>>s;

        ll maxSum = ((n)*(k-1)) + (b*k);
        ll minSum =  (b*k);
        if(s > maxSum || s < minSum || ((s==0)&&(b!=0)) ){
            cout<<-1;N();return;
        }
        vector<ll>nums(n,0);
        nums[n-1] = minSum;
        ll rem = s - minSum;
        for(int i=0;i<n;i++){
            if(rem == 0)break;
            int add = min(rem,k-1);
            nums[i] += add;
            rem-= add;
        }
        
        PRINT(nums);
        // if(b == 0){
        //     vector<ll>ans(n,0);
        //     int j=0;
        //     while(j<n && s != 0){
        //         ll add = min(s,k-1);
        //         ans[j] += add;
        //         s-= add;
        //         j++;
        //     }
        //     PRINT(ans);return;
        // }
    }
    // 5 5 b*k - 1 --> b = 3
    // n,k,b,s
    // 5,4,7,38
    // 0 0 0 0 0
    // 1 1 1 1 34



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
