# singularity

[![https://www.singularity-hub.org/static/img/hosted-singularity--hub-%23e32929.svg](https://www.singularity-hub.org/static/img/hosted-singularity--hub-%23e32929.svg)](https://singularity-hub.org/collections/3111)

## Test of torch matplotlib environment

```
$ singularity pull shub://bmacherone/singularity:torchmatplotlib
$ wget https://raw.githubusercontent.com/bmacherone/singularity/master/test1.bat
$ wget https://raw.githubusercontent.com/bmacherone/singularity/master/train_xor.py

# this is the content of test1.bat:
$ singularity exec singularity_torchmatplotlib.sif python3 train_xor.py --output model.p
```

## scientific python jupyter notebook environment

```
$ singularity pull shub://bmacherone/singularity:scijupyter

$ singularity exec singularity_scijupyter.sif 
```

Samples in the notebooks directory

## singhesh - use singularity as a login shell

```
$ cc -o singlesh singlesh.c
$ cp singlesh /usr/local/bin/.
```

in home direcotry, create a .singleshrc file with one, and only one line:

```
exec /usr/local/singularity/mysingularitycontainter.sif /bin/bash
```

change shell entry in /etc/passwd to /usr/local/bin/singlesh


