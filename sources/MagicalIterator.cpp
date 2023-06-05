// Created by Shalev Ben David.

#include "MagicalIterator.hpp"
using namespace std;
using namespace ariel;

// <<<<<<<<<<<<<<<<<< Operator = >>>>>>>>>>>>>>>>>>
MagicalIterator& MagicalIterator :: operator = (const MagicalIterator& other) {
    // If the iterators differ in type or container, throw.
    if ((typeid (*this) != typeid (other) || (&_container != &other._container))) {
        throw runtime_error("Assigning iterator to different type or container!\n");
    }
    // Only if this is not the same iterator.
    if (this != &other) {
        _container = other._container;
        _index = other._index;
    }
    return *this;
}

// Compare operators.
// <<<<<<<<<<<<<<<<<< Operator == >>>>>>>>>>>>>>>>>>
bool MagicalIterator :: operator == (const MagicalIterator& other) const  {
    // If the iterators differ in type or container, throw.
    if ((typeid (*this) != typeid (other) || (&_container != &other._container))) {
        throw runtime_error("Comparing iterators from different types or containers!\n");
    }
    // Two iterators are equal if their index are equal.
    return (_index == other._index);
}

// <<<<<<<<<<<<<<<<<< Operator != >>>>>>>>>>>>>>>>>>
bool MagicalIterator :: operator != (const MagicalIterator& other) const {
    // Two iterators are not equal if == return false.
    return !(*this == other);
}

// <<<<<<<<<<<<<<<<<< Operator > >>>>>>>>>>>>>>>>>>
bool MagicalIterator :: operator > (const MagicalIterator& other) const {
    // If the iterators differ in type or container, throw.
    if ((typeid (*this) != typeid (other) || (&_container != &other._container))) {
        throw runtime_error("Comparing iterators from different types or containers!\n");
    }
    // Two iterators are equal if their index are equal.
    return (_index > other._index);
}

// <<<<<<<<<<<<<<<<<< Operator < >>>>>>>>>>>>>>>>>>
bool MagicalIterator :: operator < (const MagicalIterator& other) const {
    // If the iterators differ in type or container, throw.
    if ((typeid (*this) != typeid (other) || (&_container != &other._container))) {
        throw runtime_error("Comparing iterators from different types or containers!\n");
    }
    // Two iterators are equal if their index are equal.
    return (_index < other._index);
}