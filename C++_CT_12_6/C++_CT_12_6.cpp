#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//좌표변수
int x, y;
//기둥인지 보인지확인하는변수 0이면 기둥, 보이면 1
int a;
//건설인지 삭제인지 여부 변수 0이면 삭제, 1이면 설치
int b;
//건설이나 삭제 한 후의 현재 건축물이 조건에 부합하는지 확인하는 함수
bool is_current_struct_ok(vector<vector<int>> answer)
{
    //현재 설치된 모든 구조물 개수만큼 반복
    for (int i = 0; i < answer.size(); i++)
    {
        //현재 answer iter(기둥or 보) 의 정보 추출
        int x = answer[i][0];
        int y = answer[i][1];
        int a = answer[i][2];

        //벽면을 벗어나게 기둥,보를 설치하는 경우는 없음
        //바닥에 보를 설치하는 경우는 없음
        //기둥은 위쪽으로 삭제나설치
        //보는 오른쪽으로 삭제나 설치
        
        //현재 구조물 기둥이면
        if (a == 0)
        {
            bool is_ok = false;
            //기둥은 바닥 위에 있거나 보의 한쪽 끝 부분 위에 있거나, 또는 다른 기둥 위에 있어야 합니다.
            //바닥위면 정상
            if (y == 0) is_ok = true;
            //보의 한쪽 끝부분위나 다른 기둥위면 정상
            for (int j = 0; j < answer.size(); j++)
            {
                //보 왼쪽위인가? 
                if (x - 1 == answer[j][0] && y == answer[j][1] && 1 == answer[j][2])
                {
                    is_ok = true;
                }
                //보 오른쪽 위인가?
                if (x == answer[j][0] && y == answer[j][1] && 1 == answer[j][2])
                {
                    is_ok = true;
                }
                //다른 기둥의 위인가?
                if (x == answer[j][0] && y - 1 == answer[j][1] && 0 == answer[j][2])
                {
                    is_ok = true;
                }
            }
            if (!is_ok)return false;
        }
        //현재 구조물 보이면
        else
        {
            //보는 한쪽 끝 부분이 기둥 위에 있거나, 또는 양쪽 끝 부분이 다른 보와 동시에 연결되어 있어야 합니다.
            bool left = false;
            bool right = false;
            bool is_ok = false;
            for (int j = 0; j < answer.size(); j++)
            {
                //보의 왼쪽이다른 기둥의 위인가?
                if (x == answer[j][0] && y - 1 == answer[j][1] && 0 == answer[j][2])
                {
                    is_ok = true;
                }
                //보의 오른쪽이 다른 기둥의 위인가?
                if (x+1 == answer[j][0] && y - 1 == answer[j][1] && 0 == answer[j][2])
                {
                    is_ok = true;
                }
                //보의 양끝이 다른보와 모두 연결되어 있는가?
                if (x - 1 == answer[j][0] && y == answer[j][1] && 1 == answer[j][2]) {
                    left = true;
                }
                if (x + 1 == answer[j][0] && y == answer[j][1] && 1 == answer[j][2]) {
                    right = true;
                }
            }
            if (left && right)is_ok = true;
            if (!is_ok)return false;
        }
    }
    //결과 반환(괜찮은 상태면 true 반환)
    return true;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    //build_frame 개수만큼 반복
    for (int i = 0; i < build_frame.size();i++)
    {
        //현재 build_frame iter의 정보 추출
        x = build_frame[i][0];
        y = build_frame[i][1];
        a = build_frame[i][2];
        b = build_frame[i][3];

        //작업이 삭제인경우(없는 구조물 삭제작업은 입력으로 들어오지 않음)
        if (b == 0)
        {
            //삭제하려하는 구조물 정보 추출
            int index = 0;
            for (int j = 0; j < answer.size(); j++)
            {
                if (x == answer[j][0] && y == answer[j][1] && a == answer[j][2])
                {
                    index = j;
                }
            }
            vector<int> temp_save_for_erased = answer[index];
            //일단 구조물 제거
            answer.erase(answer.begin() + index);
            //제거한 뒤 구조물 상태가 가능한 구조물인지 확인

            //가능하면 그대로 다음 build_frame확인하러 이동
            if (is_current_struct_ok(answer))
            {
                continue;
            }
            //불가하면 삭제했던 구조물 다시 추가
            else
            {
                answer.push_back(temp_save_for_erased);
            }
        }
        //작업이 건설인경우(겹치도록 설치하는 작업은 입력으로 들어오지 않음)
        else
        {
            //일단 건설
            vector<int> temp_construct;
            temp_construct.push_back(x);
            temp_construct.push_back(y);
            temp_construct.push_back(a);
            answer.push_back(temp_construct);
            if (is_current_struct_ok(answer))
            {
                continue;
            }
            else
            {
                answer.pop_back();
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{
    return 0;
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
