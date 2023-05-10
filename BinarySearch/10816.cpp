#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin>>n;
    vector<int> card(n,0);

    for(int i=0; i<n; i++){
        cin>>card[i];
    }

    sort(card.begin(), card.end());

    cin>>m;

    int num;

    for(int i=0; i<m; i++){
        cin>>num;
        cout << upper_bound(card.begin(), card.end(), num) - lower_bound(card.begin(), card.end(), num) <<' ';
    }

    return 0;

}