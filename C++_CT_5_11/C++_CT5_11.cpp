#include <bits/stdc++.h>

using namespace std;

int n, m;
int graph[201][201];

// 이동할 네 가지 방향 정의 (상, 하, 좌, 우) 
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(int x, int y)
{
    queue<pair<int,int>> q;
    q.push({x,y});

    while(!q.empty()){
    int cx=q.front().first;
    int cy=q.front().second;
    q.pop();

    //현재 위치서 상하좌우 4방향 확인
    for(int i=0;i<4;i++)
    {
        int nx=cx+dx[i];
        int ny=cy+dy[i];
        //맵 벗어나면 무시
        if(nx<0||nx>=n||ny<0||ny>=m) continue;
        //괴물 있는 곳이면 무시
        if(graph[nx][ny]==0) continue;
        //괴물 없는 곳이고 방문한적이 없는 노드면 해당노드 비용 1 증가시키고 해당노드 연결노드 탐색위해 queue에 push
        if(graph[nx][ny]==1)
        {
            graph[nx][ny]=graph[cx][cy]+1;
            q.push({nx,ny});
        }
    }
    }
    // 가장 오른쪽 아래까지의 최단 거리 반환
    return graph[n - 1][m - 1];
}
int main()
{
    cin>>n>>m;
    cin.ignore();

    //2차원 맵 정보 공백없이 1줄씩 입력
    for(int i=0;i<n;i++)
    {
        string line;
        getline(cin,line);
        for(int j=0;j<m;j++)
        {
            graph[i][j]=line[j]-'0';
        }
    }
    
    cout<<bfs(0,0)<<'\n';
    return 0;
}