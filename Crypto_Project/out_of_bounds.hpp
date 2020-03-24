/* Name: Phuong Hoang
WSU ID: A554P695
Program #: Final Project
Desciption: Check for errors in the Encrypt_message class and throw exceptions
when necessary. You will need to write a Out_of_bounds_exception class for the
out of bounds error.

Pseudo code:
   Function:
      out of bound exception - checks for when array size is out of bound and
      returns out of bounds exception message in the main but continues running
      the program
*/

#ifndef __OUT_OF_BOUNDS_HPP__
#define __OUT_OF_BOUNDS_HPP__
#include <iostream>
#include <exception>
using namespace std;
namespace Bounds
{
  class Out_of_bounds_exception : public exception
  {
    public:
    const char * what() const throw()
    {
      return "Out of bounds exception \n";
    }
  };
}
#endif