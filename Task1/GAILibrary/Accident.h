#pragma once
#include <string>
#include <chrono>

class Accident final :public std::enable_shared_from_this<Accident>
{
    public:
        std::chrono::system_clock::time_point date;
        std::string description;

        Accident(const std::chrono::system_clock::time_point& date, const std::string& description);

        std::string getInfo() const;

        std::string dateToString() const;

        void setDateFromString(const std::string& dateStr);
};