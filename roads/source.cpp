#include <fstream>
#include <iostream>

using namespace std;

struct disjointSet
{
    int parent;
    int size;

    disjointSet(int val)
    {
        parent = val;
        size = 1;
    }

    disjointSet()
    {
        parent = ID++;
        size = 1;
    }

    static int ID;
};

int disjointSet::ID = 0;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n, m;

    in >> n;
    in >> m;

    disjointSet *DSU = new disjointSet[n];

    int components = n;

    for (int i = 0; i < m; i++)
    {
        int idLeft, idRight;
        in >> idLeft;
        in >> idRight;

        idLeft -= 1;
        idRight -= 1;

        while (idLeft != DSU[idLeft].parent)
        {
            // Until we meet leader of disjoint set
            idLeft = DSU[idLeft].parent;
        }

        while (idRight != DSU[idRight].parent)
        {
            // Until we meet leader of disjoint set
            idRight = DSU[idRight].parent;
        }

        if (idLeft != idRight)
        {
            disjointSet *dsLeft = &DSU[idLeft];
            disjointSet *dsRight = &DSU[idRight];
            if (dsLeft->size >= dsRight->size)
            {
                // join to Right (smaller)
                dsRight->parent = idLeft;
                dsLeft->size += dsRight->size;
            }
            else
            {
                dsLeft->parent = idRight;
                dsRight->size += dsLeft->size;
            }
            components--;
        }

        out << components << " ";
    }
}

#include <iostream>
#include <fstream>
using namespace std;

int findLeader(int *parent, int v)
{
    if (v == parent[v - 1])
    {
        return v;
    }
    else
    {
        return findLeader(parent, parent[v - 1]);
    }
}

int main(int argc, const char *argv[])
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n = 0;
    int request = 0;

    fin >> n;
    fin >> request;

    int *parent = new int[n];
    int *sizes = new int[n];

    for (int i = 0; i < n; i++)
    {
        parent[i] = i + 1;
        sizes[i] = 1;
    }

    int v;
    int u;

    int k = n;
    for (int i = 0; i < request; i++)
    {
        fin >> v;
        fin >> u;

        int vLeader = findLeader(parent, v);
        int uLeader = findLeader(parent, u);

        if (vLeader != uLeader)
        {
            parent[uLeader - 1] = vLeader;
            sizes[vLeader - 1] += sizes[uLeader - 1];
            sizes[uLeader - 1] = 0;
            k--;
        }

        fout << k << endl;
    }

    return 0;
}