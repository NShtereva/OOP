# Преговор на наученото, изброими типове, оператори за сравнение

## Задача 1 📆
Да се реализира клас Date, който пази в себе си информация за следните променливи:
  - Дата - std::uint8_t
  - Месец - std::uint8_t
  - Година - std::uint16_t

Класът да има следния интерфейс:
  - Класът НЕ ТРЯБВА да има конструктор по подразбиране.
  - Date(unsigned int day, unsigned int month, unsigned int year); - конструктор, създаващ нов обект за дата и проверяващ с assert валидността й.
  - unsigned int day() const;
  - unsigned int month() const;
  - unsigned int year() const;
  - bool operator == (const Date& rhs) const;
  - bool operator < (const Date& rhs) const;

## Задача 2 ✏️
Да се реализира клас Task, който има член-данни заглавие, описание, краен срок (от тип Date) и категория (изброим тип със следните 
полета: UNIVERSITY, WORK, FOR_HOME, OTHER). Реализирайте гетъри и сетъри за член данните, както и подходящ/и конструктор/и.

## Задача 3 📝
Да се реализира клас TaskManager, който представлява саморазширяващ се контейнер със задачи. 

Реализирайте следните методи:
  - size_t getTaskCount() const;
  - void addTask(const Task& task);
  - void removeTask(const char* title);
  - const Task& getNextTask() const; - връща задачата с най-скорошен краен срок

⚠️ Навсякъде, където е нужно, реализирайте функциите от rule of 3. Ако това не е необходимо, следвайте rule of 0.
