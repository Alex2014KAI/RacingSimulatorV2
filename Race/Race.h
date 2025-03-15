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
		uint16_t typeTransport; // ��� ������������� �������� groundTransport = 1, airTransport, airAndGroundVehicles, unspecifiedVehicle,
		std::string raceName; // ��� �����
		uint16_t nameTransport; // ���  ���������� 0 - ����� �� �����, notDefined = 0, camel, camelFast, centaur,
		// allTerrainBoots, magicCarpet, eagle, broom
		uint16_t actionType; // ��� �������� 1 - ���������������� ��. 2 - ������ �����
		float distance;
		uint16_t counterRegisteredVehicles; // ����� ������������������ ������������ �������

		bool endRase;

		void (Race::* _execute)();
		void execute();

		void determiningRaceType(); // ����������� ����� ��
		void determiningRaceLength(); // ����������� �����
		void firstAction(); // ������ ��������. ��������������� ��� ����� ������ ������ ����������� ��
		void registerVehicle(); // ���������������� ������������ ��������
		void secondAct(); // �������� ���������������� ������������ �������� ��� ����� �����
		void startRace(); // ����� �����
		void arrangeSeats();


	};

}

