package examSampleWeb.dto;

import lombok.*;

import javax.persistence.Column;

@NoArgsConstructor
@AllArgsConstructor
@Getter
@Setter
@Builder
public class PersonDto extends BaseDto {
    @Column(unique = true)
    private String ssn;
    private String name;

    @Override
    public String toString() {
        return "Person{" +
                "ssn='" + ssn + '\'' +
                ", name='" + name + '\'' +
                "} " + super.toString();
    }
}
