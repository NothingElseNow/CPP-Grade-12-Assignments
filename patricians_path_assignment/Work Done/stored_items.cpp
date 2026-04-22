#include "stored_items.h"
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

void mapSettings::functionInArray(string fileName) {
    string line;
    vector<vector<char>> mazeMatrix; //create out multidimensional vecto
    while (getline(fileName, line)) {
        vector<char> row; // Temporary vector for the current row
        for (char c : line) {
            row.push_back(c); // Add each character to the row
        }
        mazeMatrix.push_back(row); //add the temporary
    }

    myFile.close();

      for (int i = 0; i < mazeMatrix.size(); i++)
    {
        for (int j = 0; j < mazeMatrix[i].size(); j++)
        {
            cout << mazeMatrix[i][j] << " ";
        }
        cout << endl;
    } //This nested for loop outputs each character of the row

    return 0;

}
