#include <fstream>
#include <list>
using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n, m;

    in >> n;
    in >> m;

    list<int> *adjLists = new list<int>[n];

    for (int i = 0; i < n; i++)
    {
        list<int> *adj = new list<int>;
        adjLists[i] = *adj;
    }

    for (int i = 0; i < m; i++)
    {
        int l, r;
        in >> l;
        in >> r;
        adjLists[l - 1].push_back(r);
        adjLists[r - 1].push_back(l);
    }

    for (int i = 0; i < n; i++)
    {
        list<int> adj = adjLists[i];
        int deg = adj.size();
        out << deg << " ";
        for (int j = 0; j < deg; j++)
        {
            out << adj.front() << " ";
            adj.pop_front();
        }
        out << endl;
    }

    return 0;
}