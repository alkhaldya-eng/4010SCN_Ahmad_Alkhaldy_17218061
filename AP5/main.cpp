#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

class Employee {
protected:
    std::string name;
    float salary;
    int staffID;
    static int IDCounter;

public:
    Employee(const std::string& employeeName, float annualSalary)
        : name(employeeName), salary(0.0f), staffID(IDCounter++) {
        SetSalary(annualSalary);
    }
    virtual ~Employee() = default;

    const std::string& GetName() const { return name; }
    void SetName(const std::string& newName) { name = newName; }
    float GetSalary() const { return salary; }
    void SetSalary(float newSalary) {
        if (std::isfinite(newSalary) && newSalary >= 0.0f) salary = newSalary;
    }
    int GetStaffID() const { return staffID; }
    virtual float CalculatePay() const { return salary / 12.0f; }
};

int Employee::IDCounter = 0;

class Manager : public Employee {
private:
    std::vector<Employee*> managedEmployees; // Non-owning pointers; employees must outlive manager.

public:
    Manager(const std::string& managerName, float annualSalary)
        : Employee(managerName, annualSalary) {}

    float CalculatePay() const override {
        return (salary / 12.0f) * (1.0f + 0.1f * managedEmployees.size());
    }

    bool AssignEmployee(Employee& employee) {
        if (employee.GetStaffID() == staffID || FindEmployee(employee.GetStaffID()) != nullptr)
            return false;
        managedEmployees.push_back(&employee);
        return true;
    }

    bool RemoveEmployee(Employee& employee) {
        auto it = std::find_if(managedEmployees.begin(), managedEmployees.end(),
            [&employee](const Employee* person) {
                return person->GetStaffID() == employee.GetStaffID();
            });
        if (it == managedEmployees.end()) return false;
        managedEmployees.erase(it);
        return true;
    }

    Employee* FindEmployee(int ID) const {
        auto it = std::find_if(managedEmployees.begin(), managedEmployees.end(),
            [ID](const Employee* person) { return person->GetStaffID() == ID; });
        return it == managedEmployees.end() ? nullptr : *it;
    }

    float CalculateTeamPay() const {
        float total = CalculatePay();
        for (const Employee* employee : managedEmployees)
            total += employee->CalculatePay();
        return total;
    }
};

class Admin : public Employee {
public:
    Admin(const std::string& adminName, float annualSalary)
        : Employee(adminName, annualSalary) {}

    float CalculatePay() const override { return (salary / 12.0f) * 1.15f; }

    Employee& MoreSkilled(Employee& A, Employee& B) const {
        return A.GetSalary() >= B.GetSalary() ? A : B;
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(2);
    Employee ahmad("Ahmad", 24000.0f);
    Employee sara("Sara", 36000.0f);
    Admin omar("Omar", 30000.0f);
    Manager manager("Maya", 48000.0f);

    std::cout << "C.A.L.S Employee System\n\n";
    std::cout << "Staff IDs: " << ahmad.GetStaffID() << ", " << sara.GetStaffID()
              << ", " << omar.GetStaffID() << ", " << manager.GetStaffID() << "\n";
    std::cout << "Employee monthly pay: " << ahmad.CalculatePay() << "\n";
    std::cout << "Admin monthly pay (15% bonus): " << omar.CalculatePay() << "\n";

    std::cout << "Assign Ahmad: " << std::boolalpha << manager.AssignEmployee(ahmad) << "\n";
    std::cout << "Assign Sara: " << manager.AssignEmployee(sara) << "\n";
    std::cout << "Assign Omar: " << manager.AssignEmployee(omar) << "\n";
    std::cout << "Duplicate Ahmad rejected: " << !manager.AssignEmployee(ahmad) << "\n";
    std::cout << "Find Sara: " << (manager.FindEmployee(sara.GetStaffID()) != nullptr) << "\n";
    std::cout << "Find missing ID: " << (manager.FindEmployee(999) == nullptr) << "\n";
    std::cout << "Manager monthly pay (3 reports): " << manager.CalculatePay() << "\n";
    std::cout << "Team monthly pay: " << manager.CalculateTeamPay() << "\n";

    std::cout << "Remove Sara: " << manager.RemoveEmployee(sara) << "\n";
    std::cout << "Remove Sara again rejected: " << !manager.RemoveEmployee(sara) << "\n";
    std::cout << "Team monthly pay after removal: " << manager.CalculateTeamPay() << "\n";

    ahmad.SetSalary(-500.0f);
    std::cout << "Salary unchanged after negative input: " << ahmad.GetSalary() << "\n";
    ahmad.SetName("Ahmad Alkhaldy");
    std::cout << "Updated name: " << ahmad.GetName() << "\n";
    std::cout << "Higher annual salary: " << omar.MoreSkilled(ahmad, omar).GetName() << "\n";
    Employee equalPay("Equal Pay", 24000.0f);
    std::cout << "Equal salary returns A: " << (&omar.MoreSkilled(ahmad, equalPay) == &ahmad) << "\n";

    const Employee& polymorphicManager = manager;
    const Employee& polymorphicAdmin = omar;
    std::cout << "Virtual manager pay: " << polymorphicManager.CalculatePay() << "\n";
    std::cout << "Virtual admin pay: " << polymorphicAdmin.CalculatePay() << "\n";
}
