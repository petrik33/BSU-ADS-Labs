#include <fstream>

using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;
    in >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        in >> arr[i];
    }

    bool isHeap = true;

    for (int i = n - 1; i > 0; i--)
    {
        int thisElem = arr[i];
        int parentElem = arr[(i - 1) >> 1];
        if (thisElem < parentElem)
        {
            isHeap = false;
            break;
        }
    }

    if (isHeap)
    {
        out << "Yes\n";
    }
    else
    {
        out << "No\n";
    }
}