### Crack

Notes: 
  - The `crypt()` function we used is only available in this form on Linux.  
  - `crack` handles passwords of fixed length 4, consisting of the uppercase and lowercase letters of the English alphabet.
  - This is a brute-force search. `crack` takes a couple of seconds to find the answer.

First, generate a hash to crack. Compile and run `crypt`:
```
$ gcc crypt.c -o crypt -lcrypt
$ ./crypt qwer
abjGQUdiE9.wE
```

Compile and run `crack`. Wait to see if we can find the password we just hashed:
```
$ gcc -Wextra -Wall crack.c -o crack -lcrypt
$ ./crack abjGQUdiE9.wE
Hash supplied: abjGQUdiE9.wE
Password: qwer
```
