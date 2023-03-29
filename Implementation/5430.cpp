#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool isError = false;

vector<string> splitString(string arr, int n){
    int ends = arr.find(']');
    string name = arr.substr(1, ends-1);
    int previous= 0, current = name.find(',');
    name.push_back(',');

    vector<string> str_arr;

    while(current != string::npos){
        str_arr.push_back(name.substr(previous, current-previous));
        previous = current + 1;
        current = name.find(',', previous);
    }

    return str_arr;
}

void printResult(vector<string> arr_v){
    if(isError == true){
        cout<<"error"<<'\n';
        isError= false;
        return;
    }
    cout<<'[';
    for(int i=0; i<arr_v.size(); i++){
        if(i== arr_v.size()-1){
            cout<< arr_v[i];
            break;
        }
        cout<< arr_v[i]<<',';
    }
    cout<<']'<<'\n';
}

int main(){
    int t, n;
    cin >> t;

    while(t--){
        string str, arr;
        cin>>str>> n>>arr;
        vector<int> result;

        vector<string> arr_v;
        if(arr.size()>2){
            arr_v = splitString(arr, n);
        }


        for(int i=0; i<str.length(); i++){
            if(str[i] == 'R'){
                reverse(arr_v.begin(), arr_v.end());
            }
            if(str[i] == 'D'){
                if(arr_v.size() <=0){
                    isError = true;
                    break;
                }
                arr_v.erase(arr_v.begin());
            }
        }
        printResult(arr_v);
    }
    return 0;
}