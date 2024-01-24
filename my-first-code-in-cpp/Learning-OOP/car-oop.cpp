#include<iostream>
#include<string>

using namespace std;

class Cars
{
    private:

    string company_name;
    string model_name;
    string fuel_type;
    double mileage;
    string price;

    public:

        void setData(string cname, string mname, string ftype, double m, string p)
        {
            company_name = cname;
            model_name = mname;
            fuel_type = ftype;
            mileage = m;
            price = p;
        }

        void displayData()
        {
            cout << "Class 'Car' Specifics\n\n";
            cout <<  "Manufacturer: " << company_name << endl;
            cout << "Model Name: " << model_name << endl;
            cout << "Fuel Type: " << fuel_type << endl;
            cout << "Mileage: " << mileage << " mpg" << endl;
            cout << "Price: " << price << endl;
        }
    
};

int main()
{
    Cars supramk4, gtr5;

    supramk4.setData("Toyota", "Supra MK4", "Gasoline", 20.3, "50,000");

    gtr5.setData("Nissan", "GT-R R35", "Petrol", 23.8, "100,000");

    supramk4.displayData();

    cout << endl;

    gtr5.displayData();

    return 0;
}
