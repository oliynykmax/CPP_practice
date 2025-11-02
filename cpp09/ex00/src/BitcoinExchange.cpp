#include "../inc/BitcoinExchange.hpp"
#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <string>

static bool isFloatOrInt(const std::string &str) {
  std::istringstream iss(str);
  double value;
  iss >> value;
  return iss.eof() && !iss.fail();
}

static std::string ymd_to_string(const std::chrono::year_month_day &d) {
  std::ostringstream oss;
  oss << int(d.year()) << '-';
  oss << std::setfill('0') << std::setw(2) << unsigned(d.month()) << '-'
      << std::setfill('0') << std::setw(2) << unsigned(d.day());
  return oss.str();
}

void BitcoinExchange::queryAndPrint(std::chrono::year_month_day date,
                                    double value) {
  auto it = data.lower_bound(date);
  if (it == data.end() || it->first > date) {
    if (it == data.begin()) {
      std::cerr << "No earlier data available for " << ymd_to_string(date)
                << '\n';
      return;
    }
    --it;
  }
  std::cout << ymd_to_string(date) << " => " << value << " = "
            << it->second * value << '\n';
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
    std::chrono::year_month_day date;
    {
      int y = 0, m = 0, d = 0;
      char sep1 = 0, sep2 = 0;
      std::istringstream ds(date_str);
      if (!(ds >> y >> sep1 >> m >> sep2 >> d) || sep1 != '-' || sep2 != '-') {
        std::cerr << "Error: bad input => " << date_str << std::endl;
        continue;
      }
      date = std::chrono::year_month_day{
          std::chrono::year(y), std::chrono::month(static_cast<unsigned>(m)),
          std::chrono::day(static_cast<unsigned>(d))};
      if (!date.ok()) {
        std::cerr << "Error: bad input => " << date_str << std::endl;
        continue;
      }
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
    std::string date_str, rate_str;

    if (!std::getline(ss, date_str, ',') || !std::getline(ss, rate_str))
      throw std::runtime_error("Invalid data format in data.csv");
    auto trim = [](std::string &s) {
      size_t a = s.find_first_not_of(" \t\r\n");
      size_t b = s.find_last_not_of(" \t\r\n");
      if (a == std::string::npos)
        s.clear();
      else
        s = s.substr(a, b - a + 1);
    };
    trim(date_str);
    trim(rate_str);

    try {
      double rate = std::stod(rate_str);
      std::chrono::year_month_day date;
      {
        int y = 0, m = 0, d = 0;
        char sep1 = 0, sep2 = 0;
        std::istringstream ds(date_str);
        if (!(ds >> y >> sep1 >> m >> sep2 >> d) || sep1 != '-' ||
            sep2 != '-') {
          throw std::invalid_argument("invalid date format");
        }
        date = std::chrono::year_month_day{
            std::chrono::year(y), std::chrono::month(static_cast<unsigned>(m)),
            std::chrono::day(static_cast<unsigned>(d))};
        if (!date.ok()) {
          throw std::invalid_argument("invalid date format");
        }
      }
      data[date] = rate;
    } catch (const std::exception &e) {
      throw std::runtime_error("Invalid line format in data.csv");
    }
  }
}
