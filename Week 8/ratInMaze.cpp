#include<iostream>
#include<vector>

using namespace std;

//a fn.. that will handle all the below mentioned possibilities
//Possibilities
    //1. path closed, 2. out of bound, 3. check if position is already visited 
bool isSafe(int srcx, int srcy, int newx, int newy, int maze[][4], int row, int col, vector<vector<bool>>& visited){
    if((newx>=0 && newx<row) && (newy>=0 && newy<col) && (maze[newx][newy] == 1) && (visited[newx][newy] == false)){
        return true;
    }
    else{
        return false;
    } 
}

void printAllPath(int maze[][4], int row, int col, int srcx, int srcy, string& output, vector<vector<bool>>& visited){
    //base case
    if(srcx == row-1 && srcy == col-1){
        cout<<output<<endl;
        return;
    }

    //UP --> (x-1, y)
    int newx = srcx-1;
    int newy = srcy;
    if(isSafe(srcx, srcy, newx, newy, maze, row, col, visited)){
        //mark visited
        visited[newx][newy] = true;
        output.push_back('U');
        printAllPath(maze, row, col, newx, newy, output, visited);
        //backtracking
        output.pop_back();
        visited[newx][newy] = false;

    }

    //DOWN --> (x+1, y)
    newx = srcx+1;
    newy = srcy;
    if(isSafe(srcx, srcy, newx, newy, maze, row, col, visited)){
        //mark visited
        visited[newx][newy] = true;
        output.push_back('D');
        printAllPath(maze, row, col, newx, newy, output, visited);
        //backtracking
        output.pop_back();
        visited[newx][newy] = false;
    }

    //RIGHT --> (x, y+1)
    newx = srcx;
    newy = srcy+1;
    if(isSafe(srcx, srcy, newx, newy, maze, row, col, visited)){
        //mark visited
        visited[newx][newy] = true;
        //call recurssion
        output.push_back('R');
        printAllPath(maze, row, col, newx, newy, output, visited);
        //backtracking
        output.pop_back();
        visited[newx][newy] = false;
    }

    //LEFT --> (x, y-1)
    newx = srcx;
    newy = srcy-1;
    if(isSafe(srcx, srcy, newx, newy, maze, row, col, visited)){
        //mark visited
        visited[newx][newy] = true;
        output.push_back('L');
        printAllPath(maze, row, col, newx, newy, output, visited);
        //backtracking
        output.pop_back();
        visited[newx][newy] = false;
    }
}

int main(){
    int maze[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 1, 0},
        {1, 1, 1, 1}
    };
    int row = 4, col = 4; 
    int srcx = 0, srcy = 0;
    string output = ""; //empty string for answer

    //visited 2D array
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    if(maze[0][0] == 0){
        cout<<"No Path Exists"<<endl;
    }
    else{
        visited[srcx][srcy] = true;
        printAllPath(maze, row, col, srcx, srcy, output, visited);
    }
}