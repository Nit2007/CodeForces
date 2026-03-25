#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  
    void solve(){//2202B
        int n;cin>>n;
        string s,build="";
        cin>>s;
        
        bool valid = true;
        if(n%2 == 1){//Both First and Last contains 'a' , hence first newString would have 'a'
            if( s[0] == 'b')valid = false;
        }
        int start = (n%2 == 0) ? 0 : 1;//Skip for odd strings as we checked earlier
        for(int i=start;i<n-1;i+=2){
            if(s[i] == '?' || s[i+1] == '?')continue;
            if(s[i] == s[i+1]){
                valid = false;
                break;
            }
        }
        string output = (valid)? "YES" : "NO";
        cout<<output;N();
    }
    
    //MLE at TestCase 2 due to usage of memo[1001][1001]
    // void solve(){//2202B
    //     int n;cin>>n;
    //     string s,build="";
    //     cin>>s;
    //     int**memo = new int*[1001];
    //     for(int i=0;i<1001;i++){
    //         memo[i] = new int[1001];
    //         fill(memo[i],memo[i]+1001,-1);// memset(memo, -1, sizeof(memo));
    //     }
        
    //     int ans = f(0,0,n-1,s,memo);
    //     string output = (ans)? "YES" : "NO";
    //     cout<<output;N();
    // }
    // int f(int i,int first,int last,string &s,int** memo){
    //     if(i == s.length())return true;
    //     if(memo[first][last] != -1)return memo[first][last];
    //     // 1 - indexed : {even,a} {odd,b}
    //     char first_char = (first%2 == 0)? 'a' : 'b';
    //     char last_char = (last%2 == 0)? 'a' : 'b';

    //     bool placedAtFirst = false;
    //     bool placedAtLast = false;
    //     if(s[i] == '?' || (first_char == s[i]) )placedAtFirst = true;
    //     if(s[i] == '?' || (last_char == s[i]) )placedAtLast = true;

    //     int x=0,y=0;
    //     if(placedAtFirst){
    //         x = f(i+1,first+1,last,s,memo);
    //     }
    //     if(placedAtLast){
    //         y = f(i+1,first,last-1,s,memo);
    //     }
    //     return memo[first][last] = max(x,y);
    // }


    // int f(int i,int first,int last,string build,string s){
    //     if(i == s.length()){
    //         if(build == s)return true;
    //         return false;
    //     }
    //     if(i>0 && build[i-1] != s[i-1])return false;
    //     if(s[i] == '?'){
    //         int useFirst = f(i+1,first+1,last,build+s[first],s);
    //         int useLast  = f(i+1,first,last-1,build+s[last],s);
    //         return max(useFirst,useLast);
    //     }
    //     if(s[i] == 'a'){
    //         int x=0,y=0;
    //         if(first%2 == 1){
    //             x = f(i+1,first+1,last,build+s[first],s);
    //         }
    //         if(last%2 == 1){
    //             y = f(i+1,first,last-1,build+s[last],s);
    //         }
    //         return max(x,y);
    //     }
    //     if(s[i] == 'b'){
    //         int x=0,y=0;
    //         if(first%2 == 0){
    //             x = f(i+1,first+1,last,build+s[first],s);
    //         }
    //         if(last%2 == 0){
    //             y = f(i+1,first,last-1,build+s[last],s);
    //         }
    //         return max(x,y);
    //     }
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
        vector<T> v(n);
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