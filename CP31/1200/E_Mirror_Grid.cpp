#include <bits/stdc++.h>
using namespace std;/*AUTHOR : NITHISH JAISARUN*/using ll = long long int; const int INF = 1e9;
#define P(...) debugPrint(#__VA_ARGS__, __VA_ARGS__)
class Main{
public:  

    void simple(){//1703E 
        int n;cin>>n;
        vector<string>nums = readVector<string>(n);
        int z=0,o=0 , ans = 0;
        for(int i=0;i<(n+1)/2;++i){
            for(int j=0;j<n/2;j++){
                z=0,o=0;
                (nums[i][j] == '0')? z++ : o++; 
                (nums[j][n-i-1] == '0')? z++ : o++; 
                (nums[n-i-1][n-j-1] == '0')? z++ : o++; 
                (nums[n-j-1][i] == '0')? z++ : o++; 
                ans += min(z,o);
            }
        }
        cout<<ans<<endl;
    }

    void solve(){//1703E
        int n;cin>>n;
        vector<string>nums = readVector<string>(n);
        int ans = Border(nums);
        while(nums.size() > 2){
            vector<string>temp(0);
            for(int i=1;i<nums.size()-1;i++){
                string str = nums[i];
                string skipped = "";
                for(int x=1;x<str.length()-1;x++){
                    skipped += str[x];
                }
                temp.push_back(skipped);
            }
            nums = temp;
            ans += Border(nums);
        }
        cout<<ans;N();
    }
    int Border(vector<string>nums){
        // for(auto&x:nums){cout<<(x);ND();}
        int n = nums.size();
        if(n <= 1)return 0;
        string first = nums[0];
        string last = nums[n-1];
        string left = "";
        for(int i=0;i<n;i++){
            left += nums[i][0];
        }
        string right = "";
        for(int i=0;i<n;i++){
            right += nums[i][n-1];
        }
        reverse(last.begin(),last.end());
        reverse(left.begin(),left.end());

        int m = first.length();
        int op = 0;
        int z = 0,o = 0;
        for(int i=1;i<m-1;++i){
            z = 0,o = 0;
            if(first[i] == '0')z++;
            else o++;
            if(last[i] == '0')z++;
            else o++;
            if(left[i] == '0')z++;
            else o++;
            if(right[i] == '0')z++;
            else o++;
            op += min(z,o);
        }
        z = 0, o = 0;
        if(nums[0][0] == '0')z++;
        if(nums[n-1][0] == '0')z++;
        if(nums[n-1][n-1] == '0')z++;
        if(nums[0][n-1] == '0')z++;
        op += min(z,4-z);
        // cout<<op<<"###################\n";
        return op;
    }


    signed run() {
        ios_base::sync_with_stdio(false);   cin.tie(NULL);
        int z;cin>>z;
        while(z--){ simple();}
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
