#include <bits/stdc++.h>
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){//2224A
        int n;cin>>n;
        vector<ll>nums = readVector<ll>(n);

        for(int i=n-2;i>=0;i--){
            if(nums[i+1] > 0){
                nums[i] += nums[i+1] ;
            }
        }
        ll pos = 0;
        for(auto a:nums){
            if(a > 0)pos++;
        }
        cout<<pos;N();
    }
    void solve__MY_ATTEMPT_WORKING(){//2224A
        int n;cin>>n;
        vector<ll>nums = readVector<ll>(n);

        ll pos = (nums.back()>0)? 1 : 0;
        ll sum = (nums.back()>0)? nums.back() : 0;
        for(int i=n-2;i>=0;i--){
            if(nums[i] > 0){
                pos++;
                sum += nums[i];
            }else if(nums[i] == 0){
                if(sum > 0) pos++;
            }else{
                if(sum + (nums[i]) > 0){
                    pos++;
                    sum = sum + nums[i] ;
                }else{
                    sum = 0;
                }
            }
        }
        cout<<pos;N();
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
