#include <bits/stdc++.h>
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){//2227C
        int n;cin>>n;
        vector<int>nums = readVector<int>(n);
        
        vector<int>rem(0);
        vector<int>div2(0);
        vector<int>div3(0);
        vector<int>div6(0);
        for(int i=0;i<n;i++){
            if(nums[i]%6 == 0){
                div6.push_back(nums[i]);
            }
            else if(nums[i]%2 == 0){
                div2.push_back(nums[i]);
            }
            else if(nums[i]%3 == 0){
                div3.push_back(nums[i]);
            }
            else{
                rem.push_back(nums[i]);
            }
        }
        vector<int>ans(0);
        for(int i:div6){
            ans.push_back(i);
        }
        for(int i:div2){
            ans.push_back(i);
        }
        sort(rem.begin(),rem.end());
        for(int i:rem){
            ans.push_back(i);
        }
        for(int i:div3){
            ans.push_back(i);
        }
        PRINT(ans);
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
