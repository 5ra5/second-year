
// abstract class Shape
abstract class Shape {
    protected String color;

    // constructor
    public Shape(String color){
        this.color = color;
    }

    // abstract function
    abstract double getArea();

    // concrete function
    void displayColor(){
        System.out.printf("Shape color: %s\n", color);
    }
}

// subclass rectangle
class Circle extends Shape {
    private double radius;

    // constructor
    public Circle(String color, double radius) {
        super(color);
        if (radius < 0){
            this.radius = 0;
        }else{
            this.radius = radius;
        }
    }

    @Override
    double getArea() {
        return Math.PI * (radius * radius);
    }
}

class Rectangle extends Shape {
    private double width;
    private double height;

    // constructor
    public Rectangle(String color, double width, double height) {
        super(color);
        if (width < 0){
            this.width = 0;
        }else{
            this.width = width;
        }

        if (height < 0){
            this.height = 0;
        }else{
            this.height = height;
        }
    }

    double getArea(){
        return width * height;
    }
}