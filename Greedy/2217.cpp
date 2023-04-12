#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxLoop(vector<int> num, int n){
    int max_num=0, cur;

    for(int i=0; i<n; i++){
        cur = num[i]*(n-i);
        max_num = max(max_num, cur);
    }

    return max_num;
}

int main(){
    int n;
    cin>>n;
    vector<int> num(n,0);

    for(int i=0; i<n; i++){
        cin>>num[i];
    }
    sort(num.begin(), num.end());

    cout<< maxLoop(num, n);

    return 0;
}