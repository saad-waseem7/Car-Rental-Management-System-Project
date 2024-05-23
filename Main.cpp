#include "Classs_Function.h"
#include "Utility_Function.h"
int main()
{

    int x1, x2, x3, x4, x5, x6;
    cars Info;
    Person data;
    Booked_Car booked;
    TotalRent Rent;
    const string filename = "quantity.txt";

    if (!fileExists(filename))
    {

        ofstream file(filename);

        // Check if the file is opened successfully
        if (!file.is_open())
        {
            cerr << ">>>Failed to create the file!\n";
            return 1;
        }

        for (int i = 0; i < 6; i++) // Initialize with base quantity...
        {
            file << "2\n";
        }

        file.close(); // Close the file

        // cout << ">>>File created successfully.\n";
    }
    else
    {
        // cout << ">>>File already exists. No action taken.\n";
    }

    int choice, use;
    do
    {
        Menu();
        setColor(31);
        cout << "\t\t\t Enter 1 for admin \n\t\t\t Enter 2 for user  \n\t\t\t Enter 3 to Exit.\n"
             << endl;
        cout << "\n\t\t\t Choice: ";

        do
        {
            cin >> use;
            Validation(use);
            if (use < 1 || use > 3)
            {
                cout << "\n\t\t\t>>>Enter 1 to 3 : ";
            }
        } while (use < 1 || use > 3);
        resetColor();
        system("cls");

        string username, pass;
        string default_username = "admin";
        string default_password = "pass";
        string update_pass;
        int a = 0;
        int Book_ment;
        int num_day;
        double num_hour;
        int checking;

        // switch
        switch (use)
        {
        case 1:
            // Admin Login and Password handle...
            Menu_admin();
            do
            {
                setColor(33);
                cout << "\t\t\tEnter your User name (Minimum 4 Letters...) : \n";
                cout << "\t\t\tUsername: ";
                cin >> username;
                if (!(username.size() > 3))
                {
                    cout << "\t\t\tError ! : " << endl;
                }
            } while (!(username.size() > 3));
            do
            {
                cout << "\t\t\tEnter Password (Minimum 4 Letters...) : \n";
                cout << "\t\t\tPassword: ";
                cin >> pass;
                if (!(pass.size() > 3))
                {
                    cout << "\t\t\tError ! : " << endl;
                    Sleep(1500);
                }
            } while (!(pass.size() > 3));
            system("cls");
            Menu_admin();
            if ((username == default_username) && (pass == default_password))
            {
                a += 2;
            }
            else
            {
                cout << "\n\t\t\tWrong Username & Password..." << endl;
                Sleep(2000);
            }
            resetColor();

            if (a == 2)
            {
                int x = 0;
                setColor(31);
                cout << "\t\t\tPress 1 ( Loading the data of Customers who Rented the cars )" << endl
                     << endl;
                cout << "\t\t\tPress 2 ( See the active status of any of Customer )" << endl
                     << endl;
                cout << "\t\t\tPress 3 ( See the Quantity of all Cars Available )" << endl
                     << endl;
                cout << "\t\t\tPress 4 ( Reset all Data )" << endl
                     << endl;
                resetColor();

                do
                {
                    cout << "\n\t\t\tChoice: ";
                    cin >> x;
                    Validation(x);
                    if (x < 1 || x >= 5)
                    {
                        cout << "\t\t\tEnter 1 to 4 : ";
                    }
                } while (x < 1 || x >= 5);
                if (x == 1)
                {
                    system("cls");
                    cout << ">>>Loading All Customers Information...Please wait..." << endl;
                    Sleep(4500);
                    system("cls");
                    cout << endl;
                    booked.Get_Booked();
                    cout << "\t\t\tPress Any Key to Logout or Go to MAIN menu : ";
                }
                else if (x == 2)
                {
                    system("cls");
                    cout << ">>>Loading Customer's Information...Please wait..." << endl;
                    Sleep(4500);
                    system("cls");
                    string cnic_to_search = "";
                    bool check1 = false;
                    do
                    {
                        setColor(33);

                        int a = 0;
                        cout << "\t\t\tEnter CNIC you wanna find ( 13 Digits without Dashes... ) : ";
                        cin >> cnic_to_search;
                        for (int i = 0; i < cnic_to_search.size(); i++)
                        {
                            if (!(isdigit(cnic_to_search[i])))
                            {
                                a++;
                            }
                            else
                            {
                                check1 = false;
                            }
                        }
                        if (a != 0 || cnic_to_search.size() != 13)
                        {
                            cout << "\t\t\tError ! : " << endl;
                            check1 = true;
                        }
                    } while (!(cnic_to_search.size() == 13) || check1 == true); // CNIC validation
                    search_cnic_for_admin(cnic_to_search);
                    resetColor();
                }
                else if (x == 3)
                {
                    system("cls");
                    cout << "\n\t\t\t>>>Loading Data...Please Wait..." << endl;
                    Sleep(3000);
                    system("cls");
                    readQuantityFile();
                    Sleep(4500);
                    cout << endl;
                }
                else if (x == 4)
                {
                    system("cls");
                    cout << "\n\t\t\t>>>Performing Operation...Please Wait..." << endl;
                    Sleep(3000);
                    system("cls");
                    resetFiles();
                    system("cls");
                    setColor(31);
                    cout << "\n\t\t\t>>>All Data has been Reset..." << endl;
                    resetColor();
                    Sleep(3000);
                }

                else
                {
                    cout << "\n\t\t\t>>>Invalid Choice " << endl;
                    cout << "\n\t\t\tReturning..." << endl;
                }
            }
            else
            {
                cout << "\t\t\tUsername or Password is Incorrect !!\n\n";
                cout << "\t\t\tPress Any Key to go to main menu : ";
                system("cls");
                cout << ">>>Returning to main menu...please wait..." << endl;
                Sleep(3500);
            }
            system("pause");
            break;
        case 2:
            Menu_user();
            Display_cars();
            cout << "\t\t\tEnter one of the given Number : ";
            do
            {
                cin >> choice;
                Validation(choice);
                if (choice < 1 || choice > 8)
                {
                    cout << "\t\t\tEnter Number from 1 to 8 : ";
                }
            } while (choice < 1 || choice > 8);
            system("cls");
            switch (choice)
            {
            case 1:

                Info.SetData("TOYOTA COROLLA", "STP-3080", "GREY", 2017, 700, 5000);
                Menu_user();
                x1 = getQuantityOnLine(1);
                cout << "\n\t\t\t Quantity of this car is: " << getQuantityOnLine(1) << endl;
                cout << endl;

                if (x1 > 0)
                {

                    cout << "\t\t\t Enter 1 to BOOK\n\t\t\t Enter 2 to exit. \n ";
                    do
                    {
                        cout << "\n\t\t\t Choice: ";
                        cin >> Book_ment;
                        Validation(Book_ment);
                        if (Book_ment < 1 || Book_ment > 2)
                        {
                            cout << "\n\t\t\t Enter 1 or 2 : ";
                        }
                    } while (Book_ment < 1 || Book_ment > 2);
                    if (Book_ment == 1)
                    {
                        booked.Add_one();
                        system("cls");
                        Menu_user();
                        cout << "\t\t\tEnter Your Information : \n";
                        cout << "\t\t\t=========================\n";
                        bool cnic_valid1 = true;
                        Person_Info(data, cnic_valid1);
                        if (cnic_valid1)
                        {

                            booked.Set_Booked(Info, data);
                            system("cls");
                            Menu_user();
                            cout << "\t\t\tEnter 1 if you want to Rent A Car for some Days \n\n";
                            cout << "\t\t\tEnter 2 if you want to Rent A Car for some Hours \n\n";
                            do
                            {
                                cout << "\n\t\t\t";
                                cin >> checking;
                                Validation(checking);
                                if (checking != 1 && checking != 2)
                                {
                                    cout << "\t\t\tError ! : " << endl;
                                }
                            } while (checking != 1 && checking != 2);
                            system("cls");
                            Menu_user();
                            if (checking == 1)
                            {
                                cout << "\t\t\tEnter Number of Days you want to Rent A Car : ";
                                cout << "\n\t\t\t";
                                cin >> num_day;
                                Validation(num_day);
                                while (num_day < 1)
                                {
                                    cout << "\t\t\tEnter Positive Number of Days : ";
                                    cout << "\n\t\t\t";
                                    cin >> num_day;
                                    Validation(num_day);
                                }
                                Rent.Set_day(num_day);
                                Rent.Calculate_price_per_day(Info);
                            }
                            else if (checking == 2)
                            {
                                cout << "\t\t\tEnter Number of Hours you want to Rent A Car : ";
                                cout << "\n\t\t\t";
                                cin >> num_hour;
                                Validation(num_hour);
                                while (num_hour < 1)
                                {
                                    cout << "\t\t\tEnter Positive Number of Hours : ";
                                    cout << "\n\t\t\t";
                                    cin >> num_hour;
                                    Validation(num_hour);
                                }
                                Rent.Set_hour(num_hour);
                                Rent.Calculate_price_per_hour(Info);
                            }

                            system("cls");
                            Menu_user();

                            cout << "\t\t\t\t>>>Calculating and Saving Rent...";
                            Sleep(3000);
                            system("cls");
                            cout << "\t\t\t\t\t\tDisplaying Total Rent...";
                            Sleep(1000);
                            decrementCarQuantity("Corolla");
                            system("cls");
                            cout << endl;
                            Show_Rent(Info, data, Rent, checking);
                        }
                        else
                        {
                            system("cls");
                            cout << "\n\t\t\t >>>This Person has already booked a car .....Return it first" << endl;

                            Sleep(4000);
                        }
                    }
                    else
                    {
                        system("cls");
                        cout << "\n\t\t\t>>>Returning..." << endl;
                        Sleep(2500);
                        break;
                    }
                }
                else if (x1 == 0)
                {
                    Sleep(2500);
                    cout << "\n\t\t\t>>>Car is out of stock..." << endl;
                    Sleep(2500);
                    break;
                }

                break;
            case 2:

                Info.SetData("HONDA CIVIC", "RIX-6878", "BLACK", 2015, 800, 8000);
                Menu_user();
                x2 = getQuantityOnLine(2);
                cout << "\n\t\t\t Quantity of this car is: " << getQuantityOnLine(2) << endl;
                cout << endl;
                if (x2 > 0)
                {

                    cout << "\t\t\t Enter 1 to BOOK\n\t\t\t Enter 2 to exit. \n ";
                    do
                    {
                        cout << "\n\t\t\t Choice: ";
                        cin >> Book_ment;
                        Validation(Book_ment);
                        if (Book_ment < 1 || Book_ment > 2)
                        {
                            cout << "\n\t\t\t Enter 1 or 2 : ";
                        }
                    } while (Book_ment < 1 || Book_ment > 2);
                    if (Book_ment == 1)
                    {
                        booked.Add_one();
                        system("cls");
                        Menu_user();
                        cout << "\t\t\tEnter Your Information : \n";
                        cout << "\t\t\t=========================\n";
                        bool cnic_valid2 = true;
                        Person_Info(data, cnic_valid2);
                        if (cnic_valid2 == true)
                        {
                            booked.Set_Booked(Info, data);
                            system("cls");
                            Menu_user();

                            cout << "\t\t\tEnter 1 if you want to Rent A Car for some Days \n\n";
                            cout << "\t\t\tEnter 2 if you want to Rent A Car for some Hours \n\n ";
                            do
                            {
                                cout << "\n\t\t\t";
                                cin >> checking;
                                Validation(checking);
                                if (checking != 1 && checking != 2)
                                {
                                    cout << "\t\t\tError ! : " << endl;
                                }
                            } while (checking != 1 && checking != 2);
                            system("cls");
                            Menu_user();
                            if (checking == 1)
                            {
                                cout << "\t\t\tEnter Number of Days you want to Rent A Car : ";
                                cout << "\n\t\t\t";
                                cin >> num_day;
                                Validation(num_day);
                                while (num_day < 1)
                                {
                                    cout << "\t\t\tEnter Positive Number of Days : ";
                                    cout << "\t\t\t";
                                    cin >> num_day;
                                    Validation(num_day);
                                }
                                Rent.Set_day(num_day);
                                Rent.Calculate_price_per_day(Info);
                            }
                            else if (checking == 2)
                            {
                                cout << "\t\t\tEnter Number of Hours you want to Rent A Car : ";
                                cout << "\n\t\t\t";
                                cin >> num_hour;
                                Validation(num_hour);
                                while (num_hour < 1)
                                {
                                    cout << "\t\t\tEnter Positive Number of Hours : ";
                                    cout << "\n\t\t\t";
                                    cin >> num_hour;
                                    Validation(num_hour);
                                }
                                Rent.Set_hour(num_hour);
                                Rent.Calculate_price_per_hour(Info);
                            }

                            system("cls");
                            Menu_user();
                            cout << "\t\t\t\t>>>Calculating and Saving Rent...";
                            Sleep(3000);
                            decrementCarQuantity("Civic");
                            system("cls");
                            cout << "\t\t\t\t\t\tDisplaying Total Rent...";
                            Sleep(1000);

                            system("cls");
                            Show_Rent(Info, data, Rent, checking);
                        }
                        else
                        {
                            system("cls");
                            cout << "\n\t\t\t >>>This Person has already booked a car .....Return it first" << endl;

                            Sleep(4000);
                        }
                    }
                    else
                    {
                        system("cls");
                        cout << "\n\t\t\t>>>Returning..." << endl;
                        Sleep(2500);
                        break;
                    }
                }
                else if (x2 == 0)
                {

                    Sleep(2500);
                    cout << "\n\n\n\t\t\t>>>Car is out of stock..." << endl;
                    Sleep(2500);
                    break;
                }
                break;
            case 3:

                Info.SetData("TOYOTA HILUX", "MIK-2724", "WHITE", 2013, 900, 10000);
                Menu_user();
                x3 = getQuantityOnLine(3);
                cout << "\n\t\t\t Quantity of this car is: " << getQuantityOnLine(3) << endl;
                cout << endl;
                if (x3 > 0)
                {

                    cout << "\t\t\t Enter 1 to BOOK\n\t\t\t Enter 2 to exit. \n ";
                    do
                    {
                        cout << "\n\t\t\t Choice: ";
                        cin >> Book_ment;
                        Validation(Book_ment);
                        if (Book_ment < 1 || Book_ment > 2)
                        {
                            cout << "\n\t\t\t Enter 1 or 2 : ";
                        }
                    } while (Book_ment < 1 || Book_ment > 2);
                    if (Book_ment == 1)
                    {
                        booked.Add_one();
                        system("cls");
                        Menu_user();
                        cout << "\t\t\tEnter Your Information : \n";
                        cout << "\t\t\t=========================\n";
                        bool cnic_valid3 = true;
                        Person_Info(data, cnic_valid3);
                        if (cnic_valid3 == true)
                        {
                            booked.Set_Booked(Info, data);
                            system("cls");
                            Menu_user();
                            cout << "\t\t\tEnter 1 if you want to Rent A Car for some Days \n\n";
                            cout << "\t\t\tEnter 2 if you want to Rent A Car for some Hours \n\n";
                            do
                            {
                                cout << "\n\t\t\t";
                                cin >> checking;
                                Validation(checking);
                                if (checking != 1 && checking != 2)
                                {
                                    cout << "\t\t\tError ! : " << endl;
                                }
                            } while (checking != 1 && checking != 2);
                            system("cls");
                            Menu_user();
                            if (checking == 1)
                            {
                                cout << "\t\t\tEnter Number of Days you want to Rent A Car : ";
                                cout << "\n\t\t\t";
                                cin >> num_day;
                                Validation(num_day);
                                while (num_day < 1)
                                {
                                    cout << "\t\t\tEnter Positive Number of Days : ";
                                    cout << "\n\t\t\t";
                                    cin >> num_day;
                                    Validation(num_day);
                                }
                                Rent.Set_day(num_day);
                                Rent.Calculate_price_per_day(Info);
                            }
                            else if (checking == 2)
                            {
                                cout << "\t\t\tEnter Number of Hours you want to Rent A Car : ";
                                cout << "\n\t\t\t";
                                cin >> num_hour;
                                Validation(num_hour);
                                while (num_hour < 1)
                                {
                                    cout << "\t\t\tEnter Positive Number of Hours : ";
                                    cout << "\n\t\t\t";
                                    cin >> num_hour;
                                    Validation(num_hour);
                                }
                                Rent.Set_hour(num_hour);
                                Rent.Calculate_price_per_hour(Info);
                            }

                            system("cls");
                            Menu_user();
                            cout << "\t\t\t\t>>>Calculating and Saving Rent...";
                            Sleep(3000);
                            decrementCarQuantity("Hilux");
                            system("cls");
                            cout << "\t\t\t\t\t\tDisplaying Total Rent...";
                            Sleep(1000);

                            system("cls");
                            Show_Rent(Info, data, Rent, checking);
                        }
                        else
                        {
                            system("cls");
                            cout << "\n\t\t\t >>>This Person has already booked a car .....Return it first" << endl;

                            Sleep(4000);
                        }
                    }
                    else
                    {
                        system("cls");
                        cout << "\n\t\t\t>>>Returning..." << endl;
                        Sleep(2500);
                        break;
                    }
                }
                else if (x3 == 0)
                {
                    Sleep(2500);
                    cout << "\n\t\t\t>>>Car is out of stock..." << endl;
                    Sleep(2500);
                    break;
                }

                break;
            case 4:

                Info.SetData("HONDA CITY", "RIM-5498", "BLUE", 2011, 1000, 8000);
                Menu_user();
                x4 = getQuantityOnLine(4);
                cout << "\n\t\t\t Quantity of this car is: " << getQuantityOnLine(4) << endl;
                cout << endl;
                if (x4 > 0)
                {

                    cout << "\t\t\t Enter 1 to BOOK\n\t\t\t Enter 2 to exit. \n ";
                    do
                    {
                        cout << "\n\t\t\t Choice: ";
                        cin >> Book_ment;
                        Validation(Book_ment);
                        if (Book_ment < 1 || Book_ment > 2)
                        {
                            cout << "\n\t\t\t Enter 1 or 2 : ";
                        }
                    } while (Book_ment < 1 || Book_ment > 2);
                    if (Book_ment == 1)
                    {
                        booked.Add_one();
                        system("cls");
                        Menu_user();
                        cout << "\t\t\tEnter Your Information : \n";
                        cout << "\t\t\t=========================\n";
                        bool valid_cnic4 = true;
                        Person_Info(data, valid_cnic4);
                        if (valid_cnic4 == true)
                        {

                            booked.Set_Booked(Info, data);
                            system("cls");
                            Menu_user();
                            cout << "\t\t\tEnter 1 if you want to Rent A Car for some Days \n\n";
                            cout << "\t\t\tEnter 2 if you want to Rent A Car for some Hours \n\n ";
                            do
                            {
                                cout << "\n\t\t\t";
                                cin >> checking;
                                Validation(checking);
                                if (checking != 1 && checking != 2)
                                {
                                    cout << "\t\t\tError ! : " << endl;
                                }
                            } while (checking != 1 && checking != 2);
                            system("cls");
                            Menu_user();
                            if (checking == 1)
                            {
                                cout << "\t\t\tEnter Number of Days you want to Rent A Car : ";
                                cout << "\n\t\t\t";
                                cin >> num_day;
                                Validation(num_day);
                                while (num_day < 1)
                                {
                                    cout << "\t\t\tEnter Positive Number of Days : ";
                                    cout << "\n\t\t\t";
                                    cin >> num_day;
                                    Validation(num_day);
                                }
                                Rent.Set_day(num_day);
                                Rent.Calculate_price_per_day(Info);
                            }
                            else if (checking == 2)
                            {
                                cout << "\t\t\tEnter Number of Hours you want to Rent A Car : ";
                                cout << "\n\t\t\t";
                                cin >> num_hour;
                                Validation(num_hour);
                                while (num_hour < 1)
                                {
                                    cout << "\t\t\tEnter Positive Number of Hours : ";
                                    cout << "\n\t\t\t";
                                    cin >> num_hour;
                                    Validation(num_hour);
                                }
                                Rent.Set_hour(num_hour);
                                Rent.Calculate_price_per_hour(Info);
                            }

                            system("cls");
                            Menu_user();
                            cout << "\t\t\t\t>>>Calculating and Saving Rent...";
                            Sleep(3000);
                            system("cls");
                            cout << "\t\t\t\t\t\tDisplaying Total Rent...";
                            Sleep(1000);
                            decrementCarQuantity("City");
                            system("cls");
                            Show_Rent(Info, data, Rent, checking);
                        }
                        else
                        {
                            system("cls");
                            cout << "\n\t\t\t >>>This Person has already booked a car .....Return it first" << endl;

                            Sleep(4000);
                        }
                    }
                    else
                    {
                        system("cls");
                        cout << "\n\t\t\t>>>Returning..." << endl;
                        Sleep(2500);
                        break;
                    }
                }
                else if (x4 == 0)
                {
                    Sleep(2500);
                    cout << "\n\t\t\t>>>Car is out of stock..." << endl;
                    Sleep(2500);
                    break;
                }

                break;
            case 5:

                Info.SetData("HYUNDAI SONATA", "RIM-5498", "BLACK", 2019, 1000, 8000);
                Menu_user();
                x5 = getQuantityOnLine(5);
                cout << "\n\t\t\t Quantity of this car is: " << getQuantityOnLine(5) << endl;
                cout << endl;
                if (x5 > 0)
                {

                    cout << "\t\t\t Enter 1 to BOOK\n\t\t\t Enter 2 to exit. \n ";
                    do
                    {
                        cout << "\n\t\t\t Choice: ";
                        cin >> Book_ment;
                        Validation(Book_ment);
                        if (Book_ment < 1 || Book_ment > 2)
                        {
                            cout << "\n\t\t\t Enter 1 or 2 : ";
                        }
                    } while (Book_ment < 1 || Book_ment > 2);
                    if (Book_ment == 1)
                    {
                        booked.Add_one();
                        system("cls");
                        Menu_user();
                        cout << "\t\t\tEnter Your Information : \n";
                        cout << "\t\t\t=========================\n";
                        bool cnic_valid5 = true;
                        Person_Info(data, cnic_valid5);
                        if (cnic_valid5)
                        {
                            booked.Set_Booked(Info, data);
                            system("cls");
                            Menu_user();
                            cout << "\t\t\tEnter 1 if you want to Rent A Car for some Days \n\n";
                            cout << "\t\t\tEnter 2 if you want to Rent A Car for some Hours \n\n ";
                            do
                            {
                                cout << "\n\t\t\t";
                                cin >> checking;
                                Validation(checking);
                                if (checking != 1 && checking != 2)
                                {
                                    cout << "\t\t\tError ! : " << endl;
                                }
                            } while (checking != 1 && checking != 2);
                            system("cls");
                            Menu_user();
                            if (checking == 1)
                            {
                                cout << "\t\t\tEnter Number of Days you want to Rent A Car : ";
                                cout << "\n\t\t\t";
                                cin >> num_day;
                                Validation(num_day);
                                while (num_day < 1)
                                {
                                    cout << "\t\t\tEnter Positive Number of Days : ";
                                    cout << "\n\t\t\t";
                                    cin >> num_day;
                                    Validation(num_day);
                                }
                                Rent.Set_day(num_day);
                                Rent.Calculate_price_per_day(Info);
                            }
                            else if (checking == 2)
                            {
                                cout << "\t\t\tEnter Number of Hours you want to Rent A Car : ";
                                cout << "\n\t\t\t";
                                cin >> num_hour;
                                Validation(num_hour);
                                while (num_hour < 1)
                                {
                                    cout << "\t\t\tEnter Positive Number of Hours : ";
                                    cout << "\n\t\t\t";
                                    cin >> num_hour;
                                    Validation(num_hour);
                                }
                                Rent.Set_hour(num_hour);
                                Rent.Calculate_price_per_hour(Info);
                            }

                            system("cls");
                            Menu_user();
                            cout << "\t\t\t\t>>>Calculating and Saving Rent...";
                            Sleep(3000);
                            system("cls");
                            cout << "\t\t\t\t\t\tDisplaying Total Rent...";
                            Sleep(1000);
                            decrementCarQuantity("Sonata");
                            system("cls");
                            Show_Rent(Info, data, Rent, checking);
                        }
                        else
                        {
                            system("cls");
                            cout << "\n\t\t\t >>>This Person has already booked a car .....Return it first" << endl;

                            Sleep(4000);
                        }
                    }
                    else
                    {
                        system("cls");
                        cout << "\n\t\t\t>>>Returning..." << endl;
                        Sleep(2500);
                        break;
                    }
                }
                else if (x5 == 0)
                {
                    Sleep(2500);
                    cout << "\n\t\t\t>>>Car is out of stock..." << endl;
                    Sleep(2500);
                    break;
                }

                break;
            case 6:
                Info.SetData("SUZUKI WAGON-R", "RIM-5498", "BLUE", 2011, 1000, 8000);
                Menu_user();
                x6 = getQuantityOnLine(6);
                cout << "\n\t\t\t Quantity of this car is: " << getQuantityOnLine(6) << endl;
                cout << endl;
                if (x6 > 0)
                {

                    cout << "\t\t\t Enter 1 to BOOK\n\t\t\t Enter 2 to exit. \n ";
                    do
                    {
                        cout << "\n\t\t\t Choice: ";
                        cin >> Book_ment;
                        Validation(Book_ment);
                        if (Book_ment < 1 || Book_ment > 2)
                        {
                            cout << "\n\t\t\t Enter 1 or 2 : ";
                        }
                    } while (Book_ment < 1 || Book_ment > 2);
                    if (Book_ment == 1)
                    {
                        booked.Add_one();
                        system("cls");
                        Menu_user();
                        cout << "\t\t\tEnter Your Information : \n";
                        cout << "\t\t\t=========================\n";
                        bool cnic_valid7 = true;
                        Person_Info(data, cnic_valid7);
                        booked.Set_Booked(Info, data);
                        if (cnic_valid7)
                        {
                            system("cls");
                            Menu_user();
                            cout << "\t\t\tEnter 1 if you want to Rent A Car for some Days \n\n";
                            cout << "\t\t\tEnter 2 if you want to Rent A Car for some Hours \n\n ";
                            do
                            {
                                cout << "\n\t\t\t";
                                cin >> checking;
                                Validation(checking);
                                if (checking != 1 && checking != 2)
                                {
                                    cout << "\t\t\tError ! : " << endl;
                                }
                            } while (checking != 1 && checking != 2);
                            system("cls");
                            Menu_user();
                            if (checking == 1)
                            {
                                cout << "\t\t\tEnter Number of Days you want to Rent A Car : ";
                                cout << "\n\t\t\t";
                                cin >> num_day;
                                Validation(num_day);
                                while (num_day < 1)
                                {
                                    cout << "\t\t\tEnter Positive Number of Days : ";
                                    cout << "\n\t\t\t";
                                    cin >> num_day;
                                    Validation(num_day);
                                }
                                Rent.Set_day(num_day);
                                Rent.Calculate_price_per_day(Info);
                            }
                            else if (checking == 2)
                            {
                                cout << "\t\t\tEnter Number of Hours you want to Rent A Car : ";
                                cout << "\n\t\t\t";
                                cin >> num_hour;
                                Validation(num_hour);
                                while (num_hour < 1)
                                {
                                    cout << "\t\t\tEnter Positive Number of Hours : ";
                                    cout << "\n\t\t\t";
                                    cin >> num_hour;
                                    Validation(num_hour);
                                }
                                Rent.Set_hour(num_hour);
                                Rent.Calculate_price_per_hour(Info);
                            }

                            system("cls");
                            Menu_user();
                            cout << "\t\t\t\t>>>Calculating and Saving Rent...";
                            Sleep(3000);
                            system("cls");
                            cout << "\t\t\t\t\t\tDisplaying Total Rent...";
                            Sleep(1000);
                            decrementCarQuantity("WagonR");

                            system("cls");
                            Show_Rent(Info, data, Rent, checking);
                        }
                        else
                        {
                            system("cls");
                            cout << "\n\t\t\t >>>This Person has already booked a car .....Return it first" << endl;

                            Sleep(4000);
                        }
                    }
                    else
                    {
                        system("cls");
                        cout << "\n\t\t\t>>>Returning..." << endl;
                        Sleep(2500);
                        break;
                    }
                }
                else if (x6 == 0)
                {

                    Sleep(2500);
                    cout << "\n\t\t\t>>>Car is out of stock..." << endl;
                    Sleep(2500);
                    break;
                }
                break;
            case 7:
            {
                string cnic_on_booked;
                bool isValid;

                do
                {
                    setColor(32);
                    cout << "\t\t\t>>>Please enter your CNIC on which you booked Car " << endl
                         << "\t\t\t>>>Note: It must be 13 digits without any dashes or spaces: \n"
                         << endl;
                    cout << "\t\t\tCNIC: ";
                    cin >> cnic_on_booked;

                    // Check if CNIC is exactly 13 digits
                    if (cnic_on_booked.length() != 13)
                    {
                        cout << "\t\t\tInvalid input. CNIC must be exactly 13 digits long.\n";
                        isValid = false;
                    }
                    else
                    {
                        isValid = true;
                        // Check each character to ensure it's a digit
                        for (char k : cnic_on_booked)
                        {
                            if (!isdigit(k))
                            {
                                cout << "\t\t\tInvalid input. CNIC must contain only digits.\n";
                                isValid = false;
                                break;
                            }
                        }
                    }
                    resetColor();
                }

                while (!isValid);
                int late;
                cout << "\n\t\t\tAre You Returning The Car Late: " << endl;
                cout << "\n\t\t\tEnter 1 if Yes\n\t\t\tEnter 2 if No\n\t\t\t";
                cin >> late;
                if (late == 1)
                {
                    cout << "\n\t\t\tEnter Extra Number of Days Used: " << endl;
                    int days;
                    cout << "\t\t\t";
                    cin >> days;
                    int fine = days * 2000;
                    // cout << "\n\t\t\t" << fine;
                    system("cls");
                    cout << "\n\t\t\t>>>Calculating the Penalty Bill... \n";
                    Sleep(2000);
                    system("cls");
                    setColor(33);
                    cout << endl;
                    cout << "\n\t\t           ...Car Rental - Penalty Bill...                 " << endl
                         << endl;
                    cout << "\t\t //////////////////////////////////////////////////////" << endl;
                    cout << "\t\t | Bill Number. :" << "------------------|" << setw(18) << "#Fpb81353" << " |" << endl;
                    cout << "\t\t | Your Payable Amount is :" << "--------|" << setw(18) << fine << " |" << endl;
                    cout << "\t\t | Extra Days Used :" << "---------------|" << setw(18) << days << " |" << endl;
                    cout << "\t\t | Advanced :" << "----------------------|" << setw(18) << "00" << " |" << endl;
                    cout << "\t\t ______________________________________________________" << endl;
                    cout << "\t\t # This is a computer generated invoce and it does not" << endl;
                    cout << "\t\t require an authorised signture #" << endl;

                    cout << " " << endl;
                    cout << "\t\t //////////////////////////////////////////////////////" << endl;
                    cout << endl;
                    cout << endl;
                    cout << "\t\t                              Thanks for Visiting us... \n"
                         << endl;
                    cout << endl;
                    resetColor();
                    Sleep(4000);
                    system("cls");
                    cout << "\n\t\t\t>>>Loading Data...Please Wait..." << endl;
                    Sleep(2000);
                    system("cls");
                    resetColor();
                    Sleep(1000);
                    delete_cnic_from_file_admin(cnic_on_booked);
                    system("cls");
                }

                else if (late == 2)
                {
                    delete_cnic_from_file_admin(cnic_on_booked);
                    Sleep(2000);
                    system("cls");
                }
                else
                {
                    cout << "\n\t\t\tInvalid..." << endl;
                }
            }

            break;

            case 8:
                break;
            }
        }
        system("cls");
    } while (use != 3);

    system("pause");
}
