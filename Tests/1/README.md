# Контролна работа №1

## Задача 1
Да се реализира клас, представящ крайно множество от естествени числа (NaturalNumbers) в интервала [0, 2^32 - 1]. Всяко множество се описва с: 
  - произволен брой от неповтарящи се елементи; 
  - име - символен низ с произволна дължина. 

Класът трябва да разполага с подходящи селектори за двете член-данни и да разполага с всички необходими елементи от каноничното представяне, които гарантират коректен 
жизнен цикъл на обекта. 

Класът трябва да разполага със следните конструктори: 
  - конструктор по подразбиране, който създава празното множество с име "Empty set";
  - конструктор с два параметъра: масив от елементи и име. Да се направи подходяща валидация за уникалността на елементите. Ако има дублиране на елементи, те трябва 
да се добавят еднократно в множеството и трябва да се изведе подходящо предупреждение. 

Да се предефинират следните оператори: 
  - оператори + и += за обединение на две множества: 
    - името на новото множество следва да бъде "Union of '< name1 >' and '< name2 >'", където name1 и name2 ca имената на двете обединявани множества; 
    - операторът + следва да създава ново множество, а операторът += трябва да променя първото множество, обединявайки го с второто; 
    - ако има дублиране на елементи, те трябва да се добавят еднократно в множеството и трябва да се изведе подходящо предупреждение;
  - оператори за въвеждане и извеждане на множество ( << и >> ) от входен или изходен поток, в избран от вас формат; 
  - оператор [n], който връща булева стойност, указваща дали числото n е елемент на множеството. 

Внимание: Всички символни низове в програмата трябва да се представят динамично, т.е. за всеки от тях трябва да се заделя памет с new, да се освобождава с delete и да 
има указател char*, който сочи към нея. НЕ Е ПОЗВОЛЕНО да се използват статични масиви (например сhаr buffer[100]), нито класа std::string, НИТО друг помощен клас за 
работа с низове, който е писан на упражнения или лекции.

## Задача 2
Да се реализира клас Book, който описва книга. Всяка книга трябва да има заглавие и автор (символни низове с дължина до 100 символа) и тираж (цяло число без знак). 
За класа да се осигури канонично представяне (голяма четворка), ако е нужно и подходящи селектори и мутатори за член данни. Използването на класа да се демонстрира 
в програма, която: 
  - въвежда последователност от книги (< подходящ тип > bookList) от двоичен файл с име library.dat, съдържащ последователност от обекти от клас Book; 
  - записва в текстов файл с име popular.txt онези книги , които имат тираж от поне хиляда броя; При записването всяка книга да бъде на отделен ред във файла, като 
този ред съдържа заглавие, автор и тираж, разделени със запетайки. 

Внимание: В решенията и на двете задачи НЕ Е позволено използването на стандартни контейнерни класове, включително std::string , std::set, std::vector и други.
