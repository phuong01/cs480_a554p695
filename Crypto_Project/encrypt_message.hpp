/*Name: Phuong Hoang
WSU ID: A554P695
Program #: Final Project
Desciption: Create an Encrypt_message class that asks the user for a secret meesage. The program encrypts and decrypts the message. 
It will throw an out_of_bounds error if the message goes out of bounds.
Pseudo code:
   Data:
      size - represents the size of the message array
      message - message array of character type
   Functions:
      default constructor
      overloaded constructor one -accepts the size of the array and a value to
      initialize the message. Default initiazation = 0
      destructor- destorys data after used
      Member functions:
         get_message_size - gets message size from private Data
         operator[]-overloaded operator that returns the array
         const operator[] - overloads the []
         encrypt - Uses Caesar Cipher to encrypt the message
         decrypt - Uses Caesar Cipher to decrypt the message
         operator<< - friend function that overloads the ouput
*/

#include <iostream>
#ifndef __ENCRYPT_MESSAGE_HPP__
#define __ENCRYPT_MESSAGE_HPP__
using namespace std;

namespace Cryptography_message
{
  class Encrypt_message
  {
    private:
    int size;
    char *message;
    public:
    Encrypt_message();
    Encrypt_message(int s, char mess = 0);
    ~Encrypt_message();
    int get_message_size() const { return size;}
    char & operator[](int x);
    const char & operator[] (int x) const;
    void encrypt();
    void decrypt();
    friend ostream& operator<<(ostream& os, const Encrypt_message& a)
    {
      int i;
      for(i = 0; i<a.get_message_size(); i++)
      {
        os<<a.message[i];
      }
      return os;
    }
  };
  
}

#endif