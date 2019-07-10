
int main(int argc, char** argv)
{
int input = argc;

   if (input == 1) return 13;
   if (input ==2 ) return 17;
   if (input == 3) return 23;
   return 42;

   
}

////////////////////////////////////////////////////////////////////////////////

struct Camel { static constexpr int type = 1; };
struct Horse { static constexpr int type = 2; };
struct Rhino { static constexpr int type = 3; };

inline int HandleMsg(Camel&) { return 13;}
inline int HandleMsg(Horse&) { return 17;}
inline int HandleMsg(Rhino&) { return 23;}

template<typename T> int Dispatch()
{
   T t;
   return HandleMsg(t);
} 

template<typename ThisOne, typename... TheOthers>
struct Dispatcher
{
   static int eval(int input)
      {
         if (input == ThisOne::type)
            return Dispatch<ThisOne>();            
         else
            return Dispatcher<TheOthers...>::eval(input);
      }
};

template<typename T> struct Dispatcher<T> 
{ 
   static int eval(int input) 
      { 
         if (input == T::type) return Dispatch<T>();
         return -1;
      }
};

int main(int argc, char** argv)
{
   int input = argc;

   return Dispatcher<Camel, Horse, Rhino>::eval(input);

   
}




//////

struct Camel { static constexpr int type = 1; };
struct Horse { static constexpr int type = 2; };
struct Rhino { static constexpr int type = 3; };

inline int HandleMsg(Camel&) { return 13;}
inline int HandleMsg(Horse&) { return 17;}
inline int HandleMsg(Rhino&) { return 23;}
template<typename T> int Dispatch()
{
      T t;
      return HandleMsg(t);
} 

int main(int argc, char** argv)
{
   int input = argc;
   
   if (input == Camel::type) return Dispatch<Camel>();
   if (input == Horse::type) return Dispatch<Horse>();
   if (input == Rhino::type) return Dispatch<Rhino>();
   return -1;

   
}
