#include"vector.h"
#include<iostream>

//parametric ctor
template <typename T>
Vector<T>::const_iterator::const_iterator(pointer ptr) : ptr(ptr) {}

//default ctor
template <typename T>
Vector<T>::const_iterator::const_iterator() : ptr(nullptr) {}

//copy ctro
template <typename T>
Vector<T>::const_iterator::const_iterator(const const_iterator& rhv) : ptr(rhv.ptr) {}

//move ctor
template <typename T>
Vector<T>::const_iterator::const_iterator(const_iterator&& rhv) : ptr(rhv.ptr) {
    rhv.ptr = nullptr;
}

//dtor
template <typename T>
Vector<T>::const_iterator::~const_iterator() {}

//copy =
template <typename T>
const typename Vector<T>::const_iterator& Vector<T>::const_iterator::operator=(const typename Vector<T>::const_iterator& rhv) {
    if (this != &rhv) {
        ptr = rhv.ptr;
    }
    return *this;
}



//move=
template <typename T>
const typename Vector<T>::const_iterator& Vector<T>::const_iterator::operator=(Vector<T>::const_iterator&& rhv) {
    if (this != &rhv) {
        ptr = rhv.ptr;
        rhv.ptr = nullptr;
    }
    return *this;
}

//dereference
//const_reference = const value_type&
template <typename T>
typename Vector<T>::const_reference  Vector<T>::const_iterator::operator*() const {
    return *ptr;
}

//pointer = value_type*
template <typename T>
typename Vector<T>::const_pointer  Vector<T>::const_iterator::operator->() const {
    return ptr;
}

//size_type = T;
template <typename T>
const typename Vector<T>::const_iterator  Vector<T>::const_iterator::operator+( typename Vector<T>::size_type val) const {
    return const_iterator(ptr + val);
}

//size_type = T  
template <typename T>
const typename Vector<T>::const_iterator Vector<T>::const_iterator::operator-(typename Vector<T>::size_type val) const {
    return const_iterator(ptr - val);
}

//size_type = T
template <typename T>
const typename Vector<T>::const_iterator&  Vector<T>::const_iterator::operator-=(typename Vector<T>::size_type val) const {
    ptr -= val;
    return *this;
}

//size_type = T
template <typename T>
const typename Vector<T>::const_iterator& Vector<T>::const_iterator::operator+=(typename Vector<T>::size_type val) const {
    ptr += val;
    return *this;
}

//prefix++
template <typename T>
const typename Vector<T>::const_iterator& Vector<T>::const_iterator::operator++() {
    ++ptr;
    return *this;
}
//postfix++
template <typename T>
const typename Vector<T>::const_iterator Vector<T>::const_iterator::operator++(int) {
    const_iterator tmp = *this;
    ++ptr;
    return tmp;
}

//prefix--
template <typename T>
const typename Vector<T>::const_iterator& Vector<T>::const_iterator::operator--() {
    --ptr;
    return *this;
}

//postfix--
template <typename T>
const typename Vector<T>::const_iterator Vector<T>::const_iterator::operator--(int) {
    const_iterator tmp = *this;
    --ptr;
    return tmp;
}

//operator []
//const_reference = const value_type&
template <typename T>
typename Vector<T>::const_reference Vector<T>::const_iterator::operator[](typename Vector<T>::size_type ind) const {
    return ptr[ind];
}

//logical operators oherloading
template <typename T>
bool Vector<T>::const_iterator::operator==(const Vector<T>::const_iterator& rhv) const {
    return ptr == rhv.ptr;
}

template <typename T>
bool Vector<T>::const_iterator::operator!=(const Vector<T>::const_iterator& rhv) const {
    return !(ptr == rhv.ptr);
}

template <typename T>
bool Vector<T>::const_iterator::operator<(const Vector<T>::const_iterator& rhv) const {
    return ptr < rhv.ptr;
}

template <typename T>
bool Vector<T>::const_iterator::operator<=(const Vector<T>::const_iterator& rhv) const {
    return ptr <= rhv.ptr;
}

