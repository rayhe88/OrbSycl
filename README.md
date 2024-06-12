# OrbSycl
![3dz2](https://github.com/rayhe88/OrbSycl/assets/30420297/57156e77-f572-4681-8807-1615720d2f3d=1x)

## Compilation

### Laptop DELL with oneapi
```
mkdir build
cmake ../src/ -DCMAKE_CXX_COMPILER=icpx
cmake --build .
```

### Polaris - ALCF machine
```
module use /soft/modulefiles
module load oneapi/upstream
module load nvhpc-mixed
module load craype-accel-nvidia80
module unload nvhpc-mixed
module load spack-pe-base cmake

EXTRA_FLAGS="-sycl-std=2020 -O3 -fsycl -fsycl-targets=nvptx64-nvidia-cuda -Xsycl-target-backend --cuda-gpu-arch=sm_80"
export CFLAGS="-ffp-model=precise"
export CXXFLAGS="-ffp-model=precise -fsycl $EXTRA_FLAGS"
export CC=clang
export CXX=clang++


mkdir build
cmake ../src/ -DCMAKE_CXX_COMPILER=clang++
cmake --build .
```


## Acknowledgements
This research used resources of the Argonne Leadership Computing Facility, which is a DOE Office of Science User Facility supported under Contract DE-AC02-06CH11357. Argonne National Laboratory’s work was supported by the U.S. Department of Energy, Office of Science, under contract DE-AC02-06CH11357.


All rights reserved. Copyright Argonne National Laboratory UChicago LLC. Raymundo Hernandez-Esparza
