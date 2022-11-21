#include "fstream"
#include "sstream"
#include "iomanip"
#include "UnitTests.h"

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
  // open and read files
  std::ifstream file1("archive/student-mat.csv");
  std::ifstream file2("archive/student-por.csv");
  std::vector<Student> matStudents = parse(file1);
  std::vector<Student> porStudents = parse(file2);

  // math averages
  double mathGradeAverage = Stats::gradeAverageByAlc(matStudents, 0, 0);
  int mathDAlcAvg = Stats::dAlcAverage(matStudents);
  int mathWAlcAvg = Stats::wAlcAverage(matStudents);
  int mathAttAvg = Stats::attendanceAverage(matStudents);
  double mathAlcGradeAverage = Stats::gradeAverageByAlc(matStudents, mathDAlcAvg, mathWAlcAvg);
  double mathAttGradeAverage = Stats::gradeAverageByAtt(matStudents, mathAttAvg);
  

  // portuguese averages
  double portGradeAverage = Stats::gradeAverageByAlc(porStudents, 0, 0);
  int portDAlcAvg = Stats::dAlcAverage(porStudents);
  int portWAlcAvg = Stats::wAlcAverage(porStudents);
  int portAttAvg = Stats::attendanceAverage(porStudents);
  double portAlcGradeAverage = Stats::gradeAverageByAlc(porStudents, portDAlcAvg, portWAlcAvg);
  double portAttGradeAverage = Stats::gradeAverageByAtt(porStudents, portAttAvg);

  // calc and output math grade
  int mathGrades[20] = { 0 };
  Stats::countGradesByAlc(matStudents, mathGrades, 0, 0);
  std::cout << "::Math class grades::" << std::endl;
  std::cout << "-Sample size: " << Stats::studentCount(mathGrades) << std::endl;
  std::cout << std::fixed << std::setprecision(2)  << "-Average grade: " << mathGradeAverage << std::endl;
  Stats::printHistogram(mathGrades, 20, "Num of Students", "Grades");

  std::cout << "\n\n\n";

  // calc and output portuguese grades
  int portGrades[20] = { 0 };
  Stats::countGradesByAlc(porStudents, portGrades, 0, 0);
  std::cout << "::Portuguese class grades::" << std::endl;
  std::cout << "-Sample size: " << Stats::studentCount(portGrades) << std::endl;
  std::cout << std::fixed << std::setprecision(2)  << "-Average grade: " << portGradeAverage << std::endl;
  Stats::printHistogram(portGrades, 20, "Num of Students", "Grades");

  std::cout << "\n\n\n";

  // calc and output math grades of students who drink above class average
  int alcAvgMathGrades[20] = { 0 };
  Stats::countGradesByAlc(matStudents, alcAvgMathGrades, mathDAlcAvg, mathWAlcAvg);
  std::cout << "::Above average alcohol consumption Math student grades::" << std::endl;
  std::cout << "-Sample size: " << Stats::studentCount(alcAvgMathGrades) << std::endl;
  std::cout << std::fixed << std::setprecision(2)  << "-Class Average: " << mathGradeAverage << std::endl;
  std::cout << std::setprecision(2)  << "-Average grade: " << mathAlcGradeAverage << std::endl;
  Stats::printHistogram(alcAvgMathGrades, 20, "Num of Students", "Grades");

  std::cout << "\n\n\n";

  // calc and output portuguese grades of students who drink above class average
  int alcAvgPortGrades[20] = { 0 };
  Stats::countGradesByAlc(porStudents, alcAvgPortGrades, portDAlcAvg, portWAlcAvg);
  std::cout << "::Above average alcohol consumption Portuguese student grades::" << std::endl;
  std::cout << "-Sample size: " << Stats::studentCount(alcAvgPortGrades) << std::endl;
  std::cout << std::fixed << std::setprecision(2)  << "-Class Average: " << portGradeAverage << std::endl;
  std::cout << std::setprecision(2)  << "-Average grade: " << portAlcGradeAverage << std::endl;
  Stats::printHistogram(alcAvgPortGrades, 20, "Num of Students", "Grades");

  std::cout << "\n\n\n";

  // calc and output math grades of students who miss more than average amount of days
  int attAvgMathGrades[20] = { 0 };
  Stats::countGradesByAtt(matStudents, attAvgMathGrades, mathAttAvg);
  std::cout << "::Below average attendance Math student grades::" << std::endl;
  std::cout << "-Sample size: " << Stats::studentCount(attAvgMathGrades) << std::endl;
  std::cout << "-Average # skipped classes: " << mathAttAvg << std::endl;
  std::cout << std::fixed << std::setprecision(2)  << "-Class Average: " << mathGradeAverage << std::endl;
  std::cout << std::setprecision(2)  << "-Average grade: " << mathAttGradeAverage << std::endl;
  Stats::printHistogram(attAvgMathGrades, 20, "Num of Students", "Grades");

  std::cout << "\n\n\n";

  // calc and output portuguese grades of students who miss more than average amount of days
  int attAvgPortGrades[20] = { 0 };
  Stats::countGradesByAtt(porStudents, attAvgPortGrades, portAttAvg);
  std::cout << "::Below average attendance Portuguese student grades::" << std::endl;
  std::cout << "-Sample size: " << Stats::studentCount(attAvgPortGrades) << std::endl;
  std::cout << "-Average # skipped classes: " << portAttAvg << std::endl;
  std::cout << std::fixed << std::setprecision(2)  << "-Class Average: " << portGradeAverage << std::endl;
  std::cout << std::setprecision(2)  << "-Average grade: " << portAttGradeAverage << std::endl;
  Stats::printHistogram(attAvgPortGrades, 20, "Num of Students", "Grades");

  std::cout << "\n\n\n";

  return 0;
}