#include "../include/figure.h"

Figure::Figure() noexcept: dots(0) {}

bool Figure::operator == (const Figure& other) const  
{
    return dots == other.dots;
}
