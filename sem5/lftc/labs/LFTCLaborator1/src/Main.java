public class Main {
    public static void main(String[] args){
        Lexer lexer = new Lexer("example2.txt","table.txt");

        lexer.addToST();
        lexer.addToPIF();

        System.out.println("PIF\n" + lexer.getPIF().toString() + "\n");
        System.out.println("Symbol Table for Identifiers\n" + lexer.getSTIdentifiers() + "\n");
        System.out.println("Symbol Table for Constants\n" + lexer.getSTIConstants() + "\n");
    }
}
