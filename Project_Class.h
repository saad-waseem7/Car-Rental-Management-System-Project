#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <Windows.h>
#include <iomanip>
#include <cctype>
using namespace std;

class cars
{
protected:
    string car_name;
    string car_number;
    string colour;
    int model;
    double price_per_hour;
    double price_per_day;

public:
    cars();
    string get_car_name();
    string get_car_number();
    string get_color();
    int get_model();
    double get_price_per_hour();
    double get_price_per_day();
    void SetData(string car_name, string car_number, string colour, int model, double price_per_hour, double price_per_day);
    string get_carname();
    virtual ~cars();
};
class Person : public cars
{
protected:
    string name;
    string address;
    string CNIC;
    string Number;
    bool status;

public:
    Person();
    string get_name();
    string get_address();
    string get_CNIC();
    string Get_Number();
    bool get_status();
    void SetData(string name, string address, string CNIC, string Number, bool status);
    virtual ~Person();
};
class Booked_Car : public cars
{
private:
    int booked;
    int returnTime; // Member to store return time

public:
    Booked_Car();
    void Add_one();
    virtual void setReturnTime(int time);
    virtual double getRentalDurationInHours(int currentTime);
    virtual double calculateFine(double hourlyRate, double dailyRate, int currentTime);
    virtual void Set_Booked(cars &c, Person &p);
    virtual void Get_Booked();
    virtual ~Booked_Car();
};
class TotalRent : public cars
{
private:
    double total;
    int days;
    double hours;

public:
    TotalRent();
    int get_days();
    double get_hours();
    void Set_day(int days);
    void Set_hour(double hours);
    virtual double Calculate_price_per_day(cars &obj);
    virtual double Calculate_price_per_hour(cars &obj);
    virtual double get_Total();
    virtual ~TotalRent();
};