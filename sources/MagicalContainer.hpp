// Created by Shalev Ben David.

#ifndef SP2_EX5A_MAGICALCONTAINER_H
#define SP2_EX5A_MAGICALCONTAINER_H
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
        class AscendingIterator {
        private:
            MagicalContainer& _container;
            size_t _index;

        public:
            // Constructors.
            AscendingIterator (MagicalContainer& container, size_t index = 0); // Default constructor.
            AscendingIterator (const AscendingIterator&); // Copy constructor.

            // Destructor.
            ~AscendingIterator () = default;

            // <<<<<<<<<<<<<<<<<< Operator = >>>>>>>>>>>>>>>>>>
            AscendingIterator& operator = (const AscendingIterator&);

            // <<<<<<<<<<<<<<<<<< Operator * >>>>>>>>>>>>>>>>>>
            int& operator * ();

            // <<<<<<<<<<<<<<<<<< Prefix increment (++n) >>>>>>>>>>>>>>>>>>
            AscendingIterator& operator ++ ();

            // Compare operators.
            // <<<<<<<<<<<<<<<<<< Operator == >>>>>>>>>>>>>>>>>>
            bool operator == (const AscendingIterator&) const;
            // <<<<<<<<<<<<<<<<<< Operator != >>>>>>>>>>>>>>>>>>
            bool operator != (const AscendingIterator&) const;
            // <<<<<<<<<<<<<<<<<< Operator > >>>>>>>>>>>>>>>>>>
            bool operator > (const AscendingIterator&) const;
            // <<<<<<<<<<<<<<<<<< Operator < >>>>>>>>>>>>>>>>>>
            bool operator < (const AscendingIterator&) const;

            // Begin and end operators.
            AscendingIterator begin () const;
            AscendingIterator end () const;

            // For Tidy.
            AscendingIterator(AscendingIterator&&) noexcept; // Move Constructor.
            AscendingIterator& operator = (AscendingIterator&&) noexcept; // Move assignment operator.
        };

        // --------------------------- Class: SideCrossIterator ---------------------------
        class SideCrossIterator {
        private:
            MagicalContainer& _container;
            size_t _index;

        public:
            // Constructors.
            SideCrossIterator (MagicalContainer& container, size_t index = 0); // Default.
            SideCrossIterator (const SideCrossIterator&); // Copy.

            // Destructor.
            ~SideCrossIterator () = default;

            // <<<<<<<<<<<<<<<<<< Operator = >>>>>>>>>>>>>>>>>>
            SideCrossIterator &operator = (const SideCrossIterator&);

            // <<<<<<<<<<<<<<<<<< Operator * >>>>>>>>>>>>>>>>>>
            int &operator * ();

            // <<<<<<<<<<<<<<<<<< Prefix increment (++n) >>>>>>>>>>>>>>>>>>
            SideCrossIterator& operator ++ ();

            // Compare operators.
            // <<<<<<<<<<<<<<<<<< Operator == >>>>>>>>>>>>>>>>>>
            bool operator == (const SideCrossIterator&) const;
            // <<<<<<<<<<<<<<<<<< Operator != >>>>>>>>>>>>>>>>>>
            bool operator != (const SideCrossIterator&) const;
            // <<<<<<<<<<<<<<<<<< Operator > >>>>>>>>>>>>>>>>>>
            bool operator > (const SideCrossIterator&) const;
            // <<<<<<<<<<<<<<<<<< Operator < >>>>>>>>>>>>>>>>>>
            bool operator < (const SideCrossIterator&) const;

            // Begin and end operators.
            SideCrossIterator begin () const;
            SideCrossIterator end () const;

            // For Tidy.
            SideCrossIterator(SideCrossIterator&&) noexcept; // Move Constructor.
            SideCrossIterator& operator = (SideCrossIterator&&) noexcept; // Move assignment operator.
        };

        // --------------------------- Class: PrimeIterator ---------------------------
        class PrimeIterator {
        private:
            MagicalContainer& _container;
            size_t _index;

        public:
            // Constructors.
            PrimeIterator (MagicalContainer& container, size_t index = 0);
            PrimeIterator (const PrimeIterator&);

            // Destructor.
            ~PrimeIterator () = default;

            // Methods.
            static bool isPrime (int);

            // <<<<<<<<<<<<<<<<<< Operator = >>>>>>>>>>>>>>>>>>
            PrimeIterator& operator = (const PrimeIterator&);

            // <<<<<<<<<<<<<<<<<< Operator * >>>>>>>>>>>>>>>>>>
            int &operator * ();

            // <<<<<<<<<<<<<<<<<< Prefix increment (++n) >>>>>>>>>>>>>>>>>>
            PrimeIterator &operator ++ ();

            // Compare operators.
            // <<<<<<<<<<<<<<<<<< Operator == >>>>>>>>>>>>>>>>>>
            bool operator == (const PrimeIterator&) const;
            // <<<<<<<<<<<<<<<<<< Operator != >>>>>>>>>>>>>>>>>>
            bool operator != (const PrimeIterator&) const;
            // <<<<<<<<<<<<<<<<<< Operator > >>>>>>>>>>>>>>>>>>
            bool operator > (const PrimeIterator&) const;
            // <<<<<<<<<<<<<<<<<< Operator < >>>>>>>>>>>>>>>>>>
            bool operator < (const PrimeIterator&) const;

            // Begin and end operators.
            PrimeIterator begin () const;
            PrimeIterator end () const;

            // For Tidy.
            PrimeIterator(PrimeIterator&&) noexcept; // Move Constructor.
            PrimeIterator& operator = (PrimeIterator&&) noexcept; // Move assignment operator.
        };
    };
}
#endif //SP2_EX5A_MAGICALCONTAINER_H