#include <iostream>

using namespace std;

class Lipsum
{
private:
    int a;
    int *p;

public:
    Lipsum(int x)
    {
        a = x;
        p = new int[a];
        for (int i = 0; i < a; i++)
            p[i] = i;
    }

    Lipsum(Lipsum &copy)
    {
        a = copy.a;
        // p = copy.p; // <-- Shallow copying

        // Deep copying
        p = new int[a];
        for (int i = 0; i < a; i++)
            p[i] = copy.p[i];
    }

    int *get_array()
    {
        return p;
    }
};

int main()
{
    Lipsum lorem(10);
    Lipsum ipsum(lorem);

    for (int i = 0; i < 10; i++)
        cout << (lorem.get_array())[i] << " " << (ipsum.get_array())[i] << endl;

    // ! Again, always remember to free heap memory
    delete[] lorem.get_array();
    delete[] ipsum.get_array();

    return 0;
}