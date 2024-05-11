#pragma once
#include "Project_Class.h"

// Using a Template Input Validation...
template <class T>
void Validation(T &a)
{
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "\t\t\t>>>Enter Valid Choice : ";
        cin >> a;
    }
}

// Prototyping For Helper Functions...
void Menu();
void Menu_admin();
void Menu_user();
void Display_cars();
// New functions Prototype...
// Because Passing of classes in functions...
void Person_Info(Person &p, bool &cnic_valid);
void Show_Rent(cars &c, Person &p, TotalRent &r, int check);
void search_cnic_for_admin(string cnic);
void delete_cnic_from_file_admin(string cnic);
void modify_status_of_person_info_from_file_admin(string cnic);
bool isCNICPresent(const string &cnic);
bool fileExists(const string &filename);
bool decrementCarQuantity(const string &carName);
int getQuantityOnLine(int x);
void readQuantityFile();
void resetFiles();
void setColor(int color);
void resetColor();
void drawCar(int position);
void load_screen();

//----------------------------------------------------------------

void Menu() // Menu to Show Car Rental System Logo/Slogan...
{
    cout << endl;
    setColor(33);
    cout << "\t\t\t=================================================\n";
    resetColor();
    setColor(32);
    cout << "\t\t\t|                                               |\n";
    cout << "\t\t\t|        -----------------------------          |\n";
    cout << "\t\t\t|        |     CAR RENTAL SYSTEM     |          |\n";
    cout << "\t\t\t|        -----------------------------          |\n";
    cout << "\t\t\t|                                               |\n";
    resetColor();
    setColor(33);
    cout << "\t\t\t=================================================\n";
    resetColor();
    setColor(32);
    cout << "\t\t\t|                                               |\n";
    cout << "\t\t\t|              Drive Efficiency,                |\n";
    cout << "\t\t\t|               Ride with Ease:                 |\n";
    cout << "\t\t\t| Your Ultimate Car Rental Management Solution! |\n";
    cout << "\t\t\t|                                               |\n";
    resetColor();
    setColor(33);
    cout << "\t\t\t=================================================\n\n\n";
    resetColor();
}

void Menu_admin()
{
    setColor(33);
    cout << endl;
    cout << "\t\t\t=================================================\n";
    resetColor();
    setColor(32);
    cout << "\t\t\t|                                               |\n";
    cout << "\t\t\t|        -----------------------------          |\n";
    cout << "\t\t\t|        |     CAR RENTAL SYSTEM     |          |\n";
    cout << "\t\t\t|        -----------------------------          |\n";
    cout << "\t\t\t|                                               |\n";
    resetColor();
    setColor(33);
    cout << "\t\t\t=================================================\n";
    resetColor();
    setColor(31);
    cout << "\t\t\t|              <<<...ADMIN...>>>                |\n";
    resetColor();
    setColor(33);
    cout << "\t\t\t=================================================\n\n";
    resetColor();
}
void Menu_user()
{
    cout << endl;
    setColor(33);
    cout << "\t\t\t=================================================\n";
    resetColor();
    setColor(32);
    cout << "\t\t\t|                                               |\n";
    cout << "\t\t\t|        -----------------------------          |\n";
    cout << "\t\t\t|        |     CAR RENTAL SYSTEM     |          |\n";
    cout << "\t\t\t|        -----------------------------          |\n";
    cout << "\t\t\t|                                               |\n";
    resetColor();
    setColor(33);
    cout << "\t\t\t=================================================\n";
    resetColor();
    setColor(31);
    cout << "\t\t\t|              <<<...USERS...>>>                |\n";
    resetColor();
    setColor(33);
    cout << "\t\t\t=================================================\n\n";
    resetColor();
}

void Display_cars() // Showing the available cars..
{
    cout << endl;
    setColor(31);
    cout << "\t\t\tPlease Select a Car" << endl<<endl;
    cout << "\t\t\tEnter 1 for TOYOTA COROLLA ." << endl<<endl;
    cout << "\t\t\tEnter 2 for HONDA CIVIC ." << endl<<endl;
    cout << "\t\t\tEnter 3 for TOYOTA HILUX ." << endl<<endl;
    cout << "\t\t\tEnter 4 for HONDA CITY ." << endl<<endl;
    cout << "\t\t\tEnter 5 for HYUNDAI SONATA ." << endl<<endl;
    cout << "\t\t\tEnter 6 for SUZUKI WAGON-R ." << endl<<endl;
    cout << "\t\t\tEnter 7 to Return Vehicle" << endl<<endl;
    cout << "\t\t\tEnter 8 to Exit." << endl<<endl;
    resetColor();
}

