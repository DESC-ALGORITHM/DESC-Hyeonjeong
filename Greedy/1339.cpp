#include <iostream>
#include <vector>

using namespace std;
/*
 * 알파벳 몇개인지 알기 -> 이 개수만큼 (0~9) 중 내림차순으로 정해짐
 * 자릿수 큰 순서로 단어 내림차순 정렬하기
 * index 0인 행부터 차례대로 숫자 주기
 */
int cnt=0;

void isExistedAlpha(string input, vector<bool> &alpha){
    for(int i=0; i<input.size(); i++){
        int index = int(input[i]) - 65;

        if(!alpha[index]){
            alpha[index] = true;
            cnt++;
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<string> words(n);
    vector<bool> alpha(27, false);

    for(int i=0; i<n; i++){
        string input;
        cin>> input;
        words.push_back(input);
        isExistedAlpha(input, alpha); // 알파벳 이미 나온거인지 여부에 따라 cnt 증가
    }
    alpha.assign(27, false);

    return 0;
}