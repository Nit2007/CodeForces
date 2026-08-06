#include <bits/stdc++.h> /*https://codeforces.com/contest/2242/problem/B*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  
// {1 majority,3 minority,anything}
    void solve(){
        int n;cin>>n;
        vector<int>nums = readVector<int>(n);
        vector<int>ones(n+1);
        for(int i=0;i<=n;i++){ 
            if(i > 0){
                ones[i] += ones[i-1] + ((nums[i-1] == 1)? +1 : -1);
            }
        }
        for(int i=1;i<=n;i++){ 
            if(ones[i] >= 0){
                int three = 0;
                for(int j=i;j<n;j++){
                    three += (nums[j] == 3)? +1 : -1 ;
                    if(three <= 0 && (j < n-1)){
                        cout<<"YES";N();return;
                    }
                }
            }
        }
        cout<<"NO";N();
    }
    // if(ones[i] > 0 && nums[i] == 3){
    //     ones[i]--;
    // }
    // else{
    // }


    // vector<int>three(n+1);
    // for(int i=0;i<=n;i++){ 
    //     if(i > 0){
    //         three[i] += three[i-1] + ((nums[i-1] == 3)? +1 : -1);
    //     }
    // }

    // void solve(){
    //     int n;cin>>n;
    //     vector<int>nums = readVector<int>(n);
    //     int phase = 0;
    //     int ones = 0 , three = 0;
    //     for(int i=0;i<n;i++){
    //         if(phase == 0){
    //             ones += (nums[i] == 1)? +1 : -1;
    //             if(ones >= 0){
    //                 phase++;
    //             }
    //         }
    //         else if(phase == 1){
    //             three += (nums[i] == 3)? +1 : -1 ;
    //             if(three <= 0){
    //                 phase++;
    //             }
    //         }
    //         else if(phase == 2){
    //             phase++;
    //         }
    //     }
    //     if(phase == 3){
    //         cout<<"YES";N();return;
    //     }
    //     cout<<"NO";N();
    // }


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
