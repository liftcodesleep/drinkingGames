#include "fstream"
#include "vector"
#include "sstream"
#include "student.cpp"
#include "iomanip"
#include "iostream"

std::vector<Student> parse(std::ifstream &file)
{
  std::vector<Student> students;
  std::string line;
  int row = 0;
  int index = 0;
  while (std::getline(file, line))
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
  for (int currentRow = 1; currentRow < row; currentRow++)
  {
    Student student;
    // std::cout << data[currentRow][GradeIndex] << std::endl;
    student.setDalc(stoi(data[currentRow][DalcIndex]));
    student.setWalc(stoi(data[currentRow][WalcIndex]));
    student.setGrade(stoi(data[currentRow][GradeIndex]));
    students.push_back(student);
  }
  return students;
}

void getDistro(std::vector<Student> students)
{
  int studentNum = 0;
  for (auto student : students)
  {
    studentNum++;
    std::cout << "Student " << studentNum << "'s daily alcohol rate: " << student.getDalc() << std::endl
              << "Student " << studentNum << "'s weekend alcohol rate: " << student.getWalc() << std::endl
              << "Student " << studentNum << "'s final grade: " << student.getGrade() << std::endl;
  }
}

int main()
{
  std::ifstream file1("archive/student-mat.csv");
  // std::ifstream file2("archive/student-por.csv");
  getDistro(parse(file1));
  // getDistro(parse(file2));
}