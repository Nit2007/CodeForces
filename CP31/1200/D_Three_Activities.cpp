#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  

    void solve(){//1914D
        int n;cin>>n;
        vector<ll>a = readVector<ll>(n);
        vector<ll>b = readVector<ll>(n);
        vector<ll>c = readVector<ll>(n);

        vector<int>maxA = max3(a);
        vector<int>maxB = max3(b);
        vector<int>maxC = max3(c);
        
        ll ans = 0;
        for(int x:maxA){
            for(int y:maxB){
                for(int z:maxC){
                    if(x == y || y == z || x == z)continue;
                    else{//Try all combinations and pick the unique Max Combo
                        ans = max(ans , ( a[x] + b[y] + c[z] ) )  ;
                    }
                }
            }
        }
        cout<<ans;N();

    }
    vector<int> max3 (vector<ll>&a){
        vector<pair<int,int>>ai(0);
        for(int i=0;i<(int)a.size();i++){
            ai.push_back(make_pair(a[i],i));
        }
        sort(ai.begin(),ai.end(),Value_DESC_Index_ASC);

        vector<int>ans(3,0);
        for(int i=0;i<3;i++){
            ans[i] = ai[i].second;
        }
        return ans;
    }
    static bool Value_DESC_Index_ASC(const pair<int,int>&a , const pair<int,int>&b){
        if(a.first == b.first)a.second < b.second;
        return a.first > b.first;
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

// vector<pair<int,int>>ai(0),bi(0),ci(0);
//         for(int i=0;i<n;i++){
//             ai.push_back(make_pair(a[i],i));
//             bi.push_back(make_pair(b[i],i));
//             ci.push_back(make_pair(c[i],i));
//         }
//         sort(ai.begin(),ai.end(),Value_DESC_Index_ASC);
//         sort(bi.begin(),bi.end(),Value_DESC_Index_ASC);
//         sort(ci.begin(),ci.end(),Value_DESC_Index_ASC);
        
//         int i1 = ai[0].second;
//         int i2 = bi[0].second;
//         int i3 = ci[0].second;
//         if(ai[0].second != bi[0].second && bi[0].second != ci[0].second){
//             cout<<ai[0].first+bi[0].first+ci[0].first;N();return;
//         }
//         else if(ai[0].second == bi[0].second && bi[0].second == ci[0].second){
//             if(ai[1].first < bi[1].first && ai[1].first < ci[1].first){
//                 i2++;
//                 i3++;
//             }
//             else if(bi[1].first < ai[1].first && bi[1].first < ai[1].first){
//                 i1++;
//                 i3++;
//             }else{
//                 i1++;
//                 i2++;
//             }

//             if(i1 == i2){
//                 if(ai[2].first > bi[2].first){
//                     i2++;
//                 }else i1++;
//             }
//             else if(i2 == i3){
//                 if(bi[2].first > ci[2].first){
//                     i3++;
//                 }else i2++;
//             }
//             else{
//                 if(ci[2].first > ai[2].first){
//                     i1++;
//                 }else i3++;
//             }
//         }
//         else if(ai[0].second == bi[0].second ){
//             if(ai[1].first > bi[1].first){
//                 i1 = 1;
//             }else i2 = 1;
//         }
//         else if(bi[0].second == ci[0].second ){
//             if(bi[1].first > ci[1].first){
//                 i2 = 1;
//             }else i3 = 1;
//         }

//         cout<<ai[i1].first+bi[i2].first+ci[i3].first;N();

//     }
//     vector<int> max3 (vector<int>&a){
//         vector<pair<int,int>>ai(0);
        
//     }
//     static bool Value_DESC_Index_ASC(const pair<int,int>&a , const pair<int,int>&b){
//         if(a.first == b.first)a.second < b.second;
//         return a.first > b.first;
//     }