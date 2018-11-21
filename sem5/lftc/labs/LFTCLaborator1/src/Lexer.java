import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.*;
import java.util.regex.Pattern;

public class Lexer {
    public static final List<String> separators = Collections.unmodifiableList(Arrays.asList("(",")","[","]","{","}",";",","," ","\n","\t"));
    public static final List<String> operators = Collections.unmodifiableList(Arrays.asList("+","-","*","/","=","<","<=","==","!=",">=",">","!"));
    public static final List<String> reservedWords = Collections.unmodifiableList(Arrays.asList("and","char","else","if","int","or","std::cin","return","while","std::cout"));

    private String fileName;
    private String fileTable;

    private Map<String, Integer> contentTable;

    private List<Pair<Integer, Integer>> PIF;
    private List<Pair<String, Integer>> STIdentifiers;
    private List<Pair<String, Integer>> STIConstants;

    private static int counterIdentifiers = 0;
    private static int counterConstants = 0;
    private boolean error;

    public Lexer(String fileName, String fileTable){
        this.fileName = fileName;
        this.fileTable = fileTable;
        this.contentTable = readContentTable();
        this.PIF = new ArrayList<Pair<Integer, Integer>>();
        this.STIdentifiers = new ArrayList<Pair<String, Integer>>();
        this.STIConstants = new ArrayList<Pair<String, Integer>>();
        this.error = false;
    }

    public int find(List<Pair<String, Integer>> table, String element){
        for (int i = 0; i < table.size(); i++){
            String str = table.get(i).getKey();
            if (str.compareTo(element) == 0){
                return i;
            }
        }
        return -1;
    }

    public int insertSorted(List<Pair<String, Integer>> table, String element, String mode){
        if (table.size() == 0){
            if (mode == "identifiers"){
                table.add(0, new Pair(element, counterIdentifiers++));
                return counterIdentifiers-1;
            }
            else{
                table.add(0, new Pair(element, counterConstants++));
                return counterConstants-1;
            }
        }
        else{
            int i = 0;
            while (i < table.size() && table.get(i).getKey().compareTo(element) < 0){
                i++;
            }
            if (mode == "identifiers"){
                table.add(i, new Pair(element, counterIdentifiers++));
                return counterIdentifiers-1;
            }
            else{
                table.add(i, new Pair(element, counterConstants++));
                return counterConstants-1;
            }
        }
    }

    public List<Pair<String, Integer>> getSTIdentifiers() {
        return STIdentifiers;
    }

    public List<Pair<String, Integer>> getSTIConstants() {
        return STIConstants;
    }

    public List<Pair<Integer, Integer>> getPIF() {
        return PIF;
    }

    public HashMap<String, Integer> readContentTable(){
        HashMap<String, Integer> table = new HashMap<String, Integer>();
        try{
            File file = new File("/Users/andreiblaj/Documents/ubb/An 3/LFTCLaborator1/resources/" + this.fileTable);
            BufferedReader br = new BufferedReader(new FileReader(file));
            String str;
            String[] list;
            int  i = 0;
            while ((str = br.readLine()) != null) {
                list = str.split(" ");
                table.put(list[0], Integer.parseInt(list[1]));
            }
        }
        catch (Exception e){
            e.printStackTrace();
            System.out.println("Exception while reading from table file!");
        }
        return table;
    }

    public String parseFile(){
        String content = "";
        try{
            File file = new File("/Users/andreiblaj/Documents/ubb/An 3/LFTCLaborator1/resources/" + this.fileName);
            BufferedReader br = new BufferedReader(new FileReader(file));
            String str;
            while ((str = br.readLine()) != null) {
                content += str;
            }
        }
        catch (Exception e){
            e.printStackTrace();
            System.out.println("Exception while reading from file!");
        }
        return content;
    }

