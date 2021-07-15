# GenerateParentheses Design
## Theory
Calculate all possible permutations of up to N valid pairs of parentheses:
```plantuml
digraph parentheses {
    node [fontname="consolas"]
    
    "()" [xlabel="n=1"]
    "()()" [xlabel="n=2"]
    "()()()" [xlabel="n=3"]

    "()" -> "()()"
    "()" -> "(())"

    "()()" -> "()()()"
    "()()" -> "()(())"
    "()()" -> "(())()"

    "(())" -> "((()))"
    "(())" -> "(()())"
    "(())" -> "()(())"
    "(())" -> "(())()"
}
```
## Solution ideas
### Lateral Insertion
Insert parenthesis pairs left-to-right in valid positions, based on previous roots:
```
## n = 1 ####
## root: none
  ()
  ^^
## n = 2 ####
## root: ()
  ()()
  ^^
  (())
   ^^
## n = 3 ####
## root: ()()
  ()()()
  ^^
  (())()
   ^^
  ()()()
    ^^
  ()(())
     ^^
  ()()()
      ^^

## root: (())
  ()(())
  ^^
  (()())
   ^^
  ((()))
    ^^
  (()())
     ^^
  (())()
      ^^
```
Then discard duplicates.
