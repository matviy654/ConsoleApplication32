#include <iostream>
#include <cstring>
#include <cctype>

int findSubstring(const char* str, const char* substr) {
    const char* pos = strstr(str, substr);
    return pos ? pos - str : -1;
}

void replaceSubstring(char* str, const char* oldSubstr, const char* newSubstr) {
    char buffer[1024];
    char* pos = strstr(str, oldSubstr);
    if (pos) {
        size_t prefixLen = pos - str;
        strcpy(buffer, str);
        strcpy(buffer + prefixLen, newSubstr);
        strcpy(buffer + prefixLen + strlen(newSubstr), pos + strlen(oldSubstr));
        strcpy(str, buffer);
    }
}

void reverseString(char* str) {
    size_t len = strlen(str);
    for (size_t i = 0; i < len / 2; ++i) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int countOccurrences(const char* str, char ch) {
    int count = 0;
    while (*str) {
        if (*str == ch) ++count;
        ++str;
    }
    return count;
}

bool isPalindrome(const char* str) {
    size_t len = strlen(str);
    for (size_t i = 0; i < len / 2; ++i) {
        if (tolower(str[i]) != tolower(str[len - i - 1])) return false;
    }
    return true;
}

void splitString(const char* str, char words[][100], int& wordCount) {
    wordCount = 0;
    const char* start = str;
    while (*start) {
        while (*start && isspace(*start)) ++start;
        if (*start) {
            const char* end = start;
            while (*end && !isspace(*end)) ++end;
            size_t len = end - start;
            strncpy(words[wordCount], start, len);
            words[wordCount][len] = '\0';
            ++wordCount;
            start = end;
        }
    }
}

void removeExtraSpaces(char* str) {
    char buffer[1024];
    char* dest = buffer;
    const char* src = str;
    bool inSpace = true;
    while (*src) {
        if (isspace(*src)) {
            if (!inSpace) {
                *dest++ = ' ';
                inSpace = true;
            }
        }
        else {
            *dest++ = *src;
            inSpace = false;
        }
        ++src;
    }
    if (dest > buffer && isspace(*(dest - 1))) --dest;
    *dest = '\0';
    strcpy(str, buffer);
}

void toLowercase(char* str) {
    while (*str) {
        *str = tolower(*str);
        ++str;
    }
}

void toUppercase(char* str) {
    while (*str) {
        *str = toupper(*str);
        ++str;
    }
}

void removeCharacter(char* str, char ch) {
    char* dest = str;
    while (*str) {
        if (*str != ch) *dest++ = *str;
        ++str;
    }
    *dest = '\0';
}

void addCharAfterVowels(char* str, char ch) {
    char buffer[1024];
    char* dest = buffer;
    while (*str) {
        *dest++ = *str;
        if (strchr("aeiouAEIOU", *str)) *dest++ = ch;
        ++str;
    }
    *dest = '\0';
    strcpy(str, buffer);
}

void replaceFirstLastWords(char* str, const char* firstWord, const char* lastWord) {
    char words[100][100];
    int wordCount = 0;
    splitString(str, words, wordCount);
    if (wordCount > 0) {
        strcpy(words[0], firstWord);
        strcpy(words[wordCount - 1], lastWord);
    }
    str[0] = '\0';
    for (int i = 0; i < wordCount; ++i) {
        strcat(str, words[i]);
        if (i < wordCount - 1) strcat(str, " ");
    }
}

size_t findLongestWordLength(const char* str) {
    char words[100][100];
    int wordCount = 0;
    splitString(str, words, wordCount);
    size_t maxLength = 0;
    for (int i = 0; i < wordCount; ++i) {
        size_t len = strlen(words[i]);
        if (len > maxLength) maxLength = len;
    }
    return maxLength;
}

void removeDuplicateCharacters(char* str) {
    char seen[256] = { 0 };
    char* dest = str;
    while (*str) {
        if (!seen[(unsigned char)*str]) {
            seen[(unsigned char)*str] = 1;
            *dest++ = *str;
        }
        ++str;
    }
    *dest = '\0';
}

void removeDigits(char* str) {
    char* dest = str;
    while (*str) {
        if (!isdigit(*str)) *dest++ = *str;
        ++str;
    }
    *dest = '\0';
}

void sortCharacters(char* str) {
    size_t len = strlen(str);
    for (size_t i = 0; i < len - 1; ++i) {
        for (size_t j = i + 1; j < len; ++j) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

void replaceVowelsWithAsterisk(char* str) {
    while (*str) {
        if (strchr("aeiouAEIOU", *str)) *str = '*';
        ++str;
    }
}

bool areAllWordsPalindromes(const char* str) {
    char words[100][100];
    int wordCount = 0;
    splitString(str, words, wordCount);
    for (int i = 0; i < wordCount; ++i) {
        if (!isPalindrome(words[i])) return false;
    }
    return true;
}

int countWords(const char* str) {
    char words[100][100];
    int wordCount = 0;
    splitString(str, words, wordCount);
    return wordCount;
}

int main() {
    char input[1024], input2[1024], input3[1024];
    char ch;
    return 0;
}
