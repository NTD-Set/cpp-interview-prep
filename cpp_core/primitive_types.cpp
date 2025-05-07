//
// Created by td on 5/7/2025.
//

#include <cstdint>
#include <iostream>
#include <stdlib.h>
#include <bitset>   // For bit manipulation examples
#include <limits>


int main (){
    // ======================================================
    // RECOMMENDED: Using 'int' for general-purpose integers
    // ======================================================

    // Use 'int' when size doesn't matter
    int userAge = 25;                  // Age will always be a reasonable value

    // ======================================================
    // RECOMMENDED: Using fixed-width types when specific size guarantees are needed
    // ======================================================
       // GOOD: Use std::int32_t when you need a guaranteed 32-bit signed integer
    std::int32_t largeValue = 2000000000;  // Need guaranteed range for large values

    // GOOD: Use std::int64_t for very large values
    std::int64_t veryLargeValue = 9000000000000000000LL;

    std::cout << "32-bit integer value: " << largeValue << std::endl;
    std::cout << "64-bit integer value: " << veryLargeValue << std::endl;

    // GOOD: Use std::uint32_t for bit manipulation operations
    std::uint32_t bitFlags = 0x0000FFFF;  // 32-bit value for storing flags
    std::cout << "Bit flags: " << std::bitset<32>(bitFlags) << std::endl;

    // Set a specific bit without affecting others
    bitFlags |= (1U << 24);  // Set bit 24
    std::cout << "After setting bit 24: " << std::bitset<32>(bitFlags) << std::endl;

    // Clear a specific bit
    bitFlags &= ~(1U << 24);  // Clear bit 24
    std::cout << "After clearing bit 24: " << std::bitset<32>(bitFlags) << std::endl;

    // ======================================================
    // RECOMMENDED: Using unsigned types for well-defined wrap-around behavior
    // ======================================================
    // Example of wrap-around behavior (useful in certain algorithms)
    std::uint16_t counter16 = std::numeric_limits<std::uint16_t>::max();
    std::cout << "Counter: " << counter16 << std::endl;
    counter16++;
    std::cout << "Counter + 1: " << counter16 << std::endl; // This will wrap around to 0


    // AVOID: Using 8-bit integers except for specialized uses. Prefer 16 bits fixed-width integer instead
    std::int8_t tinyValue = 100;  // Often interacts poorly with iostream, may print as char

    // ======================================================
    // SIZING INFORMATION
    // ======================================================

    // Display the size of various integer types on this system
    std::cout << "\nSystem integer type sizes:\n";
    std::cout << "size of int: " << sizeof(int) << " bytes\n";
    std::cout << "size of int16_t: " << sizeof(std::int16_t) << " bytes\n";
    std::cout << "size of int32_t: " << sizeof(std::int32_t) << " bytes\n";
    std::cout << "size of int64_t: " << sizeof(std::int64_t) << " bytes\n";

    // Display range information for integer types
    std::cout << "\nInteger range information:\n";
    std::cout << "int range: " << std::numeric_limits<int>::min() << " to "
              << std::numeric_limits<int>::max() << std::endl;
    std::cout << "int32_t range: " << std::numeric_limits<std::int32_t>::min() << " to "
              << std::numeric_limits<std::int32_t>::max() << std::endl;
    std::cout << "uint32_t range: " << 0 << " to "
              << std::numeric_limits<std::uint32_t>::max() << std::endl;
              

    return EXIT_SUCCESS;
}
