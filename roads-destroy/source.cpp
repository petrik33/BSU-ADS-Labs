#include <fstream>
#include <iostream>
#include <string>
#include <vector>

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

int findSet(disjointSet *DSU, int id)
{
    while (id != DSU[id].parent)
    {
        // Until we meet leader of disjoint set
        id = DSU[id].parent;
    }
    return id;
}

bool uniteSets(disjointSet *DSU, int ds1, int ds2)
{
    ds1 = findSet(DSU, ds1);
    ds2 = findSet(DSU, ds2);
    if (ds1 == ds2)
    {
        return false;
    }
    disjointSet *dsLeft = &DSU[ds1];
    disjointSet *dsRight = &DSU[ds2];
    if (dsLeft->size >= dsRight->size)
    {
        // join to Right (smaller)
        dsRight->parent = ds1;
        dsLeft->size += dsRight->size;
    }
    else
    {
        dsLeft->parent = ds2;
        dsRight->size += dsLeft->size;
    }
    return true;
}

int disjointSet::ID = 0;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n, m, q;

    in >> n;
    in >> m;
    in >> q;

    int **roads = new int *[m];

    for (int i = 0; i < m; i++)
    {
        int left, right;
        in >> left;
        in >> right;
        left--;
        right--;
        roads[i] = new int[2];
        roads[i][0] = left;
        roads[i][1] = right;
    }

    bool *roadsKept = new bool[m];

    for (int i = 0; i < m; i++)
    {
        roadsKept[i] = true;
    }

    int *roadsIdxs = new int[q];

    for (int i = 0; i < q; i++)
    {
        int idx;
        in >> idx;
        roadsIdxs[i] = idx;
        roadsKept[idx - 1] = false;
    }

    disjointSet *DSU = new disjointSet[n];
    int components = n;
    int undestroyed = m - q;
    int iRoad = 0;

    while (undestroyed > 0)
    {
        if (roadsKept[iRoad])
        {
            int *road = roads[iRoad];
            if (uniteSets(DSU, road[0], road[1]))
            {
                components--;
            }
            undestroyed--;
        }
        iRoad++;
    }

    int j = q - 1;

    while (components > 1 && j >= 0)
    {
        int roadIdx = roadsIdxs[j];
        int *road = roads[roadIdx - 1];
        if (uniteSets(DSU, road[0], road[1]))
        {
            components--;
        }
        j--;
    }

    for (int i = 0; i <= j; i++)
    {
        out << "1";
    }

    for (int i = j + 1; i < q; i++)
    {
        out << "0";
    }
}