import java.util.Base64;

interface EncryptionStrategy{
    String encrypt(String text);
}

class CaesarCipherEncryption implements EncryptionStrategy {
    private final int shift;

    public CaesarCipherEncryption(int shift) {
        this.shift = shift;
    }

    @Override
    public String encrypt(String text){
        String result = "";
        for (char ch : text.toCharArray()) {
            if (Character.isLetter(ch)) {
                char base = Character.isLowerCase(ch) ? 'a' : 'A';
                ch = (char) ((ch - base + this.shift) % 26 + base);
            }
            result = result + ch;
        }
        return result.toString();
    }
}

class Base64Encryption implements EncryptionStrategy {
    public String encrypt(String text){
        return Base64.getEncoder().encodeToString(text.getBytes());
    }
}

class XOREncryption implements EncryptionStrategy {

    private final char key;

    public XOREncryption(char key){
        this.key = key;
    }

    @Override
    public String encrypt(String text){
        String result = "";
            for (char ch : text.toCharArray()) {
                result = result + (char)(ch ^ key);
            }
            return result.toString();
    }
}

class ReverseStringEncryption implements EncryptionStrategy {

    @Override
    public String encrypt(String text){
        String result = "";
        for (int i = 0; i < text.length(); i++){
            result = text.charAt(i) + result;
        }
        return result;
    }
}

class DuplicateCharacterEncryption implements EncryptionStrategy {

    @Override
    public String encrypt(String text){
        String result = "";
        for (int i = 0; i< text.length(); i++){
            result = result + text.charAt(i);
            result = result + text.charAt(i);
        }
        return result;
    }
}

class EncryptionService {
    private EncryptionStrategy strategy;

    public void setEncryptionStrategy(EncryptionStrategy strategy) {
        this.strategy = strategy;
    }

    public String encrypt(String text){
        String result = strategy.encrypt(text);
        return result;
    }    
}