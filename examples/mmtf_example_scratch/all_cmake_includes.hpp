#include <algorithm>
#include <arpa/inet.h>
#include <cstring> // low level mem
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <math.h>
#include <mmtf.hpp>
#include <mmtf/binary_decoder.hpp>
#include <mmtf/binary_encoder.hpp>
#include <mmtf/custom_zone_type_binding.hpp>
#include <mmtf/decoder.hpp>
#include <mmtf/encoder.hpp>
#include <mmtf/errors.hpp>
#include <mmtf/map_decoder.hpp>
#include <mmtf/msgpack_decoders.hpp>
#include <mmtf/msgpack_encoders.hpp>
#include <mmtf/structure_data.hpp>
#include <msgpack.hpp>
#include <pybind11/stl_bind.h>
#include <sstream>
#include <stdexcept>
#include <stdint.h>
#include <string>
#include <vector>
namespace msgpack { using namespace v2; }
