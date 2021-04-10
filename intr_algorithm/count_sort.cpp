#include <iostream>
#include <vector>

using namespace std;

void count_sort(vector<int> a, vector<int> &b, int k)
{
    ++k;
    vector<int> c(k);
    b.resize(a.size());

    for (int i = 0; i < a.size(); i++)
    {
        ++c[a[i]];
    }

    for (int i = 1; i < k; i++)
    {
        c[i] = c[i] + c[i-1];
    }

    for (int i = a.size()-1; i >= 0; --i)
    {
        b[c[a[i]]-1] = a[i];
        --c[a[i]];
    }
}

int main(int argc, char **argv)
{
    vector<int> a{2, 5, 3, 0, 2, 3, 0, 3};

    vector<int> b;
    count_sort(a, b, 5);

    for (auto value : b)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    
    return 0;
}