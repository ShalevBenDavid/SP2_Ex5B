// Created by Shalev Ben David.

#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;

// <<<<<<<<<<<<<<<<<< Operator = >>>>>>>>>>>>>>>>>>
MagicalContainer :: AscendingIterator& MagicalContainer :: AscendingIterator :: operator = (const AscendingIterator& other) {
    // If the iterators differ in container, throw.
    if (&_container != &other._container) {
        throw runtime_error("Assigning iterator with different container!\n");
    }
    // Only if this is not the same iterator.
    if (this != &other) {
        _container = other._container;
        _index = other._index;
    }
    return *this;
}

// <<<<<<<<<<<<<<<<<< Operator * >>>>>>>>>>>>>>>>>>
const int& MagicalContainer :: AscendingIterator :: operator * () const {
    return _container._sorted_container.at(_index);
}

// <<<<<<<<<<<<<<<<<< Prefix increment (++n) >>>>>>>>>>>>>>>>>>
MagicalContainer :: AscendingIterator& MagicalContainer :: AscendingIterator :: operator ++ () {
    // Performing ++ will exceed iterator bounds.
    if (_index == _container._sorted_container.size()) {
        throw runtime_error ("Exceeding Iterators bounds.\n");
    }
    // Iterate over to the next index and return reference.
    _index++;
    return *this;
}

// Compare operators.
// <<<<<<<<<<<<<<<<<< Operator == >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: AscendingIterator :: operator == (const AscendingIterator& other) const {
    // If no the same container, throw.
    if (&_container != &other._container) {
        throw runtime_error("Comparing iterators from different containers.");
    }
    // Two iterators are equal if their iterators and i
    return (_index == other._index);
}
// <<<<<<<<<<<<<<<<<< Operator != >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: AscendingIterator :: operator != (const AscendingIterator& other) const {
    return !(*this == other);
}
// <<<<<<<<<<<<<<<<<< Operator > >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: AscendingIterator :: operator > (const AscendingIterator& other) const {
    // If no the same container, throw.
    if (&_container != &other._container) {
        throw runtime_error("Comparing iterators from different containers.");
    }
    return (_index > other._index);
}
// <<<<<<<<<<<<<<<<<< Operator < >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: AscendingIterator :: operator < (const AscendingIterator& other) const {
    // If no the same container, throw.
    if (&_container != &other._container) {
        throw runtime_error("Comparing iterators from different containers.");
    }
    return (_index < other._index);
}

// Begin and end operators.
MagicalContainer :: AscendingIterator MagicalContainer :: AscendingIterator :: begin () const {
    // Return a AscendingIterator with index to the start.
    return AscendingIterator(_container, 0);
}
MagicalContainer :: AscendingIterator MagicalContainer :: AscendingIterator :: end () const {
    // Return a AscendingIterator with index to the end.
    return AscendingIterator (_container, _container._sorted_container.size());
}