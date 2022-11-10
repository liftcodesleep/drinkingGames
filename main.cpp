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
  int DalcIndex = 26;
  int WalcIndex = 27;
  int GradeIndex = 32;
  for (int currentRow = 0; currentRow < row; currentRow++)
  {
    Student student;
    student.setDalc(stoi(data[row][DalcIndex]));
    student.setDalc(stoi(data[row][WalcIndex]));
    student.setDalc(stoi(data[row][GradeIndex]));
    students.push_back(student);
  }
}