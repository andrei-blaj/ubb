package controller;

import repository.IRepository;

public class Controller {

    public IRepository repo;

    public Controller(IRepository repo) {
        this.repo = repo;
    }



}
