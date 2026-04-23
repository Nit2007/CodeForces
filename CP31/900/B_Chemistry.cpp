#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
#define yes {cout<<"YES"<<endl;return;} 
#define no {cout<<"NO"<<endl;return;}
class Main{
public:  
    void solve(){//1883B
        int n,k;cin>>n>>k;
        string s;
        cin>>s;
        vector<int>count_char(26,0);
        for(char c:s){
            count_char[c-'a']++;
        }// PRINT(count_char);
        int odd = 0;
        int even =0;
        for(int i=0;i<26;i++){
            if(count_char[i]%2 == 0){
                even++;
            }else odd++;
        }
        if(odd-1 > k)no
        else yes
    }
    // if(odd == 0){
    //     if(k%2 == 0) yes
    //     else no
    // }
    // while(k){
    //     if(odd != 1){
    //         odd--;
    //     }
    //     if(odd == 1)break;
    //     k--;
    // }
    // if(k%2 == 0 && odd <= 1) yes
    // else no

    
    // int ones = count(count_char.begin(),count_char.end(),1);
    // if(ones == 0){
    //     if(k%2 == 0){
    //         yes
    //     }else no
    // }
    // sort(count_char.begin(),count_char.end());
    // k -= ones;
    // if(k%2 == 0){
    //         yes
    // }else no
    // for(int i=0;i<count_char.size();i++){
    //     if(count_char[i] == 0)continue;
        
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