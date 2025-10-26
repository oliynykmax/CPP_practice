#include "../inc/BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

static bool isFloatOrInt(const std::string &str) {
  std::istringstream iss(str);
  double value;
  iss >> value;
  return iss.eof() && !iss.fail();
}

void BitcoinExchange::queryAndPrint(std::chrono::year_month_day date,
                                    double value) {
  auto it = data.lower_bound(date);
  if (it == data.end() || it->first > date) {
    if (it == data.begin()) {
      std::cerr << "No earlier data available for " << date << '\n';
      return;
    }
    --it;
  }
  std::cout << date << " => " << value << " = " << it->second * value << '\n';
}

void BitcoinExchange::processFile(const std::string &filename) {
  std::ifstream file(filename);
  if (!file.is_open())
    throw std::runtime_error("Error: could not open file.");
  std::string line;
  std::getline(file, line);
  if (line != "date | value")
    throw std::runtime_error("Error: invalid header." + filename);
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string date_str, value_str;
    std::getline(ss, date_str, '|');
    std::getline(ss, value_str);
    std::istringstream date_stream(date_str);
    std::chrono::year_month_day date;
    date_stream >> std::chrono::parse("%F", date);
    if (date_stream.fail() || !date.ok()) {
      std::cerr << "Error: bad input => " << date_str << std::endl;
      continue;
    }
    if (value_str.empty()) {
      std::cerr << "Error: bad input => empty value." << std::endl;
      continue;
    }
    if (!isFloatOrInt(value_str)) {
      std::cerr << "Error: bad input => " << value_str << std::endl;
      continue;
    }
    double value = std::stod(value_str);
    if (value > 1000) {
      std::cerr << "Error: too large a number." << std::endl;
      continue;
    }
    if (value < 0) {
      std::cerr << "Error: not a positive number." << std::endl;
      continue;
    }
    queryAndPrint(date, value);
  }
}

BitcoinExchange::BitcoinExchange() {
  std::ifstream file("data.csv");
  if (!file.is_open())
    throw std::runtime_error("Cannot open data.csv");
  std::string line;
  std::getline(file, line);
  if (line != "date,exchange_rate")
    throw std::runtime_error("Invalid header in data.csv");
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string rate_str, date_str;

    if (!std::getline(ss, date_str, ',') or !std::getline(ss, rate_str))
      throw std::runtime_error("Invalid data format in data.csv");
    try {
      double rate = std::stod(rate_str);
      std::istringstream date_stream(date_str);
      std::chrono::year_month_day date;
      date_stream >> std::chrono::parse("%F", date);
      if (date_stream.fail() || !date.ok()) {
        throw std::invalid_argument("invalid date format");
      }
      data[date] = rate;
    } catch (const std::exception &e) {
      throw std::runtime_error("Invalid line format in data.csv");
    }
  }
}
