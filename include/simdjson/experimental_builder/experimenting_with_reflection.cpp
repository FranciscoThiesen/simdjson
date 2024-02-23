/*
This is only supported by the reflection branch in llvm. The idea here is to experiment how
can we use static reflection to generate a JSON document from a C++ struct.

I also want to use this to learn more about C++ concepts (which seem pretty elegant to me)
*/

// See https://twitter.com/pdimov2/status/1462802234761170949
#include <array>
#include <string_view>
#include <string>
#include <iostream>
#include <vector>

// For now experimental/reflect is not available generally, but
// it should be standardized for C++ 26 ???? Still, we have
// access to it with the very latest llvm.
#include <experimental/reflect>

// We want to have access to the names a, b, c.
// Because we want to produce a JSON document that goes...
// {"a":....., "b":..., "c":....} but for that, we need
// the names "a", "b", "c" as strings accessible in C++.
struct S {
    int a;
    int b;
    double z;
    std::string x;
    std::vector<int> y;
};
namespace reflect = std::experimental::reflect;


// source: https://rebraws.github.io/CppDetectMemberVariables/
template <class... T>
class Helper {  // Note: We could have used a struct too
public:
  static constexpr std::array<std::string_view, sizeof...(T)> getNames() {
    return {reflect::get_name_v<T>...};
  }
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1) os << ", ";
    }
    os << "]";
    return os;
}

template<typename T>
    requires std::is_aggregate_v<T>
constexpr std::size_t size() {
    if constexpr (std::is_array_v<T>) {
        return std::extent_v<T>;
    }
    else {
        using Reflected_t = reflexpr(T);
        using data_members = reflect::get_data_members_t<Reflected_t>;
        return reflect::get_size_v<data_members>;
    }
}


template<typename T, typename Func>
    requires std::is_aggregate_v<T>
void for_each_member(const T& t, Func func) {
    constexpr auto T_size = size<T>();
    if constexpr (std::is_array_v<T>) {
        for (const auto& i : t) {
            func(i);
        }
    }
    else {
        using Reflected_t = reflexpr(T);
        using data_members = reflect::get_data_members_t<Reflected_t>;
        [&] <size_t... ints>(std::index_sequence<ints...>) {
            std::tuple args{ reflect::get_pointer_v<reflect::get_element_t<ints, data_members>>... };
            auto application = [&](auto&&... args) { (func(t.*args), ...); };
            std::apply(application, args);
        }(std::make_index_sequence<T_size>{});
    }
}

template<typename T, typename Func>
    requires std::is_aggregate_v<T>
void for_each(const T& t, Func func) {
    constexpr auto T_size = size<T>();
    if constexpr (std::is_array_v<T>) {
        for (const auto& i : t) {
            func(i);
        }
    }
    else {
        using Reflected_t = reflexpr(T);
        using data_members = reflect::get_data_members_t<Reflected_t>;
        [&] <size_t... ints>(std::index_sequence<ints...>) {
            std::tuple args{ reflect::get_pointer_v<reflect::get_element_t<ints, data_members>>... };
            auto application = [&](auto&&... args) { (func(t.*args), ...); };
            std::apply(application, args);
        }(std::make_index_sequence<T_size>{});
    }
}

template <typename T>
void print2(T x)
{
    using reflected_t = reflexpr(T);
    using data_members = reflect::get_data_members_t<reflected_t>;
    using unpacked = reflect::unpack_sequence_t<Helper, data_members>;
    std::cout << unpacked::getNames().back() << std::endl;
    for(const auto& val : unpacked::getNames())
    {
        std::cout << val << " + ";
    }
    /*
    if constexpr(!requires { std::cout << x; }) {
        std::cout << "[" << &x << "]";
    }
    else
    {
        std::cout << x << ' ';
    }*/
    std::cout << std::endl;
}

template <typename T>
void print_json(T x)
{
    auto print = [](const auto& member) {
        if constexpr (!requires { std::cout << member; }) {
            // This during compile time we don't have std::cout available for the type, we will print this instead
            std::cout << "[" << &member << "] ";
        }
        else {
            // This is the "well-behaved" scenario, where a std::cout implementation is available at compile-time.
            std::cout << member << ' ';
        }
    };

    auto print3 = [](const auto& name, const auto& value) {
        std::cout << std::string_view{name} << " : " << value << '\n';
    };

    using mo = reflexpr(T);
    using member_sequence = reflect::get_data_members_t<mo>;
    using unpacked = reflect::unpack_sequence_t<Helper, member_sequence>;
    std::vector<std::string> field_names;
    static constexpr auto names = unpacked::getNames();
    /*for(const auto& val : unpacked::getNames())
    {
        print2(val);
    }*/
    std::cout << std::endl;

    print2(x);

    for_each_member(x, print);
    return;
}

int main() {
  using mo = reflexpr(S);
  using member_sequence = reflect::get_data_members_t<mo>;
  using unpacked = reflect::unpack_sequence_t<Helper, member_sequence>;
  static constexpr auto names = unpacked::getNames();

  S instance = S();
  instance.a = 3;
  instance.b = 63;
  instance.z = 1.14f;
  instance.x = "batata";
  instance.y = std::vector<int>{1, 2, 3};
  print_json(instance);
  return 0;
}