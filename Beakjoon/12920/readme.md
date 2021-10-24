# 📄 평범한 배낭 2

## 출처
https://www.acmicpc.net/problem/12920

## 조건
|시간 제한|	메모리 제한|
|:----:|:------:|
|1 초 |	512 MB|

## 문제
이 문제는 아주 평범한 배낭에 관한 두 번째 문제이다.

민호는 BOJ 캠프에 가기 위해 가방을 싸려고 한다. 가방에 어떠한 물건들을 넣냐에 따라 민호의 만족도가 달라진다. 집에 있는 모든 물건들을 넣으면 민호가 느낄 수 있는 만족도는 최대가 될 것이다. 하지만 민호가 들 수 있는 가방의 무게는 정해져 있어 이를 초과해 물건을 넣을수가 없다.

민호가 만족도를 최대로 느낄 수 있는 경우를 찾아보자.

단, 집에 동일한 물건들이 여러개가 있을 수 있기 때문에 한 물건을 두개 이상 챙기는 것도 가능하다.

## 입력
첫 번째 줄에 N, M (1 ≤ N ≤ 100, 1 ≤ M ≤ 10,000) 이 빈칸을 구분으로 주어진다. N은 민호의 집에 있는 물건의 종류의 수이고 M은 민호가 들 수 있는 가방의 최대 무게다.

두 번째 줄부터 N개의 줄에 걸쳐 민호의 집에 있는 물건의 정보가 주어진다.

각각의 줄은 V, C, K (1 ≤ V ≤ M, 1 ≤ C, K ≤ 10,000, 1 ≤ V * K ≤ 10,000) 으로 이루어져 있다.

V는 물건의 무게, C는 물건을 가방에 넣었을 때 올라가는 민호의 만족도, K는 물건의 개수이다.

## 출력
최대 무게가 넘기지 않고 물건을 담았을 때 민호가 느낄 수 있는 최대 만족도를 출력한다.