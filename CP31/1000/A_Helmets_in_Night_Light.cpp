#include <bits/stdc++.h>
using namespace std;//AUTHOR : NITHISH JAISARUN
using ll = long long int; const int INF = 1e9;
class Main{
public:  

    void solve(){//1876A
        int n,p;cin>>n>>p;
        vector<int>noOfResidents = readVector<int>(n);
        vector<int>cost = readVector<int>(n);

        vector<pair<int,int>>ResidentCost(n,make_pair(0,0));
        transform(noOfResidents.begin(),noOfResidents.end(),cost.begin(),ResidentCost.begin()
        ,[](int x,int y){
            return make_pair(x,y); 
        });

        sort(ResidentCost.begin(),ResidentCost.end(),
        [](const pair<int,int>&a,const pair<int,int>&b){
            if(a.second == b.second)return a.first > b.first;//Min cost,max Resident
            return a.second < b.second;
        });

        int filled = 1;
        int current = 0; 
        ll answer = p;
        while(filled < n && current < n){
            if(ResidentCost[current].second > p)break;

            int remainingResident = min(ResidentCost[current].first,n-filled);
            answer += 1ULL * remainingResident * ResidentCost[current].second;
            filled += remainingResident;
            current++;
        }
        int cheapToInformDirectly = n-filled ;
        answer += 1ULL * cheapToInformDirectly * p;

        cout<<answer;
        N();
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
