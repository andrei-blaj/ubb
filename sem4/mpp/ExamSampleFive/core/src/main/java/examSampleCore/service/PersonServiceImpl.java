package examSampleCore.service;

import examSampleCore.model.Person;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import examSampleCore.repository.PersonRepository;

import java.util.List;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

@Service
public class PersonServiceImpl  implements  PersonService{

    private static final Logger log = LoggerFactory.getLogger(PersonServiceImpl.class);

    @Autowired
    private PersonRepository personRepository;


    @Override
    public List<Person> findAll() {
        List<Person> persons = personRepository.findAll();
        return persons;
    }

    @Override
    public Person createPerson(String ssn, String name) {
        log.trace("createPerson: name={}, ssn={}", name, ssn);


        Person person= new Person(ssn, name);
        personRepository.save(person);

        log.trace("createPerson: person={}", person);

        return person;
    }


}


