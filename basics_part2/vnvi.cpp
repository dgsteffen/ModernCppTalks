// This pure abstract interface creates a way
// for unit test suites to stub-out Foo objects
class FooInterface
{
public:
   virtual void DoSomething() = 0;
private:
   virtual void DoSomethingImpl() = 0;
};

// Implement Non-Virtual Interface Pattern in FooBase using final
// (Alternatively implement the Template Pattern in FooBase using final)
class FooBase : public FooInterface
{
public:
    virtual void DoSomething() final { DoFirst(); DoSomethingImpl(); DoLast(); }
private:
    virtual void DoSomethingImpl() { /* left for derived classes to customize */ }
    void DoFirst(); // no derived customization allowed here
    void DoLast(); // no derived customization allowed here either
};

// Feel secure knowing that unit test suites can stub you out at the FooInterface level
// if necessary
// Feel doubly secure knowing that your children cannot violate your Template Pattern
// When DoSomething is called from a FooBase * you know without a doubt that
// DoFirst will execute before DoSomethingImpl, and DoLast will execute after.
class FooDerived : public FooBase
{
private:
    virtual void DoSomethingImpl() {/* customize DoSomething at this location */}
};
