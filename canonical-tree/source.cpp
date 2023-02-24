#include <fstream>
using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;

    in >> n;
    int m = n - 1;

    int *tree = new int[n];

    for (int i = 0; i < n; i++)
    {
        tree[i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int par, son;
        in >> par;
        in >> son;
        tree[son - 1] = par;
    }

    for (int i = 0; i < n; i++)
    {
        out << tree[i] << " ";
    }

    out << endl;

    return 0;
}