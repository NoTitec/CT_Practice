// C++_CT_4_4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <bits/stdc++.h>
using namespace std;

//일반적으로 방향을 설정해서 이동하는 문제유형은 dx,dy 라는 배열 만들어 방향 정하는게 효율적

//입력 저장 맵 n,m
// 캐릭터 좌표 x,y 바라보는 방향 direction

int n, m, x, y, direction;

// 방문위치 저장가능한 가장 큰 맵 크기만큼의 공간 생성 과동시 0으로 초기화
int d[50][50];
// 전체 맵 x좌표는 북쪽으로부터 떨어진 칸의 개수, y좌표는 서쪽으로부터 멀어진 칸의 개수 
int allmap[50][50];

//direction에 따른 방향 정의 북,동,남,서
//북남 방향
int dx[] = {-1,0,1,0};
//동서 방향
int dy[] = {0,1,0,-1};

//반시계 방향 회전
void turn_left()
{
    direction -= 1;
    if (direction == -1)
    {
        direction = 3;
    }
}
int main()
{
    //맵 크기 입력받기
    cin >> n >> m;
    // 캐릭터의 좌표 입력받기
    cin >> x >> y >> direction;
    //시작위치 방문표시
    d[x][y] = 1;
    //전체 맵 구조 입력받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            allmap[i][j] = x;
        }
    }

    //탐색시작

    int count = 1;
    //4방향 모두 못가는것 체크위한 변수
    int turn_time = 0;

    while (true)
    {
        turn_left();
        int nx = x + dx[direction];
        int ny = y + dy[direction];
        //회전한이후 보는방향 바로앞에 안가본 칸이 있고 갈 수 있는 칸인 경우 이동
        if (d[nx][ny] == 0 && allmap[nx][ny] == 0)
        {
            d[nx][ny] = 1;
            x = nx;
            y = ny;
            count += 1;
            turn_time = 0;
            continue;
        }
        //회전한 이후 보는방향이 이미 방문한 칸이거나 바다인 경우
        else
        {
            turn_time += 1;
        }
        //네방향 모두 못가는 경우
        if (turn_time == 4)
        {
            nx = x - dx[direction];
            ny = y - dy[direction];
            //뒤이동 가능하면 이동하기
            if (allmap[nx][ny] == 0)
            {
                x = nx;
                y = ny;
                turn_time = 0;
            }
            //뒤가 바다인 경우
            else
            {
                break;
            }

        }
    }
    cout << count << '\n';
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
