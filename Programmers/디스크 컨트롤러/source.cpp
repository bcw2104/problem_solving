#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

bool comp(vector<int> a, vector<int> b) {
    if (a[0] == b[0])
        return a[1] < b[1];

    return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0;
    deque<pair<int, int>> dq;
    deque<pair<int, int>>::iterator iter;
    deque<pair<int, int>>::iterator temp;

    sort(jobs.begin(), jobs.end(), comp);

    for (int i = 0; i < jobs.size(); i++) {
        dq.push_back(make_pair(jobs[i][0], jobs[i][1]));
    }

    while (!dq.empty()) {
        int mintime = 1001;
        int start = 0;
        for (iter = dq.begin(); iter != dq.end(); iter++) {
            if ((*iter).first <= time) {
                if (mintime > (*iter).second) {
                    mintime = (*iter).second;
                    start = (*iter).first;
                    temp = iter;
                }
            }
        }

        if (mintime == 1001) {
            time = dq.front().first + dq.front().second;
            answer += time - dq.front().first;
            dq.pop_front();
        }
        else {
            time += mintime;
            answer += time - start;
            dq.erase(temp);
        }
    }

    return answer / jobs.size();
}