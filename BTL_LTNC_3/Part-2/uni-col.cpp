/**
 * File: uni-col.cpp
 * ----------------
 * This program specifies all class and functions for managing student's information (in this part, we use C++ dynamic array data structure
 * to store the names of students).
 */
#include "uni-col.h"

/**
 * Function: running()
 * ------------------
 * This function prompts the user to manage their students. The user can choose to manage between two type of students
 */
void running()
{
    University group;
    int choice = -1;
    int supChoice = -1;
    srand(time(0));
    cout << "\t\tStudent Management program\n";
    cout << "\t\t--------------------------\n";
    while (true)
    {
        getInput(choice, supChoice);
        if (choice == 0)
        {
            break;
        }
        showOutput(group, choice, supChoice);
    }
}
/**
 * Function: getInput(int &user, int &subuser)
 * ------------------------------------------
 * This function prompts the user to interact with their student's data based on their choice.
 * @param user User's option between add, delete, display or assign scores
 * @param subuser User's option between managing university students or college students
 */
void getInput(int &user, int &subuser)
{
    cout << "Please make a choice (0 to quit):\n";
    cout << "1. Add a student to the system.\n";
    cout << "2. Display all students that has highest score in the system.\n";
    cout << "3. Display all students in the system.\n";
    cout << "4. Delete a student in the system.\n";
    cout << "5. Randomly assign score to a specific student.\n";
    cout << "Your choice is: ";
    cin >> user;
    if (user < 1 || user > 5)
    {
        user = 0;
    }
    else
    {
        cout << "Please make a choice on type of student that you want to interact (0 to quit):\n";
        cout << "1. University student\n";
        cout << "2. College student\n";
        cout << "Your choice is: ";
        cin >> subuser;
        if (subuser < 1 || subuser > 2)
        {
            user = 0;
        }
        else
        {
            if (user == 4 || user == 5)
            {
                cin.ignore();
            }
        }
    }
}
/**
 * Function: showOutput(Students &sus, int user, int subuser)
 * --------------------------------------------------------
 * This function processes the datas by asking the user to type in proper parameter.
 * @param sus The group of students that the user manages
 * @param user User's option between add, delete, display or assign scores
 * @param subuser User's option between managing university students or college students
 */
void showOutput(University &sus, int user, int subuser)
{
    int position = -1;
    string name;
    switch (user)
    {
    case ADD:
        cout << "Please type in the position that you want to add: ";
        cin >> position;
        cin.ignore();
        sus.addStu(subuser, position);
        break;
    case DISPL:
        sus.display(subuser);
        break;
    case DISPL_BST:
        sus.displayBest(subuser);
        break;
    case DEL:
        cout << "Please type in the name of the student that you want to delete: ";
        getline(cin, name);
        sus.delStu(name, subuser);
        break;
    case STUDY:
        cout << "Please type in the name of the student that you want to assign: ";
        getline(cin, name);
        sus.study(name, subuser);
        break;
    default:
        break;
    }
}
/**
 * Constructor of Student
 * ----------------------
 * This function set the scores array to null pointer
 */
Student::Student()
{
    scores = nullptr;
}
/**
 * Destructor of Student
 * --------------------
 * This function frees the memory of scores
 */
Student::~Student()
{
    delete[] scores;
    scores = nullptr;
}
/**
 * Getter of the name of student
 * @return The name of the student
 */
string Student::getName()
{
    return name;
}
/**
 * Getter of the date of birth of student
 * @return The date of birth of the student
 */
string Student::getDate()
{
    return dateOfBirth;
}
/**
 * Getter of the school's name of the student
 * @return The school's name of the student
 */
string Student::getSchool()
{
    return nameSchool;
}
/**
 * Getter of the list of scores of the student
 * @return The list of scores of the student
 */
float *Student::getScores()
{
    return scores;
}
/**
 * Getter of the number of scores in the lists of student
 * @return The number of scores in the list of student
 */
int Student::getNumScores()
{
    return numScore;
}
/**
 * Setter of the name of student
 * @param nameVal The new name of the student
 */
void Student::setName(string nameVal)
{
    name = nameVal;
}
/**
 * Setter of the name of school
 * @param schoolVal The name of the student's school
 */
