#ifndef QUEUE
#define QUEUE

template <class T>
struct Node
{
    T data;
    Node <T> *next;
}

class Queue
{
    private:
        Node<T> * top = 0;
    public:
        Queue()
        {
            top = 0;
        }
        void EnQueue(T value)
        {
            Node <T> * n = new NOde();
            n -> data = value;
            n-> next = 0;
            if (top == 0)
            {
                top = n;
            }
            else
            {
                Node<T> * temp = top;
                while (n -> next != 0)
                {
                    temp = temp -> next;
                }
                temp -> next = n;
            }
        }
        T DeQueue()
        {
            T t =top -> data;
            Node <T> * temp = top;
            top = top -> next;
            delete temp;
            return t;
        }
        bool IsEmpty ()
        {
            return top = 0;
        }
}
#endif
