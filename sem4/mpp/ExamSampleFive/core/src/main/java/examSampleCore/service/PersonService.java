package examSampleCore.service;

import examSampleCore.model.Person;

import java.util.List;

public interface PersonService {

    List<Person> findAll();

    Person createPerson(String ssn, String name);

    /*
    Person updateStudent(Long personId, String ssn, String name);

    void deleteStudent(Long personId);*/
}