void Student::setNameSchool(string schoolVal)
{
    nameSchool = schoolVal;
}
/**
 * Member function: assign(Student &partner)
 * ----------------------------------------
 * This function gets the information of the other student
 * @param partner The other student that sets the information
 */
void Student::assign(Student &partner)
{
    name = partner.getName();
    dateOfBirth = partner.getDate();
    nameSchool = partner.getSchool();
    scores = partner.getScores();
    numScore = partner.getNumScores();
    setAssignStatus(partner.getAssignStatus());
    setTestStatus(partner.getTestStatus());
    setExamStatus(partner.getExamStatus());
}
/**
 * Setter of the date of birth
 * --------------------------
 * @param dateVal The date of birth of the student
 */
void Student::setDate(string dateVal)
{
    dateOfBirth = dateVal;
}
/**
 * Member fucntion: addScore(int pos)
 * ---------------------------------
 * This function adds a random score to the list of scores based on the position.
 * @param pos The position that needs to be added
 */
void Student::addScore(int pos)
{
    numScore++;
    float *newScore = new float[numScore];
    for (int i = 0; i < numScore - 1; i++)
    {
        newScore[i] = scores[i];
    }
    for (int i = numScore - 2; i >= pos; i--)
    {
        newScore[i + 1] = newScore[i];
    }
    newScore[pos] = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (100)));
    scores = newScore;
}
/**
 * Constructor of University Student class
 * -------------------------------------
 * This function sets number of semesters, courses, assignments, examx, test to 8, 4, 3, 1, 2 respectively.
 * Then, this function set status of taking scores of this student to false
 */
UniStu::UniStu()
{
    numSem = 8;
    numCourse = 4;
    numAssg = 3;
    numExam = 1;
    numTest = 2;
    takeAssignment[0] = false;
    DotakeExam[0] = false;
    DotakeTest[0] = false;
    numScore = 0;
}
/**
 * Member function: doAssign()
 * --------------------------
 * This function randomly assigns the score for assignment at the front of the list
 */
void UniStu::doAssign()
{
    if (!takeAssignment[0])
    {
        for (int i = 0; i < numAssg * numSem * numCourse; i++)
        {
            addScore(0);
        }
        takeAssignment[0] = true;
    }
    else
    {
        cout << "This student's marks of assignments are available.\n";
    }
}
/**
 * Member function: takeTest()
 * ---------------------------
 * This function randomly assigns the score for test right after the list of scores of assignments
 */
void UniStu::takeTest()
{
    if (!DotakeTest[0])
    {
        for (int i = 0; i < numCourse * numSem * numTest; i++)
        {
            if (!takeAssignment[0])
            {
                addScore(0);
            }
            else
            {
                addScore(numCourse * numSem * numAssg);
            }
        }
        DotakeTest[0] = true;
    }
    else
    {
        cout << "This student's marks of tests are available.\n";
    }
}
/**
 * Member function: getGPA()
 * -----------------------
 * This function calculates the avarage of scores in the list
 * @return The GPA of the student over all semesters and courses
 */
float UniStu::getGPA()
{
    if (!takeAssignment[0] || !DotakeTest[0] || !DotakeExam[0])
    {
        return -1;
    }
    float avg = 0;
    for (int i = 0; i < numScore; i++)
    {
        avg += scores[i];
    }
    return avg / numScore;
}
/**
 * Member function: takeExam()
 * --------------------------
 * This function randomly assigns the scores of exams at the back of the list
 */
void UniStu::takeExam()
{
    if (!DotakeExam[0])
    {
        for (int i = 0; i < numCourse * numSem * numExam; i++)
        {
            addScore(numScore);
        }
        DotakeExam[0] = true;
    }
    else
    {
        cout << "This student's marks of exams are available.\n";
    }
}
/**
 * Getter of assignment status
 * @return The status of assignment's score
 */
bool UniStu::getAssignStatus()
{
    return takeAssignment[0];
}
/**
 * Setter of assignment status
 * @param assgVal The new status of doing assignment
 */
void UniStu::setAssignStatus(bool assgVal)
{
    takeAssignment[0] = assgVal;
}
/**
 * Getter of taking test status
 * @return The status of taking test
 */
