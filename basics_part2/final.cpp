// put up on godbolt...

class A {
public:
    virtual void f() = 0;
};

class B : public A {
public:
    void f() final override;
};

void foo(B& b) {
    b.f();
}


or


class A {
public:
    virtual void f() = 0;
};

class B : public A {
public:
    void f() final override;
};

class C : public A {
public:
    void f() override;
};

void foo(B& b) {
    b.f();
}

void bar(C& c) {
    c.f();
}


https://gcc.godbolt.org/#compilers:!((compiler:g6,options:'-O2+-Wall++-xc%2B%2B+-std%3Dc%2B%2B11',sourcez:MYGwhgzhAECC0G8BQAHArgIxAS2ALiWiOgDdsAnAFzTBFIHtsATaAMwAoBKaAXmgAYA3EgC%2BwpKEgwAQtDzR0WXHESpMOfIWIlGLDt1bYAdrWj0SAU3LlmF4WKQTwUaAGE5C9cvjJFGgsQMzGxcZpbWtvbiOsGs9PTs0gBk0BjcyIEYAHT69o4xLBhg5OyuKcDpWkTAOVz2QAA%3D%3D)),filterAsm:(commentOnly:!t,directives:!t,intel:!t,labels:!t),version:3
