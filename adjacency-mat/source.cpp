#include <fstream>
using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n, m;

    in >> n;
    in >> m;

    int **mat = new int *[n];

    for (int i = 0; i < n; i++)
    {
        mat[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int l, r;
        in >> l;
        in >> r;
        mat[l - 1][r - 1] = 1;
        mat[r - 1][l - 1] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            out << mat[i][j] << " ";
        }
        out << endl;
    }

    return 0;
}