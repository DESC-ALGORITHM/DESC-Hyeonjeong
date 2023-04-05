#include <string>
#include <vector>

using namespace std;
vector<bool> col_check;
vector<bool> right_col_check;
vector<bool> left_col_check;
int num, ans=0;

void backtracking(int row){
    if(row==num){
        ans++;
        return;
    }
    for(int i=0; i<num; i++){
        if(!col_check[i] && !right_col_check[row-i+num] && !left_col_check[i+row]){
            col_check[i] = true;
            right_col_check[row-i+num] = true;
            left_col_check[i+row] = true;
            backtracking(row+1);
            col_check[i] = false;
            right_col_check[row-i+num] = false;
            left_col_check[i+row] = false;

        }
    }
}

int solution(int n) {
    int answer = 0;

    num = n;
    col_check.assign(n,false);
    right_col_check.assign(2*n,false); // 오른쪽은 빼기
    left_col_check.assign(2*n,false); // 왼쪽은 더하기

    backtracking(0);
    answer = ans;

    return answer;
}