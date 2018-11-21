import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { PersonComponent } from './person/person.component';
import {PersonService} from "./person/shared/person.service";
import {HttpClientModule} from "@angular/common/http";
import {FormsModule} from "@angular/forms";
import { PersonAddComponent } from './person/person-add/person-add.component';
import { PersonErrorComponent } from './person/person-error/person-error.component';
import { PersonAddCheckComponent } from './person-addcheck/person-addcheck.component';

@NgModule({
  declarations: [
    AppComponent,
    PersonComponent,
    PersonAddComponent,
    PersonErrorComponent,
    PersonAddCheckComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    FormsModule,
    HttpClientModule
  ],
  providers: [PersonService],
  bootstrap: [AppComponent]
})
export class AppModule { }
