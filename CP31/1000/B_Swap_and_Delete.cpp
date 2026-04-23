#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  

    void solve(){//1913B
        string s ; cin>>s;
        int n = s.length();

        int zero = count(s.begin(),s.end(),'0');
        int ones = count(s.begin(),s.end(),'1');
        
        if(ones == zero){
            cout<<0;N();
            return;
        }
        int cost = 0;
        int temp_0 = 0, temp_1 = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '0')temp_0++;
            if(s[i] == '1')temp_1++;
            //Remove everything else ,if the number of 0 cannot match no of ones 
            if(temp_0 > ones){
                cost = n-i;
                break;
            }
            if(temp_1 > zero){
                cost = n-i;
                break;
            }
        }
        cout<<cost;N();
    }





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