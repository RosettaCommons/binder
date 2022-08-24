
from _build import BufferProtocolTest
import numpy as np
m = BufferProtocolTest.buffer_protocol_example.Matrix(3,2)
m1 = np.array(m, copy=False)
m1[2,1] = 4
assert m1[2,1] == m.get(2,1), "Failure: error in sharing data/buffer protocol for Matrix()"
print("Success: Buffer protocol is working for Matrix class")
