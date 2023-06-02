// Created by Shalev Ben David.
#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <stdexcept>
using namespace std;
using namespace ariel;

TEST_CASE("Case 1: Adding Elements To The Container.") {
    MagicalContainer container;

    // ---- Testing: Adding the same element a couple of times.
    // ---- Expecting: Should work.
    SUBCASE("Adding The Same Item") {
        int x = 1;
        container.addElement(x);
        CHECK_NOTHROW(container.addElement(x));
        CHECK_NOTHROW(container.addElement(x));
        CHECK_EQ(container.size(), 3);
    }

    // ---- Testing: Adding double to container.
    // ---- Expecting: Should cast to int and work.
    SUBCASE("Adding Double Type") {
        double x = 1;
        CHECK_NOTHROW(container.addElement(x));
        CHECK_EQ(container.size(), 1);
    }
}

TEST_CASE("Case 2: Removing Elements From The Container.") {
    MagicalContainer container;

    // ---- Testing: Removing item from an empty container.
    // ---- Expecting: Should throw exception.
    CHECK_THROWS(container.removeElement(-1));

    // Add elements to the container.
    container.addElement(1);
    container.addElement(2);

    // ---- Testing: Removing items completely from the container.
    // ---- Expecting: Should work.
    SUBCASE("Emptying The Container") {
        CHECK_NOTHROW(container.removeElement(1));
        CHECK_NOTHROW(container.removeElement(2));
        CHECK_EQ(container.size(), 0);
    }

    // ---- Testing: Removing a number which isn't in the container.
    // ---- Expecting: Should throw.
    SUBCASE("Removing non-existing item") {
        CHECK_THROWS(container.removeElement(-100));
        CHECK_THROWS(container.removeElement(100));
    }
}

TEST_CASE("Case 3: Checking Size Of Container.") {
    MagicalContainer container;

    // ---- Testing: Checking size at the beginning.
    // ---- Expecting: Should be 0.
    SUBCASE("Size At Initialization") {
        CHECK_EQ(container.size(), 0);
    }

    // ---- Testing: Checking size After adding and removing items.
    // ---- Expecting: Should be set accordingly.
    SUBCASE("Size Through Adding/Deleting") {
        container.addElement(5);
        CHECK_EQ(container.size(), 1);
        container.addElement(1);
        container.addElement(3);
        CHECK_EQ(container.size(), 3);

        container.removeElement(5);
        container.removeElement(1);
        container.removeElement(3);
        CHECK_EQ(container.size(), 0);
    }
}

TEST_CASE("Case 3: Check AscendingIterator.") {
    MagicalContainer container;
    MagicalContainer :: AscendingIterator ascIter(container);

    // Adding elements.
    container.addElement(5);
    container.addElement(10);
    container.addElement(0);
    container.addElement(15);


    // ---- Testing: Iterating over the container with AscendingIterator.
    // ---- Expecting: Should be as following: 0, 5, 10, 15.
    SUBCASE("Iterating In Ascending Order") {
        CHECK_EQ(*ascIter, 0);
        ++ascIter;
        CHECK_EQ(*ascIter, 5);
        ++ascIter;
        CHECK_EQ(*ascIter, 10);
        ++ascIter;
        CHECK_EQ(*ascIter, 15);
    }

    // ---- Testing: Iterating while removing.
    // ---- Expecting: Should be set accordingly.
    SUBCASE("Deleting Items While Iterating") {
        // Should point to 0.
        MagicalContainer :: AscendingIterator ascIter1(container);
        CHECK_EQ(*ascIter1, 0);

        // Should point to 5.
        ++ascIter1;
        CHECK_EQ(*ascIter1, 5);

        // ---- Testing: Deleting 0 (previous item).
        // ---- Expecting: Shouldn't have effect on iterator.
        container.removeElement(0);
        CHECK_EQ(container.size(), 3);
        CHECK_EQ(*ascIter1, 5);

        // ---- Testing: Deleting 10 (next item).
        // ---- Expecting: ++ should iterate to 15.
        container.removeElement(10);
        CHECK_EQ(container.size(), 2);
        CHECK_EQ(*ascIter1, 5);
        ++ascIter1;
        CHECK_EQ(*ascIter1, 15);
    }

    container.addElement(0);
    container.addElement(10);

    // ---- Testing: Iterating while adding.
    // ---- Expecting: Should be set accordingly.
    SUBCASE("Adding Items While Iterating") {
        // Should point to 0.
        MagicalContainer :: AscendingIterator ascIter1(container);
        CHECK_EQ(*ascIter1, 0);

        // ---- Testing: Adding 3.
        // ---- Expecting: ++ should iterate to 3.
        container.addElement(3);
        CHECK_EQ(container.size(), 5);
        CHECK_EQ(*ascIter1, 0);
        ++ascIter1;
        CHECK_EQ(*ascIter1, 3);

        // ---- Testing: Adding 2 (previous item).
        // ---- Expecting: Shouldn't have effect on iterator.
        container.addElement(2);
        CHECK_EQ(container.size(), 6);
        CHECK_EQ(*ascIter1, 3);
    }
}

