struct complex_num {
   constexpr complex_num() : re(0), im(0) {}
   constexpr complex_num(double r, double i)
        : re(r), im(i) {}

   constexpr double abs_squared() const { return re*re+im*im; }
  
   double re;
   double im;   
};

double main()
{
   constexpr complex_num c(3,4);
   return c.abs_squared();
}
