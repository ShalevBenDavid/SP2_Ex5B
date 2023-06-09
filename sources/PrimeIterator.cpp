// Created by Shalev Ben David.

#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;

// <<<<<<<<<<<<<<<<<< Operator = >>>>>>>>>>>>>>>>>>
MagicalContainer :: PrimeIterator& MagicalContainer :: PrimeIterator :: operator = (const PrimeIterator& other) {
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
const int& MagicalContainer :: PrimeIterator :: operator * () const {
    return *_container._prime_container.at(_index);
}

// <<<<<<<<<<<<<<<<<< Prefix increment (++n) >>>>>>>>>>>>>>>>>>
MagicalContainer :: PrimeIterator& MagicalContainer :: PrimeIterator :: operator ++ () {
    // Performing ++ will exceed iterator bounds.
    if (_index == _container._prime_container.size()) {
        throw runtime_error ("Exceeding Iterators bounds.\n");
    }
    // Iterate over to the next index and return reference.
    _index++;
    return *this;
}

// Compare operators.
// <<<<<<<<<<<<<<<<<< Operator == >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: PrimeIterator :: operator == (const PrimeIterator& other) const {
    // If no the same container, throw.
    if (&_container != &other._container) {
        throw runtime_error("Comparing iterators from different containers.");
    }
    // Two iterators are equal if their iterators and i
    return (_index == other._index);
}
// <<<<<<<<<<<<<<<<<< Operator != >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: PrimeIterator :: operator != (const PrimeIterator& other) const {
    return !(*this == other);
}
// <<<<<<<<<<<<<<<<<< Operator > >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: PrimeIterator :: operator > (const PrimeIterator& other) const {
    // If no the same container, throw.
    if (&_container != &other._container) {
        throw runtime_error("Comparing iterators from different containers.");
    }
    return (_index > other._index);
}
// <<<<<<<<<<<<<<<<<< Operator < >>>>>>>>>>>>>>>>>>
bool MagicalContainer :: PrimeIterator :: operator < (const PrimeIterator& other) const {
    // If no the same container, throw.
    if (&_container != &other._container) {
        throw runtime_error("Comparing iterators from different containers.");
    }
    return (_index < other._index);
}

// Begin and end operators.
MagicalContainer :: PrimeIterator MagicalContainer :: PrimeIterator :: begin () const {
    // Return a PrimeIterator with index to the start.
    return PrimeIterator (_container, 0);
}
MagicalContainer :: PrimeIterator MagicalContainer :: PrimeIterator :: end () const {
    // Return a PrimeIterator with index to the end.
    return PrimeIterator (_container, _container._prime_container.size());
}

/**
 * Check if a num is prime.
 * @param num - The num we check if is prime.
 * @return - True if num is prime, and false otherwise.
 */
bool MagicalContainer :: PrimeIterator :: isPrime (int num) {
    if (num < 2) { return false; }
    if (!(num % 2) && (num != 2)) { return false; }
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (!(num % i)) { return false; }
    }
    return true;
}