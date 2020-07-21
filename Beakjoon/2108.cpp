#include<iostream>
#include<cmath>
using namespace std;

void statistics(int list[], int n, int _sum) {
	int sum = _sum;
	int count = 0;
	int center = 4001;		// 중앙값
	int max = 4001;			// 최대값
	int min = 4001;			// 최소값
	int freq = 0;			// 최빈값
	int freq_c = 1;
	for (int i = 0; i < 8001; i++) {
		count += list[i];
		if (center == 4001 && count >= n / 2 + 1) {
			center = i - 4000;
		}
		if (list[i] != 0) {
			if (min == 4001) {
				min = i - 4000;
			}
			max = i - 4000;
			if (i > 0 && list[freq] < list[i]) {
				freq = i;
				freq_c = 1;
			}
			else if (i > 0 && list[freq] == list[i] && freq_c == 1) {
				freq = i;
				freq_c++;
			}
		}
	}
	cout << (int)round((double)sum / n) << "\n";		//산술 평균
	cout << center << "\n" << freq - 4000 << "\n" << max - min << "\n";		//중앙값, 최빈값, 범위

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int num;
	int sum = 0;
	int list[8001]{ 0, };

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		sum += num;
		list[num + 4000]++;
	}
	statistics(list, n, sum);
	return 0;
}