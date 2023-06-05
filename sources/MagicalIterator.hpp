// Created by Shalev Ben David.

#ifndef SP2_EX5B_MAGICALITERATOR_H
#define SP2_EX5B_MAGICALITERATOR_H
#include "MagicalContainer.hpp"

namespace ariel {
    class MagicalIterator {
        // Private attributes.
        MagicalContainer& _container;
        size_t _index;

    public:
        // Default constructor.
        MagicalIterator (MagicalContainer& container, size_t index) : _container(container), _index(index) {
            // If index is out of the containers bound, throw.
            if (index > container._sorted_container.size()) { throw invalid_argument("Invalid index.\n"); }
        }

        // Copy constructor.
        MagicalIterator (const MagicalIterator& other) : _container (other._container), _index (other._index) {}

        // Destructor.
        virtual ~MagicalIterator () = default;

        // <<<<<<<<<<<<<<<<<< Operator = >>>>>>>>>>>>>>>>>>
        MagicalIterator& operator = (const MagicalIterator&);

        // <<<<<<<<<<<<<<<<<< Operator * >>>>>>>>>>>>>>>>>>
        virtual int& operator * () = 0;

        // <<<<<<<<<<<<<<<<<< Prefix increment (++n) >>>>>>>>>>>>>>>>>>
        virtual MagicalIterator& operator ++ () = 0;

        // Compare operators.
        // <<<<<<<<<<<<<<<<<< Operator == >>>>>>>>>>>>>>>>>>
        bool operator == (const MagicalIterator&) const;
        // <<<<<<<<<<<<<<<<<< Operator != >>>>>>>>>>>>>>>>>>
        bool operator != (const MagicalIterator&) const;
        // <<<<<<<<<<<<<<<<<< Operator > >>>>>>>>>>>>>>>>>>
        bool operator > (const MagicalIterator&) const;
        // <<<<<<<<<<<<<<<<<< Operator < >>>>>>>>>>>>>>>>>>
        bool operator < (const MagicalIterator&) const;

        // Begin and end operators.
        virtual MagicalIterator begin () const = 0;
        virtual MagicalIterator end () const = 0;

        // Getters and setters.
        MagicalContainer& getContainer () { return _container; }
        size_t& getIndex () { return _index; }

        // For Tidy.
        MagicalIterator(MagicalIterator&&) noexcept; // Move Constructor.
        MagicalIterator& operator = (MagicalIterator&&) noexcept; // Move assignment operator.
    };
}

#endif //SP2_EX5B_MAGICALITERATOR_H