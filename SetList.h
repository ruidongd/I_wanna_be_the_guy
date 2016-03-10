//
// Created by Ruidongd on 2016/3/6.
//

#ifndef HW9_SETLIST_H
#define HW9_SETLIST_H
#include <iostream>
using namespace std;
template <typename T>
class SetList
{
public:
    struct ListNode
    {
        T info;
        ListNode *next;
        ListNode(T newInfo, ListNode *newNext)
                : info(newInfo), next(newNext) { }
    };
    struct iterator
    {
        typedef forward_iterator_tag iterator_category;
        typedef ListNode* pointer;
        typedef ListNode & reference;
        typedef iterator self_type;
        typedef ListNode value_type;
        typedef ptrdiff_t difference_type;
    private:
        pointer head;
    public:
        iterator(pointer ptr):head(ptr){}
        self_type operator ++()
        {
            head = head->next;
            return *this;
        }
        self_type operator ++(int postfix)
        {
            self_type cpy = *this;
            head = head->next;
            return cpy;
        }
        reference operator *()
        {
            return *head;
        }
        pointer  operator ->()
        {
            return head;
        }
        bool operator == (const self_type & rhs) const
        {
            return head == rhs.head;
        }
        bool operator != (const self_type & rhs) const
        {
            return head != rhs.head;
        }

    };
    struct const_iterator
    {
        typedef forward_iterator_tag iterator_category;
        typedef ListNode* pointer;
        typedef ListNode & reference;
        typedef const_iterator self_type;
        typedef ListNode value_type;
        typedef ptrdiff_t difference_type;
    private:
        pointer head;
    public:
        const_iterator(pointer ptr):head(ptr){}
        self_type operator ++()
        {
            head = head->next;
            return *this;
        }
        self_type operator ++(int postfix)
        {
            self_type cpy = *this;
            head = head->next;
            return cpy;
        }
        const reference operator *()
        {
            return *head;
        }
        const pointer  operator ->()
        {
            return head;
        }
        bool operator == (const self_type & rhs) const
        {
            return head == rhs.head;
        }
        bool operator != (const self_type & rhs) const
        {
            return head != rhs.head;
        }
    };
private:
    ListNode *head;
public:
    SetList()
    : head(nullptr)
    {
    }
    ListNode& operator [] ( int index)
    {
        int i = 0;
        for(ListNode* p = head; p != nullptr;p = p->next)
        {
            if(i = index)
                return *p;
            ++i;
        }
    }
    const ListNode& operator [] ( int index) const
    {
        int i = 0;
        for(ListNode* p = head; p != nullptr;p = p->next)
        {
            if(i = index)
                return *p;
            ++i;
        }
    }

    void insert(T s)
    {
        if(! this->find(s))
            head = new ListNode(s,head);
    }
    iterator begin(){return iterator(head);}
    iterator end()
    {
        ListNode* p = head;
        for(; p!= nullptr; p = p->next);
        return iterator(p);

    }
    const_iterator begin()const {return const_iterator(head);}
    const_iterator end() const
    {
        ListNode* p = head;
        for(; p!= nullptr; p = p->next);
        return const_iterator(p);
    }
    bool find(T s)
    {
        for(ListNode* p = head; p != nullptr; p = p->next)
        {
            if (p->info == s)
                return true;
        }
        return false;
    }
    ~SetList()
    {
        ListNode* temp;
        temp = head;
        head = head->next;
        delete temp;
    }
};


#endif //HW9_SETLIST_H
