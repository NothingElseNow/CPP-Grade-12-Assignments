#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <bits/stdc++.h>
#include <queue>
#include <utility>

using namespace std;


void breadthFirstSearch(pair<int, int>start, vector<vector<char>>& matrix) { //the ampersnand will use the maze already printed

    int rows = 13;//define amount of rows
    int cols = 23;//define amount of columns

   // int rows=matrix.size();
   // int cols=matrix[0].size();


    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1}; //allows us to access neighboring cells from current node


    vector<vector<bool>> visitedNodes (rows, vector<bool>(cols,false)); //checks visited nodes
    queue<pair<int, int>> output; //this will create queue to current pair (coordinate of the maze

    if (start.first < 0 || start.first >= rows || start.second < 0 || start.second >= cols || matrix[start.first][start.second] == 'X') { //checks if starting coordinate can navigate the maze (starts on barrier, more than columns/rows or below zero)
        cout << "Not Valid Starting Point" << endl;
        return;
    }

    visitedNodes[start.first][start.second] = true;
    output.push(start);//push starting value into cpp

    //we cannot have this on the inside because it will run infinitely

    while (!output.empty()) {//checks if the available stored coordinates
        pair<int, int>currentNode = output.front();//accesses variable at start of the quque (which is now the starting pair)
        output.pop(); //revmoves the top queue
        cout << currentNode.first <<","<< currentNode.second<<endl; // outputs the current coordinate

        for (int i=0; i<4; i++){
            int rowTransversal=currentNode.first + dr[i]; //add one to current row
            int columnTransversal=currentNode.second+ dc[i]; //add one to current column

            if (rowTransversal<0 || columnTransversal<0) {
                continue;
            }
            else if(rowTransversal>=rows || columnTransversal>=cols) {//check if the movement surpases the amount of rows in the maze matrix
                continue;
            }
            else if (matrix[rowTransversal][columnTransversal]!='X' && !visitedNodes[rowTransversal][columnTransversal]) {//sees if there is not arrow or if point is not visited
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



void putInFile(string mazeInput, vector<vector<char>>&matrix) {
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
        matrix.push_back(row); //add the row vector into matrix
    }

    myFile.close();

    for (int i = 0; i < matrix.size(); i++){
        for (int j = 0; j < matrix[i].size(); j++){
            cout << matrix[i][j] << " "; //prints out each coordinate of the matrix
        }
        cout << endl;
    } //This nested for loop outputs each character of the row

}
int main() {
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
}






