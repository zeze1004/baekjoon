# 2003번: 수들의 합 2

https://www.acmicpc.net/problem/2003

## zeze의 풀이

[투 포인터](https://m.blog.naver.com/kks227/220795165570) 이용

~~위의 글을 읽고 오자^^~~


백준 예제 1을 예시로 설명하겠다.

num = 4, goal_num = 2다.


배열 arr[num] = { 1, 1, 1, 1 }을 넣어준다.

start = 0, end = 0, sum = 0, count = 0인 상태이다.

- start: 배열의 왼쪽 인덱스를 가르키는 변수
- end: 배열의 오른쪽 인덱스를 가르키는 변수, end는 start보다 항상 크거나 같다

```c++
// 투 포인터 코드
 while (1)

 {
  if (sum >= goal_num)
  {

   sum -= arr[start]; 	// 1 1 1 1일 때 goal_num이 2라면

            						// arr[0] + arr[1] = 2

           							// sum >= goal_num

            						// sum -= arr[start]
   start++;
  }
  else if (end == num)
   break;
  else
   sum += arr[end++];
  if (sum == goal_num)
   count++;
 }
```

무한루프 안에서 2가지를 검색한다.

​ 1.1) sum이 goal_num 보다 큰가

​ 1.2) end가 num이랑 같은가

​ 1.3 ) 위의 1,2가 모두 아닌가

​ 2) sum이 goal_num이랑 같은가

### 1

무한 루프에 들어가면 가장 먼저 1.1) 을 검사한다.

sum = 0 < goal_num = 2 이므로

1.2) 를 검사한다.

end = 0 != num = 4 이므로

1.1), 1.2) 모두 false이므로 1.3인 else 구문을 실행한다

1.3)

```c++
sum += arr[end++]; // end++이 나중에 실행
/* 위와 같은 구문
sum = sum + arr[end]; // sum에 arr[0] 더하기
end++;	// end 1 증가, end = 1
*/
```

현재 sum = 1, end = 1, start = 0이다.

마지막으로 2)를 검사한다.

sum != goal_num이므로 다시 1.1부터 시작한다.

### 2

#### 현재까지 상태

_sum = 1, end = 1, start = 0, count = 0_

1.1)

sum = 1, goal_num = 2이므로 1.2로 이동

1.2)

end = 1, num = 4이므로 1.3으로 이동

1.3)

sum = sum + arr[1] 가 되므로

sum = 2, end = 2

2.

sum == goal_num이므로

count 1 증가 후 다시 1.1로 이동

#### 현재까지 상태

_sum = 2, end = 2, start = 0, count = 1_

### 3

1.1)

sum >= goal_num 이므로

sum에서 arr[start]의 값을 뺀다.

arr[start] = 1이므로

sum = 1이 된다.

start는 1 증가하여 start = 1이다.

1.1) if문에 걸렸으므로 1.2), 1.3)은 건너뛴다.

2. sum == goal_num이 아니므로 다시 1.1로 이동한다.

### 4

#### 현재까지 상태

_sum = 1, end = 2, start = 1, count = 1_

1.1) false이므로 pass

1.2) false이므로 pass

1.3) 1.1, 1.2 모두 false이므로 1.3이 실행

```c++
sum = sum + sum[end];

end++;

// sum = 2, end = 3
```

2. true 이므로 count 1 증가

### 5

#### 현재까지 상태

_sum = 2, end = 3, start = 1, count = 1_

1.1) true이므로

​ sum에서 arr[start]를 빼고

​ start를 1 증가 시켜준다.

2. false

### 6

#### 현재까지 상태

_sum = 1, end = 3, start = 2, count = 1_

1.1) false

1.2) false

1.3) sum = 2, end = 4

2. count++

### 7

#### 현재까지 상태

_sum = 1, end = 4, start = 2, count = 3_

1.1) false

1.2) true이므로 break; 선언되어 루프를 종료한다.

count가 3이므로 3을 출력하고 종료된다.
