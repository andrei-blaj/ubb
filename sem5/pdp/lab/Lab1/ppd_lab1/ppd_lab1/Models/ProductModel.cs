namespace ppd_lab1.Models
{
    public class Product
    {
        public Product(string name, int price)
        {
            Name = name;
            Price = price;
        }
        
        public string Name { get; }

        public int Price { get; }
        
        public override string ToString() => $"Product: {Name}, ${Price}";
    }
}