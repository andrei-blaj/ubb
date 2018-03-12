package ro.ubb.bookstore.domain.models;

public class Person extends ModelBase<Integer> {
    private final String firstName;
    private final String lastName;
    private final String address;
    private final String phoneNo;

    public Person(String firstName, String lastName, String address, String phoneNo) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.address = address;
        this.phoneNo = phoneNo;
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public String getAddress() {
        return address;
    }

    public String getPhoneNo() {
        return phoneNo;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;

        if (obj == null || getClass() != obj.getClass()) {
            return false;
        }

        Person person = (Person)obj;

        return this.firstName.equalsIgnoreCase(person.firstName)
                && this.lastName.equalsIgnoreCase(person.lastName)
                && this.address.equals(person.address)
                && this.phoneNo.equals(person.phoneNo);
    }

    @Override
    public int hashCode() {
        int result = firstName.hashCode();
        result = 101 * result + lastName.hashCode();
        result = 101 * result + address.hashCode();
        result = 101 * result + phoneNo.hashCode();

        return result;
    }
}
