#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 20;
const int INF = 10e8;

int n;
int answer = INF;
int power[SIZE][SIZE];
bool is_start[SIZE];
int start[SIZE], link[SIZE];

int calcPower(int arr[], int size) {
    int result = 0;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++)
            result += power[arr[i]][arr[j]] + power[arr[j]][arr[i]];
    }
    return result;
}

void backtracking(int cnt, int st) {
    if (cnt == n)
        return;
    if (cnt > 0) {
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (!is_start[i])
                link[idx++] = i;
        }
        int diff_value = abs(calcPower(link, idx) - calcPower(start, cnt)); //두 팀의 능력치 차이
        answer = min(answer, diff_value); //차이의 최솟값 저장
    }
    for (int i = st; i < n; i++) {
        is_start[i] = true;
        start[cnt] = i; //스타트 팀에 배치
        backtracking(cnt + 1, i + 1);
        if (i == 0)
            return;
        is_start[i] = false;
    }
}


int main() {
    //입력
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> power[i][j]; //사람 사이의 능력치 관계
        }
    }
    backtracking(0, 0);

    cout << answer << '\n';

    return 0;
}