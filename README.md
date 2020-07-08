# School 21/42

## Push-swap

<img src="resources/push-swap_final-mark.png"/>

### Options

Flags | Description
------|------------
  -v  | Debugging mode /and color mode
  -f  | Reading instructions from a file

<img src="resources/debug_mode.gif"/>

### Running

ARG=``ruby -e "puts (1..50).to_a.shuffle.join(' ')"``; ./push_swap $ARG | ./checker -v $ARG
