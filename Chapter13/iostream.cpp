#include <cstring>
#include <iostream>

using namespace std;

// why the data is not reading
// why the flush does not print out
void getReservationData() {
  string guestName;
  int partySize;
  cout << "Name and number of guests: ";
  cin >> guestName >> partySize;
  cout << "Thank you, " << guestName << "." << endl;
  if (partySize > 10) {
    cout << "An extra gratuity will apply." << endl;
  }
}

int main() {

  using std::cerr;
  using std::cin;
  using std::cout;
  using std::endl;

  int i{7};

  // character output stream
  //   writing to console

  //   << return a reference to the stream
  std::cout << i << std::endl;
  char ch{'a'};
  std::cout << ch << std::endl;
  std::string myString{"Hello World."};
  std::cout << myString << std::endl;

  // c style string
  const char *test{"hello there\n"};
  cout.write(test, strlen(test));

  cout.put('a');

  // the a will not be printed without flush, meeting \n or endl the stream will
  // be flushed
  cout.put('\n');

  cout << "abc";
  cout.flush();

  cout.flush();
  if (cout.fail()) {
    cerr << "Unable to flush to standard out" << endl;
  }

  cout.flush();
  if (!cout) {
    cerr << "Unable to flush to standard out" << endl;
  }

  cout.exceptions(std::ios::failbit | std::ios::badbit | std::ios::eofbit);
  try {
    cout << "Hello World." << endl;
  } catch (const std::ios_base::failure &ex) {
    cerr << "Caught exception: " << ex.what() << ", error code = " << ex.code()
         << endl;
  }

  // cout to reset the error state
  cout.clear();

  int userInput;
  cin >> userInput;
  cout << "User input was " << userInput << endl;

  // why the data is not reading
  getReservationData();

  //   if (cout.good()) {
  //     cout << "cout is good" << endl;
  //   }

  //   cout.flush();
  //   cout << "\n";

  // wired, "abc" is not printed

  // cout << "def";
  // cout << endl;
  // abc is written to the console.
  // def is written to the console.

  return 0;
}
