import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.InputMismatchException;

interface Reader {
    Scanner scanner = new Scanner(System.in);
}

// abstract class defining the template method
abstract class Document implements Reader{
    protected List<String> content = new ArrayList<>();
    protected String type;

    // template method defining the overall process
    public final void generateDocument() {
        createHeader();
        createBody();
        createFooter();
        printDocument();
    }


    void createHeader() {
        System.out.print("Enter company name: ");
        String companyName = scanner.nextLine();
        if (companyName.isEmpty()) throw new IllegalArgumentException("Company name cannot be empty.");

        System.out.print("Enter date (DD/MM/YYYY): ");
        String date = scanner.nextLine();
        if (date.isEmpty()) throw new IllegalArgumentException("Date cannot be empty.");

        // add lines to the document
        content.add("Company: " + companyName);
        content.add("Date: " + date);
    }

    // abstract method to be implemented by subclasses
    abstract void createBody();

    // common methods
    void createFooter() {
        content.add("Prepared by: AutoDoc System");
        content.add("Document Type: " + type);
    }

    void printDocument() {
        System.out.println();
        System.out.println("=== Printing Document ===");
        System.out.printf("=== %s ===\n", type);
        for (String line : content){
            System.out.println(line);
        }
        System.out.println("=========================");
    }
}

class Invoice extends Document {
    
    public Invoice() {
        type = "INVOICE";
    }

    @Override
    void createBody() {
        System.out.print("Enter total amount: ");
        double totalAmount;

        try {
            totalAmount = scanner.nextDouble();
            if(totalAmount <= 0) {
                throw new IllegalArgumentException("Total amount must be positive.");
            }
        } catch (InputMismatchException e) {
            throw new IllegalArgumentException("Total amount must be numeric.");
        }

        content.add("Total Due: €" + totalAmount);
    }
}

class Report extends Document {

    public Report() {
        type = "REPORT";
    }

    @Override
    void createBody() {
        System.out.print("Enter report summary: ");
        String report = scanner.nextLine();
        if (report.isEmpty()){
            System.out.println("Warning: Summary is empty.");
            report = "";
        }

        content.add("Report Summary: " + report);
    }

    @Override
     // common methods
    void createFooter() {
        content.add("Reviewed by: Management Department");
    }
}

class Receipt extends Document {

    public Receipt(){
        type = "RECEIPT";
    }

    @Override
    void createBody() {
        System.out.print("Enter amount paid: ");
        double totalAmount;

        try {
            totalAmount = scanner.nextDouble();
            if(totalAmount <= 0) {
                throw new IllegalArgumentException("Total amount must be positive.");
            }
        } catch (InputMismatchException e) {
            throw new IllegalArgumentException("Total amount must be numeric.");
        }
        
        if (totalAmount <= 0) throw new IllegalArgumentException("Total amount must be positive.");
        
        System.out.print("Enter number of items: ");
        int itemsCount = scanner.nextInt();
        if (itemsCount <= 0) throw new IllegalArgumentException("Items count must be positive.");

        double pricePerItem = totalAmount / itemsCount;

        content.add("Total Paid: €" + totalAmount);
        content.add("Items Purchased: " + itemsCount);
        content.add("Price per Item: €" + pricePerItem);
    }

}

public class DocumentGenerator implements Reader {
    public static void main(String[] args) {
        try {
            System.out.println("Choose document type: (INV) Invoice, (REP) Report, (REC) Receipt");
            String choice = scanner.nextLine();

            Document document;

            switch (choice) {
                case "INV":
                    document = new Invoice();
                    break;
                case "REP":
                    document = new Report();
                    break;
                case "REC":
                    document = new Receipt();
                    break;
                default:
                    System.out.println("Invalid choice. Exiting.");
                    return;
            }

            document.generateDocument();

        } catch (IllegalArgumentException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}