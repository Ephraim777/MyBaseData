
#include "Menu.h"
//Меню:
void Menu::menu(){
    size_t num;

    std::cout << "\t\tМеню базы данных\n";
    std::cout << "Распечатать базу данных -> 1\n";
    std::cout << "Добавить нового сотрудника -> 2\n";
    std::cout << "Удалить сотрудника -> 3\n";
    std::cout << "Удалить всех сотрудников -> 4\n";
    std::cout << "Найти сотрудника по Имени -> 5\n";
    std::cout << "Выйти из программы -> 6\n";
    std::cout << "Количество сотрудников: " << this->data.count << std::endl;
    std::cout << "Резерв: " << this->data.capacity-this->data.count << std::endl;
    std::cin >> num;
    switch(num){
        case 1: std::cout << this->data ; std::cout <<std::endl; Backtomenu();
            break;
        case 2: this->AddNewCrew(); break;
        case 3: this->DeleteforKey();std::cout << "Возвращаемся в меню\n"; sleep(2);
            std::cout << "\033[2J\033[1;1H"; this->menu();break;
        case 4: DeleteEveryone(); std::cout << "Возвращаемся в меню\n"; sleep(2);
            std::cout << "\033[2J\033[1;1H"; this->menu();break;
        case 5: FindKeYandprint() ;break;
        case 6: std::cout << "Программа завершилась\n" ; exit(6);break;
        default: std::cin.clear(); std::cin.ignore(99999999999999 , '\n'); std::cout << "Ошибка, возвращаемся в меню\n"; sleep(2);
            std::cout << "\033[2J\033[1;1H"; this->menu();break;
    }



}
//Метод возвращения в меню:
void Menu::Backtomenu(){
    std::string answer;

    std::cout << "Вернуться в меню? Нажми на любую клавишу\n";
    std::cin >> answer;
    if (answer == "a"){
        std::cout << "Возвращаемся в меню...\n";
        sleep(2); std::cout << "\033[2J\033[1;1H";
        menu();
    } else {
        std::cout << "Возвращаемся в меню...\n";
        sleep(2); std::cout << "\033[2J\033[1;1H";
        menu();
    }

}


// №2 Добавляем сотрудника
void Menu::AddNewCrew(){
    char name[100];
    std::cout << "Укажите ключ (ФИО)\n";
    std::cin.ignore();
    std::cin.getline(name, 100);
    std::string sex_str;
    MyData::Sex sex;
    std::cout << "Укажите пол М или Ж\n";
    std::cin >> sex_str;
    if (sex_str == "М" || sex_str == "м" || sex_str == "M" || sex_str == "m")
    {
        sex = MyData::Sex::MALE;
    } else if(sex_str == "ж" || sex_str == "Ж")  {
        sex = MyData::Sex::FEMALE;
    } else{
        std::cin.clear();
        std::cin.ignore(99999999, '\n');
        sex = MyData::Sex::FEMALE;
    } std::cout << "Укажите должность на работе\n";
    char job[100];
    std::cin.getline(job, 100);
    std::cout << "Укажите возраст\n";
    size_t age;
    while (true){
        std::cin >> age;
        if (std::cin.fail()){
            std::cout << "Ошибка ввода\n";
            std::cin.clear();
            std::cin.ignore(99999999999, '\n');
        } else {
            break;
        }
    }
    std::cin.clear();
    std::cin.ignore(99999999999, '\n');
    std::cout << "Укажите Зарплату\n";
    float salary;
    while (true){
        std::cin >> salary;
        if (std::cin.fail()){
            std::cout << "Ошибка ввода\n";
            std::cin.clear();
            std::cin.ignore(99999999999, '\n');
        } else {
            break;
        }
    }



    this->data[name] = MyData(sex, age, job, salary);
   std::cout << "Ещё добавить? ->(1)\n";
    size_t num;
    std:: cin >> num;
    switch(num){
        case 1: this->AddNewCrew();break;
        default: std::cin.clear();
            std::cin.ignore(99999999999, '\n'); std::cout << "Возвращаемся в меню...\n";  std::cout << "\033[2J\033[1;1H"; this->menu();
    }
    std::cout << "Возвращаемся в меню...\n";  std::cout << "\033[2J\033[1;1H"; this->menu();
}
// №3 Удаляем по ключу
void Menu::DeleteforKey(){
    std::cout << "Введите ключ:\n";
    char name[100];
    std::cin.ignore();
    std::cin.getline(name,100);
    if(this->data.Checkname(name)){
     int num =this->data.deletePair(name);
        this->data.count--;

     for ( int i =num; i < data.count; i++){

         data.pBase[i] = data.pBase[i+1];
     }


        std::cout << "Удаление сотрудника из базы...\n";
    }else {
        std::cout << "Такого сотрудника нет\n";
    }




}
// № 4 Удаляем всех
void Menu::DeleteEveryone(){
    if (this->data.count != 0){
        this->data.count = 0;
        this->data.capacity = 1;
    }else {
        std::cout << "Ваша база данных пустая\n";
    }


}
// № 5 Находим по ключу и печатаем
void Menu::FindKeYandprint(){
    char key[100];
    std::cout << "Введите ключ: \n";
    std::cin.ignore();
    std::cin.getline(key, 100);
    if(this->data.Checkname(key)){
        for ( size_t i =0; i <this->data.count; i++){
            if ( this->data.pBase[i].key == key){
                std::cout << "№ " << i+1 << std::endl;
                std::cout << "Имя: \n";
                std::cout << this->data.pBase[i].key << std::endl;
                std::cout << "Гендер: \n";
                std::cout << this->data.pBase[i].dat.Return_Sex() << std::endl;
                std::cout << "Возраст: \n";
                std::cout << this->data.pBase[i].dat.Return_m_age() << std::endl;
                std::cout << "Должность: \n";
                std::cout << this->data.pBase[i].dat.Return_m_job() << std::endl;
                std::cout << "Зарплата: \n";
                std::cout << this->data.pBase[i].dat.Return_m_salary() << std::endl;
            }
        }
        Backtomenu();
    } else {

        std::cout << "Такого сотрудника нет в базе данных\n";
        std::cout << "Возвращаемся в меню...\n";
        sleep(2);
        std::cout << "\033[2J\033[1;1H";
        menu();
    }

}
