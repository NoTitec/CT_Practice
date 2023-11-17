// C++_CT_11_6.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}
int solution(vector<int> food_times, long long k) {
    int answer = 0;

    long long allfoodtime = 0;
    for (int i = 0; i < food_times.size(); i++)
    {
        allfoodtime += food_times[i];
    }
    if (allfoodtime <= k) return -1;

    //섭취 시간 작은 음식부터 순회에서 사라지므로 우선순위 큐 이용
    //<음식시간, 음식번호> 형태 큐 사용
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < food_times.size(); i++)
    {
        //섭취시간 작은것이 큐 상단으로 가야하기때문에 -붙여서 push
        pq.push({ -food_times[i], i + 1 });
    }
    //섭취시간
    long long eattime = 0;
    //이전음식 1개 다먹는데 걸리는 시간
    long long previousfoodtime = 0;
    //남은 음식 수
    long long leftfoodcount = food_times.size();

    //큐 상단 음식을 남은시간동안 다 먹을 수있는지 확인
    //현재까지 먹는데 쓴 총 시간= 이전까지 먹은 시간+(현재음식시간-이전 음식 시간)
    while (eattime + ((-pq.top().first - previousfoodtime) * leftfoodcount) <= k)
    {
        //현재 음식 다먹는데 소요되는 시간
        int nowfoodtime = -pq.top().first;
        pq.pop();
        //현재 음식을 다 먹는데 걸리는 시간 = 현재음식시간-이전음식 먹는데 걸리는시간(원판 돌면서 한번씩 현재음식도 1초씩 먹었을 것이기 때문)
        eattime += (nowfoodtime - previousfoodtime) * leftfoodcount;
        leftfoodcount -= 1;
        previousfoodtime = nowfoodtime;
    }

    //큐상단음식을 남은k시간동안 다 먹지 못하는경우 남은 큐 중에서 k+1번째의 음식번호 return 하면 됨
    vector < pair<int, int> >resultnode;
    //큐에 남은 음식시간,번호를 새로은 resultnode 벡터에 담아두기
    while (!pq.empty())
    {
        int food_time = -pq.top().first;
        int num = pq.top().second;
        pq.pop();
        resultnode.push_back({ food_time, num });
    }
    //음식 번호순서대로 정렬
    sort(resultnode.begin(), resultnode.end(), compare);
    //남은시간+1번째의 음식번호 저장
    answer = resultnode[(k - eattime) % leftfoodcount].second;
    return answer;
}
int main()
{
    int n = 3;
    vector<int> foods = {3,1,2};
    /*for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        foods.push_back(x);
    }*/
    long long k = 5;

    int result = solution(foods, k);

    cout << result;

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
