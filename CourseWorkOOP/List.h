#ifndef LIST_H
#define LIST_H
#include <exception>
#include <iostream>


template<typename T>
class ListNode
{
public:
    ListNode* next;
    ListNode* prev;

    T* Get()
    {
        return &data;
    }

    ListNode(T data = T(), ListNode* next = nullptr, ListNode* prev = nullptr)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }

private:
    T data;
};

template<typename T>
class Iterator
{
    ListNode<T>* current;

public:
    Iterator() { current = nullptr; }
    Iterator(ListNode<T>* first) { current = first; }

    Iterator operator ++(int)
    {
        Iterator temp(current);
        ++(*this);
        return temp;
    }
    bool operator ++ ()
    {
        if (current == nullptr) return false;
        current = current->next;
        return true;
    }
    bool operator -- ()
    {
        if (current->prev == nullptr) return false;
        current = current->prev;
        return true;
    }

    T& operator +(int n)
    {
        ListNode<T>* temp = current;
        for (int i = 0; i < n; i++)
        {
            temp = temp->next;
        }

        return *temp->Get();
    }

    bool operator == (const Iterator& it)
    {
        if (current == nullptr && it.current == nullptr)
            return true;
        if (current == nullptr || it.current == nullptr)
            return false;
        if (current->Get() == it.current->Get() && current->next == it.current->next && current->prev == it.current->prev)
            return true;
        return false;
    }

    T& operator *() { return *(current->Get()); }

    bool operator!=(const Iterator& it)
    {
        if (current == nullptr && it.current == nullptr)
            return false;
        if ((current == nullptr && it.current != nullptr) || (current != nullptr && it.current == nullptr))
            return true;
        if (current->Get() == it.current->Get() && current->next == it.current->next && current->prev == it.current->prev)
            return false;
        return true;
    }
};

template<typename T>
class List
{
public:
    List();

    friend class Iterator<T>;

    void PushBack(T data);
    void PushFront(T data);
    void InsertAt(int index, T data);
    T& Find(T data);
    int GetSize() { return _size; }
    void PopFront();
    void PopBack();
    void Clear();
    void Print();

    T& operator[] (int index);

    Iterator<T> begin() { return Iterator<T>(_head); }
    Iterator<T> end() { return _tail != nullptr ? Iterator<T>(_tail->next) : Iterator<T>(_tail); }

private:
    int _size;
    ListNode<T> *_head;
    ListNode<T> *_tail;
};



template<typename T>
List<T>::List()
{
    this->_size = 0;
    this->_head = nullptr;
    this->_tail = nullptr;
}

template<typename T>
void List<T>::PushBack(T data)
{
    if (this->_head == nullptr)
    {
        this->_head = new ListNode<T>(data, nullptr, nullptr);
        this->_tail = this->_head;
    }
    else
    {
        ListNode<T> *cur = new ListNode<T>(data, nullptr, this->_tail);
        this->_tail->next = cur;
        this->_tail = cur;
    }

    this->_size++;
}

template<typename T>
void List<T>::PushFront(T data)
{
    if (_head == nullptr)
    {
        this->_head = new ListNode<T>(data);
        this->_tail = this->_head;
    }
    else
    {
        ListNode<T>* node = new ListNode<T>(data);
        this->_head->prev = node;
        node->next = this->_head;
        this->_head = node;
    }

    this->_size++;
}

template<typename T>
void List<T>::InsertAt(int index, T data)
{
    if (index == 0)
    {
        this->PushFront(data);
    }
    else if (index == this->_size - 1)
    {
        this->PushBack(data);
    }
    else if (index < 0 || index >= this->_size)
    {
        throw new std::exception("Out of array border");
    }
    else
    {
        ListNode<T> *prev = this->_head;

        for (int i = 0; i < index - 1; i++)
        {
            prev = prev->next;
        }

        ListNode<T> *insertingNode = new ListNode<T>(data, prev->next, prev);
        prev->next = insertingNode;

        this->_size++;
    }
}

template<typename T>
T & List<T>::Find(T data)
{
    ListNode<T> *cur = this->_head;

    while (cur != nullptr)
    {
        if (cur->Get() == data)
        {
            return cur->data;
        }

        cur = cur->next;
    }

    throw new std::exception("Searching element is not find.");
    return NULL;
}

template<typename T>
void List<T>::PopFront()
{
    if (this->_head == nullptr) return;

    ListNode<T> *temp = this->_head;

    if (this->_head != this->_tail)
    {
        this->_head = this->_head->next;
        this->_head = nullptr;
    }
    else
    {
        this->_head = this->_tail = nullptr;
    }

    delete temp;

    this->_size--;
}

template<typename T>
void List<T>::PopBack()
{
    if (this->_head == nullptr) return;

    ListNode<T> *temp = this->_tail;

    if (this->_head != this->_tail)
    {
        this->_tail = this->_tail->prev;
        this->_tail = nullptr;
    }
    else
    {
        this->_head = this->_tail = nullptr;
    }

    this->_size--;
}

template<typename T>
void List<T>::Clear()
{
    while (this->_size)
    {
        this->PopFront();
    }
}

template<typename T>
void List<T>::Print()
{
    if (this->_size != 0)
    {
        ListNode<T> *cur = this->_head;

        while (cur != nullptr)
        {
            std::cout << *(cur->Get()) << std::endl;
            cur = cur->next;
        }
    }
}

template<typename T>
T & List<T>::operator [](int index)
{
    if (index < this->_size || index >= this->_size)
    {
        throw new std::exception("Out of array border");
    }

    ListNode<T> *cur = this->_head;
    int counter = 0;

    while (cur != nullptr)
    {
        if (counter == index)
        {
            return *(cur->Get());
        }

        cur = cur->next;
        counter++;
    }

    T t;
    return t;
}

#endif // LIST_H
