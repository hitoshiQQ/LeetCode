class Solution {
public:
    /**
    * @brief Takes a string a character
    * It reverses the order of characters in the strings up to the first occurrence of the char
    * @param word - string
    * @param ch - character
    * @return Modified string with the prefix reversed , if the character is found
    */
    string reversePrefix(string word, char ch) {

        // Find the first occurrence of the character 'ch' in 'word'
        int index = (int)word.find(ch);

        // If the character is found, reverse the substring
        if (index != string::npos) {
            // Reverse from the beginning of 'word' to the character 'ch' inclusive
            reverse(word.begin(), word.begin() + index + 1);
        }

        // Return the modified string
        return word;
    }
};