#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isEven(int value) { return !(value&1); }

struct RingBufferFIFO
{
    int value;
    int maxSize;
    int size;
    RingBufferFIFO* head, * next, * last;

    RingBufferFIFO(int s = 10)
    {
        maxSize = s;
        size = 0;
        head = NULL;
        next = NULL;
        last = NULL;
    }
    
    void Add(int x)
    {
        if(maxSize<=size)
        {
            Del();
        }
        RingBufferFIFO* temp = new RingBufferFIFO;
        size++;
        temp->value = x;
        if (head != NULL)
        {
            last->next = temp;
            last = temp;
        }
        else {
            head = last = temp;
        }
        
    }

    void Out()
    {
        Print();
        Del();
    }

    void OutAll()
    {
        while(size > 0)
        {
            Out();
        }
    }

private:
    void Del()
    {
        RingBufferFIFO* temp;
        temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    void Print()
    {
        cout << head->value << endl;
    }
};

struct RingBufferLIFO
{
    int value;
    int maxSize;
    int size;
    RingBufferLIFO* head, * next, * before, * last;

    RingBufferLIFO(int s = 10)
    {
        maxSize = s;
        size = 0;
        head = NULL;
        next = NULL;
        before = NULL;
        last = NULL;
    }

    void Add(int x)
    {
        if (maxSize <= size)
        {
            DelHead();
        }
        RingBufferLIFO* temp = new RingBufferLIFO;
        size++;
        temp->value = x;
        if (head != NULL)
        {
            temp->before = last;

            last->next = temp;
            last = temp;
        }
        else {
            head = last = temp;
        }

    }

    void Out()
    {
        Print();
        Del();
    }

    void OutAll()
    {
        while (size > 0)
        {
            Out();
        }
    }

private:
    void Del()
    {
        RingBufferLIFO* temp;
        temp = last;
        last = last->before;
        delete temp;
        size--;
    }

    void DelHead()
    {
        RingBufferLIFO* temp;
        temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    void Print()
    {
        cout << last->value << endl;
    }
};

void quickSort(vector<int>& vec, int beg, int end)
{
    if(!vec.empty())
    {
        int less = 0;

        if (beg < end)
        {
            int value = vec[end];
            less = beg;

            for (int i = beg; i < end; i++)
            {
                if (vec[i] <= value)
                {
                    swap(vec[i], vec[less]);
                    less++;
                }
            }
            swap(vec[less], vec[end]);

            quickSort(vec, beg, less - 1);
            quickSort(vec, less + 1, end);
        }
        
    }
}


int main()
{
    std::cout << isEven(54568) << std::endl;
    std::cout << isEven(1) << std::endl;
    std::cout << isEven(2) << std::endl;

    std::cout << std::endl;

    RingBufferFIFO buffer(4);
    //RingBufferLIFO buffer(4);

    buffer.Add(3);
    buffer.Add(4);
    buffer.Add(5);
    buffer.Add(6);
    buffer.Out();
    buffer.Add(7);
    buffer.Add(8);
    buffer.Out();
    buffer.Add(9);
    buffer.OutAll();

    std::cout << std::endl;

    vector <int> vec{ 1,3,6,8,2,9,7,5,4 };
    //quickSort(vec, 0, vec.size() - 1);
    sort(vec.begin(), vec.end());
    for (int i = 0; vec.size() > i; i++)
    {
        cout << vec[i];
    }

}   
