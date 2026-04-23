#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <bits/stdc++.h>
#include <queue>
#include <utility>

using namespace std;


void breadthFirstSearch(/*pair<int, int>start,*/ vector<vector<char>>& matrix) { //the ampersnand will use the maze already printed

    int rows=matrix.size();
    int cols=matrix[0].size();


    /*int rows= 12;
    int cols=22;

    pair <int, int> start{3, 2};*/




    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1}; //allows us to access neighboring cells from current node


    vector<vector<bool>> visitedNodes (rows, vector<bool>(cols,false)); //checks visited nodes
    queue<pair<int, int>> output; //this will create queue to current pair (coordinate of the maze

    if (start.first < 0 || start.first >= rows || start.second < 0 || start.second >= cols || matrix[start.first][start.second] != 'X') {
        cout << "Valid starting point" << endl;
        return;
    }


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

    pair<int, int> startingPoint = {2,0};
    breadthFirstSearch(startingPoint, mazeMatrix);
    //use bredth-first since we are starting at 1,1


}


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




