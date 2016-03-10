//
// Created by Ruidongd on 2016/3/6.
//

#ifndef HW9_MAPARRAY_H
#define HW9_MAPARRAY_H
#include <map>
#include <iostream>
using namespace std;
template <typename first_name, typename second_name>
class MapArray
{
public:
    typedef pair<first_name,second_name> my_pair;
private:
    my_pair* buf;
    int sz;
    int currecnt_index = 0;

public:
    struct iterator
    {
        typedef random_access_iterator_tag iterator_category;
        typedef iterator self_type;
        typedef my_pair value_type;
        typedef my_pair* pointer;
        typedef my_pair& reference;
        typedef ptrdiff_t difference_type;
    private:
        pointer buf;
    public:
        iterator(pointer ptr)
                :buf(ptr)
        {}
        self_type operator ++()
        {
            buf++;
            return *this;
        }
        self_type operator++(int postfix)
        {
            self_type cpy = *this;
            buf++;
            return cpy;
        }
        self_type operator --()
        {
            buf--;
            return *this;
        }
        self_type operator --(int postfix)
        {
            self_type cpy = *this;
            buf--;
            return cpy;
        }
        reference operator*()
        {
            return *buf;
        }
        pointer  operator->()
        {
            return buf;
        }
        bool operator < (const self_type & rhs) const
        {
            return buf < rhs.buf;
        }
        bool operator > (const self_type & rhs) const{
            return buf > rhs.buf;
        }
        bool operator >= (const self_type & rhs) const{
            return (buf > rhs.buf) || (buf == rhs.buf);
        }
        bool operator <= (const self_type & rhs) const{
            return (buf < rhs.buf) || (buf == rhs.buf);
        }
        bool operator == (const self_type & rhs) const
        {
            return buf == rhs.buf;
        }
        bool operator != (const self_type & rhs) const
        {
            return buf != rhs.buf;
        }
        self_type operator += (const self_type & rhs)
        {
            buf += rhs.buf;
            return *this;
        }
        self_type operator -= (const self_type & rhs)
        {
            buf -= rhs.buf;
            return *this;
        }
        self_type operator - (const self_type & rhs)
        {
            self_type p = *this;
            p -= rhs;
            return p;
        }
        self_type operator + (const self_type & rhs) 
        {
            self_type p = *this;
            p += rhs;
            return p;
        }
   };
    struct const_iterator
    {
        typedef const_iterator self_type;
        typedef forward_iterator_tag iterator_category;
        typedef my_pair value_type;
        typedef my_pair* pointer;
        typedef my_pair& reference;
        typedef ptrdiff_t difference_type;
    private:
        pointer buf;
    public:
        const_iterator(pointer ptr)
                :buf(ptr)
        {}
        self_type operator++()
        {
            ++buf;
            return *this;
        }
        self_type operator++(int postfix)
        {
            self_type cpy = *this;
            ++buf;
            return cpy;
        }
        const reference operator*()
        {
            return *buf;
        }
        const pointer operator->()
        {
            return buf;
        }
        bool operator < (const self_type & rhs) const
        {
            return buf < rhs.buf;
        }
        bool operator > (const self_type & rhs) const{
            return buf > rhs.buf;
        }
        bool operator >= (const self_type & rhs) const{
            return (buf > rhs.buf) || (buf == rhs.buf);
        }
        bool operator <= (const self_type & rhs) const{
            return (buf < rhs.buf) || (buf == rhs.buf);
        }
        bool operator == (const self_type& rhs) const
        {
            return buf == rhs.buf;
        }
        bool operator != (const self_type& rhs) const
        {
            return buf != rhs.buf;
        }
        self_type operator += (const self_type & rhs)
        {
            buf += rhs.buf;
            return *this;
        }
        self_type operator -= (const self_type & rhs)
        {
            buf -= rhs.buf;
            return *this;
        }
        self_type operator - (const self_type & rhs)
        {
            self_type p = *this;
            p -= rhs;
            return p;
        }
        self_type operator + (const self_type & rhs) 
        {
            self_type p = *this;
            p += rhs;
            return p;
        }

    };
    MapArray(int size)
            :buf(new my_pair[size]) , sz(size)
    {
    }
    int size()
    {
        return sz;
    }
    my_pair make_pair(first_name first, second_name second) const
    {
        return pair<first_name,second_name>(first, second);
    }
    second_name& operator [] (const first_name & s)
    {

        int index = this->find(s);
        if((index == -1))
        {
            buf[currecnt_index] = make_pair(s,1);
            ++currecnt_index;
        }
        index = this->find(s);
        return buf[index].second;
    }
    iterator begin()
    {
        return iterator(buf);
    }
    iterator end()
    {
        return iterator(buf+sz);
    }
    const_iterator begin() const
    {
        return const_iterator(buf);
    }
    const_iterator end() const
    {
        return const_iterator(buf);
    }
    const int find(const first_name &s) const
    {
        for (int i = 0; i < sz;++i)
        {
            if (buf[i].first == s)
                return i;
        }
        return -1;
    }
    ~MapArray()
    {
        delete[] buf;
    }
};


#endif //HW9_MAPARRAY_H
