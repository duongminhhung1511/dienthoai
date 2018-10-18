#ifndef STACK
#define STACK

template <class T>
struct Node 
{
    T data;
    Node <T>* next;
}

class Stack
{
    private:
        Node <T> * top;
    public:
        Stack()
        {
            top = 0;
        }
        void Push (T value)
        {
            Node <T> * n = new Node();
            n -> data = value;
            n -> next = top;
            top = n;
        }
        T Pop()
        {
            T t = top -> data;
            Node <T> * temp = top;
            top = top -> next;
            delete temp;
            return t;
        }
        bool IsEmpty()const
        {
            return top = 0;
        }
}
#endif
