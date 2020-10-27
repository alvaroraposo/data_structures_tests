#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <math.h>
#include <cmath>
#include <string_view>


namespace A { 
    #include "algorithms/change_dp.cpp" 
}

namespace B { 
    #include "algorithms/primitive_calculator.cpp"
}

namespace C {
    #include "algorithms/edit_distance.cpp"
}

int main() {
    return C::main();
}