TEST_CASE("Case 4: Check SideCrossIterator.") {
    MagicalContainer container;
    MagicalContainer :: SideCrossIterator crossIter(container);

    // Adding elements.
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);

    // ---- Testing: Iterating over the container with crossIter.
    // ---- Expecting: Should be as following: 1, 4, 2, 3.
    SUBCASE("Iterating In Side Cross Order") {
        CHECK_EQ(*crossIter, 1);
        ++crossIter;
        CHECK_EQ(*crossIter, 4);
        ++crossIter;
        CHECK_EQ(*crossIter, 2);
        ++crossIter;
        CHECK_EQ(*crossIter, 3);
    }

    // ---- Testing: Iterating while removing.
    // ---- Expecting: Should be set accordingly.
    SUBCASE("Deleting Items While Iterating") {
        // Should point to 1.
        MagicalContainer :: SideCrossIterator crossIter1(container);
        CHECK_EQ(*crossIter1, 1);

        // Should point to 4.
        ++crossIter1;
        CHECK_EQ(*crossIter1, 4);

        // ---- Testing: Deleting 1 (previous item).
        // ---- Expecting: Shouldn't have effect on iterator.
        container.removeElement(1);
        CHECK_EQ(container.size(), 3);
        CHECK_EQ(*crossIter1, 4);

        // ---- Testing: Deleting 2 (next item).
        // ---- Expecting: ++ should iterate to 3.
        container.removeElement(2);
        CHECK_EQ(container.size(), 2);
        CHECK_EQ(*crossIter1, 4);
        ++crossIter1;
        CHECK_EQ(*crossIter1, 3);
    }

    // ---- Testing: Iterating while adding.
    // ---- Expecting: Should be set accordingly.
    SUBCASE("Adding Items While Iterating") {
        // Should point to 1.
        MagicalContainer :: SideCrossIterator crossIter1(container);
        CHECK_EQ(*crossIter1, 1);

        // ---- Testing: Adding 6 (next item).
        // ---- Expecting: ++ should iterate to 6.
        container.addElement(6);
        CHECK_EQ(container.size(), 5);
        CHECK_EQ(*crossIter1, 1);
        ++crossIter1;
        CHECK_EQ(*crossIter1, 6);

        // ---- Testing: Adding 10 (previous item).
        // ---- Expecting: Shouldn't have effect on iterator.
        container.addElement(10);
        CHECK_EQ(container.size(), 6);
        CHECK_EQ(*crossIter1, 6);
        ++crossIter1;
        CHECK_EQ(*crossIter1, 2);
    }
}

