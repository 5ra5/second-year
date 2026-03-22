import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

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
        double totalAmount = Double.parseDouble(scanner.nextLine());
        if (totalAmount <= 0) throw new IllegalArgumentException("Total amount must be positive.");

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
            System.out.println("Summary cannot be empty.");
            report = "N/A";
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
}