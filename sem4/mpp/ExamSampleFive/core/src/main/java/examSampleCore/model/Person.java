package examSampleCore.model;

import lombok.*;

import javax.persistence.Column;
import javax.persistence.Entity;

@Entity
@NoArgsConstructor
@AllArgsConstructor
@Getter
@Setter
@EqualsAndHashCode
public class Person extends BaseEntity<Long> {
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
