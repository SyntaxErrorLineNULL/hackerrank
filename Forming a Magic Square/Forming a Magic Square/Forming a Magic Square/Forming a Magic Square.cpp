#include <iostream>
#include <cmath>
#include <vector>
/*  We define a magic square to be an N x N matrix of distinct positive integers from 1 to n^2 where the sum of any row, column, 
    or diagonal of length is always equal to the same number: the magic constant.
    You will be given a 3 x 3 matrix 'S' of integers [1, 9] in the inclusive range . We can convert any digit 'b' 
    to any other digit in the range [1, 9] at cost of |a - b|. Given 'S', convert it into a magic square at minimal cost. Print this cost on a new line.
    Note: The resulting magic square must contain distinct integers in the inclusive range [1, 9]
*//*
    Example matrix S:
    |5 3 4|                                                      
    |1 5 8|
    |6 4 2|, We can convert it to the following magic square:

    |8 3 4|
    |1 5 9|
    |6 7 2|
    This took three replacements at a cost of |5-8|+|8-9|+|4-7| = 7.
    Function Description

    Complete the formingMagicSquare function in the editor below. It should return an integer that represents the minimal total cost of converting the input square to a magic square.

    formingMagicSquare has the following parameter(s):

*/
using namespace std;
int FormingMagicSquare(vector<vector<int>> s) {
    int Possibilities[8][3][3] = {
        {{8,1,6},{3,5,7},{4,9,2}},
        {{6,1,8},{7,5,3},{2,9,4}},
        {{4,9,2},{3,5,7},{8,1,6}},
        {{2,9,4},{7,5,3},{6,1,8}},
        {{8,3,4},{1,5,9},{6,7,2}},
        {{4,3,8},{9,5,1},{2,7,6}},
        {{6,7,2},{1,5,9},{8,3,4}},
        {{2,7,6},{9,5,1},{4,3,8}}
    };

    int Result[8];
    int Minimum;
    for (auto i = 0; i < 8; i++) {
        Result[i] = 0;
        for (auto j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (s[j][k] != Possibilities[i][j][k]) {
                    Result[i] += abs(s[j][k] - Possibilities[i][j][k]);
                }
            }
        }
    }
    Minimum = Result[0];
    for (auto i = 1; i < 8; i++) {
        if (Result[i] < Minimum) {
            Minimum = Result[i];
        }
    }
    return Minimum;

}

#ifndef Run Test
int main(int argc, char *argv) {

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = FormingMagicSquare(s);

    std::cout << result << "\n";


	system("pause");
	return 0;
}
#endif // !Run Test
