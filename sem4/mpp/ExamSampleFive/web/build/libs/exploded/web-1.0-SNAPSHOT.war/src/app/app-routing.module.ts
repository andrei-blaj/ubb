import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import {PersonAddComponent} from "./person/person-add/person-add.component";
import {PersonErrorComponent} from "./person/person-error/person-error.component";

const routes: Routes = [
  {path: 'registry', component: PersonAddComponent},
  {path: 'registry/error', component: PersonErrorComponent}
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
