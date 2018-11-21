import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { PersonErrorComponent } from './person-error.component';

describe('PersonErrorComponent', () => {
  let component: PersonErrorComponent;
  let fixture: ComponentFixture<PersonErrorComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ PersonErrorComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(PersonErrorComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
