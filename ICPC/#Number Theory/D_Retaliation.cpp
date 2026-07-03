#include <bits/stdc++.h> /*https://codeforces.com/problemset/problem/2117/D*/
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){
        int n;cin>>n;
        vector<int>nums = readVector<int>(n);
        int diff = nums[1] - nums[0];
        ll num = ((2LL * nums[0]) - nums[1]) ;
        ll den =  (n+1) ;
        if(num%den != 0){
            cout<<"NO";N();return;
        }
        ll y = num / den ;
        ll x = nums[1] - nums[0] + y ;
        if (x < 0 || y < 0) {
            cout << "NO\n";
            return;
        }
        for(int i=0;i<n;i++)
        {
            int d = i+1 , e = n-d+1;
            if((d * x) + (e * y) != nums[i]){
                cout<<"NO";N();return;
            } 
        }
        cout<<"YES";N();return;
    }
    // nums[0] = 1x + (n)y ;
    // nums[1] = 2x + (n-1)y ;
    // nums[n-1] = (n)x + 1y ;
    // nums[1] - nums[0] = x - y;      { x = nums[1] - nums[0] + y ;}
    
    // nums[0] = nums[1] - nums[0] + y + ny;
    // 2 * nums[0] - nums[1] = (n+1)y
    

    // if(nums[i] - nums[i-1] != diff){
    //     cout<<"NO";N();return;
    // }
    // void solve(){
    //     int n;cin>>n;
    //     vector<int>nums = readVector<int>(n);
    //     for(int i=0;i<n;i++)
    //     {
    //         int d = i+1 , e = n-d+1 , valid = false;
    //         if(nums[i]%d == 0 || nums[i]%e == 0){
    //             valid = true;
    //         }
    //         while(nums[i] >= 0){
    //             nums[i] = nums[i]-(d+e);
    //             if(nums[i]%d == 0 || nums[i]%e == 0){
    //                 valid = true;
    //                 break;
    //             }
    //         }
    //         if(!valid){
    //             cout<<"NO";N();return;
    //         }
    //     }
    //     cout<<"YES";N();return;
    // }


    // void solve(){
    //     int n;cin>>n;
    //     vector<int>nums = readVector<int>(n);
    //     for(int i=0;i<n;i++)
    //     {
    //         int valid = false;
    //         int d = i+1 , e = n-d+1;
    //         int x = d , j=0;
    //         while(x<nums[i]){
    //             x = d * j;
    //             if((nums[i]-x)%e == 0){
    //                 valid  = true;
    //             }
    //             j++;
    //         }
    //         if(x!= nums[i] && !valid){
    //             cout<<"NO";N();return;
    //         }
    //     }
    //     cout<<"YES";N();return;
    // }

    // nums[i] = xd - ye = 0
    // nums[i] = xd + ye
    // nums[i]-ye / d = x 



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
