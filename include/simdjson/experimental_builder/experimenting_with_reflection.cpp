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

// -*- C++ -*-
//===---------------------------- mirror ----------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
// This header is a non-standard extension of the ReflectionTS and may be
// changed or removed without prior notice.
//===----------------------------------------------------------------------===//

#ifndef _LIBCPP_EXPERIMENTAL_MIRROR
#define _LIBCPP_EXPERIMENTAL_MIRROR

#include <experimental/__config>
#include <__debug>
#include <type_traits>
#include <string_view>

#if !defined(_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER)
#endif

#ifdef _LIBCPP_HAS_NO_REFLECTION
# if defined(_LIBCPP_WARNING)
    _LIBCPP_WARNING("<experimental/mirror> cannot be used with this compiler")
# else
#   warning <experimental/mirror> cannot be used with this compiler
# endif
#else
# ifdef _LIBCPP_HAS_NO_REFLECTION_EXT
#  if defined(_LIBCPP_WARNING)
     _LIBCPP_WARNING("<experimental/mirror> cannot be used without -freflection-ext ")
#  else
#    warning <experimental/mirror> cannot be used without -freflection-ext
#  endif
# endif
#endif

#if !defined(_LIBCPP_HAS_NO_REFLECTION) && !defined(_LIBCPP_HAS_NO_REFLECTION_EXT )

