#ifndef DRINKINGGAMES_UNIT_TESTS_H
#define DRINKINGGAMES_UNIT_TESTS_H

#include "Stats.h"

namespace unit_tests {

    bool testDAlcAverage_1() {
        std::vector<Student> students;
        students.push_back(Student(2,2,5,15));
        students.push_back(Student(2,2,5,15));
        students.push_back(Student(2,2,5,15));
        students.push_back(Student(2,2,5,15));
        students.push_back(Student(2,2,5,15));

        int dAlc = Stats::dAlcAverage(students);
        
        return dAlc == 2;
    }

    bool testDAlcAverage_2() {
        std::vector<Student> students;
        students.push_back(Student(0,2,5,15));
        students.push_back(Student(2,2,5,15));
        students.push_back(Student(1,2,5,15));
        students.push_back(Student(2,2,5,15));
        students.push_back(Student(4,2,5,15));

        int dAlc = Stats::dAlcAverage(students);
        
        return dAlc == 1;
    }

    bool testDAlcAverage_3() {
        std::vector<Student> students;
        students.push_back(Student(0,2,5,15));
        students.push_back(Student(0,2,5,15));
        students.push_back(Student(0,2,5,15));
        students.push_back(Student(0,2,5,15));
        students.push_back(Student(2,2,5,15));

        int dAlc = Stats::dAlcAverage(students);
        
        return dAlc == 0;
    }

    bool testWAlcAverage_1() {
        std::vector<Student> students;
        students.push_back(Student(2,2,5,15));
        students.push_back(Student(2,2,5,15));
        students.push_back(Student(2,2,5,15));
        students.push_back(Student(2,2,5,15));
        students.push_back(Student(2,2,5,15));

        int dAlc = Stats::dAlcAverage(students);
        
        return dAlc == 2;
    }

    bool testWAlcAverage_2() {
        std::vector<Student> students;
        students.push_back(Student(0,0,5,15));
        students.push_back(Student(2,2,5,15));
        students.push_back(Student(1,1,5,15));
        students.push_back(Student(2,2,5,15));
        students.push_back(Student(4,4,5,15));

        int dAlc = Stats::dAlcAverage(students);
        
        return dAlc == 1;
    }

    bool testWAlcAverage_3() {
        std::vector<Student> students;
        students.push_back(Student(0,0,5,15));
        students.push_back(Student(0,0,5,15));
        students.push_back(Student(0,0,5,15));
        students.push_back(Student(0,0,5,15));
        students.push_back(Student(2,2,5,15));

        int dAlc = Stats::dAlcAverage(students);
        
        return dAlc == 0;
    }

    bool testAttAverage_1() {
        std::vector<Student> students;
        students.push_back(Student(2,2,2,15));
        students.push_back(Student(2,2,2,15));
        students.push_back(Student(2,2,2,15));
        students.push_back(Student(2,2,2,15));
        students.push_back(Student(2,2,2,15));

        int dAlc = Stats::dAlcAverage(students);
        
        return dAlc == 2;
    }

    bool testAttAverage_2() {
        std::vector<Student> students;
        students.push_back(Student(0,0,0,15));
        students.push_back(Student(2,2,2,15));
        students.push_back(Student(1,1,1,15));
        students.push_back(Student(2,2,2,15));
        students.push_back(Student(4,4,4,15));

        int dAlc = Stats::dAlcAverage(students);
        
        return dAlc == 1;
    }

    bool testAttAverage_3() {
        std::vector<Student> students;
        students.push_back(Student(0,0,0,15));
        students.push_back(Student(0,0,0,15));
        students.push_back(Student(0,0,0,15));
        students.push_back(Student(0,0,0,15));
        students.push_back(Student(2,2,2,15));

        int dAlc = Stats::dAlcAverage(students);
        
        return dAlc == 0;
    }

    bool testgradeAverageByAtt() {

        std::vector<Student> students;
        students.push_back(Student(2,2,5,15));
        students.push_back(Student(2,2,5,15));
        students.push_back(Student(2,2,5,15));
        students.push_back(Student(2,2,5,15));
        students.push_back(Student(2,2,5,15));

        int avg = 2;

        return Stats::gradeAverageByAtt(students, avg) == 15;
    }

    bool testgradeAverageByAlc() {
        std::vector<Student> students;
        students.push_back(Student(2,2,5,15));
        students.push_back(Student(2,2,5,15));
        students.push_back(Student(2,2,5,15));
        students.push_back(Student(2,2,5,15));
        students.push_back(Student(2,2,5,15));

        int dAlc = 1;
        int wAlc = 1;

        return Stats::gradeAverageByAlc(students, dAlc, wAlc) == 15;
    }

    bool testCountGradesByAtt() {
        std::vector<Student> students;
        students.push_back(Student(2,2,2,15));
        students.push_back(Student(2,2,2,15));
        students.push_back(Student(2,2,2,15));
        students.push_back(Student(2,2,2,15));
        students.push_back(Student(2,2,2,15));
        int expected[20] = {0};
        int actual[20] = {0};

        expected[15] = 5;
    
        Stats::countGradesByAtt(students, actual, 1);

        for (int i=0; i < 20; i++) {
            if (expected[i] != actual[i]) {
                return false;
            }
        }

        return true;
    }

   bool testCountGradesByAlc() {
    std::vector<Student> students;
        students.push_back(Student(2,2,2,15));
        students.push_back(Student(2,2,2,15));
        students.push_back(Student(2,2,2,15));
        students.push_back(Student(2,2,2,15));
        students.push_back(Student(2,2,2,15));
        int expected[20] = {0};
        int actual[20] = {0};

        expected[15] = 5;

        Stats::countGradesByAlc(students, actual, 1, 1);

        for (int i=0; i < 20; i++) {
            if (expected[i] != actual[i]) {
                return false;
            }
        }

        return true;
   }
}

#endif // DRINKINGGAMES_UNIT_TESTS_H