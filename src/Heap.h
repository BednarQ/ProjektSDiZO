#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
using namespace std;
class Heap
{
    private:
        vector <int> heap;
        int left(int parent);
        int right(int parent);
        int parent(int child);
        void heapifyup(int index);
        void heapifydown(int index);
    public:
        Heap(){}
        void loadFromFile();
        void Insert(int element);
        void DeleteMin();
        int ExtractMin();
        void DisplayHeap();
        int Size();
        void SearchElement(int element);
};
