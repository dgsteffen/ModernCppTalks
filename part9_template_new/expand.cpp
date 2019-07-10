#include <iostream>
using namespace std;

template<typename T>
void print_impl(const T& t) { cout << t << ' '; }

template<typename ...Ts>
void print (const Ts& ...ts)
{

   (void)initializer_list<int> { (print_impl(ts), 0)... };
   cout << endl;
}

template<typename... Ts>
void expand(Ts... vs)
{
   (void) initializer_list<int> 
   { 
      //( print(vs...), 0) //one line
      //( print(vs), 0)... //separate

      //( print(vs..., vs...), 0)
      //( print(vs..., vs), 0)...
      ( print(vs, vs), 0)...
      //( print(vs, vs, vs), 0)...
      //( print(vs, vs..., vs), 0)...
   }; 
}


int main()
{
   expand ("HI", true, 42);
}
   
