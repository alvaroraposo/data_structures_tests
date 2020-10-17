#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include <sstream>

namespace A { 
    #include "algorithms/change.cpp" 
}

namespace B {
    #include "algorithms/fractional_knapsack.cpp" 
}

namespace C {
    #include "algorithms/car_fueling.cpp" 
}

namespace D {
    #include "algorithms/dot_product.cpp" 
}

namespace E {
    #include "algorithms/covering_segments.cpp" 
}

namespace F {
    #include "algorithms/different_summands.cpp" 
}

namespace G {
    #include "algorithms/largest_number.cpp" 
}

int main() {
    return G::main();
}
