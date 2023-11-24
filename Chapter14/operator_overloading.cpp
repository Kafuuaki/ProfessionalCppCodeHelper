// 1. type of operators
// 2. the capability of overloading operators
// 3. limitations of operator overloading
// 4. overloading operators as member functions or global functions, choosing
// argument type, return type, Choosing Behavior

int main() {

  // copy assignment operator
  // T& operator=(const T&);

  // move assignment operator
  // T& operator=(T&&);

  //   return move(lhs.append(rhs));
  //   or return move(rhs.insert(0, lhs));

  //   string operator+(const string& lhs, const string& rhs); // No memory
  //   reuse. string operator+(string&& lhs, const string& rhs); // Can reuse
  //   memory of lhs. string operator+(const string& lhs, string&& rhs); // Can
  //   reuse memory of rhs. string operator+(string&& lhs, string&& rhs); // Can
  //   reuse memory of lhs or rhs.

  //   template <class T> bool operator!=(const T &a,const T &b); Needs
  //   operator==
  //   template<class T> bool operator>(const T& a, const T& b); // Needs
  //   operator
  //   < template<class T> bool operator<=(const T& a, const T& b);// Needs
  //   operator<
  // template<class T> bool operator>=(const T& a, const T&b);// Needs operator<

  return 0;
}