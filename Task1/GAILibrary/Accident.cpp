#include "Accident.h"
#include <sstream>
#include <iomanip>

Accident::Accident(const std::chrono::system_clock::time_point& date, const std::string& description)
    : date(date), description(description) {}

std::string Accident::getInfo() const 
{
    std::ostringstream oss;
    oss << "Date: " << dateToString() << "\nDescription: " << description;
    return oss.str();
}

std::string Accident::dateToString() const 
{
    std::time_t time = std::chrono::system_clock::to_time_t(date);
    std::ostringstream oss;
    oss << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

void Accident::setDateFromString(const std::string& dateStr) 
{
    std::tm tm = {};
    std::istringstream iss(dateStr);
    iss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
    date = std::chrono::system_clock::from_time_t(std::mktime(&tm));
}