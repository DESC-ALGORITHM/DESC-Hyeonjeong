#include <iostream>
#include <vector>

using namespace std;

// 현재 계단까지 왔을떄 최대값은 ?
int maxScore(int n, vector<int> &stairs){
    if(n==1){
        return stairs[1];
    }
    vector<int> dp(n+1, 0);
    dp[1] = stairs[1];
    dp[2] = stairs[1] + stairs[2];

    for(int i=3; i<=n; i++){
        // 두칸 전에서 왔거나, 한칸 + 세칸전에서 왔는가
        dp[i] = max(dp[i-2], dp[i-3]+ stairs[i-1]) + stairs[i];
    }

    return dp[n];
}

int main(){
    int n;
    cin >> n;
    vector<int> stairs(n+1, 0);

    for(int i=1; i<=n ;i++){
        cin>> stairs[i];
    }

    cout<<maxScore(n, stairs);

    return 0;
}