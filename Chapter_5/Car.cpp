#include <time.h>

class Car
{
public:
    Car(std::string model, std::string vendor, int year)
    {
        setModel(model);
        setVendor(vendor);
        setYear(year);
    }

    // Getters and setters
    Car* setModel(std::string model)
    {
        _model = model;
        return this;
    }
    std::string getModel()
    {
        return _model;
    }

    Car* setVendor(std::string vendor)
    {
        _vendor = vendor;
        return this;
    }
    std::string getVendor()
    {
        return _vendor;
    }

    Car* setYear(int year)
    {
        _year = year;
        return this;
    }
    int getYear()
    {
        return _year;
    }
    // END Getters and setters

    // Public methods
    std::string toString(std::string sep = "; ")
    {
        return "Model: " + _model + sep + "Vendor: " + _vendor + sep + "Year: " + std::to_string(_year);
    }

    int getAge()
    {
        time_t theTime = time(NULL);
        struct tm *aTime = localtime(&theTime);

        return aTime->tm_year + 1900 - _year;
    }
    // END Public methods
private:
    std::string _model;
    std::string _vendor;
    int _year;
};