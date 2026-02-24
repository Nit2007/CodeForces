#include <bits/stdc++.h>
using namespace std;

struct Game{
    int l;
    int r;
    int t;
    int p;
};
int main(){
    int n,m;cin>>n>>m;
    vector<Game>athlete(m);
    for(int i=0;i<m;i++){
        cin>>athlete[i].l;
        cin>>athlete[i].r;
        cin>>athlete[i].t;
        cin>>athlete[i].p;
    }
    vector<vector<int>>sections(n);
    for(int i=0;i<m;i++)
    {//compute the eligible athletes for each section
        for(int sec=athlete[i].l;sec<=athlete[i].r;sec++){
            sections[sec-1].push_back(i);
        }
    }
    vector<int>winners(n,-1);
    for(int i=0;i<n;i++){//Find winners from each section
        if(sections[i].empty())continue;

        int winnerIdx = -1;
        int minTime = INT_MAX;

        for(int athleteIdx : sections[i]){
            if(minTime > athlete[athleteIdx].t){
                minTime = athlete[athleteIdx].t;
                winnerIdx = athleteIdx;
            }
        }
        winners[i] = winnerIdx;
    }
    //compute the profit 
    int totalProfit = 0;
    for(int i=0;i<n;i++){
        if(winners[i]!=-1){
            totalProfit += athlete[winners[i]].p;
        }
    }
    cout<<totalProfit<<endl;
    return 0;
}