#include <bits/stdc++.h>
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){//1659A
        int n,r,b;cin>>n>>r>>b;
        string Result = "";
        vector<int>nums(++b,0);
        int i=0;
        while(i<r){
            nums[i%b]++;
            i++;
        }
        for(int j=0;j<nums.size();++j){
            auto&size = nums[j];
            Result += string(size,'R');
            if(j != (nums.size()-1))
                Result += string(1,'B');
        }
        cout<<Result;N();
    }
    // void solve(){//1659A
    //     int n,r,b;cin>>n>>r>>b;
    //     string Result = "";
    //     if(b == 1){
    //         int ratio = (r/2);
    //         Result += string(ratio+(r%2),'R');
    //         Result += "B";
    //         Result += string(ratio,'R');
    //     }else{
    //         int ratio = (r/b);
    //         while(n > Result.size()){
    //             Result += string(ratio,'R');
    //             if(b--){
    //                 Result += "B";
    //             }
    //         }
    //     }
    //     cout<<Result;N();
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
