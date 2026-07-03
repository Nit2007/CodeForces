#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/1919/C*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){
        int n;cin>>n;
        vector<int>nums = readVector<int>(n);
        int x = INF,y = INF;
        int penalty = 0;
        for(int i=0;i<n;i++){
            if(x > y){swap(x,y);}
            if(nums[i] <= x){
                x = nums[i];
            }else if( x <= nums[i] && nums[i] <= y){
                y = nums[i];
            }else if(y < nums[i]){ //maximize both x and y as we got a big num
                x = nums[i];
                penalty++;
            }
            // cout<<x<<" "<<y;N();
        }
        // ND();
        cout<<penalty<<endl;
        
    }
    // --1----+---2-----+----3------>
    //        X         Y
    // X and Y tends to have max benefit when they are more towards right 
    // 1 - No penalty for both X and Y 
    // 2 - penalty for X 
    // 3 - penalty for both X and Y

    // void solve(){
    //     int n;cin>>n;
    //     vector<int>nums = readVector<int>(n);
    //     vector<int>s(0),t(0);
    //     int c = 0;
    //     for(int i=0;i<n;i++){
    //         if(t.size() == 0 || t.back() >= nums[i]){
    //             t.push_back(nums[i]);
    //         }else if(s.size() == 0 || s.back() >= nums[i]){
    //             s.push_back(nums[i]);
    //         }else{
    //             s.push_back(nums[i]);
    //             c++;
    //         }
    //     }
    //     cout<<c<<endl;
    //     // PRINT(s); //waste array
    //     // PRINT(t); //Greedy array
    // }


    signed run() {
        ios_base::sync_with_stdio(false);   cin.tie(NULL);
        int z;cin>>z;
        while(z--){ solve();}
        return 0;
    }

//     8 2 3 1 1 7 4 3 
// s   8 3 1 1 
// t   2 7 4 3 

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
