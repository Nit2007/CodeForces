#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//g++ Target_Practice.cpp -o target.exe
//del *.exe
int main() {//2185E
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int z;cin>>z;
    while(z--)
    {
        int n,m,k;cin>>n>>m>>k;
        vector<ll>robot(n);
        for(int j=0;j<n;j++)
        {
            cin>>robot[j];
        }
        vector<ll>spike(m);
        for(int j=0;j<m;j++)
        {cin>>spike[j];}
        string instruction;
        cin>>instruction;

        map<int,vector<ll>>death_location;//Stores , at [current_pos] => index of robots died

        sort(spike.begin(),spike.end());
        for(int i=0;i<n;i++){
            auto spike_position = lower_bound(spike.begin(),spike.end(),robot[i]);
            if(spike[0] < robot[i]){//THere is some spike at left side
                int left_dist = *prev(spike_position) - robot[i];
                death_location[left_dist].push_back(i);
            }
            if(spike[m-1] > robot[i]){//THere is some spike at right side
                int right_dist = *(spike_position) - robot[i];
                death_location[right_dist].push_back(i);
            }
        }

        int alive=n;
        vector<int>dead(n,false);
        int current_pos = 0;

        for(int i=0;i<k;i++){
            if(instruction[i] == 'L')current_pos--;
            else if(instruction[i] == 'R')current_pos++;

            for(int robo:death_location[current_pos]){
                if(dead[robo])continue;
                dead[robo] = true;
                alive--;
            }
            death_location[current_pos].clear();
            cout<<alive<<" ";
        }


        cout<<"\n";
    }
}
//TLE on 4 th TestCase
// int main() {//2185E
//     ios_base::sync_with_stdio(false);   cin.tie(NULL);
//     int z;cin>>z;
//     while(z--)
//     {
//         int n,m,k;cin>>n>>m>>k;
//         vector<ll>robot(n);
//         for(int j=0;j<n;j++)
//         {
//             cin>>robot[j];
//         }
//         set<ll>spike;
//         for(int j=0;j<m;j++)
//         {
//             ll temp;
//             cin>>temp;
//             spike.insert(temp);
//         }
//         string instruction;
//         cin>>instruction;
//         int alive=n;
//         set<int>dead;
//         for(int i=0;i<k;i++){
//             for(int j=0;j<n;j++){
//                 if(dead.find(j) != dead.end()){
//                     continue;
//                 }
//                 if(instruction[i] == 'R')robot[j]++;
//                 if(instruction[i] == 'L')robot[j]--;
//                 if(spike.find(robot[j]) != spike.end()){
//                     alive--;
//                     dead.insert(j);
//                 }
//             }cout<<alive<<' ';
//         }cout<<"\n";
//     }
// }