template <typename T>
bool Vector<T>::const_iterator::operator>(const Vector <T>::const_iterator& rhv) const {
    return !(ptr <= rhv.ptr);
}


template <typename T>
bool Vector<T>::const_iterator::operator>=(const Vector<T>::const_iterator& rhv) const {
    return !(ptr < rhv.ptr);
}

//iterator
template <typename T>
Vector<T>::iterator::iterator(Vector<T>::pointer ptr) : const_iterator(ptr) {}

template <typename T>
Vector<T>::iterator::iterator() : const_iterator() {}

template <typename T>
Vector<T>::iterator::iterator(const Vector<T>::iterator& rhv) : const_iterator(rhv) {}

template <typename T>
Vector<T>::iterator::iterator(Vector<T>::iterator&& rhv) : const_iterator(std::move(rhv)) {}
        
template <typename T>
typename Vector<T>::reference Vector<T>::iterator::operator*() {
    return const_reverse_iterator::operator*();
}

template <typename T>
typename Vector<T>::pointer Vector<T>::iterator::operator->() {
    return  const_reverse_iterator::operator->();
}



//const_reverse_iterator 

template <typename T>
Vector<T>::const_reverse_iterator::const_reverse_iterator(pointer ptr) : ptr(ptr) {}

template <typename T>
Vector<T>::const_reverse_iterator::const_reverse_iterator() : ptr(nullptr) {}

template <typename T>
Vector<T>::const_reverse_iterator::const_reverse_iterator(const Vector<T>::const_reverse_iterator& rhv) : ptr(rhv.ptr) {}

template <typename T>
Vector<T>::const_reverse_iterator::const_reverse_iterator(Vector<T>::const_reverse_iterator&& rhv) : ptr(rhv.ptr) 
 {
     rhv.ptr = nullptr;
 }

template <typename T>
Vector<T>::const_reverse_iterator::~const_reverse_iterator() {}

template <typename T>
const typename Vector<T>::const_reverse_iterator& Vector<T>::const_reverse_iterator::operator=(const Vector<T>::const_reverse_iterator& rhv) {
    if (this != &rhv) {
        this->ptr = rhv.ptr;
    }
    return *this;
}

template <typename T>
const typename Vector<T>::const_reverse_iterator& Vector<T>::const_reverse_iterator::operator=(Vector<T>::const_reverse_iterator&& rhv) {
    if (this != &rhv) {
        this->ptr = rhv.ptr;
        rhv.ptr = nullptr;
    }
    return *this;
}

template <typename T>
typename Vector<T>::const_reference Vector<T>::const_reverse_iterator::operator*() const {
    return *ptr;
}

template <typename T>
typename Vector<T>::const_pointer Vector<T>::const_reverse_iterator::operator->() const {
    return ptr;
}

template <typename T>
const typename Vector<T>::const_reverse_iterator Vector<T>::const_reverse_iterator::operator+(typename Vector<T>::size_type val) const {
    return const_reverse_iterator(this->ptr - val);
}

template <typename T>
const typename Vector<T>::const_reverse_iterator Vector<T>::const_reverse_iterator::operator-(typename Vector<T>::size_type val) const {
    return const_reverse_iterator(this->ptr + val);
}

template <typename T>
const typename Vector<T>::const_reverse_iterator& Vector<T>::const_reverse_iterator::operator-=(typename Vector<T>::size_type val) const {
    this->ptr += val;
    return *this;
}

template <typename T>
const typename Vector<T>::const_reverse_iterator& Vector<T>::const_reverse_iterator::operator+=(typename Vector<T>::size_type val) const {
    this->ptr -= val;
    return *this;
}

template <typename T>
const typename Vector<T>::const_reverse_iterator& Vector<T>::const_reverse_iterator::operator++() {
    --this->ptr;
    return *this;
}


template <typename T>
const typename Vector<T>::const_reverse_iterator Vector<T>::const_reverse_iterator::operator++(int) {
    const_reverse_iterator temp = *this;
    --this->ptr;
    return temp;
}

