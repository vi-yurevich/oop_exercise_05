/*
 * Юревич В.Ю. М8О-207Б-19
 * Создать шаблон динамической коллекцию, согласно варианту
 * задания:
 * 01. Коллекция должна быть реализована с помощью умных указателей
 *     (std::shared_ptr, std::weak_ptr). Опционально использование
 *     std::unique_ptr;
 * 02. В качестве параметра шаблона коллекция должна принимать тип
 *     данных – фигуры;
 * 03. Реализовать forward_iterator по коллекции;
 * 04. Коллекция должны возвращать итераторы begin() и end();
 * 05. Коллекция должна содержать метод вставки на позицию
 *     итератора insert(iterator);
 * 06. Коллекция должна содержать метод удаления из позиции
 *     итератора erase(iterator);
 * 07. При выполнении недопустимых операций (например выход за
 *     границы коллекции или удаление несуществующего элемента)
 *     необходимо генерировать исключения;
 * 08. Итератор должен быть совместим со стандартными алгоритмами
 *     (например, std::count_if)
 * 09. Коллекция должна содержать метод доступа к элементу по оператору [];
 * 10. Реализовать программу, которая:
 *     -- позволяет вводить с клавиатуры фигуры (с типом int в качестве
 *        параметра шаблона фигуры) и добавлять в коллекцию;
 *     -- позволяет удалять элемент из коллекции по номеру элемента;
 *     -- выводит на экран введенные фигуры c помощью std::for_each;
 *     -- выводит на экран количество объектов, у которых площадь
 *        меньше заданной (с помощью  std::count_if).
 */

#include "List.h"
#include "Rhombus.h"
#include <iostream>
#include <algorithm>

TRhombus<int> EnterRhombus() {
    TRhombus<int> rhomb;
    bool key = false;
    do {
        std::cout << "Укажите координату Х центра ромба: ";
        std::cin >> rhomb.center.first;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода. Повторите ввод." << std::endl;
        }
        else { 
            key = true;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (key != true);
    do {
        std::cout << "Укажите координату Y центра ромба: ";
        std::cin >> rhomb.center.second;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода. Повторите ввод." << std::endl;
        }
        else { 
            key = false;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (key != false);
    do {
        std::cout << "Укажите длину вертикальной диагонали: ";
        std::cin >> rhomb.vertDiag;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода. Повторите ввод." << std::endl;
        }
        else if (rhomb.vertDiag < 0) {
                    std::cout << "Ошибка ввода. Длина не может быть отрицательной. Повторите ввод.\n";
                }
        else {
            key = true;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while(key != true);
    do {
        std::cout << "Укажите длину горизонтальной диагонали: ";
        std::cin >> rhomb.horDiag;
        if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка ввода. Повторите ввод." << std::endl;
        }
        else if (rhomb.horDiag < 0) {
                    std::cout << "Ошибка ввода. Длина не может быть отрицательной. Повторите ввод.\n";
                }
        else {
            key = false;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while(key != false);
    return(rhomb);
}

void EnterPosition (size_t& pos) {
    bool key = false;
    size_t i;
    do {
        std::cout << "Укажите номер позиции: ";
        std::cin >> i;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода. Повторите ввод." << std::endl;
        }
        else if (i < 0) {
            std::cout << "Ошибка ввода. Номер позиции в списке может быть только положительным. Повторите ввод.\n";
        }
        else {
            key = true;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while(key != true);
    pos = i;
}


int main() {
    TRhombus<int> rhomb;
    TList<TRhombus<int>> list;
    bool key = false;
    int menu = 1;
    int square;
    size_t i;

    auto Print = [](const TRhombus<int>& r) {
		std::cout << r << "\n" << std::endl;
	};
    auto TestSquare = [&square](const TRhombus<int>& r) {
        return (RhombusSquare<int>(r) < square);
    };

    while(menu != 0) {
        switch(menu) {
            case 1:
                std::cout << "1 - Вывести меню\n2 - Добавить ромб в список\n3 - Печать списка" << std::endl;
                std::cout << "4 - Вставить по номеру в списке\n5 - Удалить по номеру в списке\n6 - Вывести количество элементов в списке" << std::endl;
                std::cout << "7 - Вывести количество ромбов, площадь которых меньше указанной\n8 - Вставить элемент на место головы списка\n0 - Выход" << std::endl;
                break;
            case 2:
                rhomb = EnterRhombus();
                list.PushBack(rhomb);
                break;
            case 3:
                if (list.Size() <= 0) {
                    std::cout << "Ошибка. Сначала необходимо добавить что-нибудь в список" << std::endl;
                }
                else {
                    std::cout << std::endl;
                    std::for_each(list.Begin(), list.End(), Print);
                }
                break;
            case 4: {
                if (list.Size() <= 0) {
                    std::cout << "Ошибка. Сначала необходимо добавить что-нибудь в список" << std::endl;
                }
                else {   
                    EnterPosition(i);
                    rhomb = EnterRhombus();
                    TList<TRhombus<int>>::TLIterator iter(list, i);
                    try {
                        list.Insert(iter, rhomb);
                    }
                    catch(std::logic_error& error){
                        std::cout << error.what();
                    }
                }
            }
            break;
            case 5: {
                if (list.Size() <= 0) {
                    std::cout << "Ошибка. Сначала необходимо добавить что-нибудь в список" << std::endl;
                }
                else {
                EnterPosition(i);
                TList<TRhombus<int>>::TLIterator iter(list, i);
                try {
                        list.Erase(iter);
                    }
                    catch(std::logic_error& error){
                        std::cout << error.what();
                    }
                }
                break;
            }
            case 6:
                std::cout << list.Size() << std::endl;
            case 7:
                if (list.Size() <= 0) {
                    std::cout << "Ошибка. Сначала необходимо добавить что-нибудь в список" << std::endl;
                }
                else {
                    do {
                        std::cout << "Укажите минимальную площадь: ";
                        std::cin >> square;
                        if (std::cin.fail()) {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << "Ошибка ввода. Повторите ввод." << std::endl;
                        }
                        else if (square < 0) {
                                    std::cout << "Ошибка ввода. Площадь не может быть отрицательной. Повторите ввод.\n";
                                }
                        else {
                            key = true;
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    } while(key != true);
                    key = false;
                    std::cout << "Количество ромбов, имеющих площадь меньше заданной: ";
                    std::cout << std::count_if(list.Begin(), list.End(), TestSquare) << std::endl;
                }
            case 8:
            rhomb = EnterRhombus();
            list.InsertToHead(rhomb);
            break;
            case 0:
            break;
        }
        do {
            std::cout << "Выберете пункт меню: ";
            std::cin >> menu;
            if (std::cin.fail()) { //контроль вводимых данных
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Ошибка ввода. Повторите ввод." << std::endl;
            }
            else if ((menu < 0) || (menu > 8)) {
                std::cout << "Указанный пункт отсутсвует в меню. Попробуйте ещё раз." << std::endl;
            }
            else {
                key = true;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while(key != true);
        key = false;
    }
}