/*Name: Phuong Hoang
WSUID: A554P695
Program #: Final Project
Desciption: Create Encrypt_message class that asks the user for a secret meesage. The program encrypts and decrypts the message. 
It will throw an out_of_bounds error if the message goes out of bounds. Create an Encrypt_password class that asks the user for a password 
and inputs the encrypted password to a file. The program encrypts and decrypts the password. The encrypted password in the file will 
update everytime the user exits the program.
*/

#include <iostream>
#include "encrypt_password.hpp"
#include "encrypt_message.hpp"
#include <exception>
#include <fstream>
#include <string.h>
using namespace std;
using namespace Cryptography_password;
int main() 
{ 
  //pointer of type string points to data type name of type string
  string name;
  string *name_ptr;
  name_ptr = &name;
  cout<<"Enter your name: ";
  getline(cin, name);
  cout<<"Your name is: "<< *name_ptr<<endl;
  //create an instance of class Encrypt_password
  Encrypt_password password;
  int num = 100;
  string new_password;
  string orig_pass = "ABCabc123";
   ifstream fin;
   fin.open("Passwordfile.txt");
   //check to see if Passwordfile.txt exists
   if(!fin)
       password.set_new_password(orig_pass);
  int choice;
  while(choice != 3)
  {
    cout<< "1) Encrypt a Password" << endl << "2) Encrypted a Message " <<  endl <<"3) Exit the Program"<<endl;
    cout<<"Please enter your choice: "<<endl;
    cin>>choice;
    switch(choice)
    {
      case 1:
      {
         cin.ignore();
         //outputs criteria of password
          cout << "New password must:" << endl
          << " - be at least 6 characters long" << endl
          << " - contain at least 1 uppercase letter" << endl
          << " - contain at least 1 lowercase letter" << endl
          << " - contain at least 1 digit" << endl
          << "Enter new password: "; 
          cin >> new_password;
          //checks to see if password meets criteria
          if(password.set_new_password(new_password) == true)
          {
            cout << "Password changed" << endl << endl;
          }
          else
            cout << "Invalid password entered" << endl;
          //encrypts the password user inputted
          string encrypted = password.encrypt(new_password);
          cout<<encrypted<<endl;
          //decrypts password that was encrypted
          string decrypted = password.decrypt(encrypted);
          cout<<decrypted<<endl;
          ofstream fout;
          //create Passwordfile.txt and outputs encrypted password to the file
          fout.open("Passwordfile.txt");
          for (int x = 0; x<num; x++)  
          {
           fout<< x <<" " << password.encrypt(new_password) <<endl;
           fout.close();
          } 
          break;
      }

      case 2:
      {  
        using namespace Cryptography_message;
        int max = 500;
        int message_size = 0;
        cout<<"Enter how long your word is: ";
        cin>>message_size;
        //creates an instance of class Encrypt_message
        Encrypt_message message(message_size);
        cout<<"Enter the word you want to encrypt: ";
        
        for(int i =0; i<message_size; i++)
        {
          cin>>message[i];
          //makes message all capital letters for encryption/decrytion to work
          message[i] = toupper(message[i]);
        }
        //encrypts message
        message.encrypt();
        cout<<message<<endl;
        //decrypts the message.
        message.decrypt();
        cout<<message<<endl;

        cout<<"Input the index that you want to print out: ";
        try
        {
          for (int x=0; x<=message_size; x++)
          {
            cin>>x;
            cout.width(5);
            cout << x <<": " << message[x] << "\n";
          }
        }
        /*catches the exception and prints out the error message if index isn't in the
        region */
        catch(exception& e)
        {
          cout<<e.what();
        }
        break;
      }
      //exits program
      case 3:
      {
        cout<<"Exiting program";
        exit(0);
        break;
      }
      case 4:
      {
string new_password;
  string orig_pass = "ABCabc123";
   ifstream fin;
   fin.open("Passwordfile.txt"); 
      }
      //default in case user inputs an invalid choice
      default:
      {
        cout<<"Choice is invalid! Please choose another number."<<endl;
      }
    }
}
  
  
  return 0;
}