#ifndef DS_VECTOR_H
#define DS_VECTOR_H
#include <stdexcept>
#include <initializer_list>

template <typename T>
class Vector{
private:
    size_t _capacity;
    size_t _size;
    T* _arr;
public:
    using value_type = T;
    using size_type = std::size_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;


public:    
    class const_iterator {
        friend class Vector<value_type>;
    private:
        pointer ptr;
    protected:
        explicit const_iterator(pointer ptr);
    public:
        const_iterator();
        const_iterator(const const_iterator& rhv);
        const_iterator(const_iterator&& rhv);

        ~const_iterator();

        const const_iterator& operator=(const const_iterator& rhv);
        const const_iterator& operator=(const_iterator&& rhv);

        const_reference operator*() const;
        const_pointer operator->() const;

        const const_iterator operator+(size_type val) const;
        const const_iterator operator-(size_type val) const;
        const const_iterator& operator-=(size_type val) const;
        const const_iterator& operator+=(size_type val) const;
        const const_iterator& operator++();
        const const_iterator operator++(int);
        const const_iterator& operator--();
        const const_iterator operator--(int);

        const_reference operator[](size_type ind) const;

        bool operator==(const const_iterator& rhv) const;
        bool operator!=(const const_iterator& rhv) const;
        bool operator<(const const_iterator& rhv) const;
        bool operator>(const const_iterator& rhv) const;
        bool operator<=(const const_iterator& rhv) const;
        bool operator>=(const const_iterator& rhv) const;
        
    };

    class iterator : public const_iterator {
        friend class Vector<value_type>;
    protected:
        explicit iterator(pointer ptr);
    public:
        iterator();
        iterator(const iterator& rhv);
        iterator(iterator&& rhv);
        
        reference operator*();
        pointer operator->();
    };

public:    
    class const_reverse_iterator {
        friend class Vector<value_type>;
    private:
        pointer ptr;
    protected:
        explicit const_reverse_iterator(pointer ptr);
    public:
        const_reverse_iterator();
        const_reverse_iterator(const const_reverse_iterator& rhv);
        const_reverse_iterator(const_reverse_iterator&& rhv);

        ~const_reverse_iterator();

        const const_reverse_iterator& operator=(const const_reverse_iterator& rhv);
        const const_reverse_iterator& operator=(const_reverse_iterator&& rhv);

        const_reference operator*() const;
        const_pointer operator->() const;

        const const_reverse_iterator operator+(size_type val) const;
        const const_reverse_iterator operator-(size_type val) const;
        const const_reverse_iterator& operator-=(size_type val) const;
        const const_reverse_iterator& operator+=(size_type val) const;
        const const_reverse_iterator& operator++();
        const const_reverse_iterator operator++(int);
        const const_reverse_iterator& operator--();
        const const_reverse_iterator operator--(int);

        const_reference operator[](size_type ind) const;

        bool operator==(const const_reverse_iterator& rhv) const;
        bool operator!=(const const_reverse_iterator& rhv) const;
        bool operator<(const const_reverse_iterator& rhv) const;
        bool operator>(const const_reverse_iterator& rhv) const;
        bool operator<=(const const_reverse_iterator& rhv) const;
        bool operator>=(const const_reverse_iterator& rhv) const;
        
    };

    class reverse_iterator : public const_reverse_iterator {
        friend class Vector<value_type>;
    protected:
        explicit reverse_iterator(pointer ptr);
    public:
        reverse_iterator();
        reverse_iterator(const reverse_iterator& rhv);
        reverse_iterator(reverse_iterator&& rhv);
        
        reference operator*();
        pointer operator->();
    };


public:
    /* Constructors */
    Vector();   // default constructor
    Vector(const Vector<value_type>& rhv); // copy constructor
    Vector(Vector&& rhv);
    Vector(std::initializer_list<value_type> list);
    template <typename InputIt>
    Vector(InputIt first, InputIt last);
    
    Vector<value_type>& operator=(const Vector<value_type>& rhv); // copy assignment
    Vector<value_type>& operator=(Vector&& rhv);
    Vector<value_type>& operator=(std::initializer_list<value_type> init);
    
    ~Vector(); // destructor
    void clear() noexcept;

    /* Element access function */
    reference at(size_type pos); // access element at current index with bound checking
    const_reference at(size_type pos) const;
    reference operator[](size_type pos); // access element at current index without bound checking
    const_reference operator[](size_type pos) const;
    reference front(); // return the reference of first element
    const_reference front() const;
    reference back(); // return the reference of last element
    const_reference back() const;
    pointer data();
    const_pointer data() const;
    

    /* Capacity */
    bool empty() const; // checks whether the container is empty
    size_type size() const; // return the number of elements
    size_type capacity() const; // returns the number of elements that can be held in currently allocated storage
    
    void reserve(size_type newCapacity); // reserves storage
    /* Modifiers */
    void push_back(const_reference val);
    void pop_back();

    void assign(size_type count, const_reference val);
    void assign(std::initializer_list<value_type> init);
    template <typename InputIt>
    void assign(InputIt first, InputIt last);

    void swap(Vector<value_type>& other);

    iterator begin();
    const_iterator begin() const;
    const_iterator cbegin() const;

    iterator end();
    const_iterator end() const;
    const_iterator cend() const;

    iterator rbegin();
    const_iterator rbegin() const;
    const_iterator crbegin() const;

    iterator rend();
    const_iterator rend() const;
    const_iterator crend() const;

    iterator erase(const_iterator pos);
    iterator erase(const_iterator first, const_iterator last);

    iterator insert(const_iterator pos, const_reference val);
    iterator insert(const_iterator pos, std::initializer_list<value_type> init);
    iterator insert(const_iterator pos, size_type count, const_reference val);
    template <typename InputIt>
    iterator insert(const_iterator pos, InputIt first, InputIt last);
};

template <typename T>
bool operator==(const Vector<T>& lhv, const Vector<T>& rhv);

template <typename T>
bool operator!=(const Vector<T>& lhv, const Vector<T>& rhv);

template <typename T>
bool operator<(const Vector<T>& lhv, const Vector<T>& rhv);

template <typename T>
bool operator>(const Vector<T>& lhv, const Vector<T>& rhv);

template <typename T>
bool operator<=(const Vector<T>& lhv, const Vector<T>& rhv);

template <typename T>
bool operator>=(const Vector<T>& lhv, const Vector<T>& rhv);


#endif //DS_VECTOR_H
