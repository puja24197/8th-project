#include <iostream>
using namespace std;
#define N 5
bool isSafe(int board[N][N],int row,int col){
    for(int i= 0;i<row;i++)   if(board[i][col])  return false;
    for(int i=row,j= col;i>= 0&& j>= 0;i--, j--) if(board[i][j])  return false;
    for(int i= row,j=col;i>=0 && j< N;i--,j++) if(board[i][j])  return false;
    return true;
}
bool solveNQUtil(int board[N][N],int row){
    if(row>= N) return true;
    for(int col= 0;col< N; col++){
        if(isSafe(board,row,col)){
            board[row][col]= 1;
            if(solveNQUtil(board,row +1))  return true;
            board[row][col]=0;
        }
    }
    return false;
}
void solveNQ(){
    int board[N][N]={0};
    if(solveNQUtil(board,0)){
        for(int i=0;i<N;i++){
                for(int j=0;j<N;j++) cout<<(board[i][j]?"Q ":" . "); cout<< endl;}
    } else cout<<"No solution"<< endl;
}
int main() {
cout<<"N-Queen Solution:"<<endl; solveNQ();
return 0;
}
