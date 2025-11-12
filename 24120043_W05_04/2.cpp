#include <iostream>
#include <stdexcept>

using namespace std;

template <class T>
class SLList
{
private:
    struct Node
    {
        T _info;
        Node *_pNext;
    };

    Node *_pHead, *_pTail;
    int _n;
    static Node *CreateNode(const T &value)
    {
        Node *node = new Node{value, nullptr};
        return node;
    }

public:
    class Iterator;

    SLList();
    ~SLList();

    void AddHead(const T &);
    void AddTail(const T &);
    void RemoveHead();
    void RemoveTail();
    void Clear();

    Iterator begin()
    {
        return Iterator(_pHead);
    }

    Iterator end()
    {
        return Iterator(nullptr);
    }

    template <class U>
    friend ostream &operator<<(ostream &os, const SLList<U> &ll)
    {
        typename SLList<U>::Node *node = ll._pHead;
        while (node != nullptr)
        {
            os << node->_info << ", ";
            node = node->_pNext;
        }

        return os;
    }
};

template <class T>
SLList<T>::SLList()
{
    _pHead = _pTail = nullptr;
    _n = 0;
}

template <class T>
SLList<T>::~SLList()
{
    Node *cur = _pHead;
    while (cur != nullptr)
    {
        Node *temp = cur;
        cur = cur->_pNext;
        delete temp;
    }

    _pHead = _pTail = nullptr;
}

template <class T>
void SLList<T>::Clear()
{
    Node *cur = _pHead;
    while (cur != nullptr)
    {
        Node *temp = cur;
        cur = cur->_pNext;
        delete temp;
    }

    _pHead = _pTail = nullptr;
}

template <class T>
void SLList<T>::AddTail(const T &value)
{
    Node *node = CreateNode(value);
    if (node == nullptr)
    {
        return;
    }
    if (_pHead == nullptr)
    {
        _pHead = _pTail = node;
        _n++;
        return;
    }
    _pTail->_pNext = node;
    _pTail = node;
    _n++;
}

template <class T>
void SLList<T>::AddHead(const T &value)
{
    Node *node = CreateNode(value);
    if (node == nullptr)
    {
        return;
    }

    if (_pHead == nullptr)
    {
        _pHead = _pTail = node;
        _n++;
        return;
    }

    node->_pNext = _pHead;
    _pHead = node;
    _n++;
}

template <class T>
void SLList<T>::RemoveHead()
{
    if (_pHead == nullptr)
    {
        return;
    }

    Node *cur = _pHead;
    _pHead = _pHead->next;
    if (_pHead == nullptr)
    {
        _pTail = nullptr;
    }
    delete cur;
    _n--;
}

template <class T>
void SLList<T>::RemoveTail()
{
    if (_pHead == nullptr)
    {
        return;
    }

    Node *cur = _pHead;
    if (cur == _pTail)
    {
        delete cur;
        _pHead = _pTail = nullptr;
        _n--;
    }
    else
    {
        while (cur->_pNext != _pTail)
        {
            cur = cur->_pNext;
        }

        cur->_pNext = nullptr;
        delete _pTail;
        _pTail = cur;
        _n--;
    }
}

template <class T>
class SLList<T>::Iterator
{
public:
    using iterator_category = forward_iterator_tag;
    using difference_type = ptrdiff_t;
    using value_type = T;
    using pointer = T *;
    using reference = T &;

private:
    Node *current_node;
    Iterator(Node *node) : current_node(node) {}
    friend class SLList<T>;

public:
    Iterator() : current_node(nullptr) {}
    reference operator*() const
    {
        if (!current_node)
        {
            throw out_of_range("Dereferencing end() or null iterator");
        }

        return current_node->_info;
    }

    pointer operator->() const
    {
        if (!current_node)
        {
            throw out_of_range("Accessing member via end() or null iterator");
        }

        return &(current_node->_info);
    }

    Iterator &operator++()
    {
        if (current_node)
        {
            current_node = current_node->_pNext;
        }
        else
        {
            throw out_of_range("Incrementing end() or null iterator");
        }

        return *this;
    }

    Iterator operator++(int)
    {
        if (!current_node)
        {
            throw out_of_range("Incrementing end() or null iterator");
        }

        Iterator temp = *this;
        current_node = current_node->_pNext;
        return temp;
    }

    bool operator==(const Iterator &other) const
    {
        return current_node == other.current_node;
    }

    bool operator!=(const Iterator &other) const
    {
        return !(*this == other);
    }
};

#include <algorithm>

void fnAction(int val)
{
    cout << val << ", ";
}

void fnAction2(int &val)
{
    val *= 2;
}

bool fnPredict(int val)
{
    const int threshold = 3;
    return val > threshold;
}

int main()
{
    SLList<int> l;
    l.AddTail(1);
    l.AddTail(1);
    l.AddTail(0);
    l.AddTail(4);
    l.AddTail(2);
    l.AddTail(5);

    for (SLList<int>::Iterator it = l.begin(); it != l.end(); ++it)
    {
        cout << *it << ", ";
    }
    cout << endl;

    for_each(l.begin(), l.end(), fnAction2);
    for_each(l.begin(), l.end(), fnAction);
    cout << endl;

    replace_if(l.begin(), l.end(), fnPredict, 100);
    cout << l << endl;

    fill(l.begin(), l.end(), 123);
    cout << l << endl;
    l.Clear();

    system("pause");
    return 0;
}