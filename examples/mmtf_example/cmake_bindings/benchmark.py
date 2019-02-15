#!/usr/bin/env python

import glob

import mmtf
import time

import mmtf_cpp


mmtf_db = "/home/danpf/Databases/rcsb/mmtf/full"
all_mmtf_files = glob.glob(f"{mmtf_db}/*.mmtf")
all_mmtf_files = all_mmtf_files[:10000]

start = time.time()
for fn in all_mmtf_files:
    mmtf.parse(fn)
end = time.time()
print("time for mmtf-python was:", end-start)

start = time.time()
for fn in all_mmtf_files:
    sd = mmtf_cpp.mmtf.StructureData()
    mmtf_cpp.mmtf.decodeFromFile(sd, fn)
end = time.time()
print("time for mmtf_cpp-python was:", end-start)
