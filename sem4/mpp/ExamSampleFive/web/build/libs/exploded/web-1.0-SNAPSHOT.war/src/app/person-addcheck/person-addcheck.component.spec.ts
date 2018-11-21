import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { PersonAddcheckComponent } from './person-addcheck.component';

describe('PersonAddcheckComponent', () => {
  let component: PersonAddcheckComponent;
  let fixture: ComponentFixture<PersonAddcheckComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ PersonAddcheckComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(PersonAddcheckComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
