#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/1931/E*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){
        int n,m;cin>>n>>m;
        vector<string>nums = readVector<string>(n);
        vector<int>trailingZero(n,0);
        for(int i=0;i<n;i++){
            for(int j=nums[i].size()-1;j>=0;j--){
                if(nums[i][j] == '0')trailingZero[i]++;
                else break;
            }
        }
        sort(trailingZero.begin(),trailingZero.end(),greater<int>());
        ll removed = 0;
        for(int i=0;i<n;i+=2){
            removed += trailingZero[i];
        }
        ll size = 0;
        for(string s:nums){
            size += s.size();
        }
        if((size-removed) > m){
            cout<<"Sasha";
        }
        else{
            cout<<"Anna";
        }
        N();
    }
    // void solve(){
    //     int n,m;cin>>n>>m;
    //     vector<string>nums = readVector<string>(n);
    //     vector<int>trailingZero(n,0);
    //     for(int i=0;i<n;i++){
    //         for(int j=nums[i].size()-1;j>=0;j--){
    //             if(nums[i][j] == '0')trailingZero[i]++;
    //             else break;
    //         }
    //     }
    //     int maxi = *max_element(trailingZero.begin(),trailingZero.end());
    //     string big = "NULL";
    //     int index = -1;
    //     for(int i=0;i<n;i++){
    //         if(trailingZero[i] == maxi){
    //             if(big=="NULL" || nums[i] > big)
    //             index = i;
    //         }
    //     }
    // }
    // friend bool operator>(const string &a,const string &b){
    //     if(a.length() != b.length()){
    //         return a.length() > b.length();
    //     }
    //     return a.compare(b) > 0;
    // }
    // string Reverse(string a){
    //     size_t lastNonZero = a.find_last_not_of('0');
    //     if (lastNonZero == string::npos) {
    //         return ""; 
    //     }
    //     string trimmedStr = a.substr(0, lastNonZero + 1);
    //     reverse(trimmedStr.begin(), trimmedStr.end());
    //     return trimmedStr;
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
