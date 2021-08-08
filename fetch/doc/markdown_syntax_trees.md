```puml
@startdot

digraph simple {
    graph [
        bgcolor = transparent
        fontname = consolas
        label = "this *is **a** test* of markdown\n\n"
        labelloc = t
    ]

    node [
        fontname = consolas
        shape = underline
    ]

    t1 [label = "<root>"]
    t2 [label = "'this '"]

    t3 [label = "*"]
    t4 [label = "'is '"]

    t5 [label = "**"]
    t6 [label = "a"]

    t7 [label = "' test'"]

    t8 [label = "' of markdown'"]

    t1 -> t2
    t1 -> t3
    t1 -> t8
    t3 -> t4
    t3 -> t5
    t3 -> t7
    t5 -> t6
}

@enddot
```

```puml
@startdot

digraph adjacent_tokens {
    graph [
        bgcolor = transparent
        fontname = consolas
        label = "***bold and** italic*\n\n"
        labelloc = t
    ]

    node [
        fontname = consolas
        shape = underline
    ]

    ' * or ** first? Must be * in this case.
    t1 [label = "<root>"]

    t2 [label = "*"]
    t3 [label = "**"]
    t4 [label = "'bold and'"]

    t5 [label = "' italic'"]

    t1 -> t2
    t2 -> t3
    t2 -> t5
    t3 -> t4
}

@enddot
```
