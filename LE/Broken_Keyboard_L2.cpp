#include <iostream>

using namespace std;
using ll = long long;

template <typename E>
class Link
{
public:
    E element;
    Link<E> *next;
    Link(E data, Link *nextval = NULL)
    {
        element = data;
        next = nextval;
    }
    Link(Link *nextval = NULL)
    {
        next = nextval;
    }
};

template <typename E>
class Stack
{
private:
    Link<E> *top;
    int size = 0;

public:
    Stack()
    {
        top = NULL;
    }

    ~Stack()
    {
        clear();
    }

    void clear()
    {
        while (top != NULL)
        {
            Link<E> *temp = top;
            top = top->next;
            delete temp;
        }
        size = 0;
    }

    void push(const E item)
    {
        top = new Link<E>(item, top);
        size++;
    }

    E pop()
    {
        if (top == NULL)
            return NULL;
        E item = top->element;
        Link<E> *temp = top->next;
        delete top;
        top = temp;
        size--;
        return item;
    }

    E topValue()
    {
        if (top != NULL)
            return top->element;
    }

    int length()
    {
        return size;
    }
};
template <typename E>
class Queue
{
private:
    Link<E> *front; // Pointer to front queue node
    Link<E> *rear;  // Pointer to rear queue node
    int size = 0;   // Number of elements in queue
public:
    Queue() // Constructor
    {
        front = rear = new Link<E>();
        size = 0;
    }

    void clear()
    {
        while (front->next != NULL)
        {
            rear = front;
            delete rear;
        }
        rear = front;
        size = 0;
    }
    void enqueue(E &it)
    {
        rear->next = new Link<E>(it, NULL);
        rear = rear->next;
        size++;
    }
    E dequeue()
    {
        E it = front->next->element;
        Link<E> *temp = front->next;
        front->next = temp->next;
        if (rear == temp)
            rear = front;
        delete temp;
        size--;
        return it;
    }
    const E &frontValue() const
    {
        return front->next->element;
    }
    int length() const { return size; }
};
void solve(string s)
{

    // 3[2[1[]45
    // aux:
    // pilha:
    // fila: 3 2 1
    auto prior = new Stack<string>();
    auto after = new Queue<string>();
    string aux = "";
    int opened = false;
    for (auto ch : s)
    {
        if (ch == '[')
        {
            if (aux.size() > 0)
            {
                opened ? prior->push(aux) : after->enqueue(aux);
                aux = "";
            }
            opened = true;
        }
        else if (ch == ']')
        {
            if (aux.size() > 0)
            {
                opened ? prior->push(aux) : after->enqueue(aux);
                aux = "";
            }
            opened = false;
        }
        else
        {
            aux.push_back(ch);
        }
    }

    if (aux.size() > 0)
        opened ? prior->push(aux) : after->enqueue(aux);

    while (prior->length() > 0)
        cout << prior->pop();
    while (after->length() > 0)
        cout << after->dequeue();

    cout << '\n';
}

// condicao ? true : false;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string line;
    while (cin >> line)
        solve(line);

    return 0;
}