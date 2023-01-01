# Word Pattern
- Extract the words from the string using `getWordsFromString` function.
- if the length of `pattern` does not match with words present in s string return `FALSE`
- iterate over the pattern string
- get the char from the `pattern` string
- look if the char is present in `charToWord` map
- if it is present, then check the word mapped with char is same or not
- if different, return `FALSE`
- if it is not present, then check whether the word is already mapped with some other char or not
- if the word is mapped with some other char return `FALSE`
- otherwise, map char to word and mark word is used
- `charToWord[ch] = words[i]` and `wordVisited[words[i]] = true`
return `TRUE` if  you are out from the loop
- `charToWord[ch] = words[i]` and `wordVisited[words[i]] = true`
​