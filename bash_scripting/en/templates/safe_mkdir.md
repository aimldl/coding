```bash
safe_mkdir() {
  # Make a directory if it doesn't exist.
  DIRECTORY=$1
  if [ ! -d "$DIRECTORY" ]; then
    mkdir -p $DIRECTORY
  fi
}
```

Usage

```
safe_mkdir '../logs'
```

