#pragma once

#include <iostream>
#include "../Transports/Transports.h"

#ifdef RACE_EXPORTS
#define EXP __declspec(dllexport)
#else 
#define EXP __declspec(dllimport)
#endif

namespace MyTransports {
	class EXP Race
	{
	public:
		Race();
		MyTransports::Vehicle* arrayTraffic[7]{ nullptr };
		uint16_t typeTransport; // Тип транспортного средства groundTransport = 1, airTransport, airAndGroundVehicles, unspecifiedVehicle,
		std::string raceName; // Имя гонки
		uint16_t nameTransport; // Имя  транспорта 0 - выход из гонки, notDefined = 0, camel, camelFast, centaur,
		// allTerrainBoots, magicCarpet, eagle, broom
		uint16_t actionType; // Тип действия 1 - зарегистрировать ТС. 2 - Начать гонку
		float distance;
		uint16_t counterRegisteredVehicles; // Число зарегистрораванных трнаспортных средств

		bool endRase;

		void (Race::* _execute)();
		void execute();

		void determiningRaceType(); // Определение типов ТС
		void determiningRaceLength(); // Определение длины
		void firstAction(); // первое действие. Подразумевается что можно только начать регистрацию ТС
		void registerVehicle(); // зарегистрировать транспортное средство
		void secondAct(); // повторно зарегистрировать транспортное средство или старт гонки
		void startRace(); // старт гонки
		void arrangeSeats();


	};

}

