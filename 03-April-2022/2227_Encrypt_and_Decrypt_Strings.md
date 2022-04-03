[2227. Encrypt and Decrypt Strings](https://leetcode.com/problems/encrypt-and-decrypt-strings/)

## **Question**

You are given a character array keys containing unique characters and a string array values containing strings of length 2. You are also given another string array dictionary that contains all permitted original strings after decryption. You should implement a data structure that can encrypt or decrypt a 0-indexed string.

A string is encrypted with the following process:

For each character c in the string, we find the index i satisfying keys[i] == c in keys.

Replace c with values[i] in the string.

A string is decrypted with the following process:

For each substring s of length 2 occurring at an even index in the string, we find an i such that values[i] == s. If there are multiple valid i, we choose any one of them. This means a string could have multiple possible strings it can decrypt to.

Replace s with keys[i] in the string.

Implement the Encrypter class:

Encrypter(char[] keys, String[] values, String[] dictionary) Initializes the Encrypter class with keys, values, and dictionary.

String encrypt(String word1) Encrypts word1 with the encryption process described above and returns the encrypted string.

int decrypt(String word2) Returns the number of possible strings word2 could decrypt to that also appear in dictionary.
 

Example 1:

Input

["Encrypter", "encrypt", "decrypt"]

[[['a', 'b', 'c', 'd'], ["ei", "zf", "ei", "am"], ["abcd", "acbd", "adbc", "badc", "dacb", "cadb", "cbda", "abad"]], ["abcd"], ["eizfeiam"]]

Output

[null, "eizfeiam", 2]

Explanation

Encrypter encrypter = new Encrypter([['a', 'b', 'c', 'd'], ["ei", "zf", "ei", "am"], ["abcd", "acbd", "adbc", "badc", "dacb", "cadb", "cbda", "abad"]);

encrypter.encrypt("abcd"); // return "eizfeiam". 

// 'a' maps to "ei", 'b' maps to "zf", 'c' maps to "ei", and 'd' maps to "am".

encrypter.decrypt("eizfeiam"); // return 2. 

// "ei" can map to 'a' or 'c', "zf" maps to 'b', and "am" maps to 'd'. 

// Thus, the possible strings after decryption are "abad", "cbad", "abcd", and "cbcd". 

// 2 of those strings, "abad" and "abcd", appear in dictionary, so the answer is 2.

## **Solution**


#### **LOGIC**
* Map vector ```keys``` to ```values``` so that we do not need to loop through ```keys``` to find correct value.
* ```dictionary``` is having all decrypted string, so we will encrypt them and see if the result match to the ```word2``` if so, then increase ```sol``` by 1.
* If you crete all decrypted string from ```word2``` and then try to look ```dictionary``` for that valuse. then it will make it very complex in term of code and time.


#### **Code**  
```cpp
class Encrypter {
public:
    unordered_map<char, string> mp1;
    vector<string> dictionary;
    
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        this->dictionary = dictionary;
        for (int i = 0; i < keys.size(); i++) {
            mp1[keys[i]] =  values[i];
        }
    }
    
    string encrypt(string word1) {
        string sol = "";
        for (auto x : word1) {
            sol += mp1[x];
        }
        return sol;
    }
    
    int decrypt(string word2) {
        int sol = 0;
        
        for (auto x : this->dictionary) {
            if (encrypt(x) == word2) {
                sol++;
            }
        }
        
        return sol;
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */
```

## **Complexity**

##### __Apporach : 1__  
##### Time Complexity:  
* __Encrypter__:  __O(size_of_keys)__
* __encrypt__:  __O(size_of_word1)__
* __decrypt__:  __O(size_of_dictionary)__

##### Space Complexity:
* __O(size_of_dictionary)__


<br>

 __Check out all [my](https://leetcode.com/siddp6/) recent solutions [here](https://github.com/sidd6p/LeetCode)__

 
 __Feel Free to Ask Doubts
And Please Share Some Suggestions
HAPPY CODING :)__