_LIBCPP_BEGIN_NAMESPACE_EXPERIMENTAL
namespace mirror {

template <__metaobject_id _Mp>
struct metaobject {};

template <__metaobject_id _Mp>
consteval bool reflects_object(metaobject<_Mp>) {
  return __metaobject_is_meta_object(_Mp);
}

template <__metaobject_id _Mp>
consteval bool reflects_object_sequence(metaobject<_Mp>) {
  return __metaobject_is_meta_object_sequence(_Mp);
}

template <__metaobject_id _Mp>
consteval bool reflects_named(metaobject<_Mp>) {
  return __metaobject_is_meta_named(_Mp);
}

template <__metaobject_id _Mp>
consteval bool reflects_alias(metaobject<_Mp>) {
  return __metaobject_is_meta_alias(_Mp);
}

template <__metaobject_id _Mp>
consteval bool reflects_scope(metaobject<_Mp>) {
  return __metaobject_is_meta_scope(_Mp);
}

template <__metaobject_id _Mp>
consteval bool reflects_typed(metaobject<_Mp>) {
  return __metaobject_is_meta_typed(_Mp);
}

template <__metaobject_id _Mp>
consteval bool reflects_scope_member(metaobject<_Mp>) {
  return __metaobject_is_meta_scope_member(_Mp);
}

template <__metaobject_id _Mp>
consteval bool reflects_global_scope_member(metaobject<_Mp>) {
  if constexpr (__metaobject_is_meta_scope_member(_Mp)) {
    return __metaobject_is_meta_global_scope(__metaobject_get_scope(_Mp));
  } else {
    return false;
  }
}

template <__metaobject_id _Mp>
consteval bool reflects_enumerator(metaobject<_Mp>) {
  return __metaobject_is_meta_enumerator(_Mp);
}

template <__metaobject_id _Mp>
consteval bool reflects_record_member(metaobject<_Mp>) {
  return __metaobject_is_meta_record_member(_Mp);
}

template <__metaobject_id _Mp>
consteval bool reflects_base(metaobject<_Mp>) {
  return __metaobject_is_meta_base(_Mp);
}

template <__metaobject_id _Mp>
consteval bool reflects_namespace(metaobject<_Mp>) {
  return __metaobject_is_meta_namespace(_Mp);
}

template <__metaobject_id _Mp>
consteval bool reflects_inline_namespace(metaobject<_Mp>) {
  if constexpr (__metaobject_is_meta_namespace(_Mp)) {
    return __metaobject_is_inline(_Mp);
  } else {
    return false;
  }
}

template <__metaobject_id _Mp>
consteval bool reflects_global_scope(metaobject<_Mp>) {
  return __metaobject_is_meta_global_scope(_Mp);
}

template <__metaobject_id _Mp>
consteval bool reflects_type(metaobject<_Mp>) {
  return __metaobject_is_meta_type(_Mp);
}

template <__metaobject_id _Mp>
consteval bool reflects_enum(metaobject<_Mp>) {
  return __metaobject_is_meta_enum(_Mp);
}

template <__metaobject_id _Mp>
consteval bool reflects_record(metaobject<_Mp>) {
  return __metaobject_is_meta_record(_Mp);
}

template <__metaobject_id _Mp>
consteval bool reflects_class(metaobject<_Mp>) {
  return __metaobject_is_meta_class(_Mp);
}

template <__metaobject_id _Mp>
consteval bool reflects_lambda(metaobject<_Mp>) {
  return __metaobject_is_meta_lambda(_Mp);
}

template <__metaobject_id _Mp>
consteval bool reflects_constant(metaobject<_Mp>) {
  return __metaobject_is_meta_constant(_Mp);
}

template <__metaobject_id _Mp>
consteval bool reflects_variable(metaobject<_Mp>) {
  return __metaobject_is_meta_variable(_Mp);
}

template <__metaobject_id _Mp>
consteval bool reflects_lambda_capture(metaobject<_Mp>) {
  return __metaobject_is_meta_lambda_capture(_Mp);
}

template <__metaobject_id _Mp>
consteval bool reflects_function_parameter(metaobject<_Mp>) {
  return __metaobject_is_meta_function_parameter(_Mp);
}

template <__metaobject_id _Mp>
consteval bool reflects_callable(metaobject<_Mp>) {
  return __metaobject_is_meta_callable(_Mp);
}

template <__metaobject_id _Mp>
consteval bool reflects_function(metaobject<_Mp>) {
  return __metaobject_is_meta_function(_Mp);
}

template <__metaobject_id _Mp>
consteval bool reflects_member_function(metaobject<_Mp>) {
  return __metaobject_is_meta_member_function(_Mp);
}

template <__metaobject_id _Mp>
consteval bool reflects_special_member_function(metaobject<_Mp>) {
  return __metaobject_is_meta_special_member_function(_Mp);
}

template <__metaobject_id _Mp>
consteval bool reflects_constructor(metaobject<_Mp>) {
  return __metaobject_is_meta_constructor(_Mp);
}

template <__metaobject_id _Mp>
consteval bool reflects_destructor(metaobject<_Mp>) {
  return __metaobject_is_meta_destructor(_Mp);
}

template <__metaobject_id _Mp>
consteval bool reflects_operator(metaobject<_Mp>) {
  return __metaobject_is_meta_operator(_Mp);
}

template <__metaobject_id _Mp>
consteval bool reflects_conversion_operator(metaobject<_Mp>) {
  return __metaobject_is_meta_conversion_operator(_Mp);
}

template <__metaobject_id _Mp>
consteval bool reflects_expression(metaobject<_Mp>) {
  return __metaobject_is_meta_expression(_Mp);
}

template <__metaobject_id _Mp>
consteval bool reflects_specifier(metaobject<_Mp>) {
  return __metaobject_is_meta_specifier(_Mp);
}

// unary operations
// boolean
template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_variable(_Mp) ||
  __metaobject_is_meta_callable(_Mp)>>
consteval bool is_constexpr(metaobject<_Mp>) {
  return __metaobject_is_constexpr(_Mp);
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_constructor(_Mp) ||
  __metaobject_is_meta_conversion_operator(_Mp)>>
consteval bool is_explicit(metaobject<_Mp>) {
  return __metaobject_is_explicit(_Mp);
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_namespace(_Mp) ||
  __metaobject_is_meta_callable(_Mp)>>
consteval bool is_inline(metaobject<_Mp>) {
  return __metaobject_is_inline(_Mp);
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_variable(_Mp) ||
  __metaobject_is_meta_member_function(_Mp)>>
consteval bool is_static(metaobject<_Mp>) {
  return __metaobject_is_static(_Mp);
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_base(_Mp) ||
  __metaobject_is_meta_destructor(_Mp) ||
  __metaobject_is_meta_member_function(_Mp)>>
consteval bool is_virtual(metaobject<_Mp>) {
  return __metaobject_is_virtual(_Mp);
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_destructor(_Mp) ||
  __metaobject_is_meta_member_function(_Mp)>>
consteval bool is_pure_virtual(metaobject<_Mp>) {
  return __metaobject_is_pure_virtual(_Mp);
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_class(_Mp) ||
  __metaobject_is_meta_member_function(_Mp)>>
consteval bool is_final(metaobject<_Mp>) {
  return __metaobject_is_final(_Mp);
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_record_member(_Mp) ||
  __metaobject_is_meta_base(_Mp)>>
consteval bool is_private(metaobject<_Mp>) {
  return __metaobject_is_private(_Mp);
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_record_member(_Mp) ||
  __metaobject_is_meta_base(_Mp)>>
consteval bool is_protected(metaobject<_Mp>) {
  return __metaobject_is_protected(_Mp);
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_record_member(_Mp) ||
  __metaobject_is_meta_base(_Mp)>>
consteval bool is_public(metaobject<_Mp>) {
  return __metaobject_is_public(_Mp);
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_named(_Mp)>>
consteval bool is_unnamed(metaobject<_Mp>) {
  return __metaobject_is_unnamed(_Mp);
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_type(_Mp)>>
consteval bool is_enum(metaobject<_Mp>) {
  return __metaobject_is_enum(_Mp);
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_type(_Mp)>>
consteval bool is_scoped_enum(metaobject<_Mp>) {
  return __metaobject_is_scoped_enum(_Mp);
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_type(_Mp)>>
consteval bool is_union(metaobject<_Mp>) {
  return __metaobject_is_union(_Mp);
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_type(_Mp)>>
consteval bool uses_class_key(metaobject<_Mp>) {
  return __metaobject_uses_class_key(_Mp);
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_type(_Mp)>>
consteval bool uses_struct_key(metaobject<_Mp>) {
  return __metaobject_uses_struct_key(_Mp);
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_lambda(_Mp)>>
consteval bool uses_default_copy_capture(metaobject<_Mp>) {
  return __metaobject_uses_default_copy_capture(_Mp);
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_lambda(_Mp)>>
consteval bool uses_default_reference_capture(metaobject<_Mp>) {
  return __metaobject_uses_default_reference_capture(_Mp);
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_lambda(_Mp)>>
consteval bool is_call_operator_const(metaobject<_Mp>) {
  return __metaobject_is_call_operator_const(_Mp);
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_member_function(_Mp)>>
consteval bool is_const(metaobject<_Mp>) {
  return __metaobject_is_const(_Mp);
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_member_function(_Mp)>>
consteval bool is_volatile(metaobject<_Mp>) {
  return __metaobject_is_volatile(_Mp);
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_member_function(_Mp)>>
consteval bool has_lvalueref_qualifier(metaobject<_Mp>) {
  return __metaobject_has_lvalueref_qualifier(_Mp);
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_member_function(_Mp)>>
consteval bool has_rvalueref_qualifier(metaobject<_Mp>) {
  return __metaobject_has_rvalueref_qualifier(_Mp);
}

template <__metaobject_id _Ml, __metaobject_id _Mr>
consteval bool reflects_same(metaobject<_Ml>, metaobject<_Mr>) {
  return __metaobject_reflects_same(_Ml, _Mr);
}

// integer
template <__metaobject_id _Mp>
consteval size_t get_id(metaobject<_Mp>) {
  return __metaobject_get_id_value(_Mp);
}

template <__metaobject_id _Mp>
consteval size_t get_source_line(metaobject<_Mp>) {
  return __metaobject_get_source_line(_Mp);
}

template <__metaobject_id _Mp>
consteval size_t get_source_column(metaobject<_Mp>) {
  return __metaobject_get_source_column(_Mp);
}

template <__metaobject_id _Mp>
struct _get_pointer
  : integral_constant<
    __unrefltype(__metaobject_get_pointer(_Mp)),
    __metaobject_get_pointer(_Mp)> {};

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_variable(_Mp) ||
  __metaobject_is_meta_function(_Mp)>>
consteval auto get_pointer(metaobject<_Mp>) {
  return _get_pointer<_Mp>::value;
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_variable(_Mp)>>
constexpr const auto& get_value(metaobject<_Mp>) {
  return *_get_pointer<_Mp>::value;
}

template <__metaobject_id _Mp, class _Cp, typename = enable_if_t<
  __metaobject_is_meta_record_member(_Mp) &&
  __metaobject_is_meta_variable(_Mp)>>
constexpr const auto& get_value(metaobject<_Mp>, const _Cp& obj) {
  return obj.*_get_pointer<_Mp>::value;
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_variable(_Mp)>>
constexpr auto& get_reference(metaobject<_Mp>) {
  return *_get_pointer<_Mp>::value;
}

template <__metaobject_id _Mp, class _Cp, typename = enable_if_t<
  __metaobject_is_meta_record_member(_Mp) &&
  __metaobject_is_meta_variable(_Mp)>>
constexpr auto& get_reference(metaobject<_Mp>, _Cp& obj) {
  return obj.*_get_pointer<_Mp>::value;
}

template <__metaobject_id _Mp>
struct _get_constant
  : integral_constant<
    __unrefltype(__metaobject_get_constant(_Mp)),
    __metaobject_get_constant(_Mp)> {};

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_constant(_Mp)>>
constexpr auto get_constant(metaobject<_Mp>) {
  return _get_constant<_Mp>::value;
}

template <__metaobject_id _Mp, typename _Cp, typename ... _Ap,
  typename = enable_if_t<__metaobject_is_meta_member_function(_Mp)>>
constexpr auto invoke_on(metaobject<_Mp> mo, _Cp& obj, _Ap&&... args) {
  if constexpr(is_static(mo)) {
    return (*_get_pointer<_Mp>::value)(std::forward<_Ap>(args)...);
  } else {
    return (obj.*_get_pointer<_Mp>::value)(std::forward<_Ap>(args)...);
  }
}

template <__metaobject_id _Mp, typename ... _Ap, typename = enable_if_t<
  __metaobject_is_meta_function(_Mp) ||
  (__metaobject_is_meta_member_function(_Mp) && __metaobject_is_static(_Mp))>>
constexpr auto invoke(metaobject<_Mp>, _Ap&&... args) {
  return (*_get_pointer<_Mp>::value)(std::forward<_Ap>(args)...);
}

template <__metaobject_id _Mp, typename _Cp, typename ... _Ap,
  typename = enable_if_t<
    __metaobject_is_meta_member_function(_Mp) && !__metaobject_is_static(_Mp)>>
constexpr auto invoke(metaobject<_Mp>, _Cp& obj, _Ap&&... args) {
  return (obj.*_get_pointer<_Mp>::value)(std::forward<_Ap>(args)...);
}

template <__metaobject_id _Mp, typename ... _Ap>
constexpr std::enable_if_t<
  __metaobject_is_meta_constructor(_Mp),
  __unrefltype(__metaobject_get_scope(_Mp))>
invoke(metaobject<_Mp>, _Ap&&... args) {
  return __unrefltype(__metaobject_get_scope(_Mp))(std::forward<_Ap>(args)...);
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_object_sequence(_Mp)>>
consteval size_t get_size(metaobject<_Mp>) {
  return __metaobject_get_size(_Mp);
}

// string
consteval string_view get_source_file_name_view(__metaobject_id mo) {
  return {__metaobject_get_source_file_name(mo),
          __metaobject_source_file_name_len(mo)};
}

template <__metaobject_id _Mp>
consteval string_view get_source_file_name(metaobject<_Mp>) {
  return get_source_file_name_view(_Mp);
}

consteval string_view get_name_view(__metaobject_id mo) {
  return {__metaobject_get_name(mo),
          __metaobject_name_len(mo)};
}

template <
  __metaobject_id _Mp,
  typename = enable_if_t<__metaobject_is_meta_named(_Mp)>>
consteval string_view get_name(metaobject<_Mp>) {
  return get_name_view(_Mp);
}

consteval string_view get_display_name_view(__metaobject_id mo) {
  return {__metaobject_get_display_name(mo),
          __metaobject_display_name_len(mo)};
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_named(_Mp)>>
consteval string_view get_display_name(metaobject<_Mp>) {
  return get_display_name_view(_Mp);
}

// metaobject
template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_scope_member(_Mp)>>
constexpr auto get_scope(metaobject<_Mp>) {
  return metaobject<__metaobject_get_scope(_Mp)>{};
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_typed(_Mp)>>
constexpr auto get_type(metaobject<_Mp>) {
  return metaobject<__metaobject_get_type(_Mp)>{};
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_enum(_Mp)>>
constexpr auto get_underlying_type(metaobject<_Mp>) {
  return metaobject<__metaobject_get_underlying_type(_Mp)>{};
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_alias(_Mp)>>
constexpr auto get_aliased(metaobject<_Mp>) {
  return metaobject<__metaobject_get_aliased(_Mp)>{};
}

template <__metaobject_id _Mp>
constexpr auto remove_all_aliases(metaobject<_Mp> mo) {
  if constexpr (__metaobject_is_meta_alias(_Mp)) {
    return remove_all_aliases(metaobject<__metaobject_get_aliased(_Mp)>{});
  } else {
    return mo;
  }
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_base(_Mp)>>
constexpr auto get_class(metaobject<_Mp>) {
  return metaobject<__metaobject_get_class(_Mp)>{};
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_class(_Mp)>>
constexpr auto get_base_classes(metaobject<_Mp>) {
  return metaobject<__metaobject_get_base_classes(_Mp)>{};
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_record(_Mp)>>
constexpr auto get_member_types(metaobject<_Mp>) {
  return metaobject<__metaobject_get_member_types(_Mp)>{};
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_record(_Mp)>>
constexpr auto get_data_members(metaobject<_Mp>) {
  return metaobject<__metaobject_get_data_members(_Mp)>{};
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_record(_Mp)>>
constexpr auto get_member_functions(metaobject<_Mp>) {
  return metaobject<__metaobject_get_member_functions(_Mp)>{};
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_record(_Mp)>>
constexpr auto get_constructors(metaobject<_Mp>) {
  return metaobject<__metaobject_get_constructors(_Mp)>{};
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_record(_Mp)>>
constexpr auto get_destructors(metaobject<_Mp>) {
  return metaobject<__metaobject_get_destructors(_Mp)>{};
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_record(_Mp)>>
constexpr auto get_operators(metaobject<_Mp>) {
  return metaobject<__metaobject_get_operators(_Mp)>{};
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_enum(_Mp)>>
constexpr auto get_enumerators(metaobject<_Mp>) {
  return metaobject<__metaobject_get_enumerators(_Mp)>{};
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_callable(_Mp)>>
constexpr auto get_parameters(metaobject<_Mp>) {
  return metaobject<__metaobject_get_parameters(_Mp)>{};
}

template <__metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_lambda(_Mp)>>
constexpr auto get_captures(metaobject<_Mp>) {
  return metaobject<__metaobject_get_captures(_Mp)>{};
}

template <size_t _I, __metaobject_id _Mp, typename = enable_if_t<
  __metaobject_is_meta_object_sequence(_Mp)>>
constexpr auto get_element(metaobject<_Mp>) {
  return metaobject<__metaobject_get_element(_Mp, _I)>{};
}

// unpacking
template <__metaobject_id ... _Mp>
struct unpacked_metaobject_sequence {};

template <__metaobject_id _Mp>
constexpr auto unpack(metaobject<_Mp>) {
  return __unpack_metaobject_seq<unpacked_metaobject_sequence, _Mp>{};
}

// unpacked range operations
template <__metaobject_id... _Mp, typename _Fp>
void for_each(unpacked_metaobject_sequence<_Mp...>, _Fp function) {
  (void)(..., function(metaobject<_Mp>{}));
}

template <
  __metaobject_id _Mp, typename _Fp,
  typename = enable_if_t<__metaobject_is_meta_object_sequence(_Mp)>>
void for_each(metaobject<_Mp> mo, _Fp function) {
  return for_each(unpack(mo), std::move(function));
}

template <typename _Tp, __metaobject_id... _Mp, typename _Fp, typename... _Pp>
_Tp select(unpacked_metaobject_sequence<_Mp...>,
          _Fp function, _Tp fallback, _Pp&&... param) {
  (void)(..., function(fallback, metaobject<_Mp>{}, std::forward<_Pp>(param)...));
  return fallback;
}

template <typename _Tp, __metaobject_id _Mp, typename _Fp, typename... _Pp>
enable_if_t<__metaobject_is_meta_object_sequence(_Mp), _Tp>
select(metaobject<_Mp> mo, _Fp function, _Tp fallback, _Pp&&... param) {
  return select(unpack(mo), std::move(function), std::move(fallback),
                std::forward<_Pp>(param)...);
}

// type unreflection
template <__metaobject_id _Mp>
struct get_reflected_type : type_identity<__unrefltype(_Mp)> {};

template <__metaobject_id _Mp>
consteval auto get_reflected_type_id(metaobject<_Mp>) {
  return get_reflected_type<_Mp>{};
}

// reflection "operator"
#define mirror(...) \
  _VSTD_EXPERIMENTAL::mirror::metaobject<__reflexpr_id(__VA_ARGS__)>{}

} // namespace mirror
_LIBCPP_END_NAMESPACE_EXPERIMENTAL


#endif /* !_LIBCPP_HAS_NO_REFLECTION && !_LIBCPP_HAS_NO_REFLECTION_EXT */

#endif /* _LIBCPP_EXPERIMENTAL_MIRROR */

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

/*

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
    if constexpr(!requires { std::cout << x; }) {
        std::cout << "[" << &x << "]";
    }
    else
    {
        std::cout << x << ' ';
    }
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
    for(const auto& val : unpacked::getNames())
    {
        print2(val);
    }
    std::cout << std::endl;

    print2(x);

    for_each_member(x, print);
    return;
}*/

// See: https://github.com/matus-chochlik/llvm-project/blob/reflection/_reflexpr/mirror03.cpp
template <typename Z>
void print_struct(const Z& x) {
  std::cout << get_name(get_aliased(mirror(Z)));
  std::cout << '(';
  bool first = true;
  for_each(get_data_members(get_aliased(mirror(Z))),
    [&](auto mo) {
      if (first) first = false;
      else std::cout << ", ";
      std::cout << get_name(mo) << ": " << get_value(mo, x);
    });
  std::cout << ')' << std::endl;
}

int main() {
/*
  using mo = reflexpr(S);
  using member_sequence = reflect::get_data_members_t<mo>;
  using unpacked = reflect::unpack_sequence_t<Helper, member_sequence>;
  static constexpr auto names = unpacked::getNames();*/

  S instance = S();
  instance.a = 3;
  instance.b = 63;
  instance.z = 1.14f;
  instance.x = "batata";
  instance.y = std::vector<int>{1, 2, 3};
  // print_json(instance);
  print_struct(instance);
  return 0;
}