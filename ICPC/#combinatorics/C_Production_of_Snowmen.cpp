#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/2182/C*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  
    bool check(vector<int>&big,vector<int>&b,int i){
        int n = b.size();
        for(int t=0;t<n;++t){
            if(big[t] <= b[(i+t)%n]){
                return false;
            }
        }
        return true;
    }
    void solve(){
        int n;cin>>n;
        vector<int>a = readVector<int>(n);
        vector<int>b = readVector<int>(n);
        vector<int>c = readVector<int>(n);
        ll I = 0 , K = 0;
        for(int i=0;i<n;i++){
            if(check(b,a,i)){
                I += 1;
            }
            if(check(c,b,i)){
                K += 1;
            }
        }
        cout<<(I * K * n);N();
    }
    // (i,j,k) -> (i+t,j+t,k+t) should be valid ,making the brute force to n power 4
    // as we are cycling ,fixing one element ,would yield as all the combo 
    // (i,1,k) -> (i+t,1+t,k+t) should be valid ,making the approach to n power 3
    // i depends on j
    // k depends on j
    // i dont depend on k
    // so for every j ,we pick all the valid (i,k) 
    // ->so if the problem is only about i and j ,the brute force would be n cube ,
    // ->but we fix element then simulate to get a optimal n sq approach 

    // void solve(){
    //     int n;cin>>n;
    //     vector<int>a = readVector<int>(n);
    //     vector<int>b = readVector<int>(n);
    //     vector<int>c = readVector<int>(n);
    //     //a < b < c
    //     sort(a.begin(),a.end());
    //     sort(b.begin(),b.end());
    //     sort(c.begin(),c.end());
    //     ll ans = 0;
    //     for(int i=0;i<n;i++){
    //         int j = distance(b.begin() , lower_bound(b.begin(),b.end(),a[i]));
    //         int k = distance(c.begin() , lower_bound(c.begin(),c.end(),b[j]));
    //         j = n - j - 1;
    //         k = n - k - 1;
    //         ans += (j * k) ;
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