template <typename T>
const typename Vector<T>::const_reverse_iterator& Vector<T>::const_reverse_iterator::operator--() {
    ++this->ptr;
    return *this;
}

template <typename T>
const typename Vector<T>::const_reverse_iterator Vector<T>::const_reverse_iterator::operator--(int) {
    const_reverse_iterator temp = *this;
    ++this->ptr;
    return temp;
}

template <typename T>
typename Vector<T>::const_reference Vector<T>::const_reverse_iterator::operator[](typename Vector<T>::size_type ind) const {
    return this->ptr[-ind];
}

template <typename T>
bool Vector<T>::const_reverse_iterator::operator==(const Vector<T>::const_reverse_iterator& rhv) const {
    return this->ptr == rhv.ptr;
}

template <typename T>
bool Vector<T>::const_reverse_iterator::operator!=(const Vector<T>::const_reverse_iterator& rhv) const {
    return this->ptr != rhv.ptr;
}

template <typename T>
bool Vector<T>::const_reverse_iterator::operator<(const Vector<T>::const_reverse_iterator& rhv) const {
    return this->ptr > rhv.ptr;
}

template <typename T>
bool Vector<T>::const_reverse_iterator::operator>(const Vector<T>::const_reverse_iterator& rhv) const {
    return this->ptr < rhv.ptr;
}

template <typename T>
bool Vector<T>::const_reverse_iterator::operator<=(const Vector<T>::const_reverse_iterator& rhv) const {
    return this->ptr >= rhv.ptr;
}

template <typename T>
bool Vector<T>::const_reverse_iterator::operator>=(const Vector<T>::const_reverse_iterator& rhv) const {
    return this->ptr <= rhv.ptr;
}

//  reverse_iterator
template <typename T>
Vector<T>::reverse_iterator::reverse_iterator(Vector<T>::pointer ptr) : const_reverse_iterator(ptr) {}

template <typename T>
Vector<T>::reverse_iterator::reverse_iterator() : const_reverse_iterator() {}

template <typename T>
Vector<T>::reverse_iterator::reverse_iterator(const Vector<T>::reverse_iterator& rhv) : const_reverse_iterator(rhv) {}

template <typename T>
Vector<T>::reverse_iterator::reverse_iterator(Vector<T>::reverse_iterator&& rhv) : const_reverse_iterator(std::move(rhv)) {}

template <typename T>
typename Vector<T>::reference Vector<T>::reverse_iterator::operator*() {
    return *this->ptr;
}

template <typename T>
typename Vector<T>::pointer Vector<T>::reverse_iterator::operator->() {
    return this->ptr;
}


//vector 

template <typename T>
Vector<T>::Vector() : _capacity(0), _size(0), _arr(nullptr) {}//default ctor

//copy ctor
template <typename T>
Vector<T>::Vector(const Vector<T>& rhv) : _capacity(rhv._size), _size(rhv._size), _arr(new T[rhv._size]) {
     for (size_t i = 0;i < _size; ++i) {
	       _arr[i] = rhv._arr[i];
	     }
}

//move ctor
template <typename T>
Vector<T>::Vector(Vector<T>&& rhv) : _capacity(rhv._capacity), _size(rhv._size), _arr(rhv._arr) {
    rhv._capacity = 0;
    rhv._size = 0;
    rhv._arr = nullptr;
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> list) : _capacity(list.size()), _size(list.size()) {
    _arr = new T[_capacity];
    std::copy(list.begin(), list.end(), _arr);
}


