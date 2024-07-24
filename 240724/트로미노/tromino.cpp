#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int grid[222][222];
int max_sum = 0;

int check_straight(int i, int j, int flag) {//flag가 1이면 세로 0이면 가로
    int temp_sum =0;
    if (flag==1) {
        temp_sum += grid[i][j];
        temp_sum += grid[i][j+1];
        temp_sum += grid[i][j+2];
    }
    else {
        temp_sum += grid[i][j];
        temp_sum += grid[i+1][j];
        temp_sum += grid[i+2][j];
    }
    return temp_sum;
}

int check_block(int i, int j, int dir){
    //dir이 1이면 남서, 2면 동남, 3이면 북동, 4면 북서
    int temp_sum = 0;
    if (dir==1) {
        temp_sum += grid[i][j];
        temp_sum += grid[i-1][j];
        temp_sum += grid[i][j+1];
    }
    else if (dir==2) {
        temp_sum += grid[i][j];
        temp_sum += grid[i-1][j];
        temp_sum += grid[i][j-1];
    }
    else if (dir==3) {
        temp_sum += grid[i][j];
        temp_sum += grid[i+1][j];
        temp_sum += grid[i][j-1];
    }
    else {
        temp_sum += grid[i][j];
        temp_sum += grid[i+1][j];
        temp_sum += grid[i][j+1];
    }
    return temp_sum;
}

int main() {
    cin>>n>>m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin>>grid[i][j];
        }
    }

    //직선
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (j<=m-3) {
                max_sum = max(max_sum, check_straight(i,j,1));
            }
            if (i<=n-3) {
                max_sum = max(max_sum, check_straight(i,j,0));
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            //dir이 1이면 남서, 2면 동남, 3이면 북동, 4면 북서
            if (i>=1 && j<=m-2) {
                max_sum = max(max_sum, check_block(i,j,1));
            }
            if (i>=1 && j>=1) {
                max_sum = max(max_sum, check_block(i,j,2));
            }
            if (i<=m-2 && j>=1) {
                max_sum = max(max_sum, check_block(i,j,3));
            }
            if (i<=m-2 && j<=m-2) {
                max_sum = max(max_sum, check_block(i,j,4));
            }
        }
    }
    cout<<max_sum;
    return 0;
}