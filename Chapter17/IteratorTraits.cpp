#include <vector>
#include <iterator>
#include <iostream>

template <typename IteratorType>
void iteratorTraitsTest(IteratorType it)
{
    // OH, HERE, WE USE THE ITERATOR'S TYPE TO GET THE VALUE TYPE

    std::cout << "iterator type " << ":" << typeid(it).name() << std::endl;

    // The typename keyword is necessary in this context because you are dealing with a dependent type inside a template
    // function. The compiler cannot know whether the type IteratorType::value_type is a type or a static member variable.

    // the std::iterator_traits<IteratorType> construct is a helper class that provides a uniform interface to the properties of iterators.
    typename std::iterator_traits<IteratorType>::value_type temp;
    std::cout << "value type " << ":" << typeid(temp).name() << std::endl;
    temp = *it;
    std::cout << temp << std::endl;
}

int main() {
    std::vector<int> v { 5 };

    // WHAT IS ITERATOR_TRAITS?


    iteratorTraitsTest(std::cbegin(v));

    int i = 1;

    std::cout << "int type: " << typeid(i).name() << std::endl;
}