bool UniStu::getTestStatus()
{
    return DotakeTest[0];
}
/**
 * Setter of taking test status
 * @param testVal The new taking test status
 */
void UniStu::setTestStatus(bool testVal)
{
    DotakeTest[0] = testVal;
}
/**
 * Getter of taking exam status
 * @return The status of taking exam
 */
bool UniStu::getExamStatus()
{
    return DotakeExam[0];
}
/**
 * Setter of taking exam status
 * @param examVal The new status of taking exam
 */
void UniStu::setExamStatus(bool examVal)
{
    DotakeExam[0] = examVal;
}
/**
 * Member fucntion: display()
 * -------------------------
 * This function displays all of the information (with the score) of the student
 */
void UniStu::display()
{
    cout << "Information of the "
         << "University"
         << " student:\n";
    cout << "Name: " << getName() << endl;
    cout << "Date of birth: " << getDate() << endl;
    cout << "School's name: " << getSchool() << endl;
    cout << "This student has " << numSem << " semester, each semester has " << numCourse << " course\n";
    cout << "The number of assignments of this student taking is: " << numAssg << endl;
    cout << "The number of tests of this student taking is: " << numTest << endl;
    cout << "The number of exams of this student taking is: " << numExam << endl;
    if (takeAssignment[0] && DotakeExam[0] && DotakeTest[0])
    {
        cout << "The GPA of this student is: " << getGPA() << endl;
    }
    int count = 0;
    if (!takeAssignment[0])
    {
        cout << "This student has not done all of Assignments\n";
    }
    else
    {
        int currCourse = 1;
        int currSem = 1;
        for (int i = 0; i < numCourse * numSem * numAssg; i++)
        {
            cout << "The assignment score of the student on the course " << currCourse << " of the semester " << currSem << " is: " << scores[count++] << endl;
            currCourse++;
            if (currCourse == numCourse + 1)
            {
                currCourse = 1;
                currSem++;
            }
            if (currSem == numSem + 1)
            {
                currSem = 1;
            }
        }
    }
    if (!DotakeTest[0])
    {
        cout << "This student has not done all of Tests\n";
    }
    else
    {
        int currCourse = 1;
        int currSem = 1;
        for (int i = 0; i < numCourse * numSem * numTest; i++)
        {
            cout << "The test score of the student on the course " << currCourse << " of the semester " << currSem << " is: " << scores[count++] << endl;
            currCourse++;
            if (currCourse == numCourse + 1)
            {
                currCourse = 1;
                currSem++;
            }
            if (currSem == numSem + 1)
            {
                currSem = 1;
            }
        }
    }
    if (!DotakeExam[0])
    {
        cout << "This student has not done all of Exams\n";
    }
    else
    {
        int currCourse = 1;
        int currSem = 1;
        for (int i = 0; i < numCourse * numSem * numExam; i++)
        {
            cout << "The exam score of the student on the course " << currCourse << " of the semester " << currSem << " is: " << scores[count++] << endl;
            currCourse++;
            if (currCourse == numCourse + 1)
            {
                currCourse = 1;
                currSem++;
            }
            if (currSem == numSem + 1)
            {
                currSem = 1;
            }
        }
    }
}
/**
 * Constructor of College Student class
 * -------------------------------------
 * This function sets number of semesters, courses, assignments, examx, test to 4, 3, 1, 1, 1 respectively.
 * Then, this function set status of taking scores of this student to false
 */
CollegStu::CollegStu()
{
    numSem = 4;
    numCourse = 3;
    numAssg = 1;
    numExam = 1;
    numTest = 1;
    takeAssignment[1] = false;
    DotakeExam[1] = false;
    DotakeTest[1] = false;
    numScore = 0;
}
/**
 * Member fucntion: doAssign()
 * --------------------------
 * This function randomly assigns the scores of assignments at the front of the list
 */
void CollegStu::doAssign()
{
    if (!takeAssignment[1])
    {
        for (int i = 0; i < numAssg * numSem * numCourse; i++)
        {
            addScore(0);
        }
        takeAssignment[1] = true;
    }
    else
    {
        cout << "This student's marks of assignments are available.\n";
    }
}
/**
 * Member function: takeTest()
 * --------------------------
 * This function randomly assigns the scores of tests right after the list of assignment scores
 */
