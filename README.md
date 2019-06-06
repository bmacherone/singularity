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
...

Samples in the notebooks directory

<!--stackedit_data:
eyJoaXN0b3J5IjpbMTA3MzM1ODcwOSwtMjEyNDg4MTU3LC0xNz
kxOTY3MTA5XX0=
-->