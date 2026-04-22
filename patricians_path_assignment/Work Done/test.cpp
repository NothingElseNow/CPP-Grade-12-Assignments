#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

struct startingPoint {
    int r, c;
};

void breadthFirstSearch(startingPoint start, vector<vector<char>>& matrix) {
    if (!matrix.empty()) return;

    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<bool>> visitedNodes(rows, vector<bool>(cols, false));
    queue<startingPoint> q;

    q.push(start);
    visitedNodes[start.r][start.c] = true;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        startingPoint curr = q.front();
        q.pop();
        cout << "(" << curr.r << "," << curr.c << ") ";

        if (matrix[curr.r][curr.c] == '$') {
            cout<<"You reached the end"<<endl;
        }

        for (int i = 0; i < 4; i++) {
            int nr = curr.r + dr[i];
            int nc = curr.c + dc[i];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                matrix[nr][nc] != 'X' && !visitedNodes[nr][nc]) {
                visitedNodes[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
}


void putInFile(string mazeInput, vector<vector<char>>matrix) {
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
    int nodeAmount=37;//we will have to insert later once path is discovered
    vector<vector<char>>path(nodeAmount);//establishes the amount of nodes in cpp;


    /*path[0] = {3, 2};
    path[1] = {3, 4};
    path[2] = {3, 5};
    path[3] = {3, 6;
    path[4] = {3, 7};
    path[5] = {3, 8};
    path[6] = {3, 9};
    path[7] = {3, 10};
    path[8] = {3, 11};
    path[9] = {3, 12};
    path[10] = {3, 13};
    path[11] = {3, 14};
    path[12] = {4, 14};
    path[13] = {5, 14};
    path[14] = {6, 14};
    path[15] = {7, 14};
    path[16] = {8, 14};
    path[17] = {8, 13};
    path[18] = {8, 12};
    path[19] = {8, 11};
    path[21] = {8, 10};
    path[22] = {8, 9};
    path[23] = {8, 8};
    path[24] = {9, 8};
    path[25] = {10, 8};
    path[26] = {11, 8};
    path[27] = {11, 9};
    path[28] = {11, 10};
    path[29] = {11, 11};
    path[30] = {11, 12};
    path[31] = {11, 13};
    path[32] = {11, 14};
    path[33] = {12, 15};
    path[34] = {12, 16};
    path[35] = {12, 17};
    path[36] = {12, 18};*/


    vector<vector<char>> mazeMatrix; //create out multidimensional vector

    putInFile("maze.txt", mazeMatrix);//you input the maze and mazeMatrix into cpp


    startingPoint start {0,0};
    breadthFirstSearch(start, mazeMatrix);

    //use bredth-first since we are starting at 1,1


}