//----------------------------------------------------------------

void Person_Info(Person &p, bool &cnic_valid)
{
    bool check = false;
    string first_name, last_name, name, Number, cnic, address;
    int a = 0;
    setColor(32);
    do
    {
        cout<<endl;
        a = 0;
        cout << "\t\t\tEnter Your First Name: \n";
        cout << "\t\t\tName: ";
        cin.ignore();
        getline(cin, first_name);
        for (int i = 0; i < first_name.size(); i++)
        {
            if (!(isalpha(first_name[i])))
            {
                a++;
            }
            else
            {
                check = false;
            }
        }

        if (a != 0 || !(first_name.size() >= 3))
        {
            cout << "\t\t\tError ! : " << endl;
            check = true;
        }
    } while (!(first_name.size() >= 3) || check == true); // first name

    do
    {
        cout<<endl;
        a = 0;
        cout << "\t\t\tEnter Your last Name : \n";
        cout << "\t\t\tName: ";
        getline(cin, last_name);
        for (int i = 0; i < last_name.size(); i++)
        {
            if (!(isalpha(last_name[i])))
            {
                a++;
            }
            else
            {
                check = false;
            }
        }

        if (a != 0 || !(last_name.size() >= 3))
        {
            cout << "\t\t\tError ! : " << endl;
            check = true;
        }
    } while (!(last_name.size() >= 3) || check == true); // last name
    name = first_name + " " + last_name;

    do
    {
        cout<<endl;
        a = 0;
        cout << "\t\t\tEnter your CNIC (13 Digits without Dashes...) : \n";
        cout << "\t\t\tCNIC: ";
        getline(cin, cnic);
        for (int i = 0; i < cnic.size(); i++)
        {
            if (!(isdigit(cnic[i])))
            {
                a++;
            }
            else
            {
                check = false;
            }
        }
        if (a != 0 || cnic.size() != 13)
        {
            cout << "\t\t\tError ! : " << endl;
            check = true;
        }
    } while (!(cnic.size() == 13) || check == true); // CNIC
    if (isCNICPresent(cnic) == 0)
    {
        do
        {
            cout<<endl;
            a = 0;
            cout << "\t\t\tEnter your Mobile Number (11 digits without Dashes...) :\n";
            cout << "\t\t\tMobile Number: ";
            cin >> Number;
            for (int i = 0; i < Number.size(); i++)
            {
                if (!(isdigit(Number[i])))
                {
                    a++;
                }
                else
                {
                    check = false;
                }
            }
            if (a != 0 || Number.size() != 11)
            {
                cout << "\t\t\tError ! : " << endl;
                check = true;
            }
        } while (!(Number.size() == 11) || check == true); // Contact Number

        do
        {
            cout<<endl;
            cout << "\t\t\tEnter you Present Address (Full & Minimum 6 Letters or Digits...) : \n";
            cout << "\t\t\tAddress : ";
            cin.ignore();
            getline(cin, address);
        } while (!(address.size() > 5)); // Address

        p.SetData(name, address, cnic, Number, true); // Setting values to person class setdata function
        cnic_valid = true;
    }
    else
    {
        cnic_valid = false;
    }
    resetColor();
}

