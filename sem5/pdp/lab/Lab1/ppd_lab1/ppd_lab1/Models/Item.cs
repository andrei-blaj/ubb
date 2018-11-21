namespace ppd_lab1.Models {
    public class Item {
        public Item(string name, int price) {
            Name = name;
            Price = price;
        }
        
        public string Name { get; }

        public int Price { get; }
        
        public override string ToString() => $"Product: {Name}, ${Price}";
    }
}