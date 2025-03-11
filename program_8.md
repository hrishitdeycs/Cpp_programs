#  Create a Matrix class. Write a menu-driven program to perform following Matrix operations (exceptions should be thrown by the functions if matrices passed to them are incompatible and handled by the main() function):
# a. Sum
# b. Product
# c. Transpose
```bash
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
class Matrix {
private:
    int rows, cols;
    vector<vector<int>> mat;
public:
    // Constructor to initialize the matrix with given dimensions and values
    Matrix(int r, int c) : rows(r), cols(c) {
        mat.resize(rows, vector<int>(cols));
    }
    // Function to input values into the matrix
    void inputMatrix() {
        cout << "Enter elements of the matrix (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> mat[i][j];
            }
        }
    }
    // Function to display the matrix
    void displayMatrix() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
    // Function to perform matrix addition
    Matrix add(const Matrix& m) {
        if (rows != m.rows || cols != m.cols) {
            throw invalid_argument("Matrices dimensions do not match for addition.");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.mat[i][j] = mat[i][j] + m.mat[i][j];
            }
        }
        return result;
    }
    // Function to perform matrix multiplication
    Matrix multiply(const Matrix& m) {
        if (cols != m.rows) {
            throw invalid_argument("Matrices dimensions are incompatible for multiplication.");
        }
        Matrix result(rows, m.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                result.mat[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.mat[i][j] += mat[i][k] * m.mat[k][j];
                }
            }
        }
        return result;
    }
    // Function to perform matrix transpose
    Matrix transpose() {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.mat[j][i] = mat[i][j];
            }
        }
        return result;
    }
};
int main() {
    int choice;
    Matrix* m1 = nullptr;
    Matrix* m2 = nullptr;
    while (true) {
        cout << "\nMatrix Operations Menu:\n";
        cout << "1. Add Matrices\n";
        cout << "2. Multiply Matrices\n";
        cout << "3. Transpose Matrix\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: { // Sum of matrices
                int r, c;
                cout << "Enter dimensions of matrix 1 (rows columns): ";
                cin >> r >> c;
                m1 = new Matrix(r, c);
                m1->inputMatrix();

                cout << "Enter dimensions of matrix 2 (rows columns): ";
                cin >> r >> c;
                m2 = new Matrix(r, c);
                m2->inputMatrix();
                try {
                    Matrix result = m1->add(*m2);
                    cout << "Result of addition:\n";
                    result.displayMatrix();
                } catch (const invalid_argument& e) {
                    cout << "Error: " << e.what() << endl;
                }
                delete m1;
                delete m2;
                break;
            }
            case 2: { // Product of matrices
                int r1, c1, r2, c2;
                cout << "Enter dimensions of matrix 1 (rows columns): ";
                cin >> r1 >> c1;
                m1 = new Matrix(r1, c1);
                m1->inputMatrix();
                cout << "Enter dimensions of matrix 2 (rows columns): ";
                cin >> r2 >> c2;
                m2 = new Matrix(r2, c2);
                m2->inputMatrix();
                try {
                    Matrix result = m1->multiply(*m2);
                    cout << "Result of multiplication:\n";
                    result.displayMatrix();
                } catch (const invalid_argument& e) {
                    cout << "Error: " << e.what() << endl;
                }
                delete m1;
                delete m2;
                break;
            }
            case 3: { // Transpose of matrix
                int r, c;
                cout << "Enter dimensions of matrix (rows columns): ";
                cin >> r >> c;
                m1 = new Matrix(r, c);
                m1->inputMatrix();
                Matrix result = m1->transpose();
                cout << "Transpose of the matrix:\n";
                result.displayMatrix();
                delete m1;
                break;
            }
            case 4: { // Exit
                cout << "Exiting program.\n";
                return 0;
            }
            default:
                cout << "Invalid choice, please try again.\n";
                break;
        }
    }
    return 0;
}

```
![Screenshot (97)](https://github.com/user-attachments/assets/265be17f-b445-4775-8ffe-b54982674398)
![Screenshot (98)](https://github.com/user-attachments/assets/69af45b4-5127-4d8f-9fa2-4eb6f4a962ac)
![Screenshot (99)](https://github.com/user-attachments/assets/a17a7d35-5905-4666-903e-867bbbfc98c7)
![Screenshot (100)](https://github.com/user-attachments/assets/8675f7b5-f42b-4710-9ba0-0b4629e12b3e)
![Screenshot (101)](https://github.com/user-attachments/assets/e11d6305-101f-470d-8734-b26dc656b1d1)
![Screenshot (102)](https://github.com/user-attachments/assets/23765dc2-01e0-4c4c-9239-c4803e276702)

