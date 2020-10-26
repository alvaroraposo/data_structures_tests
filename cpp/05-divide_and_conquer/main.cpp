#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <math.h>
#include <cmath> 

namespace A { 
    #include "algorithms/binary_search.cpp" 
}

namespace B { 
    #include "algorithms/majority_element.cpp" 
}

namespace C { 
    #include "algorithms/sorting.cpp" 
}

namespace D { 
    #include "algorithms/inversions.cpp" 
}

namespace E { 
    #include "algorithms/points_and_segments.cpp" 
}

namespace F { 
    #include "algorithms/closest.cpp" 
}

int main() {
    return F::main();
}
