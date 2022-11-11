#include "fstream"
#include "vector"
#include "sstream"
#include "student.cpp"
#include "iomanip"

std::vector<Student> parse(std::fstream &file)
{
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
  return students;
}

void getDistro(std::vector<Student> students)
{

  for (auto student : students)
  {
  }
}

int main()
{
  std::fstream file1("student-mat.csv");
  std::fstream file2("student-por.csv");
  getDistro(parse(file1));
  getDistro(parse(file2));
}