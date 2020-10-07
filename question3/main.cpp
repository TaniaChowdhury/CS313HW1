//question number : 3
//assigned to Tania Chowdhury
//GROUP number : 01
//team members name : Brown,Jacob A
//Chowdhury,Tamzid
//Chowdhury,Tania
//Cortes,Victoria Danyel
//Deciutiis II,James Hugo
//

#include <iostream>
#include <vector>
using namespace std;

//row wise matrix bubble sort
void matrixBubbleSort(vector<vector<int>>& matrix) {
    // loop for rows of matrix
    int rows = matrix.size();
    for (int i = 0; i < rows; i++) {
        // loop for column of matrix
        int cols = matrix[i].size();
        for (int j = 0; j < cols; j++) {
            // loop for comparison and swapping
            for (int k = 0; k < cols - j - 1; k++) {
                // checking if compatible for swapping
                if (matrix[i][k] > matrix[i][k + 1]) {
                    // swapping of elements
                    swap(matrix[i][k], matrix[i][k + 1]);
                }
            }
        }
    }
}

//row wise matrix insertion sort
void matrixInertionSort(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    // loop for rows of matrix
    for (int i = 0; i < rows; i++) {
        int cols = matrix[i].size();
        // loop for column of matrix
        for (int j = 1; j < cols; j++) {
            //set key as the one to insert
            int key = matrix[i][j];
            int k = j - 1;
            //Move elements of matrix[i][0..j-1], that are greater than key, to one position ahead of their current position
            while (k >= 0 && matrix[i][k] > key) {
                matrix[i][k + 1] = matrix[i][k];//moving each element one step ahead
                k = k - 1;
            }
            matrix[i][k + 1] = key;//inserting the key
        }
    }
}
//row wise matrix insertion sort
void matrixSelectionSort(vector<vector<int>>& matrix)
{
    int rows = matrix.size();
    // loop for rows of matrix
    for (int i = 0; i < rows; i++) {
        int cols = matrix[i].size();
        // loop for column of matrix
        for (int j = 0; j < cols - 1; j++) {
            // Find the minimum element in unsorted array
            int min_idx = j;
            for (int k = j + 1; k < cols; k++)
                if (matrix[i][k] < matrix[i][min_idx])
                    min_idx = k;
            // Swap the found minimum element with the first element
            swap(matrix[i][min_idx], matrix[i][j]);
        }
    }
}
int main() {

    vector <vector<int>> matrix;
    int rows, cols;
    cout << "Enter number of rows of matrix: ";
    cin >> rows;
    cout << "Enter number of columns of the matrix: ";
    cin >> cols;
    int val;
    for (int i = 0; i < rows; i++)
    {
        matrix.push_back({});
        for (int j = 0; j < cols; j++) {
            cout << "matrix[" << i << "][" << j << "]: ";
            cin >> val;
            matrix[i].push_back(val);
        }
    }
    char choice;
    cout << "Enter 1 for Bubble Sort\nEnter 2 for Insertion Sort\nEnter 3 for Selection Sort\nEnter your choice: ";
    cin >> choice;
    if (choice == '1') {
        cout << "Matrix Bubble Sort\n";
        matrixBubbleSort(matrix);
    }
    else if (choice == '2') {
        cout << "Matrix Insertion Sort\n";
        matrixInertionSort(matrix);
    }
    else {
        cout << "Matrix Selection Sort\n";
        matrixSelectionSort(matrix);
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << matrix[i][j] << '\t';
        cout << endl;
    }
    return 0;
}
