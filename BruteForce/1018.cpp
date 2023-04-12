#include <iostream>
#include <vector>

using namespace std;


// 시작에 따라 두가지 방식이 나올거고 더 적은걸로 선택하기
int result= 1e3;
void makeColor(vector<vector<int>> square, int start_i, int start_j){

    int cnt=0;
    for(int i=start_i; i<=start_i+7; i++){
        for(int j=start_j; j<=start_j+7; j++){
            if(j==start_j){
                if(square[i-1][j]==square[i][j]){
                    square[i][j] = (square[i][j] +1) % 2;
                    cnt++;
                }
                continue;
            }
            if(square[i][j-1]==square[i][j]){
                square[i][j] = (square[i][j] +1) % 2;
                cnt++;
            }
        }
    }

    result = min(result, cnt);
}

int main() {
    int m, n;
    cin>>n>>m;
    vector<vector<int>> square(n+1, vector<int>(m+1, 0));

    // 입력
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            char input; cin>>input;
            if(input=='W'){
                square[i][j] = 0;
            }else{
                square[i][j] = 1;
            }
        }
    }

    // 연산
    vector<vector<int>> copy_square;
    for(int a =1; a<=n-8+1; a++){
        for(int b=1; b<=m-8+1; b++){
            for(int i=0; i<2; i++){ // 첫번째 원소에 대해 두 번 진행
                copy_square = square;
                if(i==0){ //white(0)
                    copy_square[a-1][b] = 0;
                }else{
                    copy_square[a-1][b] = 1;
                }
                makeColor(copy_square, a, b);
            }
        }
    }

    cout<<result;

    return 0;
}