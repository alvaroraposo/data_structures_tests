#include <iostream>
#include <vector>
#include <algorithm>

namespace A { 
    #include "algorithms/fibonacci.cpp" 
}

namespace B {
    #include "algorithms/fibonacci_last_digit.cpp" 
}

namespace C {
    #include "algorithms/gcd.cpp" 
}

namespace D {
    #include "algorithms/lcm.cpp" 
}

namespace E {
    #include "algorithms/fibonacci_huge.cpp" 
}

namespace F {
    #include "algorithms/fibonacci_sum_last_digit.cpp" 
}

namespace G {
    #include "algorithms/fibonacci_partial_sum.cpp" 
}

namespace H {
    #include "algorithms/fibonacci_sum_squares.cpp" 
}

int main() {
    return H::main();
}
