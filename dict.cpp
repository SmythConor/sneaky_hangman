/* Class that will contain dict class */

//#include <iostream>
//#include <array>
//
//using namespace std;
//
//int main() {
//  int size = 6;
//  array<int,size> well;
//  well.fill(5);
//
//  for(int& x : well) {
//    cout << ' ' << x;
//  }
//
//  cout << endl;
//}
#include <iostream>
#include <array>

int main () {
  std::array<int,6> myarray;

  myarray.fill(5);

  std::cout << "myarray contains:";
  for ( int& x : myarray) { std::cout << ' ' << x; }

  std::cout << '\n';

  return 0;
}
~                                                                                                                                           
~                
