#include <bits/stdc++.h>

using namespace std;

//도시 개수 N, 도로 개수 M, 목표 거리 K , 출발 도시 번호 X
int n,m,k,x;

//각 도시의 도로 정보 저장할 vector
vector<int> citys[300001];

//거리 정보 저장할 vector
vector<int> distanceinfo(300001,-1);

int main()
{
    cin>>n>>m>>k>>x;
    distanceinfo[x]=0;
    //도로 정보 입력
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        citys[x].push_back(y);
    }
    
    //bfs 수행

    queue<int> q;
    q.push(x);

    while(!q.empty())
    {
        int curcitynum=q.front();
        q.pop();
        //현재 도시서 도로가 이어져 있는 모든 도시 확인
        for(int i=0;i<citys[curcitynum].size();i++)
        {
            //해당 도시가 방문한 적 없는 노드면 현재도시+1 해서 거리 갱신
            int nextcity=citys[curcitynum][i];
            if(distanceinfo[nextcity]==-1)
            {
                distanceinfo[nextcity]=distanceinfo[curcitynum]+1;
                q.push(nextcity);
            }   
        }
    }
    //종료 후 모든 도시중 목표 k거리인 도시들 한줄씩 출력
    bool nok=true;
    for(int i=1;i<=n;i++)
    {
        if(distanceinfo[i]==k)
        {
            cout<<i<<'\n';
            nok=false;
        }
    }

    if(nok) cout<<"-1";

    return 0;
}