void CollegStu::takeTest()
{
    if (!DotakeTest[1])
    {
        for (int i = 0; i < numCourse * numSem * numTest; i++)
        {
            if (!takeAssignment[1])
            {
                addScore(0);
            }
            else
            {
                addScore(numCourse * numSem * numAssg);
            }
        }
        DotakeTest[1] = true;
    }
    else
    {
        cout << "This student's marks of tests are available.\n";
    }
}
/**
 * Member function: takeExam()
 * --------------------------
 * This fucntion randomly assigns the scores of exams at the back of the list
 */
void CollegStu::takeExam()
{
    if (!DotakeExam[1])
    {
        for (int i = 0; i < numCourse * numSem * numExam; i++)
        {
            addScore(numScore);
        }
        DotakeExam[1] = true;
    }
    else
    {
        cout << "This student's marks of exams are available.\n";
    }
}
/**
 * Member function: getGPA()
 * @return The average scores of the student if they complete assignments, tests and exams
 */
float CollegStu::getGPA()
{
    if (!takeAssignment[1] || !DotakeTest[1] || !DotakeExam[1])
    {
        return -1;
    }
    float avg = 0;
    for (int i = 0; i < numScore; i++)
    {
        avg += scores[i];
    }
    return avg / numScore;
}
/**
 * Getter of assignments status
 * @return The status of scores of assignments
 */
bool CollegStu::getAssignStatus()
{
    return takeAssignment[1];
}
/**
 * Setter of assignment status
 * @param assgVal The new status of scores of assignments
 */
void CollegStu::setAssignStatus(bool assgVal)
{
    takeAssignment[1] = assgVal;
}
/**
 * Getter of test status
 * @return The status of the scores of tests
 */
bool CollegStu::getTestStatus()
{
    return DotakeTest[1];
}
/**
 * Setter of test status
 * @param testVal The new status of scores of tests
 */
void CollegStu::setTestStatus(bool testVal)
{
    DotakeTest[1] = testVal;
}
/**
 * Getter of exam status
 * @return The status of scores of exams
 */
bool CollegStu::getExamStatus()
{
    return DotakeExam[1];
}
/**
 * Setter of exam status
 * @param examVal The new status of scores of exams
 */
void CollegStu::setExamStatus(bool examVal)
{
    DotakeExam[1] = examVal;
}
/**
 * Member fucntion: display()
 * -------------------------
 * This function displays all of the information (including the scores) of the student
 */
void CollegStu::display()
{
    cout << "Information of the "
         << "College"
         << " student:\n";
    cout << "Name: " << getName() << endl;
    cout << "Date of birth: " << getDate() << endl;
    cout << "School's name: " << getSchool() << endl;
    cout << "This student has " << numSem << " semester, each semester has " << numCourse << " course\n";
    cout << "The number of assignments of this student taking is: " << numAssg << endl;
    cout << "The number of tests of this student taking is: " << numTest << endl;
    cout << "The number of exams of this student taking is: " << numExam << endl;
    if (takeAssignment[1] && DotakeExam[1] && DotakeTest[1])
    {
        cout << "The GPA of this student is: " << getGPA() << endl;
    }
    int count = 0;
    if (!takeAssignment[1])
    {
        cout << "This student has not done all of Assignments\n";
    }
    else
    {
        int currCourse = 1;
        int currSem = 1;
        for (int i = 0; i < numCourse * numSem * numAssg; i++)
        {
            cout << "The assignment score of the student on the course " << currCourse << " of the semester " << currSem << " is: " << scores[count++] << endl;
            currCourse++;
            if (currCourse == numCourse + 1)
            {
                currCourse = 1;
                currSem++;
            }
            if (currSem == numSem + 1)
            {
                currSem = 1;
            }
        }
    }
    if (!DotakeTest[1])
    {
        cout << "This student has not done all of Tests\n";
    }
    else
    {
        int currCourse = 1;
        int currSem = 1;
        for (int i = 0; i < numCourse * numSem * numTest; i++)
        {
            cout << "The test score of the student on the course " << currCourse << " of the semester " << currSem << " is: " << scores[count++] << endl;
            currCourse++;
            if (currCourse == numCourse + 1)
            {
                currCourse = 1;
                currSem++;
            }
            if (currSem == numSem + 1)
            {
                currSem = 1;
            }
        }
    }
    if (!DotakeExam[1])
    {
        cout << "This student has not done all of Exams\n";
    }
    else
    {
        int currCourse = 1;
        int currSem = 1;
        for (int i = 0; i < numCourse * numSem * numExam; i++)
        {
            cout << "The exam score of the student on the course " << currCourse << " of the semester " << currSem << " is: " << scores[count++] << endl;
            currCourse++;
            if (currCourse == numCourse + 1)
            {
                currCourse = 1;
                currSem++;
            }
            if (currSem == numSem + 1)
            {
                currSem = 1;
            }
        }
    }
}
/**
 * Member function: createStudent()
 * @return The new student from University
*/
Student* UniFactory::createStudent()
{
    return new UniStu();
}
/**
 * Member function: createStudent()
 * @return The new student from College
*/
Student* CollegFactory::createStudent()
{
    return new CollegStu();
}
/**
 * Constructor of Students
 * ---------------------
 * This function constructs two variables that generate students each time adding to the system
 */
