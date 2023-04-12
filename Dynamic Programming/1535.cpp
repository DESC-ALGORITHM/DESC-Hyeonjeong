#include <iostream>
#include <vector>

using namespace std;
/*
 * 전체 시간복잡도 - 2^20 = 100만정도 (완전탐색)
 * 중복 조합으로 품
 */

int maxFun(vector<int> &strength, vector<int> &joy, int n){
    int result =0;
    vector<vector<int>> energy(n+1, vector<int>(101,0));

    for(int i=1; i<=n; i++){
        for(int j=0; j<=100; j++){
            if(j + strength[i] < 100){ //새로운 사람과 인사
                energy[i][j] = max(energy[i-1][j], energy[i-1][j+strength[i]] + joy[i]);
            }else{ // 인사 못함
                energy[i][j] = energy[i-1][j];
            }
            result = max(result, energy[i][j]);
        }
    }
    return result;
}

int main() {
    int n;
    cin>> n;

    vector<int> strength(n+1, 0);
    vector<int> joy(n+1,0);

    for(int i=1; i<=n; i++){
        cin>> strength[i];
    }
    for(int i=1; i<=n; i++){
        cin>> joy[i];
    }

    cout <<maxFun(strength, joy, n);
    return 0;
}