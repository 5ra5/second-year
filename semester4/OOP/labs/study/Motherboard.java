class Motherboard {

    // static nested class
    static class USB{
        int usb3 = 1;
        int getUSB(){
            return usb3;
        }
    }

    public static void main(String[] args) {

        Motherboard.USB usb = new Motherboard.USB();
        System.out.println("Total Ports = " + usb.getUSB());
    }
}