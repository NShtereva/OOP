#include "student.hpp"
#include "university.hpp"

#include <fstream>

void test1Student()
{
    Student st1;
    std::cout << st1.getFN() << " ";
    std::cout << st1.getName() << " ";
    std::cout << st1.getGroup() << " ";
    std::cout << st1.getAverageGrade() << "\n";

    st1.setFN(12345);
    st1.setName("Student1");
    st1.setGroup(1);
    st1.setAverageGrade(5);

    std::cout << std::endl;

    std::cout << st1.getFN() << " ";
    std::cout << st1.getName() << " ";
    std::cout << st1.getGroup() << " ";
    std::cout << st1.getAverageGrade() << "\n";

    Student st2("Student2", 85236, 2, 5.25);
    std::cout << std::endl << st2;

    std::cout << std::endl;

    Student st3(st1);

    std::cout << (st3 == st1) << std::endl;

    st3.setFN(14527);
    st3.setName("Student3");

    std::cout << std::endl << st3;
    std::cout << st1;

    Student st4;
    st4 = st2;

    std::cout << std::endl << (st4 == st2) << std::endl;

    st4.setFN(65481);
    st4.setName("Student4");
    st4.setGroup(2);
    st4.setAverageGrade(6);

    std::cout << std::endl << st4;
    std::cout << st2;

    std::cout << std::endl << (st1 < st2) << " "
                           << (st2 < st3) << " "
                           << (st3 < st4) << "\n\n";

    Student st5;
    std::cin >> st5;
    std::cout << st5;
}

void test2Student()
{
    Student st("Student", 12345, 2, 5.25);

    std::ofstream oFile("student.txt");
    if(!oFile)
    {
        std::cout << "Problem while opening the file!" << std::endl;
        return;
    }

    oFile << st;

    oFile.close();

    std::ifstream iFile("student.txt");
    if(!iFile)
    {
        std::cout << "Problem while opening the file!" << std::endl;
        return;
    }
    
    Student st1;
    iFile >> st1;
    std::cout << st1;

    iFile.close();
}

bool lessThan(const Student& st1, const Student& st2)
{
    return (st1 < st2);
}

bool moreThan5(const Student& st)
{
    return st.getAverageGrade() > 5;
}

void test1University()
{
    Student st1("Student1", 12345, 2, 5.25);
    Student st2("Student2", 85236, 1, 4.75);
    Student st3("Student3", 78951, 3, 6);
    Student st4("Student4", 45387, 4, 5);

    University uni1, uni2;
    uni1 += st1;
    uni1 += st2;
    uni1 += st3;
    uni1 += st4;

    uni2 = uni1;

    std::cout << uni1;
    std::cout << std::endl << uni2;

    std::cout << std::endl;
    uni1.sort(lessThan);
    std::cout << std::endl << uni1;

    uni1 -= 12345;
    uni1 -= 45387;
    uni1 -= 78951;
    uni1 -= 48942;

    std::cout << std::endl << uni1;
    uni1 -= 85236;
    std::cout << std::endl << uni1;

    std::cout << std::endl << uni2;
    std::cout << std::endl << uni2[uni2.getSize() - 1];

    std::cout << std::endl;
    uni2.filter(moreThan5);
}

void test2University()
{
    Student st1("Student1", 12345, 2, 5.25);
    Student st2("Student2", 85236, 1, 4.75);
    Student st3("Student3", 78951, 3, 6);
    Student st4("Student4", 45387, 4, 5);

    University uni;
    uni += st1;
    uni += st2;
    uni += st3;
    uni += st4;

    std::ofstream oFile("university.txt");
    if(!oFile)
    {
        std::cout << "Problem while opening the file!" << std::endl;
        return;
    }

    oFile << uni;

    oFile.close();

    std::ifstream iFile("university.txt");
    if(!iFile)
    {
        std::cout << "Problem while opening the file!" << std::endl;
        return;
    }
    
    University uni1;
    iFile >> uni1;
    std::cout << uni1;

    iFile.close();
}

int main()
{
    // test1Student();
    test2Student();
    // test1University();
    std::cout << std::endl;
    test2University();
    return 0;
}
