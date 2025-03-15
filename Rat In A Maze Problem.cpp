// Rat in a Maze problem
#include<iostream>
#include<vector>
using namespace std;
void maze(vector<vector<int>> &mat, int row, int col, string path,vector<string> &ans,vector<vector<bool>> &visited)
{                       // T.C= O(4^(n^2)) since 4 choices in each cell, S.C=O(n^2) since visited nxn vector
    int n=mat.size();
    if(row<0||col<0||row>=n||col>=n||mat[row][col]==0||visited[row][col]==true)
    {
        return;
    }
    if(row==n-1 && col==n-1)
    {
        ans.push_back(path);
        return;
    }
    visited[row][col]=true;
    
    maze(mat,row+1,col,path+'D',ans,visited);//down
    maze(mat,row-1,col,path+'U',ans,visited);//up
    maze(mat,row,col+1,path+'R',ans,visited);//right
    maze(mat,row,col-1,path+'L',ans,visited);//left
    
    visited[row][col]=false;
}
void mazeOptimized(vector<vector<int>> &mat, int row, int col, string path,vector<string> &ans)
{                     // T.C= O(4^(n^2)) since 4 choices in each cell, S.C=O(1) since no visited nxn vector
    int n=mat.size();
    if(row<0||col<0||row>=n||col>=n||mat[row][col]==0||mat[row][col]==-1)
    {
        return;
    }
    if(row==n-1 && col==n-1)
    {
        ans.push_back(path);
        return;
    }
    mat[row][col]=-1; //marked visited, instead of nxn vector, changed in matrix only to optimize space

    mazeOptimized(mat,row+1,col,path+'D',ans);//down
    mazeOptimized(mat,row-1,col,path+'U',ans);//up
    mazeOptimized(mat,row,col+1,path+'R',ans);//right
    mazeOptimized(mat,row,col-1,path+'L',ans);//left
    
    mat[row][col]=1; //marked unvisited
}
int main()
{
    vector<vector<int>> mat= {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    int n=mat.size();
    vector<string> ans; 
    vector<string> ans1; 
    string path="";
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    maze(mat,0,0,path,ans,visited);
    for(string path:ans)
    {
        cout<<path<<endl;
    }
    mazeOptimized(mat,0,0,path,ans1);
    for(string path:ans1)
    {
        cout<<path<<endl;
    }
    return 0;
} 