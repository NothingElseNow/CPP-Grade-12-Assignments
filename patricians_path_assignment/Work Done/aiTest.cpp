#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <bits/stdc++.h>
#include <queue>
#include <utility>

using namespace std;


void breadthFirstSearch(pair<int, int> start, vector<vector<char>>& matrix) { //the ampersnand will use the maze already printed and the pair allows one to store the starting parameter as the list of variables
// 1. Correct queue and visited types

    int rows=matrix.size();
    int cols=matrix[0].size();

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1}; //allows us to access neighboring cells from current node


    vector<vector<bool>> visitedNodes(rows, vector<bool>(cols, false));
    queue<pair<int, int>> output;

    visitedNodes[start.first][start.second] = true;
    output.push(start);

    while (!output.empty()) {
        pair<int, int> currentNode = output.front();
        output.pop();

        cout << currentNode.first << " " << currentNode.second << endl;

        for (int i = 0; i < 4; i++) {
            int rT = currentNode.first + dr[i];
            int cT = currentNode.second + dc[i];

            // Boundary checks and wall checks
            if (rT >= 0 && rT < rows && cT >= 0 && cT < cols &&
                matrix[rT][cT] != 'X' && !visitedNodes[rT][cT]) {

                visitedNodes[rT][cT] = true;
                output.push({rT, cT});
            }
        }
    }
}


        // Go through all neighbors
        /*for (int neighbor : matrix[node]) {
            if (!visitedNodes[neighbor]) {
                visitedNodes[neighbor] = true;
                output.push(neighbor);
            }
        }
    }
}*/



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
    //int nodeAmount=37;//we will have to insert later once path is discovered
    //vector<vector<char>>path(nodeAmount);//establishes the amount of nodes in cpp;

    vector<vector<char>> mazeMatrix; //create a empth 2-d vector for outputting map
    putInFile("maze.txt", mazeMatrix);//you input the maze and mazeMatrix into cpp

    /*vector<vector<char>>mazeHolder;
    ifstream maze("maze.txt");
    string line;

    while (getline(maze, line)) {
        vector<char> row; // vector for current row
        for (char c : line) {
            row.push_back(c); // Add each character to the row
        }
        mazeHolder.push_back(row); //add the row vector into matrix=
    }/*



    /*for (int i = 0; i < mazeHolder.size(); i++) {
        for (int j = 0; j < mazeHolder[i].size(); j++) {
            cout << mazeHolder[i][j] << " ";
        }
        cout<<endl;
    } //this code checks if the maze is actually printed; nothing is actuall in the mazeMatrix*/

    pair<int, int> startingPoint {3,2};

    /*pair<int, int> endPoint;
    startingPoint.first=12;
    startingPoint.second=18;*/






    breadthFirstSearch(startingPoint, mazeMatrix);

    //use bredth-first since we are starting at 1,1


}







