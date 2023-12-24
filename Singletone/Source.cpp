#include <iostream>
using namespace std;

class Abstract abstract
{
public:
	virtual Abstract* Clone() abstract;
};

class Speed : public Abstract
{
	int maxSpeed;
public:
	int GetMaxSpeed()
	{
		return maxSpeed;
;
	}
	void SetMaxSpeed(int maxSpeed)
	{
		this->maxSpeed = maxSpeed;
	}
	Abstract* Clone() override
	{
		Speed* maxSpeed = new Speed;
		*maxSpeed = *this;
		return maxSpeed;
	}
};

class FuelConsumption : public Abstract
{
	double fuelConsumption;
public:
	double GetFuelConsumption() 
	{
		return fuelConsumption;
	}
	void SetFuelConsumption(double fuelConsumption)
	{
		this->fuelConsumption = fuelConsumption;
	}
	Abstract* Clone() override 
	{
		FuelConsumption* engine = new FuelConsumption;
		*engine = *this;
		return engine;
	}
};

class GearBox : public Abstract 
{
	int numberOfTransmissions;
public:
	int GetNumOfTransmissions() 
	{
		return numberOfTransmissions;
	}
	void SetNumOfTransmissions(int numberOfTransmissions)
	{
		this->numberOfTransmissions = numberOfTransmissions;
	}
	Abstract* Clone() override 
	{
		GearBox* gearbox = new GearBox;
		*gearbox = *this;
		return gearbox;
	}
};

class BodyType : public Abstract
{
	string bodyType;
	string color;
public:
	string GetBodyType()
	{
		return bodyType;
	}
	string GetColor()
	{
		return color;
	}
	void SetBodyType(string bodyType)
	{
		this->bodyType = bodyType;
	}
	void SetColor(string color)
	{
		this->color = color;
	}
	Abstract* Clone() override
	{
		BodyType* body = new BodyType;
		*body = *this;
		return body;
	}
};

class Prototype abstract 
{
public:
	virtual Prototype* Clone() abstract;
};

class Car : public Prototype 
{
	Speed* maxSpeed;
	FuelConsumption* fuelConsumption;
	GearBox* gearbox;
	BodyType* body;
public:
	Speed* GetMaxSpeed_()
	{
		return this->maxSpeed;
	}
	void SetMaxSpeed_(Speed* maxSpeed)
	{
		this->maxSpeed = maxSpeed;
	}
	FuelConsumption* GetFuelConsumption_()
	{
		return this->fuelConsumption;
	}
	void SetFuelConsumption_(FuelConsumption* fuelConsumption)
	{
		this->fuelConsumption = fuelConsumption;
	}
	GearBox* GetGearBox()
	{
		return this->gearbox;
	}
	void SetGearBox(GearBox* gearbox)
	{
		this->gearbox = gearbox;
	}
	BodyType* GetBody()
	{
		return this->body;
	}
	void SetBody(BodyType* body)
	{
		this->body = body;
	}
	Prototype* Clone() override 
	{
		Car* car = new Car;
		car->maxSpeed= this->maxSpeed != nullptr ? (Speed*)this->maxSpeed->Clone() : nullptr;
		car->fuelConsumption = this->fuelConsumption != nullptr ? (FuelConsumption*)this->fuelConsumption->Clone() : nullptr;
		car->gearbox = this->gearbox != nullptr ? (GearBox*)this->gearbox->Clone() : nullptr;
		car->body = this->body != nullptr ? (BodyType*)this->body->Clone() : nullptr;
		return car;
	}
};

void Print(Car* car) 
{
	cout << "Car";
	cout << "\nMaximum speed: " << car->GetMaxSpeed_()->GetMaxSpeed();
	cout << "\nBody: " << car->GetBody()->GetColor();
	cout << "\nNumber of Transmissions: " << car->GetGearBox()->GetNumOfTransmissions();
	cout << "\nFuel Consumption: " << car->GetFuelConsumption_()->GetFuelConsumption();
}

int main() 
{

	Car* car = new Car();

	BodyType* body = new BodyType();
	body->SetColor("Red");
	car->SetBody(body);

	Speed* maxSpeed = new Speed();
	maxSpeed->SetMaxSpeed(180);
	car->SetMaxSpeed_(maxSpeed);

	GearBox* gearbox = new GearBox();
	gearbox->SetNumOfTransmissions(4);
	car->SetGearBox(gearbox);

	FuelConsumption* engine = new FuelConsumption();
	engine->SetFuelConsumption(3);
	car->SetFuelConsumption_(engine);

	Car* myNewCar = dynamic_cast<Car*>(car->Clone());
	delete car;
	Print(myNewCar);

	return 0;
}