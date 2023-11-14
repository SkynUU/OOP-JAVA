using System;

public class Program
{
    public static void Main()
    {
        Person person1 = new Person("Adam", "Kowalski", 23, "Owocowa 23", "555-123-457", "adam@example.com", "Male", true);
        Person person2 = new Person("Agata", "Abacka", 25, "Bacacowa 23", "555-987-6543", "janek@example.com", "Female", false);
        Person person3 = new Person("Tadeusz", "Norek", 22, "Cabacowa 243", "555-111-222", "tadek@example.com", "Male", true);
        Address universityAddress = new Address("123 University Ave", "Cityville", "12345", "USA");
        Person rector = person1;
        Person[] students = { person1, person2, person3 };
        University university = new University("City University", universityAddress.ToString(), 1990, rector, students);

        Console.WriteLine("Person 1: " + person1.ToString());
        Console.WriteLine("Person 2: " + person2.ToString());
        Console.WriteLine("Person 3: " + person3.ToString());
        Console.WriteLine("\nUniversity Information:");
        Console.WriteLine("University Name: " + university.GetName());
        Console.WriteLine("University Location: " + university.GetLocation());
        Console.WriteLine("Established Year: " + university.GetEstablishedYear());
        Console.WriteLine("Rector: " + university.GetRector().GetFullName());
        Console.WriteLine("\nStudents:");
        foreach (Person student in university.GetStudents())
        {
            Console.WriteLine("- " + student.GetFullName());
        }
    }
}

public class Person
{
    private string firstName;
    private string lastName;
    private int age;
    private string address;
    private string phoneNumber;
    private string email;
    private string gender;
    private bool isStudent;

    public Person(string firstName, string lastName, int age, string address, string phoneNumber, string email, string gender, bool isStudent)
    {
        this.firstName = firstName;
        this.lastName = lastName;
        this.age = age;
        this.address = address;
        this.phoneNumber = phoneNumber;
        this.email = email;
        this.gender = gender;
        this.isStudent = isStudent;
    }

    // Getters and setters
    public string GetFullName()
    {
        return firstName + " " + lastName;
    }

    public override string ToString()
    {
        return firstName + " " + lastName + " | Wiek: " + age + " | Adres Zamieszkania: " + address + " | Numer Telefonu:" + phoneNumber + " | Email: " + email + " | Plec:  " + gender + " | Czy jest studentem: " + isStudent;
    }
}

public class Address
{
    private string street;
    private string city;
    private string postalCode;
    private string country;

    public Address(string street, string city, string postalCode, string country)
    {
        this.street = street;
        this.city = city;
        this.postalCode = postalCode;
        this.country = country;
    }

    public override string ToString()
    {
        return street + ", " + city + ", " + postalCode + ", " + country;
    }
}

public class University
{
    private string name;
    private string location;
    private int establishedYear;
    private Person rector;
    private Person[] students;

    public University(string name, string location, int establishedYear, Person rector, Person[] students)
    {
        this.name = name;
        this.location = location;
        this.establishedYear = establishedYear;
        this.rector = rector;
        this.students = students;
    }

    public string GetName()
    {
        return name;
    }

    public string GetLocation()
    {
        return location;
    }

    public int GetEstablishedYear()
    {
        return establishedYear;
    }

    public Person GetRector()
    {
        return rector;
    }

    public Person[] GetStudents()
    {
        return students;
    }
}