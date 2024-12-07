* Draft:2021-05-06 (Thu)
# How to Read in a Config File in a Bash Script

Google search: file
>
> * [Best way to read a config file in bash](https://askubuntu.com/questions/743493/best-way-to-read-a-config-file-in-bash)

Basically, source a file into the Bash script

> ```bash
> #!/bin/bash
> # some.config has the following lines:
> # var1="default value for var1"
> # var2="default value for var2"
> 
> . /path/to/some.config
> echo "$var1" "$var2"
> ```

A more practical way is to check if the file exists before sourcing the file.

> ```bash
> #!/bin/bash
> 
> sysconfdir="/etc" 
> if test -f ${sysconfdir}/default/grub ; then
> . ${sysconfdir}/default/grub
> fi
> ```



