#include <iostream>
#include <../Race/Race.h>
#include <../Transports/Transports.h>

#pragma warning (disable : 4251 )




int main()
{
    setlocale(LC_ALL, "Russian");
    // std::cout << "Version 2.0.1" << std::endl << std::endl;

    MyTransports::Race race;

    std::cout << "ƒобро пожаловать в гоночный симул€тор!" << std::endl;


    while (true) {
        race.execute();
        if (race.endRase) break;
    }


    
    return 0;

}