University::University()
{
    stuInUni = new UniFactory();
    stuInColleg = new CollegFactory();
}
/**
 * Destructor of Students
 * ----------------------
 * This function frees all students in the systems.
 */
University::~University()
{
    if (school[0].size() > 0)
    {
        for(unsigned int i = 0; i < school[0].size();i++)
        {
            delete school[0][i];
        }
        school[0].clear();
    }
    if (school[1].size() > 0)
    {
        for(unsigned int i = 0; i < school[1].size();i++)
        {
            delete school[1][i];
        }
        school[1].clear();
    }
    delete stuInUni;
    delete stuInColleg;
}
/**
 * Member function: addStu(int choice, int pos)
 * -------------------------------------------
 * This function adds the student to a specific position in the list with the user's data
 * @param choice User's choice between university students and college students
 * @param pos The position in the list that user wants to insert the student (starting from 0 to number of students -1)
 */
void University::addStu(int choice, int pos)
{
    int *numOfStudents = nullptr;
    int typeStudents = -1;
    if (choice == 1)
    {
        typeStudents = 0;
        int size = school[typeStudents].size();
        numOfStudents = &size;
    }
    else
    {
        typeStudents = 1;
        int size = school[typeStudents].size();
        numOfStudents = &size;
    }
    if (pos < 0 || pos >= (*numOfStudents) + 1)
    {
        cout << "Your position is out of range\n";
    }
    else
    {
        (*numOfStudents)++;
        Student *newPupil = nullptr;
        if (choice == 1)
        {
            newPupil = stuInUni->createStudent();
        }
        else
        {
            newPupil = stuInColleg->createStudent();
        }
        string buff; // Contains strings from user's input
        cout << "Please enter the name of student: ";
        getline(cin, buff);
        newPupil->setName(buff);
        cout << "Please enter the date of birth of student: ";
        getline(cin, buff);
        newPupil->setDate(buff);
        cout << "Please enter the school's name of student: ";
        getline(cin, buff);
        newPupil->setNameSchool(buff);
        school[typeStudents].insert(school[typeStudents].begin() + pos, newPupil);
    }
}
/**
 * Member function: delStu(string name, int choice)
 * ----------------------------------------------
 * This function removes all of the data of student based on the name of user
 * @param name The name of student that user wants to remove
 * @param choice User's choice between university students and college students
 */
void University::delStu(string name, int choice)
{
    int *numOfStudents = nullptr;
    int typeStudents = -1;
    if (choice == 1)
    {
        typeStudents = 0;
        int size = school[typeStudents].size();
        numOfStudents = &size;
    }
    else
    {
        typeStudents = 1;
        int size = school[typeStudents].size();
        numOfStudents = &size;
    }
    if ((*numOfStudents) == 0)
    {
        cout << "There is no one to remove\n";
    }
    else
    {
        int position = -1;
        vector<Student *>::iterator it;
        for (it = school[typeStudents].begin(); it != school[typeStudents].end(); it++)
        {
            position++;
            if ((*it)->getName() == name)
            {
                break;
            }
        }
        if (position == -1)
        {
            cout << "The name " << name << " is not found in our system\n";
        }
        else
        {
            Student *deletedStu = (school[typeStudents].at(position));
            delete deletedStu;
            school[typeStudents].erase(school[typeStudents].begin() + position);
        }
    }
}
/**
 * Member function: getBest(int choice)
 * @param choice User's choice between university students and college students
 * @return The highest score from the students' list; if no one has the score in the list, return -1
 */
