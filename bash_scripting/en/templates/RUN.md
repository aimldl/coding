



```bash
#!/bin/bash

## Function Definitions
run() {
  COMMAND=$1
  echo "${COMMAND}"
  eval "${COMMAND}"
}

COMMAND="ls"
run "$COMMAND"
```