void Show_Rent(cars &c, Person &p, TotalRent &r, int check)
{
    setColor(33);
    cout << endl;
    cout << "\n\t\t             Car Rental - Customer Invoice                 " << endl;
    cout << "\t\t //////////////////////////////////////////////////////" << endl;
    cout << "\t\t | Invoice No. :" << "------------------|" << setw(18) << "#Cnb81353" << " |" << endl;
    cout << "\t\t | Customer Name:" << "-----------------|" << setw(18) << p.get_name() << " |" << endl;
    cout << "\t\t | Car Name  :" << "--------------------|" << setw(18) << c.get_car_name() << " |" << endl;
    cout << "\t\t | Car Model :" << "--------------------|" << setw(18) << c.get_model() << " |" << endl;
    cout << "\t\t | Car No. :" << "----------------------|" << setw(18) << c.get_car_number() << " |" << endl;
    if (check == 1)
    {
        cout << "\t\t | Number of days :" << "---------------|" << setw(18) << r.get_days() << " |" << endl;
    }
    else if (check == 2)
    {

        cout << "\t\t | Number of hours :" << "--------------|" << setw(18) << r.get_hours() << " |" << endl;
    }

    cout << "\t\t | Your Rental Amount is :" << "--------|" << setw(18) << r.get_Total() << " |" << endl;
    cout << "\t\t | Caution Money :" << "----------------|" << setw(18) << "00" << " |" << endl;
    cout << "\t\t | Advanced :" << "---------------------|" << setw(18) << "00" << " |" << endl;
    cout << "\t\t ______________________________________________________" << endl;
    cout << "\n";
    cout << "\t\t | Total Rental Amount is :" << "-------|" << setw(18) << r.get_Total() << " |" << endl;
    cout << "\t\t ______________________________________________________" << endl;
    resetColor();
    setColor(31);
    cout << "\t\t # This is a computer generated invoce and it does not" << endl;
    cout << "\t\t require an authorised signture #" << endl;
    resetColor();
    cout << " " << endl;
    cout << "\t\t //////////////////////////////////////////////////////" << endl;
    cout << "\t\t You are advised to pay up the amount before due date." << endl;
    cout << "\t\t Otherwise penelty fee will be applied" << endl;
    cout << "\t\t //////////////////////////////////////////////////////" << endl;
    cout << endl;
    cout << endl;
    cout << "\t\t                              Thanks for Visiting us... \n"
         << endl;
    cout << endl;
    system("pause");
    system("cls");
    cout << "\t\t\t\t\t\t >>>Loading Main Menu... ";
    Sleep(1500);
    system("cls");
    resetColor();
}

void search_cnic_for_admin(string cnic)
{
    ifstream inputFile("CNIC.txt");
    string readCNIC;
    bool found = false;
    int lineNumber = 1;
    if (inputFile.is_open())
    {
        while (getline(inputFile, readCNIC))
        {
            if (readCNIC == cnic)
            {
                found = true;
                break;
            }
            lineNumber++;
        }
        inputFile.close();

        if (found)
        {
            cout << "\t\t\tStatus is active \n"
                 << endl;
        }
        else
        {
            cout << "\t\t\tStatus is Non-Active \n"
                 << endl;
        }
    }
    else
    {
        cout << "\t\t\tUnable to open file for reading." << endl;
    }
}
void delete_cnic_from_file_admin(string cnic)
{
    ifstream inputFile("CNIC.txt");
    ofstream tempFile("temp.txt"); // Temporary file to store CNICs except the one to delete
    string readCNIC;
    bool found = false;

    if (inputFile.is_open() && tempFile.is_open())
    {
        while (getline(inputFile, readCNIC))
        {
            if (readCNIC == cnic)
            {
                found = true;
                continue; // Skip writing this CNIC to temp file
            }
            tempFile << readCNIC << endl; // Write CNIC to temp file
        }

        inputFile.close();
        tempFile.close();

        if (found)
        {
            if (remove("CNIC.txt") != 0) // Remove the original CNIC file
            {
                cout << "\t\t\tError deleting CNIC.txt" << endl;
                return;
            }
            if (rename("temp.txt", "CNIC.txt") != 0) // Rename temp file to CNIC.txt
            {
                cout << "\t\t\tError renaming temp.txt" << endl;
                return;
            }
            system("cls");
            modify_status_of_person_info_from_file_admin(cnic);
        }
        else
        {
            cout << "\n\t\t\t>>>CNIC not found...\n"
                 << endl;
            remove("temp.txt"); // Remove temp file if CNIC not found
            Sleep(2500);
        }
    }
    else
    {
        cout << "\t\t\t>>>Unable to open file for reading or writing." << endl;
        Sleep(2500);
    }
}

