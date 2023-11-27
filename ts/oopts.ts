class Person {
    private firstName: string;
    private lastName: string;
    private age: number;
    private address: string;
    private phoneNumber: string;
    private email: string;
    private gender: string;
    private isStudent: boolean;
   
    constructor(
      firstName: string,
      lastName: string,
      age: number,
      address: string,
      phoneNumber: string,
      email: string,
      gender: string,
      isStudent: boolean
    ) {
      this.firstName = firstName;
      this.lastName = lastName;
      this.age = age;
      this.address = address;
      this.phoneNumber = phoneNumber;
  this.email = email;
      this.gender = gender;
      this.isStudent = isStudent;
    }
   
    getFullName(): string {
      return `${this.firstName} ${this.lastName}`;
    }
   
    toString(): string {
  return `${this.firstName} ${this.lastName} | Wiek: ${this.age} | Adres Zamieszkania: ${this.address} | Numer Telefonu: ${this.phoneNumber} | Email: ${this.email} | Plec: ${this.gender} | Czy jest studentem: ${this.isStudent}`;
    }
  }
   
  class Address {
    private street: string;
    private city: string;
    private postalCode: string;
    private country: string;
   
    constructor(street: string, city: string, postalCode: string, country: string) {
      this.street = street;
  this.city = city;
      this.postalCode = postalCode;
  this.country = country;
    }
   
    toString(): string {
  return `${this.street}, ${this.city}, ${this.postalCode}, ${this.country}`;
    }
  }
   
  class University {
    private name: string;
    private location: string;
    private establishedYear: number;
    private rector: Person;
    private students: Person[];
   
    constructor(name: string, location: string, establishedYear: number, rector: Person, students: Person[]) {
  this.name = name;
      this.location = location;
      this.establishedYear = establishedYear;
      this.rector = rector;
      this.students = students;
    }
   
    getName(): string {
  return this.name;
    }
   
    getLocation(): string {
      return this.location;
    }
   
    getEstablishedYear(): number {
      return this.establishedYear;
    }
   
    getRector(): Person {
      return this.rector;
    }
   
    getStudents(): Person[] {
      return this.students;
    }
  }
   
  const person1 = new Person("Adam", "Kowalski", 23, "Owocowa 23", "555-123-457", "adam@example.com", "Male", true);
  const person2 = new Person("Agata", "Abacka", 25, "Bacacowa 23", "555-987-6543", "janek@example.com", "Female", false);
  const person3 = new Person("Tadeusz", "Norek", 22, "Cabacowa 243", "555-111-222", "tadek@example.com", "Male", true);
   
  const universityAddress = new Address("123 University Ave", "Cityville", "12345", "USA");
   
  const rector = person1;
  const students = [person1, person2, person3];
   
  const university = new University("City University", universityAddress.toString(), 1990, rector, students);
   
  console.log("Person 1: " + person1.toString());
  console.log("Person 2: " + person2.toString());
  console.log("Person 3: " + person3.toString());
   
  console.log("\nUniversity Information:");
  console.log("University Name: " + university.getName());
  console.log("University Location: " + university.getLocation());
  console.log("Established Year: " + university.getEstablishedYear());
  console.log("Rector: " + university.getRector().getFullName());
   
  console.log("\nStudents:");
  for (const student of university.getStudents()) {
    console.log("- " + student.getFullName());
  }