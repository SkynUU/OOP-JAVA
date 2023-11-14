#include <iostream>
#include <string>
#include <utility> // Include for std::move
 
class Person {
private:
    std::string firstName;
    std::string lastName;
    int age;
    std::string address;
    std::string phoneNumber;
    std::string email;
    std::string gender;
    bool isStudent;
 
public:
    Person(std::string firstName, std::string lastName, int age, std::string address, std::string phoneNumber,
           std::string email, std::string gender, bool isStudent)
        : firstName(firstName), lastName(lastName), age(age), address(address), phoneNumber(phoneNumber),
          email(email), gender(gender), isStudent(isStudent) {}
 
    std::string GetFullName() {
        return firstName + " " + lastName;
    }
 
    std::string ToString() {
        return firstName + " " + lastName + " | Wiek: " + std::to_string(age) + " | Adres Zamieszkania: " + address +
               " | Numer Telefonu: " + phoneNumber + " | Email: " + email + " | Plec: " + gender +
               " | Czy jest studentem: " + (isStudent ? "true" : "false");
    }
};
 
class Address {
private:
    std::string street;
    std::string city;
    std::string postalCode;
    std::string country;
 
public:
    Address(std::string street, std::string city, std::string postalCode, std::string country)
        : street(street), city(city), postalCode(postalCode), country(country) {}
 
    std::string ToString() {
        return street + ", " + city + ", " + postalCode + ", " + country;
    }
};
 
class University {
private:
    std::string name;
    std::string location;
    int establishedYear;
    Person rector;
    Person* students;
 
public:
    University(std::string name, std::string location, int establishedYear, Person rector, Person* students)
        : name(name), location(location), establishedYear(establishedYear), rector(std::move(rector)), students(students) {}
 
    std::string GetName() {
        return name;
    }
 
    std::string GetLocation() {
        return location;
    }
 
    int GetEstablishedYear() {
        return establishedYear;
    }
 
    Person GetRector() {
        return rector;
    }
 
    Person* GetStudents() {
        return students;
    }
};
 
int main() {
    Person person1 = Person("Adam", "Kowalski", 23, "Owocowa 23", "555-123-457", "adam@example.com", "Male", true);
    Person person2 = Person("Agata", "Abacka", 25, "Bacacowa 23", "555-987-6543", "janek@example.com", "Female", false);
    Person person3 = Person("Tadeusz", "Norek", 22, "Cabacowa 243", "555-111-222", "tadek@example.com", "Male", true);
 
    Address universityAddress = Address("123 University Ave", "Cityville", "12345", "USA");
    Person rector = person1;
    Person students[] = { person1, person2, person3 };
 
    University university("City University", universityAddress.ToString(), 1990, rector, students);
 
    std::cout << "Person 1: " << person1.ToString() << std::endl;
    std::cout << "Person 2: " << person2.ToString() << std::endl;
    std::cout << "Person 3: " << person3.ToString() << std::endl;
 
    std::cout << "\nUniversity Information:" << std::endl;
    std::cout << "University Name: " << university.GetName() << std::endl;
    std::cout << "University Location: " << university.GetLocation() << std::endl;
    std::cout << "Established Year: " << university.GetEstablishedYear() << std::endl;
    std::cout << "Rector: " << university.GetRector().GetFullName() << std::endl;
 
    std::cout << "\nStudents: \n Adam Kowalski \n Agata Abacka \n Tadeusz Norek" << std::endl;
    Person* studentPtr = university.GetStudents();
    for (int i = 0; i < sizeof(university.GetStudents()) / sizeof(Person); i++) {
        std::cout << "- " << studentPtr[i].GetFullName() << std::endl;
    }
 
    return 0;
}