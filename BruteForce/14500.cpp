#include<iostream>
#include <vector>

using namespace std;

int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
int n, m;
vector<vector<int>> paper;
vector<vector<bool>> visited;
int result =0;

void makeTetromino(int y, int x, int depth, int sum){
    if(depth==4){
        result = max(result,sum);
        return;
    }

    for(int i=0; i<4; i++){
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if(new_x>=0 && new_x<m && new_y>=0 && new_y <n && !visited[new_y][new_x]){
            visited[new_y][new_x] = true;
            if(depth==2){
                makeTetromino(y, x, depth+1, sum+paper[new_y][new_x]);
            }
            makeTetromino(new_y, new_x, depth+1, sum+paper[new_y][new_x]);
            visited[new_y][new_x] = false;

        }
    }

}


int main(){
    cin>>n>>m;

    paper.assign(n,vector<int>(m,0));
    visited.assign(n, vector<bool>(m,false));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>paper[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visited[i][j] = true;
            makeTetromino(i,j,1, paper[i][j]);
            visited[i][j] = false;
        }
    }

    cout<< result<<'\n';
    
    return 0;
}