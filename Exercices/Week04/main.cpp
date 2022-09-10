#include "date.hpp"
#include "task.hpp"
#include "taskManager.hpp"

void testDate()
{
    Date date1(28, 02, 2020);
    Date date2(29, 02, 2020);

    std::cout << (date1 == date2) << "\n";
    std::cout << (date1 < date2) << "\n";

    // Date date3(35, 03, 2022);
    // Date date4(30, 13, 2022);
    // Date date5(30, 13, 2025);

    Date date3(1,5,2022);
    Date date4(20,4,2022);
    Date date5(31,3,2022);

    std::cout << (date3 < date4) << "\n";
    std::cout << (date4 < date5) << "\n";
}

void testTask()
{
    Task t1("Title1", "Description1", Date(1,12,2015), Category::WORK);
    t1.print();

    std::cout << std::endl;

    Task t2("Title2", "Description2", Date(29,12,1999), Category::UNIVERSITY);
    t2.print();

    std::cout << std::endl;

    t2.setTitle("Title3");
    t2.setDescription("Description3");
    t2.setDeadline(Date(6,2,2000));
    t2.setCategory(Category::OTHER);

    Task t3(t2);
    t3.print();

    std::cout << std::endl;
    std::cout << (t3.getCategory() == Category::OTHER) << std::endl;
    std::cout << std::endl;

    Task t4;
    t4 = t1;
    t4.print();

    std::cout << std::endl;
    std::cout << (t4.getCategory() == Category::WORK) << std::endl;
}

void testTaskManager()
{
    TaskManager t1;
    t1.addTask(Task("Task1", "Description1", Date(1,5,2022), Category::UNIVERSITY));
    t1.addTask(Task("Task2", "Description2", Date(20,4,2022), Category::WORK));
    t1.addTask(Task("Task3", "Description3", Date(31,3,2022), Category::OTHER));

    t1.print();
    
    std::cout << "\n" << t1.getTaskCount() << "\n\n"; 
    
    Task temp = t1.getNextTask();
    temp.print();

    std::cout << std::endl;

    t1.removeTask("Task2");
    TaskManager t2(t1);
    t2.addTask(Task("Task4", "Description4", Date(6,4,2022), Category::FOR_HOME));

    t1.print();
    std::cout << std::endl;
    t2.print();

    TaskManager t3;
    t3 = t1;

    std::cout << "\n" << t3.getTaskCount() << "\n";
    std::cout << std::endl;
    t3.print(); 

    t3.removeTask("Task2");
    t3.removeTask("Task1");
    t3.removeTask("Task3");

    std::cout << std::endl;
    t3.print();
}

int main()
{
    // testDate();
    // testTask();
    testTaskManager();
    return 0;
}
