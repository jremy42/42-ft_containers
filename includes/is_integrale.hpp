#pragma once
namespace ft {
	template <typename T>
	struct remove_cv{
		typedef T type;
	};
	template <typename T>
	struct remove_cv<const T>{
		typedef T type;
	};
	template <typename T>
	struct remove_cv<volatile T>{
		typedef T type;
	};
	template <typename T>
	struct remove_cv<const volatile T>{
		typedef T type;
	};

	template <typename T>
	struct is_integral_helper {
		static const bool value = false;
	};

	template <>
	struct is_integral_helper<bool> {
		static const bool value = true;
	};
	template <>
	struct is_integral_helper<char> {
		static const bool value = true;
	};
	template <>
	struct is_integral_helper<signed char> {
		static const bool value = true;
	};
	template <>
	struct is_integral_helper<unsigned char> {
		static const bool value = true;
	};
	template <>
	struct is_integral_helper<wchar_t> {
		static const bool value = true;
	};
	template <>
	struct is_integral_helper<short> {
		static const bool value = true;
	};
	template <>
	struct is_integral_helper<unsigned short> {
		static const bool value = true;
	};
	template <>
	struct is_integral_helper<int> {
		static const bool value = true;
	};
	template <>
	struct is_integral_helper<unsigned int> {
		static const bool value = true;
	};
	template <>
	struct is_integral_helper<long> {
		static const bool value = true;
	};
	template <>
	struct is_integral_helper<unsigned long> {
		static const bool value = true;
	};
	template <>
	struct is_integral_helper<long long> {
		static const bool value = true;
	};
	template <>
	struct is_integral_helper<unsigned long long> {
		static const bool value = true;
	};

	template <typename T>
	struct is_integral : public is_integral_helper<typename remove_cv<T>::type> {
	};

}