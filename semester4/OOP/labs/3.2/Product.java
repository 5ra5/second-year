import java.lang.reflect.Constructor;
import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;

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

   public void setTags(List<String> input){
          this.tags = new ArrayList<>(input);
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

          
          
          System.out.println(product4);
     }
}