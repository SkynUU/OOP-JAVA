public class University {
    private String name;
    private String location;
    private int establishedYear;
    private Person rector;
    private Person[] students;

    public University(String name, String location, int establishedYear, Person rector, Person[] students) {
        this.name = name;
        this.location = location;
        this.establishedYear = establishedYear;
        this.rector = rector;
        this.students = students;
    }

    public String getName() {
        return name;
    }

    public String getLocation() {
        return location;
    }

    public int getEstablishedYear() {
        return establishedYear;
    }

    public Person getRector() {
        return rector;
    }

    public Person[] getStudents() {
        return students;
    }
}