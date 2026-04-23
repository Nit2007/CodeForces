#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  

    void solve(){//1909B
        int n;cin>>n;
        vector<ll>nums = readVector<ll>(n);

        ll ans = 0;
        for(int j=1;j<=60;j++){
            ll k = 1LL << j ;
            set<ll>mod = { };
            for(ll i:nums){
                mod.insert( (i%k) );
            }
            if(mod.size() == 2){
                ans = k;
                break;
            }
        }
        cout<<ans<<endl;
    }
    //Array contains both even and odd => 2
    // else array contains either all ones(Odd) or zeros(Even)
    //Try next power of 2 ,so if it contains one at left side ,it would go off in the mod
    //If it contains both ones and zeros ,then it is a valid answer

    // Ai mod k  = x    | Ai = mk + x |
    // Ai mod 2k = mk + x
    // if m is Even : 
    //     Ai = mk + x | Ai = (2j)k + x  
    // else m is Odd:
    //     Ai = mk + x | Ai = (2j+1)k + x  | Ai = 2j + (k+x)

    // So only 2 distinct values are possible [x , k+x]  when we divide via 2k

    // Decimal Number 	Binary|Representation
    //     1000	        1111101,000
    //     2000	       11111010,000
    //     7000	     1101101011,000
    //     11000	10101011111,000
    //     16000	11111010000,000




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
