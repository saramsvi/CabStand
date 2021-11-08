//-------------------------РАЗРАБОТКА ПРОГРАММЫ УЧЕТА АВТОМОБИЛЕЙ ТАКСОПАРКА-------------------------------------
/* Таксопарк содержит информацию об имеющихся автомобилях : вид автомобиля ( Такси , Микроавтобус , Лимузин), Вместимость, Расход топлива ,Стоимость автомобиля , Количество автомобилей данного вида.
 Индивидуальное задание : подсчитать общую стоимость таксопарка.Подсчитать общую стоимость автомобилей данного вида .Подобрать автомобилей ,по вместимости соответствующие заданному с клавиатуры диапазону.
 */
//-------------------------------------------------------------HEADER FILES-----------------------------------------------------------------
#include<iostream>
#include <iostream>
#include <fstream>
#include <string>
#include<stdio.h>
using namespace std ;
//-------------------------------------------------------FUNCTION DECLEARTION--------------------------------------------------------
//entering as admin or user?
void user_vs_admin ();
//verifying the admin
void admin();
bool checkadmin(string, string);
//verifying the user
bool checkuser(string  , string );
bool LoggedIn ();
//functions for the admin menu
void admin_menu();
bool registering();
bool members_list();
void Create_products ();
void show_product();
void write_product();
void display_all();
void modify_product();
void display_sp(int n);
void delete_product();
void menu();
//functions for user menu
void place_order();

//------------------------------------------------------declare global variable------------------------------------------------------------------
string login;
string password ;
string new_login ;
string new_password ;
string member ;
int enteras;
int Admin_choice;

