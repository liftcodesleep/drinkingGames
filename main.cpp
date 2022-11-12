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
  int AttendanceIndex = 29;
  int GradeIndex = 32;
  for (int currentRow = 1; currentRow < row; currentRow++)
  {
    Student student;
    student.setDalc(stoi(data[currentRow][DalcIndex]));
    student.setWalc(stoi(data[currentRow][WalcIndex]));
    student.setAttendance(stoi(data[currentRow][AttendanceIndex]));
    student.setGrade(stoi(data[currentRow][GradeIndex]));

    students.push_back(student);
  }
  return students;
}

void debugPrint(std::vector<Student> students)
{
  int studentNum = 0;
  for (auto student : students)
  {
    studentNum++;
    std::cout << "Student " << studentNum << "'s daily alcohol rate: " << student.getDalc() << ", weekend alcohol rate: " << student.getWalc() << ", Attendance Score: " << student.getAttendance() << ", final grade: " << student.getGrade() << std::endl;
  }
}

int main()
{
  std::ifstream file1("archive/student-mat.csv");
  std::ifstream file2("archive/student-por.csv");
  debugPrint(parse(file1));
  debugPrint(parse(file2));
}