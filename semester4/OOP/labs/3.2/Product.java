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

   // constructor with name
   public Product(String name){
        this.productName = (name == null) ? "Unknown" : name;
        this.price = 0;
        this.inStock = false;
        this.tags = new ArrayList<String>();
   }

   // constructor with name and price
   public Product(String name, int price){
        this.productName = (name == null) ? "Unknown" : name; 
        this.price = Math.max(price, 0); 
        this.inStock = false;
        this.tags = new ArrayList<String>();
   }

   // constructor with name, price and stock
   public Product(String name, int price, boolean inStock){
          this.productName = (name == null) ? "Unknown" : name;
          this.price = Math.max(price, 0);   
          this.inStock = inStock;
          this.tags = new ArrayList<String>();
   }

   // constructor with name, price and tags
   public Product(String name, int price, List<String> tags){
          this.productName = (name == null) ? "Unknown" : name; 
          this.price = Math.max(price, 0); 
          this.inStock = false;
          this.tags = (tags == null)
                  ? new ArrayList<String>()
                  : new ArrayList<String>(tags);
   }

   // constructor with all fields
   public Product(String name, int price, boolean inStock, List<String> tags){
        this.productName = (name == null) ? "Unknown" : name;
        this.price = Math.max(price, 0);  
        this.inStock = inStock;
        this.tags = (tags == null)   
                ? new ArrayList<String>()
                : new ArrayList<String>(tags);
   }

   // deep copy
   public Product(Product other) {
     if (other == null) { 
         this.productName = "Unknown";
         this.price = 0;
         this.inStock = false;
         this.tags = new ArrayList<String>();
     } else {
         this.productName = other.productName;
         this.price = other.price;
         this.inStock = other.inStock;
         this.tags = new ArrayList<String>(other.tags);
     }
   }

   public List<String> getTags(){
        return new ArrayList<String>(this.tags);
   }

   public void setTags(List<String> input){
        this.tags = (input == null)
                ? new ArrayList<String>()
                : new ArrayList<String>(input);
   }

   public void addTag(String tag){
        if (tag != null && !tags.contains(tag)){
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
}
