#include "Car.hpp"
/*
    constructor delegation: use multiple constructors OF THE SAME CLASS together to make the object
*/
Car::Car(CarType c1, std::string carId, std::string model, Engine *engine) : carId{carId}, _model{model}, engine{engine}, c1{c1}
{
}

/*
    WE CANNOT USE DELEGATED CONSTRUCTORS AND MEMBER LIST INITIALISATION IN THE SAME CONSTRUCTORS
*/
Car::Car(CarType c1, std::string carId, float price, std::string model, Engine *engine) : Car(c1, carId, model, engine)
{
    _price = price;
}

std::string Car::getCarId() const
{
    return carId;
}

float Car::price() const
{
    return _price;
}

void Car::setPrice(float price)
{
    _price = price;
}

std::ostream &operator<<(std::ostream &os, const Car &rhs)
{
    os << "CarId: " << rhs.carId << "\n"
       << "Price: " << rhs._price << "\n"
       << "Model: " << rhs._model << "\n"
       << "Engine: " << rhs.engine
       << "\n";
    return os;
}

std::string Car::model() const
{
    return _model;
}

Engine *Car::getEngine() const
{

    if (engine == nullptr)
        throw EmptyContainerException("Empty container\n", std::future_errc::broken_promise);
    return engine;
}
