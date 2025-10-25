#pragma once

#include <chrono>
#include <map>
#include <iostream>

class BitcoinExchange {
    private:
    std::map<std::chrono::year_month_day, double> data;
    public:
    BitcoinExchange();
    BitcoinExchange &operator=(const BitcoinExchange& other) = default;
    BitcoinExchange(const BitcoinExchange& other) = default;
    ~BitcoinExchange() = default;

    void processFile(const std::string& input);
    void queryAndPrint(std::chrono::year_month_day date, double value);
};
