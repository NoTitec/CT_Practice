﻿// C++_CT_3_4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <bits/stdc++.h>
using namespace std;
int n, k, result;

int main()
{
	result = 0;
	cin >> n >> k;

	while (true)
	{
		//주어진 n 에서 k로 나누어떨어지는 가장 가까운 수 산출
		int modulenum = (n / k) * k;
		// n에서 modulenum이 될 때까지 1을 빼는 연산 회수
		result += (n - modulenum);
		//나누어떨어지는 남은 결과
		n = modulenum;

		//나누는 연산 불가할때 반복문중단
		if (n < k) break;
		result += 1;
		n /= k;
	}
	//나누는 연산 불가할때 나누기없이 빠져나오기 때문에 남은n을 1로 만들기위한 -1연산 횟수는 n-1번이다
	//이 횟수를 result에 +한다
	result += (n - 1);
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
