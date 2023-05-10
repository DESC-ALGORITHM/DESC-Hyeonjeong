#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Parametric Search
// 적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값 -> 높이가 h일때 M미터 이하로 나무 가져갈 수 있는가?
int maxHeight(long long n, long long m, vector<long long> &tree) {
    // 중간값부터 시작해서 m보다 크면 오른쪽, 아니면 왼쪽
    // 주의 : 높이 높아질수록 절단되는 값은 줄어든다는것!
    long long left = 0;
    long long right = tree[n-1];
    long long result = 0;

    while (left <= right) {
        long long num = 0;
        long long mid = (left + right) / 2;
        long long idx = lower_bound(tree.begin(), tree.end(), mid) - tree.begin();

        for (int i = idx; i < n; i++) {
            num += tree[i] - mid;
        }
        if (num >= m) { // 헤깔린부분 -> 현재 절단한값이 더 크면 값더 줄여야한다 생각 (더크니깐 더 늘려서 가져갈 부분 더 적게하기)
            left = mid + 1;
            result = max(result, mid);
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    long long n, m;
    cin >> n >> m;
    vector<long long> tree(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> tree[i];
    }
    sort(tree.begin(), tree.end());

    cout << maxHeight(n, m, tree);

    return 0;
}