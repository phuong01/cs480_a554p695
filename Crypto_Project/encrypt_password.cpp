#include <iostream>
#include "encrypt_password.hpp"
#include <fstream>
using namespace std;
using namespace Cryptography_password;
//sets the encrypted password and sends it to a file.
void Encrypt_password::set_encrypted_password(string encrypted_pass)
{
     ofstream fout;
     fout.open("Passwordfile.txt");
     fout << encrypted_pass;
     fout.close();
}

//checks to make sure user's input meets the criteria
bool Encrypt_password::verify_password(string password)
{
  int pass_size = 0;
     int pass_upper = 0;
     int pass_lower = 0;
     int pass_digit = 0;

   bool pass_fail = false;

           if( password.size() >= 6)
           {
               pass_size++;
           }

     for(int i = 0; i < password.length(); i++)
     {

           if(isupper(password[i]))
           {
               pass_upper++;
           }
           if(islower(password[i]))
           {
               pass_lower++;
           }
           if(isdigit(password[i]))
           {
               pass_digit++;
           }
     }

     if(pass_size >= 1 && pass_upper >= 1 && pass_lower >= 1 && pass_digit >= 1)
           {
               pass_fail = true;
           }

     return pass_fail;
}

//sets new password as what user inputs if it meets the criteria
bool Encrypt_password::set_new_password(string password)
{
  bool pass_fail = false;

     if(verify_password(password) == true)
     {
         set_encrypted_password(encrypt(password));
         pass_fail = true;
     }

     return pass_fail;
}

//encrypts password using Caesar Cipher
string Encrypt_password::encrypt(string password)
{
  for(int i = 0; i < password.length(); i++)
     password[i] += 3;
  return password;
}

//decrypts password using Caesar Cipher
string Encrypt_password::decrypt(string password)
{
  for(int i = 0; i < password.length(); i++)
     password[i] -= 3;
  return password;
}