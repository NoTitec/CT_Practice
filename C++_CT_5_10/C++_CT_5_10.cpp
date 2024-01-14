#include <bits/stdc++.h>

using namespace std;

//얼음틀 (최대 가로세로 각각 1000)
int iceboard[1000][1000];

//가로세로 길이 변수
int n,m;

//얼음틀 현재 좌표서 DFS 수행하는 함수(현재 좌표와 연결된 묶음 모두 탐색하는 용도)
bool dfs(int x,int y)
{
    // iceboard 범위를 벗어나는 경우에는 즉시 종료
    if (x <= -1 || x >=n || y <= -1 || y >= m) {
        return false;
    }
    //현재 노드가 0인 경우
    if(iceboard[x][y]==0)
    {
        //현재노드 방문표시
        iceboard[x][y]=1;
        //현재노드로부터 상,하,좌,우 모두 재귀호출하면서 dfs 탐색하도록 하면서 현재 노드와 연결된 모든 노드 1로 변경
        dfs(x,y-1);
        dfs(x,y+1);
        dfs(x-1,y);
        dfs(x+1,y);
        //시작인 0 노드는 1개 묶음의 시작점이고 위의 재귀호출을 수행하면 같은 묶음의 모든 값은 1로 변경되어 있음
        //묶음 수 증가를위해 true 전달
        return true;
    }
    return false; 
}
//메인

int main()
{
    //가로 세로 길이 입력
    cin>>n>>m;
    cin.ignore();
    //맵 정보 입력 받기
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);  // 한 줄을 문자열로 입력 받음
        for (int j = 0; j < m; j++) {
            iceboard[i][j] = line[j] - '0';  // 문자를 정수로 변환
        }
    }

    // 모든 노드(위치)순회하며 묶음 개수 찾기
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 현재 위치에서 DFS 수행
            // return true 일 경우에만 묶음 개수 증가
            if (dfs(i, j)) {
                result += 1;
            }
        }
    }
    cout << result << '\n';
    return 0;
}