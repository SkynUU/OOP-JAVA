public class Main {
    public static void main(String[] args) {
        Person person1 = new Person("Adam", "Kowalski", 23, "Owocowa 23", "555-123-457", "adam@example.com", "Male", true);
        Person person2 = new Person("Janek", "Abacki", 25, "Bacacowa 23", "555-987-6543", "janek@example.com", "Female", true);
        Person person3 = new Person("Tadeusz", "Norek", 22, "Cabacowa 243", "555-111-222", "tadek@example.com", "Male", true);

        Address universityAddress = new Address("123 University Ave", "Cityville", "12345", "USA");

        Person rector = person1;
        Person[] students = {person1, person2, person3};

        University university = new University("City University", universityAddress.toString(), 1990, rector, students);


        System.out.println("Person 1: " + person1.toString());
        System.out.println("Person 2: " + person2.toString());
        System.out.println("Person 3: " + person3.toString());

        System.out.println("\nUniversity Information:");
        System.out.println("University Name: " + university.getName());
        System.out.println("University Location: " + university.getLocation());
        System.out.println("Established Year: " + university.getEstablishedYear());
        System.out.println("Rector: " + university.getRector().getFullName());

        System.out.println("\nStudents:");

        for (Person student : university.getStudents()) {
            System.out.println("- " + student.getFullName());
        }
    }
}