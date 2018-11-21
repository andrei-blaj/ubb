import {Component, Injectable, OnInit} from '@angular/core';
import {Person} from "../person/shared/person.model";
import {Router} from "@angular/router";
import {PersonService} from "../person/shared/person.service";
import {PersonAddComponent} from "../person/person-add/person-add.component";

@Component({
  selector: 'app-person-addcheck',
  templateUrl: './person-addcheck.component.html',
  styleUrls: ['./person-addcheck.component.css']
})
@Injectable({ providedIn: 'root'})
export class PersonAddCheckComponent implements OnInit {

  person: Person;

  constructor(private personService: PersonAddComponent, private router : Router) {
      this.person= personService.person;
  }

  ngOnInit() {
  }


}


