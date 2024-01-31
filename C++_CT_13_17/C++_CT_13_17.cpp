#include <bits/stdc++.h>

using namespace std;

//바이러스 1개의 정보 저장할 클래스
class Virus {
public:
    //종류
    int index;
    //시간
    int second;
    //행
    int x;
    //열
    int y;
    //생성자
    Virus(int index, int second, int x, int y) {
        this->index = index;
        this->second = second;
        this->x = x;
        this->y = y;
    }
    // 정렬 기준은 '번호가 낮은 순서'
    //sort 함수를 위해 operator 오버로딩
    bool operator <(Virus &other) {
        return this->index < other.index; 
    }
};
//바이러스 저장변수
vector<Virus> viruses;
//맵 크기 ,종류 수 저장 변수
int n,k;
//가능한 가장 큰 맵 공간 생성
int board[200][200];
// 진행 초, 좌표 변수
int s,x,y;
//방향 지정용 배열(상,하,좌,우)
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

int main()
{
    //맵 크기, 바이러스 종류 수 입력
    cin>>n>>k;
    //맵 구조 입력
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>board[i][j];
            if(board[i][j]!=0)
            {
                // (바이러스 종류, 시간, 위치 X, 위치 Y) 삽입
                viruses.push_back(Virus(board[i][j], 0, i, j));
            }
        }
    }
    // 바이러스 번호 오름차순 정렬 이후에 큐로 옮기기 (낮은 번호의 바이러스가 먼저 증식하므로)
    sort(viruses.begin(), viruses.end());
    queue<Virus> q;
    for (int i = 0; i < viruses.size(); i++) {
        q.push(viruses[i]);
    }

    //목표시간,최종 x,y좌표 입력
    cin>>s>>x>>y;
    // 너비 우선 탐색(BFS) 진행
    while (!q.empty()) {
        //1개 바이러스 추출
        Virus virus = q.front();
        q.pop();
        // 정확히 second만큼 초가 지나거나, 큐가 빌 때까지 반복
        if (virus.second == s) break;
        // 현재 노드에서 주변 4가지 위치를 각각 확인
        for (int i = 0; i < 4; i++) {
            int nx = virus.x + dx[i];
            int ny = virus.y + dy[i];
            // 해당 위치로 이동할 수 있는 경우
            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                // 아직 방문하지 않은 위치라면, 그 위치에 바이러스 넣고 해당 위치바이러스정보 second 1 늘리고 큐에 push
                if (board[nx][ny] == 0) {
                    //노드 방문표시
                    board[nx][ny] = virus.index;
                    q.push(Virus(virus.index, virus.second + 1, nx, ny));
                }
            }
        }
    }
    
    //문제서 시작 좌표가 1,1이라고했기때문에 s초 이후 출력을 원하는 board의 좌표는 각 좌표서 -1을 한 위치
    cout<<board[x-1][y-1];
    return 0;
}