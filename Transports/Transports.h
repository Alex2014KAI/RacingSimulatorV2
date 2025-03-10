#pragma once
#include <iostream>

#ifdef TRANSPORTS_EXPORTS
#define EXP __declspec(dllexport)
#else 
#define EXP __declspec(dllimport)
#endif

namespace MyTransports {

	enum class EXP TypeTransport {
		groundTransport = 1,
		airTransport,
		airAndGroundVehicles,
		unspecifiedVehicle,
	};

	enum class EXP nameTransport {
		notDefined,
		camel,
		camelFast,
		centaur,
		allTerrainBoots,
		magicCarpet,
		eagle,
		broom
	};

	class EXP Vehicle
	{
	protected:
		std::string name_;
		uint16_t speed_;
		TypeTransport TypeVehicle_;
		nameTransport id_;
		float timeDriving_;
	public:
		Vehicle();
		std::string getName();
		uint16_t getSpeed();
		int getTypeTransport();
		int getID();
		virtual void printData();
		virtual float drivingTime(float distance);
	};

	class EXP GroundTransport : public Vehicle
	{
	protected:
		uint16_t drivingTimeBeforeRest_;
		uint16_t numberRests;
		float DurationRest[3];

	public:
		GroundTransport();
		void printData() override;
		float drivingTime(float distance);
	};

	class EXP AirTransport : public Vehicle
	{
	protected:
		uint16_t distanceReductionFactor_;

	public:
		AirTransport();
		void printData() override;
		float drivingTime_(float newDistance);
	};//
	//

	class EXP AllTerrainBoots : public GroundTransport
	{
	public:
		AllTerrainBoots();
	};

	class EXP Broom : public AirTransport
	{
	public:
		Broom();
		float drivingTime(float distance);
	};

	class EXP Camel : public GroundTransport
	{
	public:
		Camel();
		// void printData() override;
	};

	class EXP CamelFast : public GroundTransport
	{
	public:
		CamelFast();
	};//
	//

	class EXP Centaur : public GroundTransport
	{
	public:
		Centaur();
		// void printData() override;
	};//
	//

	class EXP Eagle : public AirTransport
	{
	public:
		Eagle();
		float drivingTime(float distance);
	};//
	//

	class EXP MagicCarpet : public AirTransport
	{
	public:
		MagicCarpet();
		float drivingTime(float distance);
	};//
	//



}

