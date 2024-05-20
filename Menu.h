


#include "Base.h"

class Menu {

public:
    Base data;
    Menu() = default;
    ~Menu() = default;



    //Меню:
    void menu ();
    //Метод для возвращения в меню:

    void Backtomenu() ;

// Его методы:
// №1 - описан в сразу в Menu.cpp

// №2 Добавляем нового сотрудника:
    void AddNewCrew();
// №3 Удаление по ключу сотрудника:
    void DeleteforKey();
// №4 Удаление всех сотрудников:
    void DeleteEveryone();
// №5 Вывод информации по ключу:
    void FindKeYandprint();



};



