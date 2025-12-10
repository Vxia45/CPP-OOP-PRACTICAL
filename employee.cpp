#include <iostream>
using namespace std;

class Employee{
protected:
    string name;
    double salary;
public:
    Employee(string name, double salary){
    this -> name = name;
    this -> salary = salary;
    }
    virtual double calculateBonus() const {
    return salary * 0.10;
    }
    virtual void displayInfo(){
        cout << "Name: " << name << "\nSalary: " << salary << endl;
    }
    string getName() const{
    return name;
    }
};

class Manager : public Employee {
private:
    string department;
public:
        Manager(string n, double s, string d) : Employee(n, s)
    {
        this->department = d;
    }
    double calculateBonus() const override
    {
        return salary * 0.20;
    }
};

int main(){

Employee e1("Ivan Ivanov", 3000.0);
Manager m1("Petar Petrov", 5000.0, "IT");


Employee* employees[2];
employees[0] = &e1;
employees[1] = &m1;

for(int i = 0; i<=1;i++){
    cout << employees[i]->getName() << " Bonus: " << employees[i]->calculateBonus() << endl;
}
}
