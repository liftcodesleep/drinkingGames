#include "fstream"
#include "sstream"
#include "iomanip"
#include "./Stats.h"

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
    std::vector<Student> matStudents = parse(file1);
    std::vector<Student> porStudents = parse(file2);

    debugPrint(matStudents);
    debugPrint(porStudents);
    std::cout << "\n\n\n";

    // averages
    double mathGradeAverage = Stats::gradeAverage(matStudents, 0, 0);
    int mathDAlcAvg = Stats::dAlcAverage(matStudents);
    int mathWAlcAvg = Stats::wAlcAverage(matStudents);
    double mathAlcGradeAverage = Stats::gradeAverage(matStudents, mathDAlcAvg, mathWAlcAvg);

    // calc and output math grade
    int mathGrades[20] = { 0 };
    Stats::countStudentGrades(matStudents, mathGrades, 0, 0);
    std::cout << "::Math class grades::" << std::endl;
    std::cout << std::fixed << std::setprecision(2)  << "-Average grade: " << mathGradeAverage << std::endl;
    Stats::printHistogram(mathGrades, 20, "Num of Students", "Grades");

    std::cout << "\n\n\n";

    // calc and output math grades of students who drink above average days of the class
    int alcAvgMathGrades[20] = { 0 };
    Stats::countStudentGrades(matStudents, alcAvgMathGrades, mathDAlcAvg, mathWAlcAvg);
    std::cout << "::Above average alcohol consumption student grades::" << std::endl;
    std::cout << std::setprecision(2)  << "-Average grade: " << mathAlcGradeAverage << std::endl;
    Stats::printHistogram(alcAvgMathGrades, 20, "Num of Students", "Grades");


}