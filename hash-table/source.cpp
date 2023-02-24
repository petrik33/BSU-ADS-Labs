#include <fstream>
using namespace std;

bool hashInsert(long long x, int i, long long *hash, int hashSize, int c)
{
    int index = (x % hashSize + c * i) % hashSize;
    long long cell = hash[index];

    if (cell == -1 || cell == x)
    {
        // Cell empty -- all good
        hash[index] = x;
        return true;
    }

    return false;
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int m, c, n;
    in >> m;
    in >> c;
    in >> n;

    long long *hash = new long long[m];

    for (int i = 0; i < m; i++)
    {
        hash[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        long long x;
        in >> x;
        int attempt = 0;
        while (!hashInsert(x, attempt, hash, m, c))
        {
            attempt++;
        }
    }

    for (int i = 0; i < m; i++)
    {
        out << hash[i] << " ";
    }

    out << "\n";

    return 0;
}