// Created by Shalev Ben David.

#include "MagicalContainer.hpp"
#include <cmath>
#include <iostream>
#include <stdexcept>
using namespace std;
using namespace ariel;

// -------------------------------- Class: Magical contained --------------------------------

/**
 * Adds an element to the container.
 * @param element - The element we add.
 */
void MagicalContainer :: addElement (int element) {
    // Insert element to the end of the container.
    _sorted_container.push_back(element);
    // Sort item into place in O(n).
    for (size_t i = _sorted_container.size() - 1; i > 0; i--) {
        // Swap items until we get it in his place.
        if (_sorted_container.at(i) < _sorted_container.at(i - 1)) {
            swap(_sorted_container.at(i), _sorted_container.at(i - 1));
        }
    }
    // Update the prime container in O(n).
    _prime_container.clear();
    for (size_t i = 0; i < _sorted_container.size(); i++) {
        if (PrimeIterator :: isPrime(_sorted_container.at(i))) {
            _prime_container.push_back(&_sorted_container.at(i));
        }
    }
}

/**
 * Removed an element from the container.
 * @param element - The element we remove.
 */
void MagicalContainer :: removeElement (int element) {
    // Flag that tells if element was found in the container.
    bool found = false;
    // If the number is prime, remove from the prime container.
    if (PrimeIterator :: isPrime(element)) {
        // Iterate over the prime container.
        for (auto item = _prime_container.begin(); item != _prime_container.end(); ++item) {
            // If we found element, remove and break.
            if (**item == element) {
                _prime_container.erase(item);
                break;
            }
        }
    }
    // Iterate over the sorted container.
    for (auto item = _sorted_container.begin(); item != _sorted_container.end(); ++item) {
        // If we found element, remove and break.
        if (*item == element) {
            _sorted_container.erase(item);
            found = true;
            break;
        }
    }
    // If element isn't in the container, throw.
    if (!found) {
        throw runtime_error("Element isn't in the container!\n");
    }
}

/**
 * @return - The size of the container.
 */
size_t MagicalContainer :: size () const {
    return _sorted_container.size();
}

// -------------------------------- Class: AscendingIterator --------------------------------

// <<<<<<<<<<<<<<<<<< Operator * >>>>>>>>>>>>>>>>>>
const int& MagicalContainer :: AscendingIterator :: operator * () const {
    return getContainer()._sorted_container.at(getIndex());
}

// <<<<<<<<<<<<<<<<<< Prefix increment (++n) >>>>>>>>>>>>>>>>>>
MagicalContainer :: AscendingIterator& MagicalContainer :: AscendingIterator :: operator ++ () {
    // Performing ++ will exceed vector bounds.
    if (getIndex() == getContainer()._sorted_container.size()) {
        throw runtime_error ("Exceeding container's size.\n");
    }
    // Performing ++ will exceed iterator bounds.
    if (*this == end()) {
        throw runtime_error ("Exceeding Iterators bounds.\n");
    }
    // Iterate over to the next index and return reference.
    getIndex()++;
    return *this;
}

// Begin and end operators.
MagicalContainer :: AscendingIterator MagicalContainer :: AscendingIterator :: begin () const {
    // Return a AscendingIterator with index to the start.
    return AscendingIterator(getContainer(), 0);
}
MagicalContainer :: AscendingIterator MagicalContainer :: AscendingIterator :: end () const {
    // Return a AscendingIterator with index to the end.
    return AscendingIterator (getContainer(), getContainer()._sorted_container.size());
}

// -------------------------------- Class: SideCrossIterator --------------------------------

// <<<<<<<<<<<<<<<<<< Operator * >>>>>>>>>>>>>>>>>>
const int& MagicalContainer :: SideCrossIterator :: operator * () const {
    // If the index is even, reduce index by half.
    if (!(getIndex() % 2)) {
        return getContainer()._sorted_container.at(_index / 2);
    }
    // If the index is odd, reduce by 1 and divide by half, and look from the end.
    else {
        return getContainer()._sorted_container.at((getContainer()._sorted_container.size() - 1 - (getIndex() - 1 ) / 2));
    }
}

// <<<<<<<<<<<<<<<<<< Prefix increment (++n) >>>>>>>>>>>>>>>>>>
MagicalContainer :: SideCrossIterator& MagicalContainer :: SideCrossIterator :: operator ++ () {
    // Performing ++ will exceed vector bounds.
    if (getIndex() == getContainer()._sorted_container.size()) {
        throw runtime_error ("Exceeding container's size.\n");
    }
    // Performing ++ will exceed iterator bounds.
    if (*this == end()) {
        throw runtime_error ("Exceeding Iterators bounds.\n");
    }
    // Iterate over to the next index and return reference.
    getIndex()++;
    return *this;
}

// Begin and end operators.
MagicalContainer :: SideCrossIterator MagicalContainer :: SideCrossIterator :: begin () const {
    // Return a SideCrossIterator with index to the start.
    return SideCrossIterator (getContainer(), 0);
}
MagicalContainer :: SideCrossIterator MagicalContainer :: SideCrossIterator :: end () const {
    // Return a SideCrossIterator with index to the end.
    return SideCrossIterator (getContainer(), getContainer()._sorted_container.size());
}

// -------------------------------- Class: PrimeIterator --------------------------------

// <<<<<<<<<<<<<<<<<< Operator * >>>>>>>>>>>>>>>>>>
const int& MagicalContainer :: PrimeIterator :: operator * () const {
    return *getContainer()._prime_container.at(_index);
}

// <<<<<<<<<<<<<<<<<< Prefix increment (++n) >>>>>>>>>>>>>>>>>>
MagicalContainer :: PrimeIterator& MagicalContainer :: PrimeIterator :: operator ++ () {
    // Performing ++ will exceed vector bounds.
    if (getIndex() == getContainer()._prime_container.size()) {
        throw runtime_error ("Exceeding container's size.\n");
    }
    // Performing ++ will exceed iterator bounds.
    if (*this == end()) {
        throw runtime_error ("Exceeding Iterators bounds.\n");
    }
    // Iterate over to the next index and return reference.
    getIndex()++;
    return *this;
}

// Begin and end operators.
MagicalContainer :: PrimeIterator MagicalContainer :: PrimeIterator :: begin () const {
    // Return a PrimeIterator with index to the start.
    return PrimeIterator (getContainer(), 0);
}
MagicalContainer :: PrimeIterator MagicalContainer :: PrimeIterator :: end () const {
    // Return a PrimeIterator with index to the end.
    return PrimeIterator (getContainer(), getContainer()._prime_container.size());
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