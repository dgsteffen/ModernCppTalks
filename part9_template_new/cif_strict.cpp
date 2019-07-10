struct Camel { constexpr static char type = 1; };
struct Horse { constexpr static char type = 2; };
struct Rhino { constexpr static char type = 3; };





template<typename T, typename ...Ts>
struct cif 
{
   static int eval( char i)
      {
         if (i == T::type) return T::type*11;
         else if (sizeof...(Ts) == 0) return -1;
         else return cif<Ts...>::eval(i);

      }
};



int main(int argc, char** argv)
{
   char c = argv[0][0];
   return cif<Camel, Horse, Rhino>(c);
     
}
