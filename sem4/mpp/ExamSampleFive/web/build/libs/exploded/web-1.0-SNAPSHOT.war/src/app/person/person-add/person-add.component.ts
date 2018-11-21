import { Component, OnInit } from '@angular/core';
import {Person} from "../shared/person.model";
import {PersonService} from "../shared/person.service";
import {Router} from "@angular/router";

@Component({
  selector: 'app-person-add',
  templateUrl: './person-add.component.html',
  styleUrls: ['./person-add.component.css']
})
export class PersonAddComponent implements OnInit {

  person: Person;
  isPressed: boolean;
  init: boolean;
  persons: Array<Person>;
  checkU: boolean;
  errorMessage: string;


  constructor(private personService: PersonService, private router : Router) {
    this.isPressed = false;
    this.init = false;
    this.person = new Person();
    this.person.name = "";
    this.checkU = false;
  }


  save(name, ssn): void {
    this.init = true;
    this.isPressed = false;
    if (this.isValid(ssn)) {
      return;
    }
    this.personService.create(ssn, name)
      .subscribe(
        person => this.person = person
      )

  }

  private isValid(ssn : string) {
    if (this.checkUnique(ssn)) {
      return true;
    }
    return false;
  }

  checkUnique(ssn : string ){
    this.personService.getPersons(ssn)
      .subscribe(persons => {
          this.persons = persons;
          if(this.persons.length != 0){
             this.checkU = true;
             return this.checkU;
          }},
        error => this.errorMessage = <any>error );
  }
  ngOnInit() {
  }

  goError() {
    this.router.navigate(['/registry/error']);
  }

}
