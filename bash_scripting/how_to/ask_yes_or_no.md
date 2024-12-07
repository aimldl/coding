* Rev.1: 2021-01-25 (Mon)
* Draft: 2020-07-16 (Thu)

# Ask Yes or No

## Example: Reinstall Docker?
This function is without the `while` loop.

```bash
ask_to_reinstall() {
  read -p "Reinstall Docker? (y/n)" REPLY
  if [ $REPLY == "[Nn]" ]; then
    echo "Exiting..."
    exit 1
  fi
}
```

The popular way is to use the `while` loop as follows.

```bash
ask_to_reinstall() {
  while true; do
    read -p "Reinstall Docker? (y/n)" REPLY
    case $REPLY in
      [Yy]* ) ;;
      [Nn]* ) echo "Exiting..."; exit 1; ;;
      * ) echo "Enter either yes or no." ;;
    esac
  done
}
```
## Example: Reboot?
```bash
# Define function(s)
run() {
  COMMAND=$1
  echo $COMMAND
  eval $COMMAND
}

show_suggestions_after_reboot() {
  echo 'After rebooting the system, run:'
  echo '  $ nvidia-smi'
}

ask_to_reboot() {
  while true; do
    show_suggestions_after_reboot
    read -p "Reboot? (y/n)" REPLY
    case $REPLY in
      [Yy]* ) run 'reboot'; ;;
      [Nn]* ) echo "Exiting..."; exit 1; ;;
      * ) echo "Enter either yes or no." ;;
    esac
  done
}

# Run the defined function ask_to_reboot
ask_to_reboot
```

## References

> Google search: bash script read either yes or no
>
> The simplest and most widely available method to get user input at a shell prompt is the [`read`](https://www.gnu.org/software/bash/manual/bashref.html#index-read) command.
>
> ```sh
> while true; do
>     read -p "Do you wish to install this program?" yn
>     case $yn in
>         [Yy]* ) make install; break;;
>         [Nn]* ) exit;;
>         * ) echo "Please answer yes or no.";;
>     esac
> done
> ```
>
> Another method, [pointed out](https://stackoverflow.com/a/226946/9084) by [Steven Huwig](https://stackoverflow.com/users/28604/steven-huwig), is Bash's [`select`](https://www.gnu.org/software/bash/manual/bashref.html#index-select) command.
>
> ```sh
> echo "Do you wish to install this program?"
> select yn in "Yes" "No"; do
>     case $yn in
>         Yes ) make install; break;;
>         No ) exit;;
>     esac
> done
> ```
>
> Source: [How do I prompt for Yes/No/Cancel input in a Linux shell script?](https://stackoverflow.com/questions/226703/how-do-i-prompt-for-yes-no-cancel-input-in-a-linux-shell-script)

For details about commands, refer to:

* [Bash read command](https://linuxhint.com/bash_read_command/)
* [Bash Select Command](https://linuxhint.com/bash_select_command/)
