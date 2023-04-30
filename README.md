# PMHeap: ArcHeap on Persistent Memory Allocators

Automatic Techniques to Systematically Discover New Heap Exploitation Primitives on Persistent Memory Allocators

## Environment
- Tested on Ubuntu 20.04 64bit
- PMDK 1.8

## Installation
```bash
$ bash script/setup.sh
$ bash script/install_dependencies.sh
$ bash script/build.sh
```
You need to change `driver/src/nvalloc.c:9`, `path` to your own nvm mount path.

## How to use
```bash
$ cd artifact/nvalloc
$ bash run.sh
$ # wait for AFL running until having enough crashes
$ # you can run do_clean.sh to delete explosive useless heap file periodically.
$ bash getpoc.sh # get minimized PoC of crashes
```

## Vuln Found
- PMDK: not yet
- NValloc: **Double Free & Arbitrary Free** cause **Overlap Chunk**

## References
> [NValloc](https://github.com/ISCS-ZJU/NVAlloc), patched to support customed PM file
>
> [ArcHeap](https://github.com/sslab-gatech/ArcHeap)
