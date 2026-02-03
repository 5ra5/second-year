import java.lang.reflect.Constructor;
import java.util.ArrayList;
import java.util.List;

public class Product {
   private String productName;
   private long price;
   private boolean inStock;
   private List<String> tags = new ArrayList<String>();

   // default constructor
   public Product() {
        this.productName = "Unknown";
        this.price = 0;
        this.inStock = false;
        this.tags = new ArrayList<String>();
   }

   // constructor overloading:
   // constructor with name
   public Product(String name){
        this.productName = name;
        this.price = 0;
        this.inStock = false;
        this.tags = new ArrayList<String>();
   }

   // cosntructor with name and price
   public Product(String name, int price){
        this.productName = name;
        this.price = price;
        this.inStock = false;
        this.tags = new ArrayList<String>();
   }

   // constructor with name, price and stock
   public Product(String name, int price, boolean inStock){
          this.productName = name;
          this.price = price;
          this.inStock = inStock;
          this.tags = new ArrayList<String>();
   }

   // constructor with name, price and tags
   public Product(String name, int price, List<String> tags){
          this.productName = name;
          this.price = price;
          this.inStock = false;
          this.tags = new ArrayList<>(tags);
   }

   // deep copy constructor - constructor with all fields
   public Product(String name, int price, boolean inStock, List<String> tags){
        this.productName = name;
        this.price = price;
        this.inStock = inStock;
        this.tags = new ArrayList<>(tags);
   }

   public List<String> getTags(){
        return tags;
   }

   public void setTags(List<String> tags){
          for (String i : tags) {
               tags.add(i);
          }
   }

   public void addTag(String tag){
          if (!tags.contains(tag)){
               tags.add(tag);
          }
   }

    @Override
    public String toString() {
        return "Product{" +
                "productName='" + productName + '\'' +
                ", price=" + price +
                ", inStock=" + inStock +
                ", tags=" + tags +
                '}';
    }

     public static void main(String[] args){

          
          Product product1 = new Product();
          Product product2 = new Product("Laptop");
          Product product3 = new Product("Tablet", 2900);
          Product product4 = new Product("Case", 30, true);
          Product product5 = new Product("Charger", 10, true, tags);

          
          
          System.out.println(product4);
     }
}