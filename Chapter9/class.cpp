#include <iostream>

class Foo;

class Bar {
  // ...
public:
  void processFoo(const Foo &) {}
  // ...
};

void printFoo(const Foo &foo) {
  std::cout << "printFoo in friend" << std::endl;
}

class Foo {
  //   friend class Bar;
  friend void Bar::processFoo(const Foo &);
  // ...
};

int main() {
  Foo foo;
  Bar bar;
  bar.processFoo(foo);
  printFoo(foo);
}