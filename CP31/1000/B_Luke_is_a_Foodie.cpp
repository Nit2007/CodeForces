#include <bits/stdc++.h>
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
struct Range{ int l,r; };
class Main{
public:  

    void solve(){//1704B
        int n,x;cin>>n>>x;
        vector<int>nums = readVector<int>(n);
        vector<Range>interval(0);
        for(int i=0;i<n;i++){
            Range seg = {nums[i]-x,nums[i]+x};
            interval.push_back(seg);
        }
        int change = 0;
        int L = interval[0].l;
        int R = interval[0].r;
        for(int i=1;i<n;i++){
            L = max(L,interval[i].l);
            R = min(R,interval[i].r);
            if(L > R){//No Overlap - Reset ....[L,R] - Common Area
                change++;
                L = interval[i].l;
                R = interval[i].r;
            }
        }
        cout<<change;N();
    }
    //     0  2  4  6  8  10  12  14  16
    // |  |  |  |  |   |   |   |   |
    // 0:[====]                             [0,4]
    // 1:   [====]                          [2,6]
    // 2:      [====]                       [4,8]
    // 3:         [====]                    [6,10]   ← GAP at pile 3
    // 4:      [====]                       [4,8]
    // 5:   [====]                          [2,6]
    // 6:              [====]               [10,14]  ← GAP at pile 6
    // 7:                  [====]           [12,16]

    // void solve(){//1704B
    //     int n,x;cin>>n>>x;
    //     vector<int>nums = readVector<int>(n);
    //     int upper = nums[0] + x; 
    //     int lower = nums[0] - x;
    //     int change = 0;
    //     for(int i=0;i<n;i++){
    //         if(abs(nums[i] - lower) > x && abs(nums[i] - upper) > x){
    //             change++;
    //             upper = nums[i] + x; 
    //             lower = nums[i] - x; 
    //         }
    //     }
    //     cout<<change;N();
    // }

    // void solve(){//1704B
    //     int n,x;cin>>n>>x;
    //     vector<int>nums = readVector<int>(n);
    //     bool upper = nums[0] < nums[1];
    //     int v = nums[0] + ((upper)? x : -x);
    //     int change = 0;
    //     for(int i=0;i<n;i++){
    //         if(i+1 < n){
    //             if(nums[i] < nums[i+1]){
    //                 upper = true;
    //             }else{
    //                 upper = false;
    //             }
    //         }
    //         if(abs(nums[i] - v) > x){
    //             change++;
    //             if(upper){
    //                 v = nums[i] + x;
    //             }else{
    //                 v = nums[i] - x;
    //             }
    //         }
    //     }
    //     cout<<change;N();
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
