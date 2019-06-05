#!/bin/bash
singularity exec singularity_torchmatplotlib.sid python3 train_xor.py --output model.pt
