public class Demo {
    /* public means accessible from anywhere
     * class is a blueprint for creating objects  */
    /* Anything inside the class is accessible to all other classes in the same package and is object of that class */
    public static void main(String[] args) {
        /* static means that the method belongs to the class rather than an instance of the class
         * void means that the method does not return any value
         *main method is the entry point of any Java program
         * (String[] args) is used to pass command-line arguments 
         * arguments are values passed to the program when it is executed
         * String[] is the type of the array that holds the command-line arguments */
        System.out.println("Hello World");
        /* System is a built-in class that provides access to the system resources
         * out is a static member of the System class that represents the standard output stream
         * println is a method of the PrintStream class that prints the specified message to the console */
    }
}