void modify_status_of_person_info_from_file_admin(string cnic)
{
    ifstream inputFile("Cars Info.txt");
    ofstream tempFile("temp.txt"); // Temporary file to store data except the one to delete
    string line;
    bool found = false;

    if (inputFile.is_open() && tempFile.is_open())
    {
        while (getline(inputFile, line))
        {
            if (found)
            {                                                    // If CNIC was found in the previous iteration, write "Status is inactive" and continue
                tempFile << "\t\t\t Status is inactive" << endl; // Write status line
                found = false;                                   // Reset found flag
                continue;                                        // Continue to the next line
            }
            if (line.find(cnic) != string::npos)
            { // Check if the line contains the CNIC
                found = true;
            }
            tempFile << line << endl; // Write line to temp file
        }

        inputFile.close();
        tempFile.close();
        system("cls");

        if (found)
        {
            cout << "\t\t\t>>>Person's info not found." << endl;
            remove("temp.txt"); // Remove temp file if person's info not found
        }
        else
        {
            if (remove("Cars Info.txt") != 0)
            { // Remove the original file
                cout << "\t\t\t>>>Error deleting Cars Info.txt" << endl;
                return;
            }
            if (rename("temp.txt", "Cars Info.txt") != 0)
            { // Rename temp file to original file
                cout << "\t\t\t>>>Error renaming temp.txt" << endl;
                return;
            }
        }
    }
    else
    {
        cout << "\t\t\tUnable to open file for reading or writing." << endl;
    }
    system("cls");
    cout << "\n\t\t\t>>>Loading Data...Please Wait..." << endl;
    Sleep(2500);
    system("cls");
    cout << "\n\t\t\t>>>Car Returned successfully..." << endl;
    Sleep(2500);
}

bool isCNICPresent(const string &cnic)
{
    ifstream inputFile("CNIC.txt");
    string readCNIC;

    if (inputFile.is_open())
    {
        while (getline(inputFile, readCNIC))
        {
            if (readCNIC == cnic)
            {
                inputFile.close();
                return true;
            }
        }
        inputFile.close();
    }

    return false;
}
bool fileExists(const string &filename)
{
    ifstream file(filename.c_str());
    return file.good();
}

bool decrementCarQuantity(const string &carName)
{
    // Open the file for reading
    ifstream file("quantity.txt");
    if (!file.is_open())
    {
        cerr << "\t\t\t>>>Failed to open the file for reading!\n";
        return false;
    }

    // Read the quantities of cars from the file
    int quantities[6];
    for (int i = 0; i < 6; ++i)
    {
        if (!(file >> quantities[i]))
        {
            cerr << "\t\t\t>>>Failed to read from the file!\n";
            file.close();
            return false;
        }
    }
    file.close();

    // Decrement the quantity of the specified car
    if (carName == "Corolla")
    {
        if (quantities[0] > 0)
        {
            --quantities[0];
        }
    }
    else if (carName == "Civic")
    {
        if (quantities[1] > 0)
        {
            --quantities[1];
        }
    }
    else if (carName == "Hilux")
    {
        if (quantities[2] > 0)
        {
            --quantities[2];
        }
    }
    else if (carName == "City")
    {
        if (quantities[3] > 0)
        {
            --quantities[3];
        }
    }
    else if (carName == "Sonata")
    {
        if (quantities[4] > 0)
        {
            --quantities[4];
        }
    }
    else if (carName == "WagonR")
    {
        if (quantities[5] > 0)
        {
            --quantities[5];
        }
    }
    else
    {
        cerr << "Invalid car name!\n";
        return false;
    }

    // Open the file again for writing
    ofstream outFile("quantity.txt");
    if (!outFile.is_open())
    {
        cerr << "Failed to open the file for writing!\n";
        return false;
    }

    // Write the updated quantities back to the file
    for (int i = 0; i < 6; ++i)
    {
        outFile << quantities[i] << endl;
    }
    outFile.close();

    return true;
}

