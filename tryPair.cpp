#include <iostream>
using namespace std;
#include "Dog.h"
    
    template <class T>
    struct Pair {
      T x;
      T y;
    
      Pair(T val1, T val2) { x = val1;  y = val2; }
    };
    
    
    int main() {
	Dog h,g;
	Pair<Dog> p(h,g);
    
	p.x.get_name();
	p.y.get_name;
    }

