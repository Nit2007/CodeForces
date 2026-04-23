#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  

    void solve(){//1726A
        int n;cin>>n;
        vector<int>nums = readVector<int>(n);

        if(n == 1){
            cout<<0;N();return;
        }
        int ans = nums[n-1] - nums[0];//Max valueOf a[n] - a[0]
        //Try maximizing a[n] alone
        ans = max(ans, (*max_element(nums.begin()+1,nums.end())) - nums[0]);
        //Try minimizing a[0] alone
        ans = max(ans,  nums[n-1] - (*min_element(nums.begin(),nums.end()-1))  );
        //Try both by cyclically trying all combinations ,while rotatting ,the adjacent elements becomes first and last at some point
        for(int i=1;i<n;i++){
            ans = max(ans , nums[i-1] - nums[i]);
        }
        cout<<ans<<endl;
    }
    // void solve(){//1726A
    //     int n;cin>>n;
    //     vector<int>nums = readVector<int>(n);

    //     vector<int>s = nums;
    //     sort(s.begin(),s.end());
    //     int ans = INT_MIN;

    //     if(s[0] == nums[0] || s[n-1] == nums[n-1]){
    //         ans = abs(s[0] - s[n-1]);
    //     }else{//,abs(s[0] - nums[0]) , abs(s[n-1] - nums[n-1]) --abs value cannot be taken as only a[n] - a[0] is valid 
    //         ans = max({abs(s[0] - nums[n-1]) , abs(nums[0] - s[n-1])  });
    //     }

    //     cout<<ans<<endl;
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
