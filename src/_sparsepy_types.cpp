#include "_sparsepy.cpp"

#include <pybind11/pybind11.h>

using uint16 = uint16_t;
using uint64 = uint64_t;
using int16 = int16_t;
using float64 = double;
using uint32 = uint32_t;
using uint8 = uint8_t;
using int32 = int32_t;
using str = std::string;
using float32 = float;
using int8 = int8_t;
using int64 = int64_t;

PYBIND11_MODULE(_sparsepy, m) {
    m.doc() = "Fast and Memory Efficient Sparse Hash Tables for Python";

	declare_dict<uint32, uint8>(m, "_Dict_uint32_uint8");
	declare_dict<uint32, uint16>(m, "_Dict_uint32_uint16");
	declare_dict<uint32, uint32>(m, "_Dict_uint32_uint32");
	declare_dict<uint32, uint64>(m, "_Dict_uint32_uint64");
	declare_dict<uint32, int8>(m, "_Dict_uint32_int8");
	declare_dict<uint32, int16>(m, "_Dict_uint32_int16");
	declare_dict<uint32, int32>(m, "_Dict_uint32_int32");
	declare_dict<uint32, int64>(m, "_Dict_uint32_int64");
	declare_dict<uint32, bool>(m, "_Dict_uint32_bool");
	declare_dict<uint32, float32>(m, "_Dict_uint32_float32");
	declare_dict<uint32, float64>(m, "_Dict_uint32_float64");
	declare_dict_no_vec<uint32, str>(m, "_Dict_uint32_str");
	declare_dict<uint64, uint8>(m, "_Dict_uint64_uint8");
	declare_dict<uint64, uint16>(m, "_Dict_uint64_uint16");
	declare_dict<uint64, uint32>(m, "_Dict_uint64_uint32");
	declare_dict<uint64, uint64>(m, "_Dict_uint64_uint64");
	declare_dict<uint64, int8>(m, "_Dict_uint64_int8");
	declare_dict<uint64, int16>(m, "_Dict_uint64_int16");
	declare_dict<uint64, int32>(m, "_Dict_uint64_int32");
	declare_dict<uint64, int64>(m, "_Dict_uint64_int64");
	declare_dict<uint64, bool>(m, "_Dict_uint64_bool");
	declare_dict<uint64, float32>(m, "_Dict_uint64_float32");
	declare_dict<uint64, float64>(m, "_Dict_uint64_float64");
	declare_dict_no_vec<uint64, str>(m, "_Dict_uint64_str");
	declare_dict<int32, uint8>(m, "_Dict_int32_uint8");
	declare_dict<int32, uint16>(m, "_Dict_int32_uint16");
	declare_dict<int32, uint32>(m, "_Dict_int32_uint32");
	declare_dict<int32, uint64>(m, "_Dict_int32_uint64");
	declare_dict<int32, int8>(m, "_Dict_int32_int8");
	declare_dict<int32, int16>(m, "_Dict_int32_int16");
	declare_dict<int32, int32>(m, "_Dict_int32_int32");
	declare_dict<int32, int64>(m, "_Dict_int32_int64");
	declare_dict<int32, bool>(m, "_Dict_int32_bool");
	declare_dict<int32, float32>(m, "_Dict_int32_float32");
	declare_dict<int32, float64>(m, "_Dict_int32_float64");
	declare_dict_no_vec<int32, str>(m, "_Dict_int32_str");
	declare_dict<int64, uint8>(m, "_Dict_int64_uint8");
	declare_dict<int64, uint16>(m, "_Dict_int64_uint16");
	declare_dict<int64, uint32>(m, "_Dict_int64_uint32");
	declare_dict<int64, uint64>(m, "_Dict_int64_uint64");
	declare_dict<int64, int8>(m, "_Dict_int64_int8");
	declare_dict<int64, int16>(m, "_Dict_int64_int16");
	declare_dict<int64, int32>(m, "_Dict_int64_int32");
	declare_dict<int64, int64>(m, "_Dict_int64_int64");
	declare_dict<int64, bool>(m, "_Dict_int64_bool");
	declare_dict<int64, float32>(m, "_Dict_int64_float32");
	declare_dict<int64, float64>(m, "_Dict_int64_float64");
	declare_dict_no_vec<int64, str>(m, "_Dict_int64_str");
	declare_dict_no_vec<str, uint8>(m, "_Dict_str_uint8");
	declare_dict_no_vec<str, uint16>(m, "_Dict_str_uint16");
	declare_dict_no_vec<str, uint32>(m, "_Dict_str_uint32");
	declare_dict_no_vec<str, uint64>(m, "_Dict_str_uint64");
	declare_dict_no_vec<str, int8>(m, "_Dict_str_int8");
	declare_dict_no_vec<str, int16>(m, "_Dict_str_int16");
	declare_dict_no_vec<str, int32>(m, "_Dict_str_int32");
	declare_dict_no_vec<str, int64>(m, "_Dict_str_int64");
	declare_dict_no_vec<str, bool>(m, "_Dict_str_bool");
	declare_dict_no_vec<str, float32>(m, "_Dict_str_float32");
	declare_dict_no_vec<str, float64>(m, "_Dict_str_float64");
	declare_dict_no_vec<str, str>(m, "_Dict_str_str");
}
