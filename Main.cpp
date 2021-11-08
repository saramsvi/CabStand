#include <iostream>
#include <fstream>
#include <string>
using namespace std ;
string Username , Password , Un , Pw ;
bool IsLoggedIn ()
{
    cout << "Enter Username :" ;
    cin >> Username ;
    cout << "Enter Password :" ;
    cin >> Password ;
    ifstream read("C:\\"+ Username + ".txt");
    getline (read , Un);
    getline (read , Pw);
    if ( Un == Username && Pw== Password)
    {
        return true ;
}
    else
    {
        return false ;
    }
}
int main()
{
    int choice ;
    cout << "What would you like to do? \n";
    cout << " 1Register\n 2Login \n I would like to ";
    cin >> choice ;
    if (choice ==1)
    {
        string Username , Password ;
        cout << "Select a username:";
        cin >> Username;
        cout << "Select a password:";
        cin >> Password;
        
        ofstream file ;
        file.open ("C:\\"+ Username + ".txt");
        file << Username<<endl <<Password;
        file.close() ;
        main ();
    }
    else if (choice ==2)
    {
        bool status =IsLoggedIn() ;
        if (!status)
        {
            cout << "False username or password!\n Please try again! \n" <<endl;
            system("pause");
            return 0 ;
        }
        else
        {
            cout << "Successfully logged in !"<< endl ;
            system("pause");
            return 1 ;
        }
    }
}
