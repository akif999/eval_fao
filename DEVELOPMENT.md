# Design

## specification

```
1 + 2 -> 3
1 - 2 -> 1
1 + 2 -1 -> 1
1 - 2 + 1 -> 0
1 + 2 * 3 -> 7
1 + 2 / 3 -> 1 or 1.6XXX
(1 + 2) * 3 -> 9
(1 + 2) / 3 -> 0
```

## Components

* tokenize
* parse
* eval

## Dataflow

[input characters] ->  (tokenize) -> [tokens] -> (parse) -> [ast] -> (eval) -> [output]

