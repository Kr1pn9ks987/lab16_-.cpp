// lab16_Габестро.cpp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <Windows.h>

class Worker {
private:
    std::string surname_initials;
    std::string position;
    int year_of_joining;
    double salary;

public:
    
    Worker(std::string surname_initials, std::string position, int year_of_joining, double salary)
        : surname_initials(surname_initials), position(position), year_of_joining(year_of_joining), salary(salary) {}

    std::string getSurnameInitials() const { return surname_initials; }
    std::string getPosition() const { return position; }
    int getYearOfJoining() const { return year_of_joining; }
    double getSalary() const { return salary; }

    void print() const {
        std::cout << "Прізвище та ініціали: " << surname_initials << ", Посада: " << position
            << ", Рік вступу на роботу: " << year_of_joining << ", Зарплата: " << salary << "\n";
    }

    int getExperience(int current_year) const {
        return current_year - year_of_joining;
    }
};

void printWorkersWithExperience(Worker workers[], int size, int years, int current_year) {
    std::cout << "Працівники зі стажем більше " << years << " років:\n";
    for (int i = 0; i < size; ++i) {
        if (workers[i].getExperience(current_year) > years) {
            workers[i].print();
        }
    }
}

void printWorkersWithSalaryAbove(Worker workers[], int size, double salary) {
    std::cout << "Працівники із зарплатою більше " << salary << ":\n";
    for (int i = 0; i < size; ++i) {
        if (workers[i].getSalary() > salary) {
            workers[i].print();
        }
    }
}

void printWorkersWithPosition(Worker workers[], int size, const std::string& position) {
    std::cout << "Працівники з посадою " << position << ":\n";
    for (int i = 0; i < size; ++i) {
        if (workers[i].getPosition() == position) {
            workers[i].print();
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int size = 5; 
    Worker workers[size] = {
        Worker("Іванов І.І.", "Інженер", 2015, 15000),
        Worker("Петров П.П.", "Менеджер", 2010, 20000),
        Worker("Сидоров С.С.", "Директор", 2005, 30000),
        Worker("Кузнєцов К.К.", "Інженер", 2018, 14000),
        Worker("Федорова Ф.Ф.", "Менеджер", 2012, 22000)
    };

    int current_year = 2024;
    int years;
    double salary;
    std::string position;

    std::cout << "Введіть кількість років для перевірки стажу: ";
    std::cin >> years;
    printWorkersWithExperience(workers, size, years, current_year);

    std::cout << "Введіть зарплату для перевірки: ";
    std::cin >> salary;
    printWorkersWithSalaryAbove(workers, size, salary);

    std::cin.ignore(); 
    std::cout << "Введіть посаду для перевірки: ";
    std::getline(std::cin, position);
    printWorkersWithPosition(workers, size, position);

    return 0;
}
