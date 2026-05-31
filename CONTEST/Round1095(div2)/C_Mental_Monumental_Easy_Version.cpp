#include <bits/stdc++.h>
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){//2226C
        int n;cin>>n;
        vector<int>nums = readVector<int>(n);

        sort(nums.begin(),nums.end());
        int l = 0;
        int r = n-1;
        int ans = 0;
        // x mod y , the possible values are :
        // if y is larger than x    ==> x
        // if y is smaller than x { ==> [0,x/2]
        //     y < x/2 ==> [0,x/2]
        //     y > x/2 ==> [0,x/2]
        // }
        for(int i=0;i<n;i++){
            if(nums[l] == ans || nums[l] >= 2*i+1){//valid ,np
                l++;
                ans++;
            }
            else if(nums[r] >= 2*i+1){//Eat the biggest element ,as eating smaller element could affect the MEX
                r--;
                ans++;
            }else if(nums[l] < ans){//Small values dont contribute
                l++;
            }
        }
        cout<<ans;N();
        // PRINT(nums);N();
    }
    // sort(nums.begin(),nums.end());
    // vector<set<ll>>inc(0);
    // set<ll>t;
    // t.insert(nums[0]);
    // for(int i=1;i<n;i++){
    //     if(nums[i-1] == nums[i] || nums[i-1] == nums[i]-1){
    //         t.insert(nums[i]);
    //     }else{
    //         inc.push_back(t);
    //         t.clear();
    //         t.insert(nums[i]);
    //     }
    // }
    // inc.push_back(t);
    // // for(auto x:inc){
    // //     for(auto i:x){
    // //     cout<<i<<" ";
    // // }N();
    // // }ND();
    // vector<int>s(0);
    // for(auto x:inc){
    //     s.push_back(x.size());
    // }
    // sort(s.begin(),s.end(),greater<int>());
    // int l1 = (s.size() > 0)? s[0] : 0;
    // int l2 = (s.size() > 1)? s[1] : 0;
    // cout<<l1+l2;N();





    // int first = -1;
    // int second = -1;
    // sort(nums.begin(),nums.end());
    // int mex = 0;
    // for(int i=0;i<n;i++){
    //     if(i>0 && nums[i-1] == nums[i])continue;
    //     if(nums[i] == mex){
    //         mex++;
    //     }else{
    //         if(first == -1){
    //             first = mex;
    //         }else{
    //             second = mex;
    //             break;
    //         }
    //     }
    // }
    // if(first == -1)first = mex;
    // int ans = (second == -1)?  first : second;
    // cout<<ans;N();
    // // PRINT(nums);





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
