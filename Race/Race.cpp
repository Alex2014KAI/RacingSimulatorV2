#include "Race.h"

namespace MyTransports {
    Race::Race() : typeTransport(0), raceName(""), nameTransport(0),
        actionType(0), distance(0.0), counterRegisteredVehicles(0), endRase(false) {
        _execute = &Race::determiningRaceType;
    };//
    //

    void Race::execute() {
        (this->*_execute)();
    };//
    //



    void Race::determiningRaceType()
    {
        std::cout << "1. Гонка для наземного транспорта" << std::endl;
        std::cout << "2. Гонка для воздушного транспорта" << std::endl;
        std::cout << "3. Гонка для наземного и воздушного транспорта" << std::endl;

        while (true) {
            std::cout << "Выберите тип гонки: ";
            std::cin >> typeTransport;
            if ((typeTransport != 1) && (typeTransport != 2) && (typeTransport != 3)) {
                std::cout << "Выбран не существующий тип гонки" << std::endl;
            }
            else {
                if (typeTransport == 1) raceName = "Гонка для наземного транспорта. ";
                if (typeTransport == 2) raceName = "Гонка для воздушного транспорта. ";
                if (typeTransport == 3) raceName = " Гонка для наземного и воздушного транспорта. ";
                break;
            }
        }

        _execute = &Race::determiningRaceLength;
    };//
    //

    void Race::determiningRaceLength() {
        while (true) {
            std::cout << "Укажите длину дистанции (должна быть положительная): ";
            std::cin >> distance;
            if (distance <= 0) {
                std::cout << "ДЛИНА ДОЛЖНА БЫТЬ ПОЛОЖИТЕЛЬНОЙ!!! " << std::endl;
            }
            else break;
        }
        _execute = &Race::firstAction;
    };//
    //

    void Race::firstAction()
    {
        std::cout << "Должно быть зарегистрированно хотя бы 2 транспортных средства" << std::endl;

        while (true) {
            std::cout << "1. Зарегистрировать транспорт" << std::endl;
            std::cout << "Выберите действие: ";
            std::cin >> actionType;
            if (actionType != 1) {
                std::cout << "Выбрана не существующая команда!" << std::endl;
            }
            else break;
        };
        _execute = &Race::registerVehicle;
    };//
    //

    void Race::registerVehicle() {
        while (true) {

            std::cout << raceName << "Расстояние: " << distance << std::endl;

            if (counterRegisteredVehicles > 0) {
                std::cout << "Зарегистрированные транспортные средства: ";
                for (int i{ 0 }; i < (counterRegisteredVehicles - 1); i++) {
                    std::cout << arrayTraffic[i]->getName() << "; ";
                };
                std::cout << arrayTraffic[counterRegisteredVehicles - 1]->getName();
            };

            std::cout << std::endl;
            std::cout << "1. Верблюд" << std::endl;
            std::cout << "2. Верблюд-быстроход" << std::endl;
            std::cout << "3. Кентавр" << std::endl;
            std::cout << "4. Ботинки-вездеходы" << std::endl;
            std::cout << "5. Ковёр-самолёт" << std::endl;
            std::cout << "6. Орёл" << std::endl;
            std::cout << "7. Метла" << std::endl;
            std::cout << "0. Закончить регистрацию" << std::endl;

            std::cout << "Выбирите транспорт или 0 для окончания процесса регистрации: ";
            std::cin >> nameTransport;

            if (nameTransport == 0) {
                _execute = &Race::secondAct;
                break;
            }

            bool errorID{ false };
            for (int i{ 0 }; i < counterRegisteredVehicles; i++) {
                if (arrayTraffic[i]->getID() == nameTransport) {
                    std::cout << arrayTraffic[i]->getName() << " уже зарегестрирован!" << std::endl;
                    errorID = true;
                };
            };
            if (errorID) continue;

            bool incorrectNumber{ false };

            switch (nameTransport)
            {
            case 1: {
                arrayTraffic[counterRegisteredVehicles] = new MyTransports::Camel;
                break;
            }
            case 2: {
                arrayTraffic[counterRegisteredVehicles] = new MyTransports::CamelFast;
                break;
            }
            case 3: {
                arrayTraffic[counterRegisteredVehicles] = new MyTransports::Centaur;
                break;
            }
            case 4: {
                arrayTraffic[counterRegisteredVehicles] = new MyTransports::AllTerrainBoots;
                break;
            }
            case 5: {
                arrayTraffic[counterRegisteredVehicles] = new MyTransports::MagicCarpet;
                break;
            }
            case 6: {
                arrayTraffic[counterRegisteredVehicles] = new MyTransports::Eagle;
                break;
            }
            case 7: {
                arrayTraffic[counterRegisteredVehicles] = new MyTransports::Broom;
                break;
            }
            default:
                std::cout << "Введен не корректный номер" << std::endl;
                incorrectNumber = true;
                break;
            };
            if (incorrectNumber) continue;

            bool errorTypeTransport{ false };
            if (typeTransport != 3) {
                if (arrayTraffic[counterRegisteredVehicles]->getTypeTransport() != typeTransport) {
                    std::cout << "Попытка зарегистрировать неправильный тип транспортного средства! " << std::endl;
                    errorTypeTransport = true;
                    delete arrayTraffic[counterRegisteredVehicles];
                };
            };
            if (errorTypeTransport) continue;

            counterRegisteredVehicles++;
        };
    };//
    //


