package examSampleWeb.controller;

import examSampleCore.model.Person;
import examSampleCore.service.PersonService;
import examSampleWeb.converter.PersonConverter;
import examSampleWeb.dto.PersonDto;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.util.ArrayList;
import java.util.List;

@RestController
public class PersonController {

   private static final Logger log = LoggerFactory.getLogger(PersonController.class);


    @Autowired
    private PersonService personService;

    @Autowired
    private PersonConverter personConverter;

    @RequestMapping(value = "/persons/{name}", method = RequestMethod.GET)
    public List<PersonDto> getPersons(@PathVariable final String name){
        log.trace("filterPersons: personName={}", name);


        List<Person> people = personService.findAll();

        List<PersonDto> personDtos =  new ArrayList<>();

        for(Person person: people){
            if(person.getSsn().equals(name)){
                personDtos.add(personConverter.convertModelToDto(person));
            }
        }

        log.trace("filterPersons: persons={}", people);


        return personDtos;
    }



    @RequestMapping(value = "/personadd", method = RequestMethod.POST)
    public PersonDto createPerson( @RequestBody final PersonDto personDto) {

        log.trace("createPerson: personDto={}", personDto);

        Person person = personService.createPerson(
                personDto.getName(),
                personDto.getSsn());

        PersonDto result = personConverter.convertModelToDto(person);

         log.trace("createPerson: result={}", result);

        return result;
    }
}
