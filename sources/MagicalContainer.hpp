// Created by Shalev Ben David.

#ifndef SP2_EX5A_MAGICALCONTAINER_H
#define SP2_EX5A_MAGICALCONTAINER_H
#include "MagicalIterator.hpp"
#include <vector>

namespace ariel {
    class MagicalContainer {
        // Private attributes.
        std :: vector <int> _sorted_container;
        std :: vector <int*> _prime_container;

    public:
        // Constructors.
        MagicalContainer () {};

        // Methods.
        void addElement (int);
        void removeElement (int);
        size_t size() const;

        // --------------------------- Class: AscendingIterator ---------------------------
        class AscendingIterator : MagicalIterator {
        public:
            // Default constructor.
            AscendingIterator (MagicalContainer& container, size_t index = 0) : MagicalIterator(container, index) {}
            // Copy constructor.
            AscendingIterator (const AscendingIterator& other) : MagicalIterator(other) {}

            // <<<<<<<<<<<<<<<<<< Operator * >>>>>>>>>>>>>>>>>>
            const int& operator * () const override;

            // <<<<<<<<<<<<<<<<<< Prefix increment (++n) >>>>>>>>>>>>>>>>>>
            AscendingIterator& operator ++ () override;

            // Begin and end operators.
            AscendingIterator begin () const override;
            AscendingIterator end () const override;
        };

        // --------------------------- Class: SideCrossIterator ---------------------------
        class SideCrossIterator : MagicalIterator {
        public:
            // Default constructor.
            SideCrossIterator (SideCrossIterator& container, size_t index = 0) : MagicalIterator(container, index) {}
            // Copy constructor.
            SideCrossIterator (const SideCrossIterator& other) : MagicalIterator(other) {}

            // Destructor.
            ~SideCrossIterator () = default;

            // <<<<<<<<<<<<<<<<<< Operator * >>>>>>>>>>>>>>>>>>
            const int& operator * () const override;

            // <<<<<<<<<<<<<<<<<< Prefix increment (++n) >>>>>>>>>>>>>>>>>>
            SideCrossIterator& operator ++ () override;

            // Begin and end operators.
            SideCrossIterator begin () const override;
            SideCrossIterator end () const override;
        };

        // --------------------------- Class: PrimeIterator ---------------------------
        class PrimeIterator : MagicalIterator {
        public:
            // Default constructor.
            PrimeIterator (PrimeIterator& container, size_t index = 0) : MagicalIterator(container, index) {}
            // Copy constructor.
            PrimeIterator (const PrimeIterator& other) : MagicalIterator(other) {}

            // Methods.
            static bool isPrime (int);

            // <<<<<<<<<<<<<<<<<< Operator * >>>>>>>>>>>>>>>>>>
            const int& operator * () const override;

            // <<<<<<<<<<<<<<<<<< Prefix increment (++n) >>>>>>>>>>>>>>>>>>
            PrimeIterator& operator ++ () override;

            // Begin and end operators.
            PrimeIterator begin () const override;
            PrimeIterator end () const override;
        };
    };
}
#endif //SP2_EX5A_MAGICALCONTAINER_H