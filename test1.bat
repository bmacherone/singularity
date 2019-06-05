#!/bin/bash
singularity exec singularity_torchmatplotlib.sif python3 train_xor.py --output model.pt
