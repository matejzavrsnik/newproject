#include "../include/lib.h"

#include "internal.h"

namespace ProjectLib
{
   double sum(double a, double b)
   {
      return Internal::sumImplementation(a, b);
   }
}
