#pragma once
#include "Project_Class.h"

// Cars Class Functions Definitions --------------------------------
cars::cars()
{
    this->car_name = "";
    this->car_number = "";
    this->colour = "";
    this->model = 0;
    this->price_per_day = 0.0;
    this->price_per_hour = 0.0;
}

string cars::get_car_name()
{
    return this->car_name;
}

string cars::get_car_number()
{
    return this->car_number;
}

string cars::get_color()
{
    return this->colour;
}

int cars::get_model()
{
    return this->model;
}

double cars::get_price_per_hour()
{
    return this->price_per_hour;
}

double cars::get_price_per_day()
{
    return this->price_per_day;
}

void cars::SetData(string car_name, string car_number, string colour, int model, double price_per_hour, double price_per_day)
{
    this->car_number = car_number;
    this->car_name = car_name;
    this->model = model;
    this->colour = colour;
    this->price_per_hour = price_per_hour;
    this->price_per_day = price_per_day;
}

string cars::get_carname()
{
    return car_name;
}
cars::~cars()
{
}

// Person Class Functions Definitions --------------------------------

Person::Person()
{
    this->name = "";
    this->address = "";
    this->CNIC = "";
    this->Number = "";
    this->status = false;
}

string Person::get_name()
{
    return name;
}

string Person::get_address()
{
    return this->address;
}

string Person::get_CNIC()
{
    return this->CNIC;
}

string Person::Get_Number()
{
    return this->Number;
}

bool Person::get_status()
{
    return this->status;
}

void Person::SetData(string name, string address, string CNIC, string Number, bool status)
{
    this->name = name;
    this->address = address;
    this->CNIC = CNIC;
    this->Number = Number;
    this->status = status;
}

Person::~Person()
{
}

// Booked_Car Class Functions Definitions --------------------------------

Booked_Car::Booked_Car()
{
    this->returnTime = 0;
    this->booked = 0;
}

void Booked_Car::Add_one()
{
    booked += 1;
}

void Booked_Car::setReturnTime(int time)
{
    returnTime = time;
}

double Booked_Car::getRentalDurationInHours(int currentTime)
{
    return difftime(currentTime, returnTime) / (60 * 60); // Convert seconds to hours
}

double Booked_Car::calculateFine(double hourlyRate, double dailyRate, int currentTime)
{
    double rentalDuration = getRentalDurationInHours(currentTime);
    if (rentalDuration > 24) // If rental duration exceeds 24 hours, charge daily rate
    {
        return (rentalDuration / 24) * dailyRate;
    }
    else // Otherwise, charge hourly rate
    {
        return rentalDuration * hourlyRate;
    }
}

void Booked_Car::Set_Booked(cars &c, Person &p)
{
    ofstream Write;

    Write.open("Cars Info.txt", ios::app);
    if (Write.is_open())
    {
        Write << "BOOKED CAR : " << endl;
        Write << "================" << endl;
        Write << endl;
        Write << "\t\tCAR INFO : " << endl;
        Write << "\t\t========== " << endl;
        Write << "\t\t\t Car Name : " << c.get_carname() << "\n\t\t\t Car Model : " << c.get_model() << "\n\t\t\t Car Number : " << c.get_car_number() << "\n\t\t\t Car Color : " << c.get_color() << "\n\n";
        Write << "\t\tCUSTOMER INFO : \n";
        Write << "\t\t===============\n";
        Write << "\t\t\t Name : " << p.get_name() << "\n\t\t\t CNIC : " << p.get_CNIC() << "\n\t\t\t Status is active" << "\n\t\t\t Phone Number : " << p.Get_Number() << "\n\t\t\t Address : " << p.get_address();

        Write << endl;
    }
    ofstream Write2;

    Write2.open("CNIC.txt", ios::app);
    if (Write2.is_open())
    {
        Write2 << p.get_CNIC() << endl;
    }
}

void Booked_Car::Get_Booked()
{
    ifstream Read;
    Read.open("Cars Info.txt", ios::in);
    char data;
    if (Read.is_open())
    {
        while (!Read.eof())
        {
            Read >> noskipws >> data;
            cout << data;
        }
        Read.close();
    }
    else
    {
        cout << "File Not Found ! \n";
    }
}

Booked_Car::~Booked_Car()
{
}

// Total_Rent Class Functions Definitions --------------------------------

TotalRent::TotalRent()
{
    this->total = 0;
    this->hours = 0;
    this->days = 0;
}

int TotalRent::get_days()
{
    return this->days;
}

double TotalRent::get_hours()
{
    return this->hours;
}

void TotalRent::Set_day(int days)
{
    this->days = days;
}

void TotalRent::Set_hour(double hours)
{
    this->hours = hours;
}

double TotalRent::Calculate_price_per_day(cars &obj)
{
    total = obj.get_price_per_day() * days;
    return total;
}

double TotalRent::Calculate_price_per_hour(cars &obj)
{
    total = obj.get_price_per_hour() * hours;
    return total;
}

double TotalRent::get_Total()
{
    return this->total;
}

TotalRent::~TotalRent()
{
}

// End of Header file for all Classes Functions Definitions...