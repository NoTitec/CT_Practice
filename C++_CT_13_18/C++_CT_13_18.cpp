#include <bits/stdc++.h>
using namespace std;

//입력 문자열에서 균형문자열 u,v분리위한 인덱스 찾는 함수
int find_balance_index(string p)
{
    // '(' 개수
    int leftcount=0;
    for(int i=0;i<p.size();i++)
    {
        if(p[i]=='(')
        {
            leftcount+=1;
        }
        else
        {
            leftcount-=1;
        }
        if(leftcount==0)
            return i;
    }
    return -1;
}
//입력 문자열이 올바른 문자열인지 확인
bool check_ok(string p)
{
    int leftcount=0;
    for(int i=0;i<p.size();i++)
    {
        if(p[i]=='(')
        {
            leftcount+=1;
        }
        else
        {
            if(leftcount==0)
            {
                return false;
            }
            leftcount-=1;
        }
    }
    return true;
}
string solution(string p) {
    string answer = "";
    //입력 빈 문자열이면 빈 문자열 반환
    if (p == "") return answer;
    //균형잡힌 문자열 분리
    int index = find_balance_index(p);
    string u = p.substr(0, index + 1);
    string v = p.substr(index + 1);
    //문제 3-1 조건
    // "올바른 괄호 문자열"이면, v에 대해 재귀함수를 수행한 결과를 붙여 반환
    if (check_ok(u)) {
        answer = u + solution(v);
    }
    //문제 4 조건
    // "올바른 괄호 문자열"이 아니라면 아래의 과정을 수행
    else {
        answer = "(";
        answer += solution(v);
        answer += ")";
        u = u.substr(1, u.size() - 2); // 첫 번째와 마지막 문자를 제거
        for (int i = 0; i < u.size(); i++) {
            if (u[i] == '(') u[i] = ')';
            else u[i] = '(';
        }
        answer += u;
    }
    return answer;
}