
#ifndef DRINKINGGAMES_STATS_H
#define DRINKINGGAMES_STATS_H


#include <iostream>
#include <vector>
#include <array>
#include "student.cpp"

class Stats {
public:
    // calculate averages
    static int dAlcAverage(const std::vector<Student>& students);
    static int wAlcAverage(const std::vector<Student>& students);
    static int attendanceAverage(const std::vector<Student>& students);

    // calculates average student grade
    // can filter by daly/weekly alcohol consumption
    static double gradeAverageByAlc(const std::vector<Student>& students,  int dAlc, int wAlc);

    // calculates average student grade     
    // can filter by attendance
    static double gradeAverageByAtt(const std::vector<Student>& students,  int attAvg);

    // counts the number of students with grades 1-20 and populates grades arr
    // can filter and count grades by daly/weekly alcohol consumption
    static void countGradesByAlc(const std::vector<Student>& students, int grades[], int dAlcFilter, int wAlcFilter);

    // counts the number of students with grades 1-20 and populates grades arr
    // can filter and count grades by number of missed days
    static void countGradesByAtt(const std::vector<Student>& students, int grades[], int attAvg);

    // output histogram to console with provided axis labels
    static void printHistogram(int stats[], int size, std::string yAxis, std::string xAxis);

    // counts the number of students from grade report 
    static int studentCount(int grades[]);

private:
    static int greatestValue(int stats[], int size);
    static void printWhitespace(int length);
};

#endif //DRINKINGGAMES_STATS_H