int getQuantityOnLine(int x)
{
    // Open the file for reading
    ifstream file("quantity.txt");
    if (!file.is_open())
    {
        cerr << "\n\t\t\t>>>Failed to open the file for reading!\n";
        return -1; // Return -1 to indicate failure
    }

    // Read the integer value on the specified line
    string line;
    int quantity;
    for (int i = 1; i <= x; ++i)
    {
        if (!getline(file, line))
        {
            cerr << "\n\t\t\t>>>Failed to read line " << x << " from the file!\n";
            file.close();
            return -1; // Return -1 to indicate failure
        }
        if (i == x)
        {
            istringstream iss(line);
            if (!(iss >> quantity))
            {
                cerr << "\n\t\t\t>>>Failed to convert line " << x << " to an integer!\n";
                file.close();
                return -1; // Return -1 to indicate failure
            }
        }
    }
    file.close();

    return quantity; // Return the integer value on line x
}
void readQuantityFile()
{
    // Open the file for reading
    ifstream file("quantity.txt");
    if (!file.is_open())
    {
        cerr << "\n\t\t\tFailed to open the file for reading!\n"
             << endl;
        return; // Exit the function if file opening fails
    }

    // Read and print each line of the file
    string line;
    int lineNumber = 1;
    while (getline(file, line))
    {
        string carName;
        switch (lineNumber)
        {
        case 1:
            carName = "Corolla";
            break;
        case 2:
            carName = "Civic";
            break;
        case 3:
            carName = "Hilux";
            break;
        case 4:
            carName = "City";
            break;
        case 5:
            carName = "Sonata";
            break;
        case 6:
            carName = "WagonR";
            break;
        default:
            carName = "Unknown"; // Handle Unknown Cars...
            break;
        }
        cout << carName << " quantity: " << line << endl;
        lineNumber++;
    }

    file.close();
}
void resetFiles()
{
    // Clear "Cars Info.txt"
    ofstream carsInfoFile("Cars Info.txt", ios::trunc);
    if (!carsInfoFile.is_open())
    {
        cerr << "\n\t\t\t>>>Failed to open Cars Info file for writing!\n"
             << endl;
    }
    else
    {
        carsInfoFile.close();
        // cout << "Cars Info file cleared successfully!\n";
    }

    // Clear "CNIC.txt"
    ofstream cnicFile("CNIC.txt", ios::trunc);
    if (!cnicFile.is_open())
    {
        cerr << "\n\t\t\t>>>Failed to open CNIC file for writing!\n"
             << endl;
    }
    else
    {
        cnicFile.close();
        // cout << "CNIC file cleared successfully!\n";
    }

    // Set first six lines of "quantity.txt" to "2"
    ofstream quantityFile("quantity.txt");
    if (!quantityFile.is_open())
    {
        cerr << "\n\t\t\t>>>Failed to open quantity file for writing!\n"
             << endl;
    }
    else
    {
        for (int i = 0; i < 6; ++i)
        {
            quantityFile << "2\n";
        }
        quantityFile.close();
        // cout << "Quantity file updated successfully!\n";
    }
}

//----------------------------------------------------------------

void setColor(int color)
{
    cout << "\033[" << color << "m";
}
void resetColor()
{
    cout << "\033[0m"; // Reset color
}

void drawCar(int position)
{
    for (int i = 0; i < position; ++i)
    {
        cout << " ";
    }
    // Car body
    setColor(33);
    cout << "  ___" << endl;
    resetColor();
    for (int i = 0; i < position; ++i)
    {
        cout << " ";
    }
    cout << " /|||\\`.___" << endl;
    for (int i = 0; i < position; ++i)
    {
        cout << " ";
    }
    cout << "(  __    ___\\" << endl;

    // Wheels
    for (int i = 0; i < position + 1; ++i)
    {
        cout << " ";
    }
    cout << " (o\\./o)" << endl;
}

void load_screen()
{
    setColor(31);
    int car1Position = 15;
    int car2Position = 30;

    // Hide cursor
    cout << "\033[?25l";

    //while (car1Position < 50 && car2Position < 50)
    //{
        system("cls");
        drawCar(car1Position);
        cout << endl;
        drawCar(car2Position);
        cout << endl;
        car1Position += 1;
        car2Position += 2; // Car 2 moves faster

        Sleep(40000);
    //}
    resetColor();
    system("cls");

    if (car1Position >= 80)
    {
        cout << "Car 1 wins!" << endl;
    }
    else
    {
        cout << "Car 2 wins!" << endl;
    }

    // Show cursor
    cout << "\033[?25h";
}
