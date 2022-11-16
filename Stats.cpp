
#include "Stats.h"

int Stats::dAlcAverage(const std::vector<Student>& students) {
    int count = 0;
    int numStudents = 0;

    for (auto student : students) {
        count += student.getDalc();
        numStudents++;
    }

    return count / numStudents;
}


int Stats::wAlcAverage(const std::vector<Student>& students) {
    int count = 0;
    int numStudents = 0;

    for (auto student : students) {
        count += student.getWalc();
        numStudents++;
    }

    return count / numStudents;
}



int Stats::attendanceAverage(const std::vector<Student>& students) {
    int count = 0;
    int numStudents = 0;

    for (auto student : students) {
        count += student.getAttendance();
    }

    return count / numStudents;
}


double Stats::gradeAverage(const std::vector<Student>& students, int dAlc, int wAlc) {
    double count = 0.0;
    double numOfStudents = 0.0;

    for (auto student : students) {
        if (student.getDalc() > dAlc && student.getWalc() > wAlc) {
            count += student.getGrade();
            numOfStudents++;
        }
    }
    std::cout << "total grade: " << count << std::endl;
    std::cout << "num students: " << numOfStudents << std::endl;

    return count / numOfStudents;
}


void Stats::printHistogram(int stats[], int size, std::string yAxis, std::string xAxis) {
    int maxNumStudents = greatestValue(stats, size);

    // middle index for axis labels
    int yAxisIndex = maxNumStudents / 2;
    int xAxisIndex = size / 2;

    // adjust for odd numbers
    if (yAxisIndex % 2 != 0) {
        yAxisIndex++;
    }

    std::cout<< std::endl;

    for (int i = maxNumStudents; i >= 1; i--) {

        // display y-axis label
        if (i == yAxisIndex) {
            std::cout <<"(" << yAxis << ") ";
        }

        // increment by 2 to save space
        if (i % 2 == 0) {

            // add space to rows to align with label
            if (i != yAxisIndex) {
                printWhitespace(yAxis.size() + 3);
            }

            // format rows starting with largest value
            std::cout.width(3);
            std::cout << std::right << i << " | ";


            for (int j = 0; j<size; j++) {
                if (stats[j] < i) {

                    std::cout << "     ";
                }
                else {
                    std::cout << "  #  ";
                }
            }
            std::cout << std::endl;
        }
    }

    // add x-axis line
    printWhitespace(yAxis.size() + 4);
    for (int i = 0; i < size+2; i++) {
        std::cout << "-----";
    }

    // adjust for y-axis label
    std::cout << std::endl;
    printWhitespace(yAxis.size() + 4);

    // add x-axis numbers
    printWhitespace(6);
    for (int i = 0; i < size; i++) {
        std::cout.width(2);
        std::cout << std::right << i+1 << "   ";
    }

    // add x-axis label
    std::cout << std::endl;
    printWhitespace(xAxisIndex * 6);
    std::cout << "(" << xAxis << ")" << std::endl;
}


void Stats::countStudentGrades(
        const std::vector<Student>& students,
        int grades[],
        int dAlcFilter,
        int wAlcFilter) {

    for (auto student : students) {
        int dAlc = student.getDalc();
        int wAlc = student.getWalc();

        if (dAlc > dAlcFilter && wAlc > wAlcFilter) {
            grades[student.getGrade()]++;
        }
    }
}


int Stats::greatestValue(int stats[], int size) {
    int value = 0;

    for (int i = 0; i<size; i++) {
        if (stats[i] > value) {
            value = stats[i];
        }
    }
    return value;
}


void Stats::printWhitespace(int length) {
    for (int i = 0; i < length; i++) {
        std::cout << " ";
    }
}

