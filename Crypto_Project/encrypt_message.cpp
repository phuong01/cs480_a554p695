/*Name: Phuong Hoang
WSU ID: A554P695
Program #: Final Project
Desciption: Create an Encrypt_message class that asks the user for a secret meesage. The program encrypts and decrypts the message. 
It will throw an out_of_bounds error if there is
*/
#include <iostream>
#include "encrypt_message.hpp"
#include <exception>
#include "out_of_bounds.hpp"
using namespace std;

//sets size to 0 and message array to NULL
Cryptography_message::Encrypt_message::Encrypt_message()
{
  message = NULL;
  size = 0;
}

//accepts the size of the array and a value to initialize the message
Cryptography_message::Encrypt_message::Encrypt_message(int s, char mess)
{
  message = new char[s];
  size = s;
  /*for(int i=0; i<size; i++)
  {
    message[i] = mess;
  }*/
}

//destorys data after used
Cryptography_message::Encrypt_message::~Encrypt_message()
{
  if(message != NULL)
    delete[] message;
}

//overloaded operator that returns the array
char& Cryptography_message::Encrypt_message::operator[](int x)
{
  if(x<0 || x>=size)
  {
    using namespace Bounds;
    throw Out_of_bounds_exception();
  }
  return message[x];
}

//overloads the []
const char& Cryptography_message::Encrypt_message::operator[] (int x) const
{
  if(x<0 || x>=size)
  {
    using namespace Bounds;
    throw Out_of_bounds_exception();
  }
  return message[x];
}

//Uses Caesar Cipher to encrypt the message
void Cryptography_message::Encrypt_message::encrypt()
{
  int i=0;
  for(i=0; i<size; i++)
  //if alphabet then shift 4 
  if(isalpha(message[i]))
  {
    message[i]=(message[i]-'A'+4)%26+'A';
  }
}

//Uses Caesar Cipher to decrypt the message
void Cryptography_message::Encrypt_message::decrypt()
{
  int i=0;
  for(i=0;i<size;i++)
  //if alphabet then shift -4
  if(isalpha(message[i]))
  {
    message[i]=(message[i]-'A'-4)%26+'A';
  }
}
//friend function that overloads the ouput
//using namespace Cryptography_message;

/*ostream& Cryptography_message::operator<<(ostream & os, const Encrypt_message& a)
{
  
}*/