    void Race::secondAct() {

        while (true) {
            std::cout << "1. Зарегистрировать транспорт" << std::endl;
            std::cout << "2. Начать гонку" << std::endl;
            std::cout << "Выберите действие: ";
            std::cin >> actionType;
            if ((actionType != 1) && (actionType != 2)) {
                std::cout << "Выбрана не существующая команда!" << std::endl;
            }
            else if (actionType == 2 && counterRegisteredVehicles < 2) {
                std::cout << "Должно быть зарегистрированно хотя бы 2 транспортных средства" << std::endl;
            }
            else break;
        };

        if (actionType == 1) {
            _execute = &Race::registerVehicle;
        }
        if (actionType == 2) {
            _execute = &Race::startRace;
        }
    };//
    //

    void Race::startRace() {

        std::cout << "Результаты гонки:" << std::endl;
        arrangeSeats();
        for (int i{ 0 }; i < counterRegisteredVehicles; i++) {
            std::cout << i + 1 << ". " << arrayTraffic[i]->getName() << ". Время: " << arrayTraffic[i]->drivingTime(distance) << std::endl;
        };

        for (int i{ 0 }; i < counterRegisteredVehicles; i++) {
            delete arrayTraffic[i];
        };

        typeTransport = 0;
        raceName = "";
        nameTransport = 0;
        actionType = 0;
        distance = 0.0;
        counterRegisteredVehicles = 0;

        std::cout << std::endl;
        std::cout << "1. Провести еще одну гонку" << std::endl;
        std::cout << "2. Выйти" << std::endl;
        std::cout << "Выберите действие: ";

        uint16_t key{ 0 };
        std::cin >> key;
        if (key == 1) {
            _execute = &Race::determiningRaceType;
        }
        if (key == 2) {
            endRase = true;
        }
    };//
    //

    void Race::arrangeSeats() {

        for (int i = 0; i < counterRegisteredVehicles; i++) {
            for (int j = 0; j < (counterRegisteredVehicles - 1); j++) {
                if (arrayTraffic[j]->getSpeed() < arrayTraffic[j + 1]->getSpeed()) {
                    MyTransports::Vehicle* b = arrayTraffic[j];
                    arrayTraffic[j] = arrayTraffic[j + 1];
                    arrayTraffic[j + 1] = b;
                }
            }
        }
    };//
    //





}