//----------------------------------------------------------------Intro(main)-----------------------------------------------------------------------------
int main()
{
    setlocale(LC_ALL, "rus");
    cout<<"ТАКСОПАРК";
    cout<<"\n\nСделала : МУСАВИ САРАСАДАТ "<<endl;
    cout<<"          БГУИР 810102 ";
    getchar();
    user_vs_admin ();
}
//----------------------------------------------------------------main menu -----------------------------------------------------------------------------
void user_vs_admin ()
{
    cout<<"\n\n                  MAIN MENU \n\n";
    cout << "1 - Вход от имени пользователя" << endl;
    cout << "2 - Вход от имени администратора" << endl;
    int enteras;
    cin >> enteras;
    switch (enteras)
    {
        case 1: LoggedIn();
        case 2: admin();
    }
}
//--------------------------------------------------------Login(пользователь)?------------------------------------------------------------------
bool LoggedIn ()
{
    bool flagUser=false;
    cout << "Введите логин:"<<endl ;
    cin >> login ;
    cout << "Введите пароль:"<<endl ;
    cin >> password ;
    ifstream read(login+".txt");
    getline (read , new_login);
    getline (read , new_password);
    flagUser  = checkuser( login,  password);
    user_vs_admin ();
    return 0;
}
//----------------------------------------Check Login(пользователь)------------------------------------------------------------------
bool checkuser(string login , string password)
{
    if ( new_login == login && new_password== password)
    {
        cout<<"*************************************************************************"<<endl;
        cout <<"Вы вошли в систему от имени пользователя!"<<endl;
        cout<<"*************************************************************************"<<endl;
        place_order();
        return true ;
    }
    else
    {
        cout<<"*************************************************************************"<<endl;
        cout<<" Неверный пароль. Попробуйте еще раз. "<<endl;
        cout<<"*************************************************************************"<<endl;
        getchar();
        user_vs_admin ();
        return false ;
    }
}
//------------------------------------------------Check Login (Admin)-------------------------------------------------------------------------
void admin()
{
    bool flagA = false;
    string login_admin, password_admin;
    cout << "Введите логин: " << endl;
    cin >> login_admin;
    cout << "Введите пароль: " << endl;
    cin >> password_admin;
    flagA = checkadmin(login_admin, password_admin);
    if (flagA == true)
    {
        cout<<"*************************************************************************"<<endl;
        cout << "Вы вошли в систему от имени администратора!" << endl;
        cout<<"*************************************************************************"<<endl;
        admin_menu();
    }
    else
    {
        cout<<"*************************************************************************"<<endl;
        cout << "Неверный пароль. Попробуйте еще раз."<<endl;
        cout<<"*************************************************************************"<<endl;
        user_vs_admin ();
    }
}
//--------------------------------------------------------------Admin choices-------------------------------------------------------------------
void admin_menu()
{
    cout<<"\n\n                  ADMIN'S MENU \n";
    cout << "\n\n\t1 - Зарегестрировать нового пользователя: " ;
    cout<<"\n\n\t2 -Посмотреть список зарегистрерованных";
    cout<<"\n\n\t3 - Создать новый продукт ";
    cout<<"\n\n\t4 - Показать все продукты";
    cout<<"\n\n\t5 - QUERY ";
    cout<<"\n\n\t6 - Редактировать продукт";
    cout<<"\n\n\t7 - Удалить продукт";
    cout<<"\n\n\t8 - Показать менью продуктов ";
    cout<<"\n\n\t9 - Главное менью ";
    cout<<"\n\n\t Пожалуйста , выбирайте (1-9): ";
    cin >> Admin_choice;
    switch (Admin_choice)
    {
        case 1: registering();
            break;
        case 2:  members_list();
            break;
        case 3 :write_product ();
            break;
        case 4:display_all();
            break;
        case 5: //notsure
        case 6: modify_product();
            break;
        case 7:delete_product();
            break;
        case 8: menu() ;
            break;
        case 9:user_vs_admin ();
            break;
    }
}
//-----------------------------------------------------------Check Admin----------------------------------------------------------------------
bool checkadmin(string login_admin, string password_admin)
{
    if (login_admin == "sara" && password_admin == "123")
    {
        return true;
    }
    else
    {
        return false;
    }
}
//---------------------------------------------------------------Registering?-------------------------------------------------------------------
bool registering()
{
    
    cout << "Введите логин нового пользователя";
    cin >> login;
    cout << "Введите пароль нового пользователя:";
    cin >> password;
    ofstream file ;
    //saving the usernames
    file.open (login +".txt");
    file <<login <<endl<<password<<endl; ;
    file.close() ;
    //saving the passwords
    file.close();
    
    cout<<"\n Поздравляем! Регистрация прошла успешно!\n "<<endl;
    user_vs_admin ();
    ////////////what the fuck does this mean
    bool status =LoggedIn() ;
    if (!status)
    {
        cout << " Попробуйте еще раз." <<endl;
        return 0 ;
    }
    else
    {
        cout << "Вход успешен! "<< endl ;
        return 1 ;
    }
}
//--------------------------------------------------Memberslist(doesnt work)-----------------------------------------------------------------------
bool members_list()
{
    cout<<"*************************************************************************"<<endl<<endl;
    cout <<"List of registered members: \n"<< member <<endl;
    cout << ifstream(login+".txt").rdbuf();
    cout<<"\n*************************************************************************"<<endl<<endl;
    
    return 0;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------admin menu---------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************

class product
{
    int pno;
    char name[50];
    float price,quantity,tax,discount;
    
public:
    void create_product()
    {
        cout<<"\nPlease Enter The Product No. of The Product:";
        cin>>pno;
        cout<<"\n\nPlease Enter The Name of The Product:";
        cin >> name ;
        cout<<"\nPlease Enter The Price of The Product :";
        cin>>price;
        cout<<"\nPlease Enter The Discount (%): ";
        cin>>discount;
        getchar();
        
    }
    //
    void show_product()
    {
        cout<<"\nThe Product No. of The Product : "<<pno;
        cout<<"\nThe Name of The Product : ";
        cin>>name;
        cout<<"\nThe Price of The Product : "<<price;
        cout<<"\nDiscount : "<<discount;
    }
    
    int  retpno()
    {return pno;}
    
    float retprice()
    {return price;}
    
    char* retname()
    {return name;}
    
    int retdis()
    {return discount;}
    
};         //class ends here



//***************************************************************
//        global declaration for stream object, object
//****************************************************************

fstream fp;
product pr;
//***************************************************************
//        function to write in file
//****************************************************************
void write_product()
{
    fp.open("Shop.dat",ios::out|ios::app);
    pr.create_product();
    fp.write((char*)&pr,sizeof(product));
    fp.close();
    cout<<"\n\nThe Product Has Successfully Been Created! ";
    getchar();
    admin_menu();
}
//***************************************************************
//        function to read all records from file
//****************************************************************

void display_all()
{
    //
    cout<<"\n\n\n\t\tDISPLAY ALL RECORDS !!!\n\n";
    fp.open("Shop.dat",ios::in);
    while(fp.read((char*)&pr,sizeof(product)))
    {
        pr.show_product();
        cout<<"\n\n====================================\n";
        getchar();
    }
    fp.close();
    getchar();
    admin_menu();
    
}


//***************************************************************
//        function to read specific record from file
//****************************************************************


void display_sp(int n)
{
    int flag=0;
    fp.open("Shop.dat",ios::in);
    while(fp.read((char*)&pr,sizeof(product)))
    {
        if(pr.retpno()==n)
        {
            //
            pr.show_product();
            flag=1;
        }
    }
    fp.close();
    if(flag==0)
        cout<<"\n\nrecord not exist";
    getchar();
    admin_menu();
}


//***************************************************************
//        function to modify record of file
//****************************************************************


void modify_product()
{
    int no,found=0;
    //
    cout<<"\n\n\tTo Modify ";
    cout<<"\n\n\tPlease Enter The Product No. of The Product";
    cin>>no;
    fp.open("Shop.dat",ios::in|ios::out);
    while(fp.read((char*)&pr,sizeof(product)) && found==0)
    {
        if(pr.retpno()==no)
        {
            pr.show_product();
            cout<<"\nPlease Enter The New Details of Product"<<endl;
            pr.create_product();
            int pos=-1*sizeof(pr);
            fp.seekp(pos,ios::cur);
            fp.write((char*)&pr,sizeof(product));
            cout<<"\n\n\t Record Updated";
            found=1;
        }
    }
    fp.close();
    if(found==0)
        cout<<"\n\n Record Not Found ";
    getchar();
    admin_menu();
}


//***************************************************************
//        function to delete record of file
//****************************************************************


void delete_product()
{
    int no;
    //
    cout<<"\n\n\n\tDelete Record";
    cout<<"\n\nPlease Enter The product no. of The Product You Want To Delete";
    cin>>no;
    fp.open("Shop.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&pr,sizeof(product)))
    {
        if(pr.retpno()!=no)
        {
            fp2.write((char*)&pr,sizeof(product));
        }
    }
    fp2.close();
    fp.close();
    remove("Shop.dat");
    rename("Temp.dat","Shop.dat");
    cout<<"\n\n\tRecord Deleted ..";
    getchar();
    admin_menu();
}


//***************************************************************
//        function to display all products price list
//****************************************************************

void menu()
{
    //
    fp.open("Shop.dat",ios::in);
    if(!fp)
    {
        cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File";
        cout<<"\n\n\n Program is closing ....";
        getchar();
        exit(0);
    }
    
    cout<<"\n\n\t\tProduct MENU\n\n";
    cout<<"====================================================\n";
    cout<<"P.NO.\tNAME     \tPRICE\n";
    cout<<"====================================================\n";
    
    while(fp.read((char*)&pr,sizeof(product)))
    {
        cout<<pr.retpno()<<"\t\t"<<pr.retname()<<"\t\t"<<pr.retprice()<<endl;
        getchar();
    }
    fp.close();
    admin_menu();
}

//-----------------------------------------------------------CUSTOMER--------------------------------------------------------------------------------


//***************************************************************
//        function to place order and generating bill for Products
//****************************************************************

void place_order()
{
    int  order_arr[50],quan[50],c=0;
    float amt,damt,total=0;
    char ch='Y';

    cout<<"\n============================";
    cout<<"\n    PLACE YOUR ORDER";
    cout<<"\n============================\n";
    do{
        cout<<"\n\nEnter The Product No. Of The Chosen Product : ";
        cin>>order_arr[c];
        cout<<"\nQuantity in number : ";
        cin>>quan[c];
        c++;
        cout<<"\nWould You Like To Order Another Product ?";
        cin>>ch;
    }while(ch=='y' ||ch=='Y');
    cout<<"\n\nThank You For Placing The Order!";getchar();//
    cout<<"\n\n********************************INVOICE************************\n";
    cout<<"\nPr No.\tPr Name\tQuantity \tPrice \tAmount \tAmount after discount\n";
    for(int x=0;x<=c;x++)
    {
        fp.open("Shop.dat",ios::in);
        fp.read((char*)&pr,sizeof(product));
        while(!fp.eof())
        {
            if(pr.retpno()==order_arr[x])
            {
                amt=pr.retprice()*quan[x];
                damt=amt-(amt*pr.retdis()/100);
                cout<<"\n"<<order_arr[x]<<"\t"<<pr.retname()<<"\t"<<quan[x]<<"\t\t"<<pr.retprice()<<"\t"<<amt<<"\t\t"<<damt;
                total+=damt;
            }
            fp.read((char*)&pr,sizeof(product));
        }
        
        fp.close();
    }
    cout<<"\n\n\t\t\t\t\tTOTAL = "<<total;
    getchar();
}
