// C++_CT_12_7.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <bits/stdc++.h>

using namespace std;

//풀이 핵심 아이디어
//현재 맵의 치킨집중 M개를 고르는 모든 경우에 대해 치킨 거리 합을 구하고, 그중 결과 가 가장 적은 치킨거리 최솟값 출력하면 됨

//맵 크기, 선택 치킨집 수
int n, m;
//맵 최대 크기
int ground[50][50];
//집 좌표
vector<pair<int, int>> house;
//치킨집 좌표
vector<pair<int, int>> chicken;

//인자로 들어온 현재 선택된 치킨집 조합에 대해 각 집들의 가장가까운 치킨집 거리를 구해 합산값 리턴하는 함수
int getdistancesum(vector<pair<int, int>>currentcombination)
{
    int result = 0;
    //모든 집마다
    for (int i = 0; i < house.size(); i++)
    {
        //현재 집 좌표
        int xh = house[i].first;
        int yh = house[i].second;
        //현재 집서 인자의 선택된 치킨집 중에 가장 인접한 치킨집 찾기
        int mostclosechicken = 1000000000;
        for (int j = 0; j < currentcombination.size(); j++)
        {
            int xc = currentcombination[j].first;
            int yc = currentcombination[j].second;
            mostclosechicken = min(mostclosechicken,abs(xh-xc)+abs(yh-yc));
        }
        result += mostclosechicken;
    }
    return result;
}

int main()
{
    //n,m 입력받기
    cin >> n >> m;
    //도시 정보 입력받기
    //빈칸 0, 집 1, 치킨집 2
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cin >> ground[r][c];
            if (ground[r][c] == 1) house.push_back({ r, c }); // 일반 집
            else if (ground[r][c] == 2) chicken.push_back({ r, c }); // 치킨집
        }
    }
    // 모든 치킨 집 중에서 m개의 치킨 집을 뽑는 조합 계산
    vector<bool> binary(chicken.size());
    //binary 벡터 끝-m 위치서 끝까지의 값 true로 변경
    // 
    //사전순 첫 번째 조합 생성-> 진행하면서 사전순 오름차순으로 생성해야하기때문에 가장 뒤에 true배치
    fill(binary.end() - m, binary.end(), true);

    //치킨거리 변수
    int result = 1000000000;

    //조합의 사전순 가장 큰 조합에 도달 할 때까지 각 조합의 선택된 치킨집들 벡터를 만든후 getdistancesum에 
    //선택 치킨집 정보 전달하여 현재 조합 치킨거리 얻은 후 지금까지의 거리와 비교해 더 작은값으로 갱신

    do {
        vector<pair<int, int>> currentcombination;
        //binary 크기는 전체 치킨집 개수와 동일
        for (int i = 0; i < chicken.size(); i++)
        {
            //binary index 하나씩 검사하면서 true인 경우 현재 조합의 선택된 치킨집이므로 정보 추출하여 
            //currentcombination에 추가
            if (binary[i]) {
                int cx = chicken[i].first;
                int cy = chicken[i].second;
                currentcombination.push_back({ cx, cy });
            }
        }
        //getdistancesum으로 현재조합 치킨거리 구하고 더 적은값으로 갱신
        result = min(result, getdistancesum(currentcombination));
        //조합의 사전순 가장 큰 조합에 도달 할 때까지
    } while (next_permutation(binary.begin(), binary.end()));

    cout << result << endl;
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
