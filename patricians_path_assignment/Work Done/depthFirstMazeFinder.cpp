#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;


bool solveMaze(int r, int c, vector<vector<char>>& maze, vector<vector<bool>>& visited) {
    // 1. Check boundaries and walls
    if (r < 0 || r >= maze.size() || c < 0 || c >= maze[0].size() ||
        maze[r][c] == 'X' || visited[r][c]) {
        return false;
    }

    // 2. Mark as visited
    visited[r][c] = true;

    // 3. Check if we reached the exit (e.g., marked as 'E')
    if (maze[r][c] == 'E') return true;

    // 4. Recursively visit neighbors (Down, Up, Right, Left)
    if (solveMaze(r + 1, c, maze, visited)) return true;
    if (solveMaze(r - 1, c, maze, visited)) return true;
    if (solveMaze(r, c + 1, maze, visited)) return true;
    if (solveMaze(r, c - 1, maze, visited)) return true;

    return false; // No path found from this cell
}


void putInFile(string mazeInput, vector<vector<char>> &matrix) {
    string line;

    ifstream myFile(mazeInput); //select the file

    if (mazeInput!="maze.txt" && mazeInput!="maze2.txt") {
        cout<<"This is not one of the actual mazes"<<endl;
    }

    while (getline(myFile, line)) {
        vector<char> row; // vector for current row
        for (char c : line) {
            row.push_back(c); // Add each character to the row
        }
        matrix.push_back(row); //add the row vector into matrix=
    }

    myFile.close();

    for (int i = 0; i < matrix.size(); i++){
        for (int j = 0; j < matrix[i].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    } //This nested for loop outputs each character of the row

}

int main() {

    vector<vector<char>> mazeMatrix; //create out multidimensional vector

    putInFile("maze.txt", mazeMatrix);//you input the maze and mazeM

    int rows = mazeMatrix.size();
    int cols = mazeMatrix[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));


    solveMaze(12, 22, mazeMatrix, visited);
}

