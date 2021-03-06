#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>
namespace py = pybind11;

#include <parallel_hashmap/phmap.h>

#include <cereal/archives/binary.hpp>
#include <cereal/types/utility.hpp>
#include <cereal/types/array.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/vector.hpp>
#include <fstream>

#include <iostream>


template <typename Key, typename Value>
struct _Dict {
    _Dict () {}

    Value __getitem__ ( const Key & key ) {
        return __dict.at(key);
    }


    bool __setitem__ ( const Key & key, const Value & value ) {
        auto emplace_pair = __dict.emplace(key, value);
        return emplace_pair.second;
    }


    bool __delitem__ ( const Key & key ) {
        int check = __dict.erase(key);

        if (check) {
            return true;
        } else {
            return false;
        }
    }


    int __len__ () {
        return __dict.size();
    }


    bool __contains__ ( const Key & key ) {
        if (__dict.count(key)) {
            return true;
        } else {
            return false;
        }
    }


    void dump ( const std::string & filename ) {
        std::ofstream stream ( filename , std::ios::binary );
        cereal::BinaryOutputArchive oarchive ( stream );

        for ( auto & key_value : __dict ) {
            oarchive(key_value);
        }
    }

    void load ( const std::string & filename ) {
        std::ifstream stream ( filename , std::ios::binary);
        cereal::BinaryInputArchive iarchive ( stream );

        std::pair<Key, Value> in_key_value;
        while ( stream.peek() != EOF ) {
            iarchive(in_key_value);
            __dict.emplace(in_key_value.first, in_key_value.second);
        }
    }


    phmap::parallel_flat_hash_map<Key, Value> __dict;
};


template<typename Key, typename Value>
void declare_dict(const py::module& m, const std::string& class_name) {
    using Class = _Dict<Key, Value>;

    py::class_<Class>(m, class_name.c_str())
        .def(py::init<>())

        .def("__getitem__", &Class::__getitem__)
        .def("__getitem_vec__", py::vectorize(&Class::__getitem__))

        .def("__setitem__", &Class::__setitem__)
        .def("__setitem_vec__", py::vectorize(&Class::__setitem__))

        .def("__delitem__", &Class::__delitem__)
        .def("__delitem_vec__", py::vectorize(&Class::__delitem__))

        .def("__contains__", &Class::__contains__)
        .def("__contains_vec__", py::vectorize(&Class::__contains__))

        .def("dump", &Class::dump)
        .def("load", &Class::load)

        .def("items", [](const Class &c) { return py::make_iterator(c.__dict.begin(), c.__dict.end()); }, py::keep_alive<0, 1>() )
        .def("__len__", &Class::__len__);
}

template<typename Key, typename Value>
void declare_dict_no_vec(const py::module& m, const std::string& class_name) {
    using Class = _Dict<Key, Value>;

    py::class_<Class>(m, class_name.c_str())
        .def(py::init<>())

        .def("__getitem__", &Class::__getitem__)

        .def("__setitem__", &Class::__setitem__)

        .def("__delitem__", &Class::__delitem__)

        .def("__contains__", &Class::__contains__)

        .def("dump", &Class::dump)
        .def("load", &Class::load)

        .def("items", [](const Class &c) { return py::make_iterator(c.__dict.begin(), c.__dict.end()); }, py::keep_alive<0, 1>() )
        .def("__len__", &Class::__len__);
}