float University::getBest(int choice)
{
    int *numOfStudents = nullptr;
    int typeStudents = -1;
    if (choice == 1)
    {
        typeStudents = 0;
        int size = school[typeStudents].size();
        numOfStudents = &size;
    }
    else
    {
        typeStudents = 1;
        int size = school[typeStudents].size();
        numOfStudents = &size;
    }
    float highestScore = -1;
    vector<Student *>::iterator it;
    for (int i = 0; i < (*numOfStudents); i++)
    {
        if (school[typeStudents][i]->getGPA() > highestScore)
        {
            highestScore = school[typeStudents][i]->getGPA();
        }
    }
    return highestScore;
}
/**
 * Member function: display(int choice)
 * -----------------------------------
 * This function displays all of the informations of students on the chosen list
 * @param choice User's choice between University students and College students
 */
void University::display(int choice)
{
    int *numOfStudents = nullptr;
    int typeStudents = -1;
    if (choice == 1)
    {
        typeStudents = 0;
        int size = school[typeStudents].size();
        numOfStudents = &size;
    }
    else
    {
        typeStudents = 1;
        int size = school[typeStudents].size();
        numOfStudents = &size;
    }
    if ((*numOfStudents) == 0)
    {
        cout << "There is no one in the class\n";
    }
    else
    {
        int position = -1;
        vector<Student *>::iterator it;
        for (it = school[typeStudents].begin(); it != school[typeStudents].end(); it++)
        {
            position++;
            cout << "Display of student " << position;
            (*it)->display();
        }
    }
}
/**
 * Member function: displayBest(int choice)
 * ---------------------------------------
 * This function displays all of the informations of students that have the highest score on the chosen list
 * @param choice User's choice between University students and College students
 */
void University::displayBest(int choice)
{
    int *numOfStudents = nullptr;
    int typeStudents = -1;
    if (choice == 1)
    {
        typeStudents = 0;
        int size = school[typeStudents].size();
        numOfStudents = &size;
    }
    else
    {
        typeStudents = 1;
        int size = school[typeStudents].size();
        numOfStudents = &size;
    }
    if ((*numOfStudents) == 0)
    {
        cout << "There is no one in the class\n";
    }
    else
    {
        float studHighest = getBest(choice);
        if (studHighest == -1)
        {
            cout << "No one has gotten GPA\n";
        }
        else
        {
            for (int i = 0; i < (*numOfStudents); i++)
            {
                string name = school[typeStudents][i]->getName();
                if (name != "")
                {
                    if (school[typeStudents][i]->getGPA() == studHighest)
                    {
                        cout << "The highest score recorded in student " << i + 1 << endl;
                        school[typeStudents][i]->display();
                    }
                }
            }
        }
    }
}
/**
 * Member function: study(string name, int choice)
 * ----------------------------------------------
 * This function randomly assign scores of the students based on the user's name on a chosen list
 * @param name The name of student that needs to be assigned
 * @param choice User's choice between University student and College student
 */
void University::study(string name, int choice)
{
    int *numOfStudents = nullptr;
    int typeStudents = -1;
    if (choice == 1)
    {
        typeStudents = 0;
        int size = school[typeStudents].size();
        numOfStudents = &size;
    }
    else
    {
        typeStudents = 1;
        int size = school[typeStudents].size();
        numOfStudents = &size;
    }
    if ((*numOfStudents) == 0)
    {
        cout << "There is no one to assign\n";
    }
    else
    {
        int position = -1;
        for (int i = 0; i < (*numOfStudents); i++)
        {
            if (school[typeStudents][i]->getName() == name)
            {
                position = i;
                break;
            }
        }
        if (position == -1)
        {
            cout << "The name " << name << " is not found in our system\n";
        }
        else
        {
            school[typeStudents][position]->doAssign();
            school[typeStudents][position]->takeTest();
            school[typeStudents][position]->takeExam();
        }
    }
}