//copy=
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& rhv) {
    if (this != &rhv) {
        delete[] _arr;
        _capacity = rhv._capacity;
        _size = rhv._size;
        _arr = new T[_capacity];
        std::copy(rhv._arr, rhv._arr + rhv._size, _arr);
    }
    return *this;
}
//move=
template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& rhv) {
    if (this != &rhv) {
        delete[] _arr;
        _capacity = rhv._capacity;
        _size = rhv._size;
        _arr = rhv._arr;
        rhv._capacity = rhv._size = 0;
        rhv._arr = nullptr;
    }
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(std::initializer_list<T> init) {
    delete[] _arr;
    _capacity = init.size();
    _size = init.size();
    _arr = new T[_capacity];
    std::copy(init.begin(), init.end(), _arr);
    return *this;
}///

//dtor
template <typename T>
Vector<T>::~Vector() {
    clear();
}

template <typename T>
void Vector<T>::clear() noexcept{
    delete[] _arr;
    _arr = nullptr;
    _size = 0;
    _capacity = 0;
}

template <typename T>
template <typename InputIt>
Vector<T>::Vector(InputIt first, InputIt last) : _capacity(std::distance(first, last)), _size(_capacity) {
    _arr = new T[_capacity];
    std::copy(first, last, _arr);
}

template <typename T>
typename Vector<T>::reference Vector<T>::at(typename Vector<T>::size_type pos) {
    if (pos >= _size) {
        throw std::out_of_range("Vector::at() - Index out of range");
    }
    return _arr[pos];
}

template <typename T>
typename Vector<T>::const_reference Vector<T>::at(typename Vector<T>::size_type pos) const {
    if (pos >= _size) {
        throw std::out_of_range("Vector::at() - Index out of range");
    }
    return _arr[pos];
}

template <typename T>
typename Vector<T>::reference Vector<T>::operator[](typename Vector<T>::size_type pos) {
    return _arr[pos];
}

template <typename T>
typename Vector<T>::const_reference Vector<T>::operator[](typename Vector<T>::size_type pos) const {
    return _arr[pos];
}

template <typename T>
typename Vector<T>::reference Vector<T>::front() {
    return _arr[0];
}

template <typename T>
typename Vector<T>::const_reference Vector<T>::front() const {
    return _arr[0];
}

template <typename T>
typename Vector<T>::reference Vector<T>::back() {
    return _arr[_size - 1];
}

template <typename T>
typename Vector<T>::const_reference Vector<T>::back() const {
    return _arr[_size - 1];
}

template <typename T>
typename Vector<T>::pointer Vector<T>::data() {
    return _arr;
}

template <typename T>
typename Vector<T>::const_pointer Vector<T>::data() const {
    return _arr;
}

// Capacity
template <typename T>
bool Vector<T>::empty() const {
    return _size == 0;
}

template <typename T>
typename Vector<T>::size_type Vector<T>::size() const {
    return _size;
}

template <typename T>
typename Vector<T>::size_type Vector<T>::capacity() const {
    return _capacity;
}

template <typename T>
void Vector<T>::reserve(typename Vector<T>::size_type newCapacity) {
    if (newCapacity > _capacity) {
        T* newArr = new T[newCapacity];
        std::copy(_arr, _arr + _size, newArr);
        delete[] _arr;
        _arr = newArr;
        _capacity = newCapacity;
    }
}

// Modifiers
template <typename T>
void Vector<T>::push_back(typename Vector<T>::const_reference val) {
    if (_size == _capacity) {
        T* newArr = new T [2 * _capacity];
          std::copy(_arr, _arr + _size, newArr);
          delete[] _arr;
          _arr = newArr;
          _capacity = 2 * _capacity;

    }
    _arr[_size++] = val;
}

template <typename T>
void Vector<T>::pop_back() {
    if (_size > 0) {
        --_size;
    }
}


template <typename T>
void Vector<T>::assign(typename Vector<T>::size_type count, typename Vector<T>::const_reference val) {
    clear();
    if (count > _capacity) {
        reserve(count);
    }
    std::fill_n(_arr, count, val);
    _size = count;
}

template <typename T>
void Vector<T>::assign(std::initializer_list<T> init) {
    assign(init.begin(), init.end());
}

template <typename T>
template <typename InputIt>
void Vector<T>::assign(InputIt first, InputIt last) {
    clear();
    size_type count = std::distance(first, last);
    if (count > _capacity) {
        reserve(count);
    }
    std::copy(first, last, _arr);
    _size = count;
}

template <typename T>
void Vector<T>::swap(Vector<T>& other) {
    std::swap(_arr, other._arr);
    std::swap(_size, other._size);
    std::swap(_capacity, other._capacity);
}

template <typename T>
typename Vector<T>::iterator Vector<T>::begin() {
    return iterator(_arr);
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::begin() const {
    return const_iterator(_arr);
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::cbegin() const {
    return const_iterator(_arr);
}

template <typename T>
typename Vector<T>::iterator Vector<T>::end() {
    return iterator(_arr + _size);
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::end() const {
    return const_iterator(_arr + _size);
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::cend() const {
    return const_iterator(_arr + _size);
}

template <typename T>
typename Vector<T>::iterator Vector<T>::rbegin() {
    return iterator(_arr + _size - 1);
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::rbegin() const {
    return const_iterator(_arr + _size - 1);
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::crbegin() const {
    return const_iterator(_arr + _size - 1);
}

template <typename T>
typename Vector<T>::iterator Vector<T>::rend() {
    return iterator(_arr - 1);
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::rend() const {
    return const_iterator(_arr - 1);
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::crend() const {
    return const_iterator(_arr - 1);
}

template <typename T>
typename Vector<T>::iterator Vector<T>::erase(const_iterator pos) {

    size_type index = pos - begin();
    if (index >= 0 && index < _size) {
        std::copy(_arr + index + 1, _arr + _size, _arr + index);
        --_size;
    }
    return iterator(_arr + index);
}

template <typename T>
typename Vector<T>::iterator Vector<T>::erase(const_iterator first, const_iterator last) {
    size_type startIndex = first - begin();
    size_type endIndex = last - begin();
    if (startIndex >= 0 && endIndex >= 0 && startIndex < _size && endIndex <= _size && startIndex <= endIndex) {
        std::copy(_arr + endIndex, _arr + _size, _arr + startIndex);
        _size -= (endIndex - startIndex);
    }
    return iterator(_arr + startIndex);
}

template <typename T>
typename Vector<T>::iterator Vector<T>::insert(const_iterator pos, const_reference val) {
   
    size_type index = pos - begin();
    if (index >= 0 && index <= _size) {
        if (_size == _capacity) {
            reserve(_capacity == 0 ? 1 : 2 * _capacity);
        }
        std::copy_backward(_arr + index, _arr + _size, _arr + _size + 1);
        _arr[index] = val;
        ++_size;
    }
    return iterator(_arr + index);
}

// comparison operators
template <typename T>
bool operator==(const Vector<T>& lhv, const Vector<T>& rhv) {
    return std::equal(lhv.begin(), lhv.end(), rhv.begin(), rhv.end());
}

template <typename T>
bool operator!=(const Vector<T>& lhv, const Vector<T>& rhv) {
    return !(lhv == rhv);
}

template <typename T>
bool operator<(const Vector<T>& lhv, const Vector<T>& rhv) {
    return std::lexicographical_compare(lhv.begin(), lhv.end(), rhv.begin(), rhv.end());
}

template <typename T>
bool operator>(const Vector<T>& lhv, const Vector<T>& rhv) {
    return rhv < lhv;
}

template <typename T>
bool operator<=(const Vector<T>& lhv, const Vector<T>& rhv) {
    return !(rhv < lhv);
}

template <typename T>
bool operator>=(const Vector<T>& lhv, const Vector<T>& rhv) {
    return !(lhv < rhv);
}

int main() {
    // Create a Vector of integers
    Vector<int> v1 = {1, 2, 3, 4, 5};

    // Print the elements using iterators
    std::cout << "Vector elements: ";
    for (auto it = v1.begin(); it != v1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Use reverse iterator to print elements in reverse
    std::cout << "Reverse Vector elements: ";
    for (auto it = v1.rbegin(); it != v1.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Use const_iterator to print elements (read-only)
    std::cout << "Const Iterator: ";
    for (auto cit = v1.cbegin(); cit != v1.cend(); ++cit) {
        std::cout << *cit << " ";
    }
    std::cout << std::endl;

    // Modify elements using iterator
    std::cout << "Modified Vector elements: ";
    for (auto it = v1.begin(); it != v1.end(); ++it) {
        *it += 10;
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}


