/* 1000.zeze1004.cpp
 * 2021.01.16
 * Written by So Jung Kim, Dept. of Design, Univ. of Seoul
 */

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num, goal_num, arr[10001], sum = 0, count = 0;
	int start = 0, end = 0;
	cin >> num >> goal_num;

	// 배열에 값 집어넣기
	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}

	// arr[start]부터 arr[end] 하나씩 더하고
	// if sum >= goal_num: sum - arr[start]
	//										 start++
	// else if sum < goal_num: arr[end++]
	//												 sum이 goal_num[end]까지 더한 값이므로 goal_num[end+1]을 추가로 더 함
	// if num == end: break
	//								end가 배열의 끝까지 탐색한 것이므로 반복문 끝낸다
	int index = 0;
	while (1)
	{
		if (sum >= goal_num)
		{
			sum -= arr[start]; // 1 1 1 1일 때 goal_num이 2라면
												 // arr[0] + arr[1] = 2
												 // sum >= goal_num
												 // sum -= arr[start]
			start++;
		}
		else if (end == num)
		{
			cout << "finish_index " << index << '\n';
			break;
		}
		else
		{
			sum += arr[end++];
			cout << index << " " << end << '\n';
		}
		if (sum == goal_num)
			count++;
		cout << "find_index_4 " << index << '\n';
		index++;
	}

	cout << count;
	return 0;
}