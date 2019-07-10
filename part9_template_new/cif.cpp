struct Camel { constexpr static char type = 1; };
struct Horse { constexpr static char type = 2; };
struct Rhino { constexpr static char type = 3; };

template<typename T> constexpr int ResultOf(const T&) { return -1 ; }

template<> constexpr int ResultOf<Camel>(const Camel&) { return 11; }
template<> constexpr int ResultOf<Horse>(const Horse&) { return 222; }
template<> constexpr int ResultOf<Rhino>(const Rhino&) { return 33; }


constexpr int print(int input) { return -1; }

template<typename T, typename ...Ts>
int print (int input, const T& t, const Ts& ...ts)
{
   if (input == T::type)
   {
      T t;
      return ResultOf(t);
   }
   return print(input, ts...);
}



int main(int argc, char** argv)
{
   
   char cha = argv[0][0];
   int ch = static_cast<int>(cha);

   Camel C;
   Horse H;
   Rhino R;

   return print(ch, C, H, R);
}


... or

struct Camel { constexpr static char type = 1; constexpr static int res = 11;};
struct Horse { constexpr static char type = 2; constexpr static int res = 222;};
struct Rhino { constexpr static char type = 3; constexpr static int res = 338;};

template<typename T> struct res { enum {r=-1}; };
template<> struct res<Camel> { enum {r=11}; };
template<> struct res<Horse> { enum {r=222}; };
template<> struct res<Rhino> { enum {r=338}; };
constexpr int print(int input) { return -1; }

template<typename T, typename ...Ts>
int print (int input, const T& t, const Ts& ...ts)
{
   if (input == T::type)
   {
      return res<T>::r;
   }
   return print(input, ts...);
}



int main(int argc, char** argv)
{
   
   char cha = argv[0][0];
   int ch = static_cast<int>(cha);

   Camel C;
   Horse H;
   Rhino R;

   return print(ch, C, H, R);
}
