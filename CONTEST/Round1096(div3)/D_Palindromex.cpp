#include <bits/stdc++.h>
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){//2227D
        int n;cin>>n;
        n *= 2;
        vector<int>nums = readVector<int>(n);

        int l = -1 , r = -1 ;
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                r = i;
                if(l == -1){
                    l = i;
                }
            }
        }

        int ans = 1;
        ans = max({expand(l,l,nums) , expand(l,r,nums), expand(r,r,nums) , ans});

        cout<<ans;N();
    }
    
    int expand(int l,int r,vector<int>&nums){
        int L = l , R = r;                          //Inner check
        while(L <= R){
            if(nums[L] != nums[R])return -1;
            L++;
            R--;
        }
        while(l >= 0 && r < nums.size()){           //Outer expand
            if(nums[l] != nums[r]){
                break;
            }
            l--;
            r++;
        }
        vector<int>mex(0);
        for(int i=l+1;i<r;i++){                     //check MEX
            mex.push_back(nums[i]);
        }
        sort(mex.begin(),mex.end());
        int ans = 0;
        for(auto m:mex){
            if(ans == m)ans++;
        }
        return ans;
    }



    // void solve(){//2227D
    //     int n;cin>>n;
    //     n *= 2;
    //     vector<int>nums = readVector<int>(n);

    //     int ans = 1;
    //     set<int>half;
    //     for(int i=0;i<n;i++){
    //         half.insert(nums[i]);
    //         int l = i, r = i+1;
    //         bool pal = true;
    //         while(l>=0 && r<=n-1){
    //             if(nums[l] != nums[r]){
    //                 pal = false;
    //                 break;
    //             }
    //             l--;
    //             r++;
    //         }
    //         l = i, r = i;
    //         while(l>=0 && r<=n-1){
    //             if(nums[l] != nums[r]){
    //                 pal = false;
    //                 break;
    //             }
    //             l--;
    //             r++;
    //         }
    //         if(pal){
    //             int mex = 0;
    //             // for(int i:half){
    //             //     cout<<i<<" ";
    //             // }ND();
    //             for(int x=0;x<n;x++){
    //                 if(half.count(x))mex++;
    //                 else break;
    //             }
    //             ans = max(ans,mex);
    //         }
    //     }
    //     cout<<ans;N();
        
    //     // map<int,int>freq;
    //     // for(int i=0;i<n;i++){
    //     //     freq[i] = 2;
    //     // }

    // }
    
    
    // void R(vector<int>&nums,int l,int r,map<int,int>&freq){
    //     int n = nums.size();
    //     if(l == r)return;


    //     freq[nums[r]--];
    //     R(nums,l,r--,freq);
    //     freq[nums[r]++];

    //     freq[nums[l]--];
    //     R(nums,l++,r,freq);
    //     freq[nums[l]++];
    // }




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
