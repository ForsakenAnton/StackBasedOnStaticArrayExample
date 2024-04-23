#include <iostream>
using namespace std;

template <typename T, int SIZE>
class Stack
{
private:
    T arr[SIZE]; // Статичний масив для зберігання даних
    int topIndex; // Індекс вершини стеку

public:
    Stack() : topIndex(-1) 
    { 
    }

    bool isEmpty() const
    {
        return topIndex == -1;
    }

    bool isFull() const
    {
        return topIndex == SIZE - 1;
    }

    void push(const T& value)
    {
        if (isFull())
        {
            cerr << "Stack is full. Cannot push." << endl;
            return;
        }

        arr[++topIndex] = value;
    }

    void pop()
    {
        if (isEmpty())
        {
            cerr << "Stack is empty. Cannot pop." << endl;
            return;
        }

        topIndex--;
    }

    const T& peek() const
    {
        if (isEmpty())
        {
            cerr << "Stack is empty." << endl;

            static T dummy;

            return dummy;
        }

        return arr[topIndex];
    }
};


int main()
{
    const int SIZE = 10;
    Stack<int, SIZE> myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    cout << "Top of the stack: " << myStack.peek() << endl;

    myStack.pop();
    cout << "After pop:" << endl;
    cout << "Top of the stack: " << myStack.peek() << endl;

    return 0;
}
