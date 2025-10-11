#pragma once

class Data {
private:
  int numbers;
  double details;

public:
  Data() = default;
  ~Data() = default;
  Data(int num, double details);
  Data(const Data &other) = default;
  Data &operator=(const Data &other) = default;
};
