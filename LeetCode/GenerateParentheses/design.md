# GenerateParentheses Design

## Sample parentheses permutations

Red edges denote possible paths which I theorize to be more algorithmically complicated than other paths to the same nodes.
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
    edge [color="red"]
    "(())" -> "()(())"
    "(())" -> "(())()"
}
```