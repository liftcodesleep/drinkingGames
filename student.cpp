class Student
{
private:
  int Dalc = 0;
  int Walc = 0;
  int Attendance = 0;
  int Grade = 0;

public:
  int getDalc()
  {
    return this->Dalc;
  }
  int getWalc()
  {
    return this->Walc;
  }
  int getAttendance()
  {
    return this->Attendance;
  }
  int getGrade()
  {
    return this->Grade;
  }
  void setDalc(int Dalc)
  {
    this->Dalc = Dalc;
  }
  void setWalc(int Walc)
  {
    this->Walc = Walc;
  }
  void setAttendance(int Attendance)
  {
    this->Attendance = Attendance;
  }
  void setGrade(int Grade)
  {
    this->Grade = Grade;
  }
};