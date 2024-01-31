#include<bits/stdc++.h>

using namespace std;

//가로세로 크기 변수 n,m의 최대 입력값은 8
int n,m;

//가능한 가장 큰 맵 공간 생성
int board[8][8];
//벽을 설치한뒤 상태를 저장할 공간
int walladdboard[8][8];
//상하좌우 이동에대한 증감배열
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
//최대 안전구역 크기 저장 변수
int result=0;

//필요 함수들
//1. 바이러스 있는 좌표에서 퍼질수 있는 모든 위치로 퍼지는 함수
void virus(int x,int y)
{
    int nx,ny;
    //상하좌우 이동가능한 방향중 0인 공간이 있으면 2로 바꾸고 재귀호출
    for(int i=0;i<4;i++)
    {
        nx=x+dx[i];
        ny=y+dy[i];
        if(nx>=0&&nx<n&&ny>=0&&ny<m)
        {
            if(walladdboard[nx][ny]==0)
            {
                walladdboard[nx][ny]=2;
                virus(nx,ny);
            }
        }
    }
}
//3. 안전구역 개수를 세는 함수
int SafezoneCount(){
    int result=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(walladdboard[i][j]==0)
            {
                result+=1;
            }
        }
    }
    return result;
}
//2. 가능한 모든 벽 설치 경우의 수마다 바이러스를 전파하고 안전구역의 최대값을 구하는 함수
void DFS(int wallcount)
{
    //벽이 3개인 경우 현 상태를 임시 공간에 복사하고 현 상태에대해 바이러스 전파하고 안전구역 최대값 저장한뒤 함수 종료
    if(wallcount==3)
    {
        //현재 벽 3개 설치된 조합에대해 안전구역 계산위해 임시 공간으로 복사
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                walladdboard[i][j]=board[i][j];
            }
        }
        //임시배열에서 바이러스가 있는 모든 위치에대해 전파될 수 있는곳까지 dfs로 전파
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(walladdboard[i][j]==2)
                {
                    virus(i,j);
                }
            }
        }
        //전파가 끝나면 끝난 상태에 대해서 안전공간의 개수를 세어 최대값 갱신하고 함수 종료
        result=max(result,SafezoneCount());
        return;
    }
    //벽이 3개 설치된 상황이 아닌경우 최초 만난 빈 공간에 벽을 설치하고 재귀로 호출하여 다시 빈공간에 벽을 설치하여 벽이 3개가 될때까지 재귀호출
    //맵의 처음부터 반복하여 모든 조합에대해 계산 할 수 있도록 구현
    else
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==0)
                {
                    board[i][j]=1;
                    wallcount+=1;
                    DFS(wallcount);
                    //함수가 종료되면 빠져나오기전에 자신이 변경한 벽정보 되돌리기
                    board[i][j]=0;
                    wallcount-=1;
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    DFS(0);
    cout << result << '\n';
    return 0;
}