TEST_CASE("Case 5: General Tests For PrimeIterator.") {
    MagicalContainer container;
    MagicalContainer :: PrimeIterator primeIter(container);

    // Adding elements.
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);


    // ---- Testing: Iterating over the container with PrimeIterator.
    // ---- Expecting: Should be as following: 2, 3, 5.
    SUBCASE("Iterating In Prime Order") {
        CHECK_EQ(*primeIter, 2);
        ++primeIter;
        CHECK_EQ(*primeIter, 3);
        ++primeIter;
        CHECK_EQ(*primeIter, 5);
    }

    // ---- Testing: Iterating while removing.
    // ---- Expecting: Should be set accordingly.
    SUBCASE("Deleting Items While Iterating") {
        // Should point to 2.
        MagicalContainer :: PrimeIterator primeIter1(container);
        CHECK_EQ(*primeIter1, 2);

        // Should point to 3.
        ++primeIter1;
        CHECK_EQ(*primeIter1, 3);

        // ---- Testing: Deleting 2 (previous item).
        // ---- Expecting: Shouldn't have effect on iterator.
        container.removeElement(2);
        CHECK_EQ(container.size(), 4);
        CHECK_EQ(*primeIter1, 3);

        // ---- Testing: Deleting 5 (next item).
        // ---- Expecting: ++ should iterate to the end.
        container.removeElement(5);
        CHECK_EQ(container.size(), 3);
        CHECK_EQ(*primeIter1, 3);
        ++primeIter1;
        CHECK_EQ(primeIter1, primeIter1.end());
    }

    // ---- Testing: Iterating while adding.
    // ---- Expecting: Should be set accordingly.
    SUBCASE("Adding Items While Iterating") {
        // Should point to 5.
        MagicalContainer :: PrimeIterator primeIter1(container);
        ++primeIter; ++primeIter1;
        CHECK_EQ(*primeIter1, 5);

        // ---- Testing: Adding 11 (next item).
        // ---- Expecting: ++ should iterate to 11.
        container.addElement(11);
        CHECK_EQ(container.size(), 6);
        CHECK_EQ(*primeIter1, 5);
        ++primeIter1;
        CHECK_EQ(*primeIter1, 11);

        // ---- Testing: Adding 7 (previous item).
        // ---- Expecting: Shouldn't have effect on iterator.
        container.addElement(7);
        CHECK_EQ(container.size(), 7);
        CHECK_EQ(*primeIter1, 11);
        ++primeIter1;
        CHECK_EQ(primeIter1, primeIter1.end());
    }
}

TEST_CASE("Case 6: ==, !=, >, < Tests For AscendingIterator.") {
    MagicalContainer container1;
    MagicalContainer container2;

    // Adding elements.
    container1.addElement(5);
    container1.addElement(10);
    container2.addElement(5);

    // ---- Testing: Comparing between iterators with different containers.
    // ---- Expecting: Should throw as runtime error.
    SUBCASE("Comparing Iterators With Different Containers ") {
//        MagicalContainer :: AscendingIterator ascIter1(container1);
//        MagicalContainer :: AscendingIterator ascIter2(container2);
//        CHECK_THROWS(ascIter1 == ascIter2);
//        CHECK_THROWS(ascIter1 != ascIter2);
//        CHECK_THROWS(ascIter1 > ascIter2);
//        CHECK_THROWS(ascIter1 < ascIter2);
    }

    // ---- Testing: Comparing between iterators.
    // ---- Expecting: Should work as expected.
    SUBCASE("Comparing Ascending Iterators") {
        MagicalContainer :: AscendingIterator ascIter1(container1);
        MagicalContainer :: AscendingIterator ascIter2(container1);
        // ---- Testing: Comparing at initialization.
        // ---- Expecting: ascIter1 == ascIter2.
        CHECK(ascIter1 == ascIter2);
        CHECK_FALSE(ascIter1 != ascIter2);
        CHECK_FALSE(ascIter1 > ascIter2);
        CHECK_FALSE(ascIter1 < ascIter2);

        ++ascIter2;

        // ---- Testing: After iterating ascIter2 to next item.
        // ---- Expecting: ascIter2 > ascIter1.
        CHECK_FALSE(ascIter1 == ascIter2);
        CHECK(ascIter1 != ascIter2);
        CHECK_FALSE(ascIter1 > ascIter2);
        CHECK(ascIter1 < ascIter2);
    }
}

