#include <type_traits>

using namespace std;

template<typename T> int foo(T t)
{
   if ( is_pointer<T>::value)
      return 5;
   return 16;
}

int main() 
{
   int * i;
   return foo(*i);
}
