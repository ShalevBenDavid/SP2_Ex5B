// Created by Shalev Ben David.

#include "MagicalContainer.hpp"
#include <algorithm>
using namespace std;
using namespace ariel;

/**
 * Adds an element to the container.
 * @param element - The element we add.
 */
void MagicalContainer :: addElement (int element) {
    // Iterate over the sorted container.
    for (auto item = _sorted_container.begin(); item != _sorted_container.end(); ++item) {
        // If element already exists, return and don't add.
        if (*item == element) { return; }
    }
    // Find in O(log(n)) the position to insert the new element.
    auto position = lower_bound(_sorted_container.begin(), _sorted_container.end(), element);
    // Insert element in the correct position in O(n).
    _sorted_container.insert(position, element);
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