TEST_CASE("Case 7: ==, !=, >, < Tests For SideCrossIterator.") {
    MagicalContainer container1;
    MagicalContainer container2;

    // Adding elements.
    container1.addElement(5);
    container1.addElement(10);
    container2.addElement(5);

    // ---- Testing: Comparing between iterators with different containers.
    // ---- Expecting: Should throw as runtime error.
    SUBCASE("Comparing Iterators With Different Containers ") {
        MagicalContainer :: SideCrossIterator ascIter1(container1);
        MagicalContainer :: SideCrossIterator ascIter2(container2);
//        CHECK_THROWS(ascIter1 != ascIter2);
//        CHECK_THROWS(ascIter1 != ascIter2);
//        CHECK_THROWS(ascIter1 > ascIter2);
//        CHECK_THROWS(ascIter1 < ascIter2);
    }

    // ---- Testing: Comparing between iterators.
    // ---- Expecting: Should work as expected.
    SUBCASE("Comparing SideCross Iterators") {
        MagicalContainer :: SideCrossIterator ascIter1(container1);
        MagicalContainer :: SideCrossIterator ascIter2(container1);
        // ---- Testing: Comparing at initialization.
        // ---- Expecting: ascIter1 == ascIter2.
        CHECK(ascIter1 == ascIter2);
        CHECK_FALSE(ascIter1 != ascIter2);
        CHECK_FALSE(ascIter1 > ascIter2);
        CHECK_FALSE(ascIter1 < ascIter2);

        ++ascIter2;

        // ---- Testing: After iterating ascIter2 to next item.
        // ---- Expecting: ascIter2 > ascIter1.
        CHECK_FALSE(ascIter1 == ascIter2);
        CHECK(ascIter1 != ascIter2);
        CHECK_FALSE(ascIter1 > ascIter2);
        CHECK(ascIter1 < ascIter2);
    }
}

TEST_CASE("Case 8: ==, !=, >, < Tests For PrimeIterator.") {
    MagicalContainer container1;
    MagicalContainer container2;

    // Adding elements.
    container1.addElement(2);
    container1.addElement(3);
    container2.addElement(2);

    // ---- Testing: Comparing between iterators with different containers.
    // ---- Expecting: Should throw as runtime error.
    SUBCASE("Comparing Iterators With Different Containers ") {
        MagicalContainer :: PrimeIterator ascIter1(container1);
        MagicalContainer :: PrimeIterator ascIter2(container2);
//        CHECK_THROWS(ascIter1 == ascIter2);
//        CHECK_THROWS(ascIter1 != ascIter2);
//        CHECK_THROWS(ascIter1 > ascIter2);
//        CHECK_THROWS(ascIter1 < ascIter2);
    }

    // ---- Testing: Comparing between iterators.
    // ---- Expecting: Should work as expected.
    SUBCASE("Comparing SideCross Iterators") {
        MagicalContainer :: PrimeIterator ascIter1(container1);
        MagicalContainer :: PrimeIterator ascIter2(container1);
        // ---- Testing: Comparing at initialization.
        // ---- Expecting: ascIter1 == ascIter2.
        CHECK(ascIter1 == ascIter2);
        CHECK_FALSE(ascIter1 != ascIter2);
        CHECK_FALSE(ascIter1 > ascIter2);
        CHECK_FALSE(ascIter1 < ascIter2);

        ++ascIter2;

        // ---- Testing: After iterating ascIter2 to next item.
        // ---- Expecting: ascIter2 > ascIter1.
        CHECK_FALSE(ascIter1 == ascIter2);
        CHECK(ascIter1 != ascIter2);
        CHECK_FALSE(ascIter1 > ascIter2);
        CHECK(ascIter1 < ascIter2);
    }
}

