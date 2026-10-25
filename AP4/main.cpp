#include <iostream>
#include <string>
#include <iomanip>

class Member {
private:
    std::string name;
    int age;
    float credit;
    static int counter;
    int ID;

public:
    Member(const std::string& memberName, int memberAge)
        : name(memberName), age(memberAge), credit(0.0f), ID(counter) {
        ++counter;
    }

    virtual ~Member() = default;

    std::string GetName() const { return name; }
    void SetName(const std::string& newName) { name = newName; }

    int GetAge() const { return age; }
    void SetAge(int newAge) { age = newAge; }

    void Details() const {
        std::cout << "Name: " << name << " , Age: " << age
                  << " , ID: " << ID << '\n';
    }

    virtual void AddCredits(float amount) {
        credit += amount;
    }

    float GetCredits() const { return credit; }

    static int MembershipAmount() { return counter; }
};

int Member::counter = 0;

class GoldMember : public Member {
public:
    GoldMember(const std::string& memberName, int memberAge)
        : Member(memberName, memberAge) {}

    void AddCredits(float amount) override {
        Member::AddCredits(amount * 1.4f);
    }
};

int main() {
    std::cout << "C.A.L.S Membership System\n\n";

    Member member1("Ahmad", 19);
    Member member2("Sara", 22);
    GoldMember gold1("Omar", 25);

    std::cout << "Initial member details:\n";
    member1.Details();
    member2.Details();
    gold1.Details();

    member1.AddCredits(100.0f);
    member2.AddCredits(50.0f);
    gold1.AddCredits(100.0f);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nCredit balances after adding credits:\n";
    std::cout << member1.GetName() << " (regular): " << member1.GetCredits() << '\n';
    std::cout << member2.GetName() << " (regular): " << member2.GetCredits() << '\n';
    std::cout << gold1.GetName() << " (gold, 1.4x): " << gold1.GetCredits() << '\n';

    member1.SetName("Ahmad Alkhaldy");
    member1.SetAge(20);
    std::cout << "\nUpdated member using setters:\n";
    member1.Details();
    std::cout << "Getter check: " << member1.GetName()
              << ", age " << member1.GetAge() << '\n';

    std::cout << "\nTotal memberships created: "
              << Member::MembershipAmount() << '\n';

    return 0;
}
