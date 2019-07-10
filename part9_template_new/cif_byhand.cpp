


int main(int argc, char** argv)
{
      char cha = argv[0][0];
      int ch = static_cast<int>(cha);

      if (ch == 1) return 11;
      else if (ch == 2) return 222;
      else if (ch == 3) return 33;
      return -1;
}


struct Camel { constexpr static char type = 1; constexpr static int res = 11;};
struct Horse { constexpr static char type = 2; constexpr static int res = 222;};
struct Rhino { constexpr static char type = 3; constexpr static int res = 33;};

int main(int argc, char** argv)
{
      char cha = argv[0][0];
      int ch = static_cast<int>(cha);

           if (ch == Camel::type) return  Camel::res;
      else if (ch == Horse::type)  return  Horse::res;
      else if (ch == Rhino::type)  return  Rhino::res;
     return -1;

        
}