TEST_CASE("Case 9: Comparing Different Iterators") {
    MagicalContainer container;
    MagicalContainer :: AscendingIterator ascIter(container);
    MagicalContainer :: SideCrossIterator crossIter(container);
    MagicalContainer :: PrimeIterator primeIter(container);

    container.addElement(2);

    // ---- Testing: Comparing begin() and end() of different type iterators.
    // ---- Expecting: Should throw as runtime error.
    SUBCASE("Comparing begin() and end()") {
//        CHECK_THROWS(ascIter.begin() == crossIter.begin());
//        CHECK_THROWS(crossIter.end() == primeIter.end());
    }

    // ---- Testing: Comparing different type iterators.
    // ---- Expecting: Should throw as runtime error.
    SUBCASE("Comparing begin() and end()") {
//        CHECK_THROWS(ascIter == crossIter);
//        CHECK_THROWS(crossIter == primeIter);
    }
}

TEST_CASE("Case 10: begin() And end() Checks") {
    MagicalContainer container;
    MagicalContainer :: AscendingIterator ascIter(container);
    MagicalContainer :: SideCrossIterator crossIter(container);
    MagicalContainer :: PrimeIterator primeIter(container);

    // ---- Testing: Comparing between iterators.
    // ---- Expecting: Should work as expected.
    SUBCASE("Checking At Start") {
        CHECK_EQ(ascIter, ascIter.begin());
        CHECK_EQ(ascIter, ascIter.end());
        CHECK_EQ(crossIter, crossIter.begin());
        CHECK_EQ(crossIter, crossIter.end());
        CHECK_EQ(primeIter, primeIter.begin());
        CHECK_EQ(primeIter, primeIter.end());
    }

    // Adding elements.
    container.addElement(2);
    CHECK_EQ(*ascIter, 2);
    CHECK_EQ(*crossIter, 2);
    CHECK_EQ(*primeIter, 2);
    ++ascIter;
    ++crossIter;
    ++primeIter;

    // ---- Testing: Iterating to the end().
    // ---- Expecting: Should be equal to the iterator bounds.
    SUBCASE("Checking After Iterating") {
        CHECK_EQ(ascIter, ascIter.end());
        CHECK_EQ(crossIter, crossIter.end());
        CHECK_EQ(primeIter, primeIter.end());
    }

    // ---- Testing: Performing ++ over end of iterator bounds.
    // ---- Expecting: Should throw as runtime error.
    SUBCASE("++ Over end()") {
        CHECK_THROWS(++ascIter.end());
        CHECK_THROWS(++crossIter.end());
        CHECK_THROWS(++primeIter.end());
    }

    MagicalContainer :: AscendingIterator ascIter1(container);
    MagicalContainer :: SideCrossIterator crossIter1(container);
    MagicalContainer :: PrimeIterator primeIter1(container);

    // ---- Testing: Comparing < with end().
    // ---- Expecting: Should work as expected.
    SUBCASE("Comparing") {
        CHECK_LT(ascIter1, ascIter);
        CHECK_LT(crossIter1, crossIter);
        CHECK_LT(primeIter1, primeIter);

        CHECK_LT(ascIter.begin(), ascIter.end());
        CHECK_LT(crossIter.begin(), crossIter.end());
        CHECK_LT(primeIter.begin(), primeIter.end());
    }
}

TEST_CASE("Case 11: Check Operator = ") {
    MagicalContainer container;
    MagicalContainer :: AscendingIterator ascIter1(container);

    container.addElement(2);
    container.addElement(3);

    ++ascIter1;
    CHECK_EQ(*ascIter1, 3);
    MagicalContainer :: AscendingIterator ascIter2 = ascIter1;
    CHECK_EQ(*ascIter2, 3);
}

TEST_CASE("Case 12: Copy constructor") {
    MagicalContainer container;
    MagicalContainer :: AscendingIterator ascIter1(container);

    container.addElement(2);
    container.addElement(3);

    ++ascIter1;
    CHECK_EQ(*ascIter1, 3);
    MagicalContainer :: AscendingIterator ascIter2(ascIter1);
    CHECK_EQ(*ascIter2, 3);
}