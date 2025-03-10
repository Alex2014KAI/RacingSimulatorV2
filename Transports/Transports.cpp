#include "Transports.h"


namespace MyTransports {

	Vehicle::Vehicle() : name_("not defined"), speed_(0),
		TypeVehicle_(TypeTransport::unspecifiedVehicle),
		id_(nameTransport::notDefined), timeDriving_(0) {};//
	//

	std::string Vehicle::getName()
	{
		return name_;
	};//
	//

	uint16_t Vehicle::getSpeed()
	{
		return speed_;
	};//
	//

	int Vehicle::getTypeTransport()
	{
		return static_cast<int>(TypeVehicle_);
	};//
	//

	int Vehicle::getID()
	{
		return static_cast<int>(id_);
	}
	;//
	//

	void Vehicle::printData()
	{
		switch (TypeVehicle_)
		{
		case TypeTransport::unspecifiedVehicle: std::cout << "Транспортное стредство не определено " << std::endl;
			break;
		case TypeTransport::groundTransport: std::cout << "Наземное транспортное средство " << std::endl;
			break;
		case TypeTransport::airTransport: std::cout << "Воздушное транспортное средство " << std::endl;
			break;
		default:
			break;
		};

		std::cout << "Имя транспортного средства: " << name_ << std::endl;
		std::cout << "Скорость транспортного средства: " << speed_ << std::endl;
		std::cout << "ID: " << static_cast<int>(id_) << std::endl;
	};//
	//


	float Vehicle::drivingTime(float distance) { return 0.0f; };

	GroundTransport::GroundTransport() : Vehicle(), drivingTimeBeforeRest_(0), numberRests(0) {
		TypeVehicle_ = TypeTransport::groundTransport;
		DurationRest[0] = 0;
		DurationRest[1] = 0;
		DurationRest[2] = 0;
	}//
	//

	void GroundTransport::printData()
	{
		switch (TypeVehicle_)
		{
		case TypeTransport::unspecifiedVehicle: std::cout << "Транспортное стредство не определено " << std::endl;
			break;
		case TypeTransport::groundTransport: std::cout << "Наземное транспортное средство " << std::endl;
			break;
		case TypeTransport::airTransport: std::cout << "Воздушное транспортное средство " << std::endl;
			break;
		default:
			break;
		};

		std::cout << "Имя транспортного средства: " << name_ << std::endl;
		std::cout << "Скорость транспортного средства: " << speed_ << std::endl;
		std::cout << "Время движения до отдыха: " << drivingTimeBeforeRest_ << std::endl;
		std::cout << "ID: " << getID() << std::endl;

	};//
	//

	float GroundTransport::drivingTime(float distance)
	{
		uint16_t restCounter = static_cast<uint16_t>(distance / speed_ / drivingTimeBeforeRest_); // количество остановок
		if (static_cast<float>(restCounter * speed_ * drivingTimeBeforeRest_) == (distance)) {
			restCounter--;
		};
		float travelTime = static_cast<float>(distance / speed_); // время за транспортным средством
		timeDriving_ = travelTime;

		for (uint16_t i = 0; i < restCounter; i++)
		{
			if (i >= (numberRests - 1)) {
				timeDriving_ += DurationRest[numberRests - 1];
				continue;
			};
			timeDriving_ += DurationRest[i];
		}

		return timeDriving_;
	};//
	//

	AirTransport::AirTransport() : Vehicle(), distanceReductionFactor_(0) {
		TypeVehicle_ = TypeTransport::airTransport;

	}//
	//

	void AirTransport::printData()
	{
		switch (TypeVehicle_)
		{
		case TypeTransport::unspecifiedVehicle: std::cout << "Транспортное стредство не определено " << std::endl;
			break;
		case TypeTransport::groundTransport: std::cout << "Наземное транспортное средство " << std::endl;
			break;
		case TypeTransport::airTransport: std::cout << "Воздушное транспортное средство " << std::endl;
			break;
		default:
			break;
		};

		std::cout << "Имя транспортного средства: " << name_ << std::endl;
		std::cout << "Скорость транспортного средства: " << speed_ << std::endl;
		std::cout << "ID: " << getID() << std::endl;
	};//
	//

	float AirTransport::drivingTime_(float newDistance)
	{
		timeDriving_ = newDistance / speed_;
		return timeDriving_;
	};//
	//

	AllTerrainBoots::AllTerrainBoots() : GroundTransport() {
		name_ = "Ботинки вездеходы";
		speed_ = 6;
		id_ = nameTransport::allTerrainBoots;
		drivingTimeBeforeRest_ = 60;
		DurationRest[0] = 10;
		DurationRest[1] = 5;
		numberRests = 2;
	};//
	//

	Broom::Broom() : AirTransport() {
		name_ = "Метла";
		speed_ = 20;
		id_ = nameTransport::broom;
		distanceReductionFactor_ = 0;
	};//
	//

	float Broom::drivingTime(float distance) {

		distanceReductionFactor_ = distance / 1000;

		float newDistance = distance * (1.0 - static_cast<float>(distanceReductionFactor_) / 100);
		return drivingTime_(newDistance);
	};//
	//

	Camel::Camel() : GroundTransport() {
		name_ = "Верблюд";
		speed_ = 10;
		id_ = nameTransport::camel;
		drivingTimeBeforeRest_ = 30;
		DurationRest[0] = 5;
		DurationRest[1] = 8;
		numberRests = 2;
	};//
	//

	CamelFast::CamelFast() : GroundTransport() {
		name_ = "Верблюд - быстроход";
		speed_ = 40;
		id_ = nameTransport::camelFast;
		drivingTimeBeforeRest_ = 10;
		DurationRest[0] = 5;
		DurationRest[1] = 6.5;
		DurationRest[2] = 8;
		numberRests = 3;
	};//
	//

	Centaur::Centaur() : GroundTransport() {
		name_ = " Кентавр";
		speed_ = 15;
		id_ = nameTransport::centaur;
		drivingTimeBeforeRest_ = 8;
		DurationRest[0] = 2;
		numberRests = 1;
	};//
	//

	Eagle::Eagle() : AirTransport() {
		name_ = "Орёл";
		speed_ = 8;
		id_ = nameTransport::eagle;
		distanceReductionFactor_ = 6;
	};//
	//

	float Eagle::drivingTime(float distance) {
		float newDistance = distance * (1.0 - static_cast<float>(distanceReductionFactor_) / 100);
		return drivingTime_(newDistance);
	};//
	//

	MagicCarpet::MagicCarpet() : AirTransport() {
		name_ = "Ковёр-самолёт";
		speed_ = 10;
		id_ = nameTransport::magicCarpet;
		distanceReductionFactor_ = 0;
	};//
	//

	float MagicCarpet::drivingTime(float distance) {

		if ((distance >= 1000) && (distance < 5000)) {
			distanceReductionFactor_ = 3;
		};

		if ((distance >= 5000) && (distance < 10000)) {
			distanceReductionFactor_ = 10;
		};

		if (distance >= 10000) {
			distanceReductionFactor_ = 5;
		};

		float newDistance = distance * (1.0 - static_cast<float>(distanceReductionFactor_) / 100);
		return drivingTime_(newDistance);
	};//
	//





}