* Draft: 2021-01-29 (Fri)

# How to Check if Command Exists

Google search: ubuntu linux command how to see if a command exists

* [How can I check if a program exists from a Bash script?](https://stackoverflow.com/questions/592620/how-can-i-check-if-a-program-exists-from-a-bash-script)

> POSIX compatible:
>
> ```sh
> command -v <the_command>
> ```
>
> Example use:
>
> ```sh
> if ! command -v COMMAND &> /dev/null
> then
>     echo "COMMAND could not be found"
>     exit
> fi
> ```
>
> For Bash specific environments:
>
> ```bash
> hash <the_command> # For regular commands. Or...
> type <the_command> # To check built-ins and keywords
> ```



##   Example

Check if Docker has been installed.

* If installed, skip installing it.
* Otherwise, run Bash scripts to install and configure Docker
  * `install_docker_on_ubuntu`
  * `configure_docker_on_ubuntu`

```bash
COMMAND='docker'
if ! command -v ${COMMAND} &> /dev/null
then
    echo "${COMMAND} could not be found. Installing ..."
    install_docker_on_ubuntu
    configure_docker_on_ubuntu
else
    echo "${COMMAND} exists. Skip installing it ..."
fi
```

