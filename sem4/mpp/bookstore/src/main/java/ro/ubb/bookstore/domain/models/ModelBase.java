package ro.ubb.bookstore.domain.models;

public class ModelBase<ID> {
    private ID id;

    public ID getId() {
        return id;
    }

    public void setId(ID id) {
        this.id = id;
    }

    @Override
    public String toString() {
        return "ModelBase {" + "\n"
                + "id = " + id + "\n"
                + "}\n";
    }
}