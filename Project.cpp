#include <iostream>
#include <cmath>
using namespace std;
// recursive function for Determinant value
int Det(int Mat[100][100], int N)
{
    int Sub_Det = 0;
    int Sub_Mat[100][100];
    if (N == 1)
        return (Mat[0][0]);
    else if (N == 2)
        return ((Mat[0][0] * Mat[1][1]) - (Mat[1][0] * Mat[0][1]));
    else
    {
        for (int i = 0; i < N; i++)
        {
            int Sub_j = 0;
            for (int j = 1; j < N; j++)
            {
                int Sub_k = 0;
                for (int k = 0; k < N; k++)
                {
                    if (k == i)
                        continue;
                    Sub_Mat[Sub_j][Sub_k] = Mat[j][k];
                    Sub_k++;
                }
                Sub_j++;
            }
            Sub_Det = Sub_Det + (pow(-1, i) * Mat[0][i] * Det(Sub_Mat, N - 1));
        }
    }
    return Sub_Det;
}
// main function
int main()
{
    // declaring variables for the matrices
    int operation_no, rows_A, columns_A, rows_B, columns_B, Mat_A[100][100], Mat_B[100][100], Mat_Sum[100][100], Mat_Difference[100][100], Mat_Multi[100][100], Det_A, Det_B;
    double Mat_Cof[100][100], Mat_Adj[100][100], Mat_Inv[100][100], Mat_Div[100][100];
    // asking user for dimensions
    cout << "Please enter dimensions of Matrix A:\n";
    cin >> rows_A >> columns_A;
    cout << "Please enter dimensions of Matrix B:\n";
    cin >> rows_B >> columns_B;
    // asking user for input
    cout << "Please enter values of Matrix A:\n";
    for (int i = 0; i < rows_A; i++)
    {
        for (int j = 0; j < columns_A; j++)
        {
            cin >> Mat_A[i][j];
        }
    }
    cout << "Please enter values of Matrix B:\n";
    for (int i = 0; i < rows_B; i++)
    {
        for (int j = 0; j < columns_B; j++)
        {
            cin >> Mat_B[i][j];
        }
    }
    // user choosing operation
    do
    {
        cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit): \n";
        cin >> operation_no;
        // quiting
        if (operation_no == 7)
        {
            cout << "Thank you!\n";
            break;
        }
        // (A + B)
        else if (operation_no == 1)
        {
            if (rows_A != rows_B || columns_A != columns_B)
            {
                cout << "The operation you chose is invalid for the given matrices. \n";
            }
            else
            {
                for (int i = 0; i < rows_A; i++)
                {
                    for (int j = 0; j < columns_A; j++)
                    {
                        Mat_Sum[i][j] = Mat_A[i][j] + Mat_B[i][j];
                    }
                }
                for (int i = 0; i < rows_A; i++)
                {
                    for (int j = 0; j < columns_A; j++)
                    {
                        cout << Mat_Sum[i][j] << "  ";
                        if (j == columns_A - 1)
                            cout << "\n";
                    }
                }
            }
        }
        //(A-B)
        else if (operation_no == 2)
        {
            if (rows_A != rows_B || columns_A != columns_B)
            {
                cout << "The operation you chose is invalid for the given matrices. \n";
            }
            else
            {
                for (int i = 0; i < rows_A; i++)
                {
                    for (int j = 0; j < columns_A; j++)
                    {
                        Mat_Difference[i][j] = Mat_A[i][j] - Mat_B[i][j];
                    }
                }
                for (int i = 0; i < rows_A; i++)
                {
                    for (int j = 0; j < columns_A; j++)
                    {
                        cout << Mat_Difference[i][j] << "  ";
                        if (j == columns_A - 1)
                            cout << "\n";
                    }
                }
            }
        }
        else if (operation_no == 3)
        //(A * B)
        {
            if (columns_A == rows_B)
            {
                for (int i = 0; i < rows_A; i++)
                    for (int j = 0; j < columns_B; j++)

                        for (int k = 0; k < columns_A; k++)
                        {
                            Mat_Multi[i][j] += Mat_A[i][k] * Mat_B[k][j];
                        }
                for (int i = 0; i < rows_A; i++)
                {
                    for (int j = 0; j < columns_B; j++)
                    {
                        cout << Mat_Multi[i][j] << "  ";
                        if (j == columns_B - 1)
                            cout << "\n";
                    }
                }
                for (int i = 0; i < rows_A; i++)
                    for (int j = 0; j < columns_B; j++)
                    {
                        Mat_Multi[i][j] = 0;
                    }
            }
            else
            {
                cout << "The operation you chose is invalid for the given matrices.\n";
            }
        }
        // A/B(3x3)
        else if (operation_no == 4)
        {
            if (rows_B != columns_B)
            {
                cout << "The operation you chose is invalid for the given matrices.\n";
            }
            else if (Det(Mat_B, rows_B) == 0)
            {
                cout << "The operation you chose is invalid for the given matrices.\n";
            }
            else if (columns_A != rows_B)
            {
                cout << "The operation you chose is invalid for the given matrices.\n";
            }
            else
            {
                Mat_Cof[0][0] = (Mat_B[1][1] * Mat_B[2][2] - Mat_B[1][2] * Mat_B[2][1]);
                Mat_Cof[0][1] = (-1) * (Mat_B[1][0] * Mat_B[2][2] - Mat_B[1][2] * Mat_B[2][0]);
                Mat_Cof[0][2] = (Mat_B[1][0] * Mat_B[2][1] - Mat_B[1][1] * Mat_B[2][0]);
                Mat_Cof[1][0] = (-1) * (Mat_B[0][1] * Mat_B[2][2] - Mat_B[0][2] * Mat_B[2][1]);
                Mat_Cof[1][1] = (Mat_B[0][0] * Mat_B[2][2] - Mat_B[0][2] * Mat_B[2][0]);
                Mat_Cof[1][2] = (-1) * (Mat_B[0][0] * Mat_B[2][1] - Mat_B[0][1] * Mat_B[2][0]);
                Mat_Cof[2][0] = (Mat_B[0][1] * Mat_B[1][2] - Mat_B[0][2] * Mat_B[1][1]);
                Mat_Cof[2][1] = (-1) * (Mat_B[0][0] * Mat_B[1][2] - Mat_B[0][2] * Mat_B[1][0]);
                Mat_Cof[2][2] = (Mat_B[0][0] * Mat_B[1][1] - Mat_B[0][1] * Mat_B[1][0]);
                for (int i = 0; i < rows_B; i++)
                {
                    for (int j = 0; j < columns_B; j++)
                    {
                        Mat_Adj[i][j] = Mat_Cof[j][i];
                    }
                }
                for (int i = 0; i < rows_B; i++)
                {
                    for (int j = 0; j < columns_B; j++)
                    {
                        Mat_Inv[i][j] = Mat_Adj[i][j] / (Det(Mat_B, rows_B));
                    }
                }
                for (int i = 0; i < rows_A; i++)
                    for (int j = 0; j < columns_B; j++)

                        for (int k = 0; k < columns_A; k++)
                        {
                            Mat_Div[i][j] += Mat_A[i][k] * Mat_Inv[k][j];
                        }
                for (int i = 0; i < rows_A; i++)
                {
                    for (int j = 0; j < columns_B; j++)
                    {
                        if (round(Mat_Div[i][j]) == -0)
                        {
                            cout << 0 << "  ";
                            if (j == columns_B - 1)
                                cout << "\n";
                        }
                        else
                        {
                            cout << round(Mat_Div[i][j]) << "  ";
                            if (j == columns_B - 1)
                                cout << "\n";
                        }
                    }
                }
                for (int i = 0; i < rows_A; i++)
                    for (int j = 0; j < columns_B; j++)
                    {
                        Mat_Div[i][j] = 0;
                    }
            }
        }

        //(|A|)
        else if (operation_no == 5)
        {
            if (rows_A != columns_A)
            {
                cout << "The operation you chose is invalid for the given matrices.\n";
            }
            else
            {
                cout << Det(Mat_A, rows_A) << "\n";
            }
        }
        //(|B|)
        else if (operation_no == 6)
        {
            if (rows_B != columns_B)
            {
                cout << "The operation you chose is invalid for the given matrices.\n";
            }
            else
            {
                cout << Det(Mat_B, rows_B) << "\n";
            }
        }
    } while (operation_no != 7);

    return 0;
}
