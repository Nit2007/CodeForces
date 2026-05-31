#include <bits/stdc++.h>
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void solve(){//2227E
        int n;cin>>n;
        vector<int>nums = readVector<int>(n);
        
        vector<int>sufMin(n,0); //Immovable Blocks
        ll moveable = accumulate(nums.begin(),nums.end(),0LL); //Put all blocks as Moveable and remove the immovables
        sufMin[n-1] = nums[n-1];
        moveable -= sufMin[n-1];
        for(int i=n-2;i>=0;i--){
            sufMin[i] = min(nums[i],sufMin[i+1]);
            moveable -= sufMin[i];
        }

        ll  maxEqual = -1 , equal = 1;
        for(int i=1;i<n;i++){
            if(sufMin[i-1] == sufMin[i] ){
                equal++;
            }else{
                maxEqual = max(maxEqual,equal);
                equal = 1;
            }
        }
        maxEqual = max(maxEqual,equal);
        cout<<moveable + maxEqual - 1;N();
        //Removing one block on A[i]:
            // -> A[i]  > sufMin[i] => No use as there is already a smaller element in the right
            // -> A[i] == sufMin[i] => Removing these could give as a new sufMin value (A[i]-1);
    }

    // void solve(){//2227E
    //     int n;cin>>n;
    //     vector<int>nums = readVector<int>(n);
    //     ll total = accumulate(nums.begin(),nums.end(),0LL);
    //     ll immovable = 0;
    //     for(int i=n-2;i>=0;i--){
    //         if(nums[i] < nums[i+1]){
    //             immovable += nums[i];
    //         }else{
    //             immovable += nums[i+1];
    //             nums[i] = nums[i+1];
    //         }
    //     }
    //     ll ans = total - immovable ;
    //     cout<<ans;N();
    // }


    // void solve(){//2227E
    //     int n;cin>>n;
    //     vector<int>nums = readVector<int>(n);
    //     vector<int>pre(n+1,0);
    //     vector<int>small(n+1,0);
    //     for(int i=0;i<n;i++){
    //         pre[i+1] = pre[i] + nums[i];
    //     }
    //     for(int i=n-1;i>=0;i--){
    //         small[i] = pre[i+1] - i-1;
    //     }
    //     // PRINT(pre);
    //     // PRINT(small);
    //     int ans = 0;
    //     for(int i=n-1;i>=0;i--){
    //         int base = nums[i] - 1;
    //         int immovable = small[i];
    //         ans = max(ans,pre[i+1] - immovable);
    //     }
    //     cout<<ans;N();
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
