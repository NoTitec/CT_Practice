// C++_CT_12_5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <bits/stdc++.h>
//시뮬레이션 유형
using namespace std;

//보드크기
int n;
//사과 수
int k;
//방향 전환 수
int l;
//보드 -최대 크기는 100*100 (크기만 선언시 모든 값 0 초기화됨)
int board[101][101] = {};
// 정수형,문자로 이루어진 방향 전환 정보
vector<pair<int, char>> info;

//방향별 값 설정
//동,남,서,북 (90도 회전이동이므로 이순서로 작성해야 +1,-1 연산으로 이동시 연산값 추출용이)
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

// 방향 전환 시간인경우 현재 방향에서 입력방향 쪽으로 90도전환하는 함수
int turn(int direction,char c)
{
    //왼쪽으로 90도 회전
    if (c == 'L')
    {
        //현재 동쪽이면 90도 왼쪽 회전시 북쪽 이므로 3 그외 -1
        direction = (direction == 0) ? 3 : direction - 1;
    }
    else
    {
        //현재 동쪽이면 90도 오른쪽 회전시 남쪽 이므로 +1 그런데 3인 경우 +1시 초과되므로
        //나머지 연산으로 범위 안 벗어나게 조절
        direction = (direction + 1) % 4;
    }
    return  direction;
}
int start()
{
    //뱀 시작 위치가 1,1이라고 문제 명시됨
    int x = 1, y = 1;
    //뱀 있는 위치는 2 표시
    board[x][y] = 2;
    //처음에는 동쪽
    int direction = 0;
    //시작후 경과 초
    int time = 0;
    // 다음 회전 정보
    int direction_change_count = 0;
    //뱀의 현재 차지하고있는 위치들 정보
    queue<pair<int, int>> q;
    //push 되는 위치가 새로운 머리임
    q.push({ x,y });

    while (true)
    {
        int nx = x + dx[direction];
        int ny = y + dy[direction];
        //맵 안이고 몸통에 안닿는 위치인 경우
        if (1 <= nx && nx <= n && 1 <= ny && ny <= n && board[nx][ny] != 2)
        {
            // 사과 없으면 길이늘려 이동 후 꼬리 제거
            if (board[nx][ny] == 0)
            {
                //길이 확장
                board[nx][ny] = 2;
                q.push({ nx,ny });
                //queue에서 꼬리 제거전 위치정보 추출
                int tx = q.front().first;
                int ty = q.front().second;
                //queue에서 꼬리 제거
                q.pop();
                //제거했으므로 맵의 해당 위치 0으로 변경
                board[tx][ty] = 0;
            }
            if (board[nx][ny] == 1)
            {
                board[nx][ny] = 2;
                q.push({ nx,ny });
            }
        }
        //맵 밖이거나 몸통에 닿은경우
        else
        {
            time += 1;
            break;
        }
        //뱀 이동
        x = nx;
        y = ny;
        time += 1;
        //방향전환 수 가 입력됐던 방향전환 총수 l 보다 작고 회전시간인 경우 방향 전환
        if (direction_change_count < l && time == info[direction_change_count].first)
        {
            direction = turn(direction, info[direction_change_count].second);
            direction_change_count++;
        }
    }
    return time;
}
int main()
{
    cin >> n >> k;

    //맵에 사과있는만 1 표시
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        board[a][b] = 1;
    }

    cin >> l;
    for (int i = 0; i < l; i++)
    {
        int x;
        char c;
        cin >> x >> c;
        info.push_back({ x,c });
    }
    
    cout << start()<<endl;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
