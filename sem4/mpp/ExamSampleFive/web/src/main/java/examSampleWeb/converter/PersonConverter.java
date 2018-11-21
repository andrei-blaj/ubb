package examSampleWeb.converter;

import examSampleCore.model.Person;
import examSampleWeb.dto.PersonDto;

import org.springframework.stereotype.Component;

@Component
public class PersonConverter extends BaseConverter<Person, PersonDto> {


    @Override
    public Person convertDtoToModel(PersonDto dto) {
        throw new RuntimeException("Not yet implemented!");
    }

    @Override
    public PersonDto convertModelToDto(Person person) {
        PersonDto studentDto = new PersonDto(person.getSsn(), person.getName());
        studentDto.setId(person.getId());
        return studentDto;
    }
}