# Introduction

Compute is a simple cli calculator that accepts either 1 or 3 arguments ,
where 3 arguments are used for one operation and 1 argument is used for as many oprands and 
operations as the buffer can fit. Which's a 100B .


## Installation


```sh
git clone https://github.com/DeepBleu64/compute && cd compute && sudo make install 
```


## Uninstallation

```sh
sudo make uninstall 
```


## Usage example 

one argument can be used for as many operations as long as they fit in the buffer .

```sh
compute "(2 + 2)^2 / 3"
```
OR

a 3 arguments where only one operation can be done at a time .

```sh
compute 2 + 2
```

## Motivation

I found myself for numerous of times wanting to do a quick calculation , so i decided to write a simple minimal one that fits my needs for now .

## Additional notes 

* For multiplication using 3 arguments don't forget to escape the '*' sign to avoid shell expansion.

* Due to limitation in the infix-postfix conversion method ,there might be some ambiguity that arises from more complex expressions (particularly ones involving unary minus), to eliminate the possibility of ambiguity that might arise use parentheses to convey your intent.
for example an expression such as 
```sh
-2 + 3 * (5 - -1) - (10 / 2) + -3 would give -32 which is false however if you add parentheses as in 
-2 + (3 * (5 - -1)) - (10 / 2) + -3 you would get 8 which's the correct result.
``` 

	

