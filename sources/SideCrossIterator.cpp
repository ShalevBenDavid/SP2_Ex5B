// Created by Shalev Ben David.

#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;

// <<<<<<<<<<<<<<<<<< Operator = >>>>>>>>>>>>>>>>>>
MagicalContainer :: SideCrossIterator& MagicalContainer :: SideCrossIterator :: operator = (const SideCrossIterator& other) {
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
const int& MagicalContainer :: SideCrossIterator :: operator * () const {
    // If the index is even, reduce index by half.
    if (!(_index % 2)) {
        return _container._sorted_container.at(_index / 2);
    }
        // If the index is odd, reduce by 1 and divide by half, and look from the end.
    else {
        return _container._sorted_container.at((_container._sorted_container.size() - 1 - (_index - 1 ) / 2));
    }
}

// <<<<<<<<<<<<<<<<<< Prefix increment (++n) >>>>>>>>>>>>>>>>>>
MagicalContainer :: SideCrossIterator& MagicalContainer :: SideCrossIterator :: operator ++ () {
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
bool MagicalContainer :: SideCrossIterator :: operator == (const SideCrossIterator& other) const {
    // If no the same container, throw.
    if (&_container != &other._container) {
        throw runtime_error("Comparing iterators from different containers.");
    }
    // Two iterators are equal if their iterators and i
    return (_index == other._index);
}
// <<<<<<<<<<<<<<<<<< Operator != >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: SideCrossIterator :: operator != (const SideCrossIterator& other) const {
    return !(*this == other);
}
// <<<<<<<<<<<<<<<<<< Operator > >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: SideCrossIterator :: operator > (const SideCrossIterator& other) const {
    // If no the same container, throw.
    if (&_container != &other._container) {
        throw runtime_error("Comparing iterators from different containers.");
    }
    // Initialize indexes.
    int index1 = _index;
    int index2 = other._index;
    // Calculating side-cross index for this if not end iterator.
    if (_index != _container._sorted_container.size()) {
        index1 = !(_index % 2) ?
                 (_index / 2) : (_container._sorted_container.size() - 1 - (_index - 1 ) / 2);
    }
    // Calculating side-cross index for other if not end iterator.
    if (other._index != _container._sorted_container.size()) {
        index2 = !(other._index % 2) ?
                 (other._index / 2) : (_container._sorted_container.size() - 1 - (other._index - 1) / 2);
    }
    return (index1 > index2);
}
// <<<<<<<<<<<<<<<<<< Operator < >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: SideCrossIterator :: operator < (const SideCrossIterator& other) const {
    return !(*this > other) && (*this != other);
}

// Begin and end operators.
MagicalContainer :: SideCrossIterator MagicalContainer :: SideCrossIterator :: begin () const {
    // Return a SideCrossIterator with index to the start.
    return SideCrossIterator (_container, 0);
}
MagicalContainer :: SideCrossIterator MagicalContainer :: SideCrossIterator :: end () const {
    // Return a SideCrossIterator with index to the end.
    return SideCrossIterator (_container, _container._sorted_container.size());
}