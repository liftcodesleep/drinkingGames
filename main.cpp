#include "fstream"
#include "vector"
#include "sstream"
#include "student.cpp"
#include "iomanip"

void parse()
{
  std::fstream file("student-mat.csv");
  std::vector<Student> students;
  std::string line;
  int row = 0;
  int index = 0;
  while (getline(file, line))
  {
    row++;
  }
  std::vector<std::string> data[row];
  file.clear();
  file.seekg(file.beg);
  while (getline(file, line))
  {
    std::stringstream s(line);
    std::string value;
    while (getline(s, value, ','))
    {
      data[index].push_back(value);
    }
    index++;
  }
  file.close();
  for (int currentRow = 0; currentRow < row; currentRow++)
  {
  }
