* Draft: 2021-02-18 (Thu)

# Bash Script에서 array를 쓰는 방법

## 목적

`for`루프에서 가독성이 좋은 코드를 만들기 위해 `array`를 쓰고자 합니다.



## Bash Script: array

Google search: bash script array

* [bash loop through list of strings](https://unix.stackexchange.com/questions/450944/bash-loop-through-list-of-strings)

> Using arrays in bash can aid readability: this array syntax allows arbitrary whitespace between words.
>
> ```bash
> strings=(
>     string1
>     string2
>     "string with spaces"
>     stringN
> )
> for i in "${strings[@]}"; do
>     echo "$i"
> done
> ```

* [You don't know Bash: An introduction to Bash arrays](https://opensource.com/article/18/5/you-dont-know-bash-intro-bash-arrays)

> The basics
>
> ```bash
> allThreads=(1 2 4 8 16 32 64 128)
> ```
>
> Looping through arrays
>
> Looping through array elements
>
> ```bash
> for t in ${allThreads[@]}; do
>   ./pipeline --threads $t
> done
> ```
>
> But wait, there's more!
>
> ```bash
> ${arr[@]}	Retrieve all elements
> ```
>
> |    Syntax     |                 Result                  |
> | :-----------: | :-------------------------------------: |
> |    arr=()     |          Create an empty array          |
> |  arr=(1 2 3)  |            Initialize array             |
> |   ${arr[2]}   |         Retrieve third element          |
> |   ${arr[@]}   |          Retrieve all elements          |
> |  ${!arr[@]}   |         Retrieve array indices          |
> |  ${#arr[@]}   |          Calculate array size           |
> |   arr[0]=3    |          Overwrite 1st element          |
> |   arr+=(4)    |             Append value(s)             |
> |   str=$(ls)   |       Save ls output as a string        |
> | arr=( $(ls) ) |   Save ls output as an array of files   |
> | ${arr[@]:s:n} | Retrieve n elements starting at index s |

## 예제 코드

### 예제 1

```bash
#!/bin/bash
# Example 1

BASH_SCRIPT_LIST=(
  sftp-example1
  sftp-example2
  ssh-example3
  ssh-example4
)

## Main
for FILE_NAME in "${BASH_SCRIPT_LIST[@]}"; do
  echo $FILE_NAME
  chmod +x $FILE_NAME
done 
```

### 예제 2

```bash
#!/bin/bash
# Example 2

KEY_PAIR_LIST=(
  keypair-example1.pem
)

for FILE_NAME in "${KEY_PAIR_LIST[@]}"; do
  echo $FILE_NAME
  chmod 400 $FILE_NAME
done 
```



### 예제 3

`batch_chmod`

```bash
#!/bin/bash
# batch_chmod
##### Draft: 2021-02-18 (Thu)

## Configuration
### You may add a new file in the list.

BASH_SCRIPT_LIST=(
  sftp-darknet_benchmark_on_v100-ec2_oregon-p3_2xlarge
  ssh-darknet_benchmark_on_v100-ec2_oregon-p3_2xlarge
)

KEY_PAIR_LIST=(
  keypair-aimldl_test_2021.pem
)

## Function Definition
run() {
  COMMAND=$1
  echo $COMMAND
  eval $COMMAND
}

## Main
for FILE_NAME in "${BASH_SCRIPT_LIST[@]}"; do
  #echo $FILE_NAME
  run "chmod +x $FILE_NAME"
done 

for FILE_NAME in "${KEY_PAIR_LIST[@]}"; do
  #echo $FILE_NAME
  run "chmod 400 $FILE_NAME"
done 
```

