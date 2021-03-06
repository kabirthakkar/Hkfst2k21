// Java Program to Convert English
// Text to Morse Code and Vice Versa
import java.util.*;
public class Main {
    public static void morseToEnglish(String[] code, String morseCode) {
        String[] array = morseCode.split(" ");
        System.out.print("Morse code " + morseCode + " to English is ");
        // Morse code to English
        for (int i = 0; i < array.length; i++) {
            for (int j = 0; j < code.length; j++) {
                if (array[i].compareTo(code[j]) == 0) {
                    System.out.print((char)(j + 'a') + " ");
                    break;
                }
            }
        }
    }
    public static void englishToMorse(String[] code, String englishLang, char[] letter) {
        System.out.print("Morse code for " + englishLang + " is ");
        for (int i = 0; i < englishLang.length(); i++) {
            for (int j = 0; j < letter.length; j++) {
                if (englishLang.charAt(i) == letter[j]) {
                    System.out.print(code[j] + " ");
                    break;
                }
            }
        }
    }
    public static void main(String[] args) {
        // store the all the alphabet in an array
        char[] letter = {
            'a',
            'b',
            'c',
            'd',
            'e',
            'f',
            'g',
            'h',
            'i',
            'j',
            'k',
            'l',
            'm',
            'n',
            'o',
            'p',
            'q',
            'r',
            's',
            't',
            'u',
            'v',
            'w',
            'x',
            'y',
            'z',
            '1',
            '2',
            '3',
            '4',
            '5',
            '6',
            '7',
            '8',
            '9',
            '0'
        };
        // Morse code by indexing
        String[] code = {
            ".-",
            "-...",
            "-.-.",
            "-..",
            ".",
            "..-.",
            "--.",
            "....",
            "..",
            ".---",
            "-.-",
            ".-..",
            "--",
            "-.",
            "---",
            ".--.",
            "--.-",
            ".-.",
            "...",
            "-",
            "..-",
            "...-",
            ".--",
            "-..-",
            "-.--",
            "--..",
            "|"
        };
        // Given Strings
        Scanner ss = new Scanner(System.in);
        System.out.println("Enter 1 for EnglishToMorse and 2 for MorseToEnglish:");
        int choice = ss.nextInt();
        if (choice == 1) {
            System.out.println("Enter English String:");
            String englishLang = ss.next();
            // English to morse code
            englishToMorse(code, englishLang, letter);
        } else if (choice == 2) {
            System.out.println("Enter Morse Code:");
            String morseCode = ss.next();
            // morse to English
            morseToEnglish(code, morseCode);
        } else
            System.out.println("Invalid Choice");


    }
}
