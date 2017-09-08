/*#include "Tests.h"
 #include "assert.h"
 #include "Controller.h"
 #include <vector>
 #include "AdoptionList.h"
 #include "Repository.h"
 #include "Dog.h"
 
 void Tests::testDog()
 {
	Age a{ 1,2,12 };
	Dog d{ "Metis","Azor",a,"www.google.com" };
	assert(d.getBreed() == "Metis");
	assert(d.getName() == "Azor");
	assert(d.getAge().getYears() == 1);
	assert(d.getAge().getMonths() == 2);
	assert(d.getAge().getDays() == 12);
	assert(d.getPhotograph() == "www.google.com");
 }
 
 void Tests::testVector()
 {
	std::vector<int> v1{ 2 };
	v1.push_back(20);
	v1.push_back(10);
	assert(v1.size() == 3);
	assert(v1[1] == 20);
	v1.push_back(30);
	assert(v1.size() == 4);
 
	std::vector<int> v2;
	v2 = v1;
	assert(v2[0] == 2);
 }
 
 void Tests::testRepository()
 {
	Repository repo{};
	Dog d{ "Labrador","Elba",Age{ 2,10,11 },"www.google.com" };
	repo.addDog(d);
	Dog dd = repo.findByBreedAndName("Labrador", "Elba");
	assert(dd.getAge().getDays() == 11);
	assert(dd.getPhotograph() == "www.google.com");
	assert(dd.getBreed() == "Labrador");
	Dog dd2 = repo.findByBreedAndName("Labrador", "Cora");
	assert(dd2.getBreed() == "");
	assert(dd2.getName() == "");
 
	std::vector<Dog> dogs = repo.getDogs();
	assert(dogs.size() == 1);
 
	assert(repo.findPosByBreedAndName("Labrador", "Elba") == 0);
	assert(repo.findPosByBreedAndName("d", "n") == -1);
 
	Dog d1{ "L","E",Age{ 2,10,11 },"www.google.com" };
	repo.addDog(d1);
	std::vector<Dog> dogs2 = repo.getDogs();
	assert(dogs2.size() == 2);
 
	assert(repo.findPosByBreedAndName("L", "E") == 1);
 
	repo.deleteDog(d1);
	std::vector<Dog> dogs3 = repo.getDogs();
	assert(dogs3.size() == 1);
 
	Dog d3{ "D","N",Age{ 6,1,11 },"www.google.com" };
	repo.updateDog(d, d3);
	std::vector<Dog> dogs4 = repo.getDogs();
	assert(dogs4[0].getBreed() == "D");
	assert(dogs4[0].getName() == "N");
	assert(dogs4[0].getAge().getYears() == 6);
 
	Dog d4{ "D2","N2",Age{ 3,12,1 },"www.google.com" };
	repo.setDogOnPos(0, d4);
	std::vector<Dog> dogs5 = repo.getDogs();
	assert(dogs5[0].getBreed() == "D2");
	assert(dogs5[0].getName() == "N2");
	assert(dogs5[0].getAge().getYears() == 3);
 
	Dog d5{ "Ciobanesc","Cora",Age{ 2,10,11 },"www.google.com" };
	repo.addDog(d5);
	repo.sortAscendingByBreed();
	std::vector<Dog> dogs6 = repo.getDogs();
	assert(dogs6.size() == 2);
	assert(dogs6[0].getBreed() == "Ciobanesc");
	assert(dogs6[1].getBreed() == "D2");
 
 
	std::vector<Dog> dogs7 = repo.getDogs();
	repo.deleteDog(dogs7[0]);
	repo.deleteDog(dogs7[1]);
	assert(repo.findPosByBreedAndName("Ciobanesc", "D2") == -1);
 }
 
 void Tests::testAdoptionList()
 {
	AdoptionList adopted{};
	assert(adopted.isEmpty() == true);
	Dog d{ "Labrador","Elba",Age{ 2,10,11 },"www.google.com" };
	Dog d2{ "Labrador","Elsa",Age{ 2,10,11 },"www.google.com" };
	adopted.add(d);
	adopted.add(d2);
	assert(adopted.isEmpty() == false);
	std::vector<Dog> l = adopted.getAdoptedDogs();
	assert(l.size() == 2);
	assert(l[0].getBreed() == "Labrador");
	assert(l[0].getName() == "Elba");
	assert(l[1].getBreed() == "Labrador");
	assert(l[1].getName() == "Elsa");
 }
 void Tests::testController()
 {
	Repository repo{};
	AdoptionList adoptionList{};
	Controller ctrl{ repo,adoptionList };
	Controller();
 
	ctrl.addDogToRepository("b", "n", 1, 1, 1, "www");
	ctrl.addDogToRepository("b2", "n2", 2, 2, 2, "aaa");
	assert(ctrl.getRepo().getDogs().size() == 2);
	assert(ctrl.addDogToRepository("b2", "n2", 2, 2, 2, "aaa") != 1);
	assert(ctrl.addDogToRepository("b3", "n3", 2, 2, 2, "ccc") == 1);
 
	assert(ctrl.deleteDogToRepository("b", "n") == 1);
	assert(ctrl.deleteDogToRepository("b", "n2") == -1);
 
	assert(ctrl.updateDogToRepository("b", "n2", "c", "d", 3, 2, 22, "newSite") == -1);
	assert(ctrl.updateDogToRepository("b2", "n2", "bNew", "nNew", 3, 2, 22, "newSite") == 1);
 
	ctrl.sortAscendingByBreedCtrl();
	std::vector<Dog> dogs = ctrl.getRepo().getDogs();
	assert(dogs[0].getBreed() == "b3");
	assert(dogs[1].getBreed() == "bNew");
 
	std::vector<Dog> q = ctrl.filterByBreedAndAge("ciobanesc", 4);
	assert(q.size() == 0);
	std::vector<Dog> q2 = ctrl.filterByBreedAndAge("b3", 4);
	assert(q2.size() == 1);
 
	std::vector<Dog> l = ctrl.getRepo().getDogs();
	ctrl.showFirstDog(l);
	Dog d = ctrl.getCurrentDog(l);
	assert(d.getBreed() == "b3");
	assert(d.getName() == "n3");
 
	ctrl.nextDog(l);
	Dog d2 = ctrl.getCurrentDog(l);
	assert(d2.getBreed() == "bNew");
	assert(d2.getName() == "nNew");
 
	//assert(this->current == l.size());
 
	ctrl.nextDog(l);
	Dog d3 = ctrl.getCurrentDog(l);
	assert(d3.getBreed() == "b3");
	assert(d3.getName() == "n3");
 
	ctrl.addDogToAdoptionList(d3);
	std::vector<Dog> adopted = ctrl.getAdoptionList().getAdoptedDogs();
	std::vector<Dog> rep = ctrl.getRepo().getDogs();
	assert(adopted.size() == 1);
	assert(rep.size() == 1);
 
	ctrl.addDogToAdoptionList(d2);
	std::vector<Dog> adopted2 = ctrl.getAdoptionList().getAdoptedDogs();
	std::vector<Dog> rep2 = ctrl.getRepo().getDogs();
	assert(adopted2.size() == 2);
	assert(rep2.size() == 0);
 
 
	ctrl.nextDog(rep2);
	ctrl.showFirstDog(rep2);
 }
 
 void Tests::testAll()
 {
	testDog();
	testVector();
	testRepository();
	testAdoptionList();
	testController();
 }*/