    public List<String> detectTokens(){
        String content = parseFile();
        String tokenChar = "";
        String tokenOp = "";
        List<String> tokens = new ArrayList<String>();
        int i = 0;
        while(i < content.length()){
            String ch = Character.toString(content.charAt(i));
            while (!isSeparator(ch) && !isOperator(ch)){
                tokenChar += ch;
                i++;
                if (i < content.length()) {
                    ch = Character.toString(content.charAt(i));
                }
                else{
                    break;
                }
            }
            if (tokenChar != ""){
                tokens.add(tokenChar);
                tokenChar = "";
            }
            while(isSeparator(ch)){
                tokens.add(ch);
                i++;
                if (i < content.length()) {
                    ch = Character.toString(content.charAt(i));
                }
                else{
                    break;
                }
            }
            int ok = 0;
            while(isOperator(ch)){
                tokenOp += ch;
                if (ok == 0){
                    ok = 1;
                    String prev;
                    if (i > 0){
                        prev = Character.toString(content.charAt(i - 1));
                    }
                    else{
                        prev = " ";
                    }
                    if (ch.compareTo("-") == 0 && !isInteger(prev) && !isIdentifier(prev)){
                        i++;
                        if (i < content.length()) {
                            String ch2 = Character.toString(content.charAt(i));
                            while (i < content.length() && isInteger(ch2)){
                                tokenOp += ch2;
                                i++;
                                if (i < content.length()){
                                    ch2 = Character.toString(content.charAt(i));
                                }
                                else{
                                    break;
                                }
                            }
                            break;
                        }
                        else{
                            break;//finish token
                        }
                    }
                    //else if (isInteger(prev) && ch.compareTo("-") == 0){
                        //facem token numa cu intu
                    //}
                    else{
                        i++;
                        if (i < content.length()) {
                            ch = Character.toString(content.charAt(i));
                        }
                        else{
                            break;
                        }
                    }
                }
                else{
                    i++;
                    if (i < content.length()) {
                        ch = Character.toString(content.charAt(i));
                    }
                    else{
                        break;
                    }
                }
            }
            if (tokenOp != ""){
                tokens.add(tokenOp);
                tokenOp = "";
            }
        }
        tokens = removeWhitespaces(tokens);
//        System.out.println(tokens);
        return tokens;
    }

    public List<String> removeWhitespaces(List<String> str){
        List<String> output  = new ArrayList<String>();
        Pattern pattern = Pattern.compile("\\s+");
        for (int i = 0; i < str.size(); i++){
            if (!pattern.matcher(str.get(i)).matches()){
                output.add(str.get(i));
            }
        }
        return output;
    }

    public boolean isSeparator(String ch){
        return separators.contains(ch);
    }

    public boolean isOperator(String ch){
        return operators.contains(ch);
    }

    public boolean isReservedWord(String ch){
        return reservedWords.contains(ch);
    }

    public boolean isIdentifier(String ch){
        Pattern pattern = Pattern.compile("[a-zA-Z]{1,250}");
        if (ch.length() > 8) {
            return false;
        }
        return (pattern.matcher(ch).matches());
    }

    public boolean isConstant(String ch){
        return (isCharacter(ch) || isInteger(ch));
    }

    public boolean isCharacter(String ch){
        Pattern pattern = Pattern.compile("^'[a-zA-Z0-9]'$");
        return (pattern.matcher(ch).matches());
    }

    public boolean isInteger(String ch){
        Pattern pattern = Pattern.compile("[-]?\\d+");
        return (pattern.matcher(ch).matches());
    }

    public void addToST(){
        List<String> tokens = detectTokens();
        for (String token : tokens){
            if (isReservedWord(token) || isOperator(token) || isSeparator(token)){
                continue;
            }
            else if (isIdentifier(token)){
                int pos = find(STIdentifiers, token);
                if (pos == -1){
                    pos = insertSorted(STIdentifiers, token, "identifiers");
                }
            }
            else if (isConstant(token)){
                int pos = find(STIConstants, token);
                if (pos == -1){
                    pos = insertSorted(STIConstants, token, "constants");
                }
            }
        }
    }

    public void addToPIF(){
        List<String> tokens = detectTokens();
        for (String token : tokens){
            if (isReservedWord(token) || isOperator(token) || isSeparator(token)){
                this.PIF.add(new Pair(this.contentTable.get(token),-1));
            }
            else{
                if (isIdentifier(token)){
                    int pos = find(STIdentifiers, token);
                    /*if (pos == -1){
                        pos = insertSorted(STIdentifiers, token, "identifiers");
                    }*/
                    this.PIF.add(new Pair(1, pos));
                }
                else if (isConstant(token)){
                    int pos = find(STIConstants, token);
                    /*if (pos == -1){
                        pos = insertSorted(STIConstants, token, "constants");
                    }*/
                    this.PIF.add(new Pair(0, pos));
                }
                else{
                    this.error = true;
                    System.out.println("Lexical Error "+ token + " is not defined.");
                    this.PIF.clear();
                    this.STIdentifiers.clear();
                    this.STIConstants.clear();
                    break;
                }
            }
        }
    }
}