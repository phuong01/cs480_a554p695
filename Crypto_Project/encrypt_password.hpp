/*Name: Phuong Hoang
WSU ID: A554P695
Program #: Final Project
Desciption: Create an Encrypt_password class that asks the user for password. The program encrypts and decrypts the message. 
It will output encrypted password to a file when you exit the program.
Pseudo code:
   Member Functions:
      default constructor
      overloaded constructor one -accepts the size of the array and a value to
      initialize the message. Default initiazation = 0
      destructor- destorys data after used
      Member functions:
         set_encrypted_password - sets the encrypted password and sends it to a file.
         verify_password - checks to make sure user's input meets the criteria
         set_new_password - sets new password as what user inputs if it meets the criteria
         encrypt - encrypts password using Caesar Cipher
         decrypt - decrypts password using Caesar Cipher
*/

#include <iostream>
#ifndef __ENCRYPT_PASSWORD_HPP__
#define __ENCRYPT_PASSWORD_HPP__
using namespace std;

namespace Cryptography_password
{
  class Encrypt_password
  {
    public:
      void set_encrypted_password(string encrypted_pass);
      bool verify_password(string password);
      bool set_new_password(string password);
      string encrypt(string password);
      string decrypt(string password);
  };
}
#endif