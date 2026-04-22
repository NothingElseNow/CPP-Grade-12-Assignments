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

void breadthFirstSearch(pair<int, int>start, vector<vector<char>>& matrix) { //the ampersnand will use the maze already printed

    int rows=matrix.size();
    int cols=matrix[0].size();

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1}; //allows us to access neighboring cells from current node


    vector<vector<bool>> visitedNodes (rows, vector<bool>(cols,false)); //checks visited nodes
    queue<pair<int, int>> output; //this will create queue to current pair (coordinate of the maze


    visitedNodes[start.first][start.second] = true;
    output.push(start);//push starting value into cpp

    while (!output.empty()) {
        pair<int, int>currentNode = output.front();//accesses variable at start of the quque (which is now the starting pair)
        output.pop(); //revmoves the top queue
        cout << currentNode.first <<","<< currentNode.second<<endl; // process current node

        for (int i=0; i<4; i++){
            int rowTransversal=currentNode.first + dr[i]; //add one to current row
            int columnTransversal=currentNode.second+ dc[i]; //add one to current column

            if (rowTransversal<0 || columnTransversal<0) {
                continue;
            }
            else if(rowTransversal>=rows || columnTransversal>=cols) {//check if the movement surpases the amount of rows in the maze matrix
                continue;
            }
            else if (matrix[rowTransversal][columnTransversal]!='X' && !visitedNodes[rowTransversal][columnTransversal]) {//checks if there is a wall
                visitedNodes[rowTransversal][columnTransversal]=true;
                output.push({rowTransversal, columnTransversal});
            }

        }//Have to establish start area

        // Go through all neighbors
        /*for (int neighbor : matrix[currentNode]) { //need to change the currentNode to similar type as the matrix
            if (!visitedNodes[neighbor]) {
                visitzzedNodes[neighbor] = true;
                output.push(neighbor);
            }
        }*/
    }
}


void putInFile(string mazeInput, vector<vector<char>>matrix) {


    ifstream file(mazeInput); //select the file

    int ROWS, COLS;

    file >> ROWS, COLS;

    file.ignore();

    matrix.assign(ROWS, vector<char>(COLS));


    for (int i = 0; i < ROWS; ++i) {
        string line;
        getline(file, line);

        for (int j=0; j < COLS; ++j) {
            matrix[i][j]=line[j];
        }
    }
    for (int i=0; i<ROWS; ++i) {
        for (int j=0; j<COLS; ++j) {
            cout<<matrix[i][j];
        }
    cout<< '\n';
    }
}



int main() {
    //int nodeAmount=37;//we will have to insert later once path is discovered
    //vector<vector<char>>path(nodeAmount);//establishes the amount of nodes in cpp;

    vector<vector<char>> mazeMatrix; //create a empth 2-d vector for outputting map
    putInFile("maze.txt", mazeMatrix);//you input the maze and mazeMatrix into function

    /*vector<vector<char>>mazeHolder;
    ifstream maze("maze.txt");
    string line;

    while (getline(maze, line)) {
        vector<char> row; // vector for current row
        for (char c : line) {
            row.push_back(c); // Add each character to the row
        }
        mazeHolder.push_back(row); //add the row vector into matrix=
    }*/



    /*for (int i = 0; i < mazeHolder.size(); i++) {
        for (int j = 0; j < mazeHolder[i].size(); j++) {
            cout << mazeHolder[i][j] << " ";
        }
        cout<<endl;
    } //this code checks if the maze is actually printed; nothing is actuall in the mazeMatrix*/

    pair<int, int> startingPoint = {3,2};
    breadthFirstSearch(startingPoint, mazeMatrix);
    //use bredth-first since we are starting at 1,1


}




