#ifndef VALIDATE_CPP
#define VALIDATE_CPP
#include "iostream"
#include "regex"
#include "string"
#include "sstream"
#include "iomanip"
using namespace std;

class Validate {
public:
    static bool validateNgay(const string& ngay);
    static bool validateSoDienThoai(const string& soDienThoai);
    static bool validateEmail(const string& email);
    static bool validateCMND(const string& cmnd);

private:
    static bool isLeapYear(int year);
    static bool isValidDate(int day, int month, int year);
};

bool Validate::validateNgay(const string& ngay) {
    regex pattern("^([0-2][0-9]|3[0-1])/(0[1-9]|1[0-2])/([0-9]{4})$");
    if (!regex_match(ngay, pattern)) {
        return false;
    }

    int day, month, year;
    char delimiter;
    stringstream ss(ngay);
    ss >> day >> delimiter >> month >> delimiter >> year;

    return isValidDate(day, month, year);
}

bool Validate::isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool Validate::isValidDate(int day, int month, int year) {
    if (month < 1 || month > 12) return false;

    int daysInMonth[] = { 31, (isLeapYear(year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    return (day >= 1 && day <= daysInMonth[month - 1]);
}

bool Validate::validateSoDienThoai(const string& soDienThoai) {
    regex pattern("^0[0-9]{9}$");
    return regex_match(soDienThoai, pattern);
}

bool Validate::validateEmail(const string& email) {
    regex pattern("^[\\w-\\.]+@([\\w-]+\\.)+[\\w-]{2,4}$");
    return regex_match(email, pattern);
}

bool Validate::validateCMND(const string& cmnd) {
    if (cmnd.length() != 12) return false; 
    for (char c : cmnd) {
        if (!isdigit(c)) return false;
    }
    return true;
}

#endif
