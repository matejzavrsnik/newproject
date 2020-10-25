#include <iostream>

#include "lib.h"

#include "another.h"

int main()
{
   auto result = ProjectLib::sum(1.0, 2.0);
   std::cout << result << std::endl;
   std::cout << ProjectApp::mul(2, 3) << std::endl;
   return 0;
}
