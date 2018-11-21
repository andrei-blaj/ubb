import { Injectable } from '@angular/core';
import {HttpClient} from "@angular/common/http";
import {Observable} from "rxjs/index";
import {Person} from "./person.model";

@Injectable({
  providedIn: 'root'
})
export class PersonService {
  private personsUrl = 'http://localhost:8080/api/persons';
  private personAddUrl = 'http://localhost:8080/api/personadd';

  constructor(private httpClient: HttpClient) { }

  getPersons(name: string): Observable<Person[]>{

    const url = `${this.personsUrl}/${name}`;
    return this.httpClient.get<Array<Person>>(url)
  }

  create(name: string, ssn: string): Observable<Person> {
    let person = {name, ssn};
    return this.httpClient
      .post<Person>(this.personAddUrl, person);
  }
}
