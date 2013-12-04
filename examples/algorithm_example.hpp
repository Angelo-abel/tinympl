
#include <tinympl/algorithm.hpp>

namespace algorithm_example {

static_assert(tinympl::count_if< std::tuple<int,float>,std::is_integral >::type::value == 1,"count_if");
static_assert(tinympl::count< std::tuple<int,float,char,int>,int >::type::value == 2,"count");
static_assert(tinympl::find_if< std::tuple<double,int,float>, std::is_integral>::type::value == 1,"find_if");
static_assert(tinympl::find<std::tuple<char,int,float>, float >::type::value == 2,"find");
static_assert(
	std::is_same<
		tinympl::copy_if< std::tuple<char,int,float>,std::is_integral >::type,
		std::tuple<char,int> >::value,"copy_if");

static_assert(
	std::is_same<
		tinympl::copy_n<std::tuple<char,int,float,double,int>,3 >::type,
		std::tuple<char,int,float> >::value,"copy_n");

static_assert(
	std::is_same<
		tinympl::fill_n< 4,int,std::tuple >::type,
		std::tuple<int,int,int,int> >::value,"fill_n");

static_assert(
	std::is_same<
		tinympl::transform< std::tuple<char,int>,std::add_const >::type,
		std::tuple<const char,const int> >::value,"transform");

static_assert(
	std::is_same<
		tinympl::replace_if< std::tuple<float,int,long,double>,std::is_floating_point,int >::type,
		std::tuple<int,int,long,int> >::value,"replace_if");

static_assert(
	std::is_same<
		tinympl::replace<std::tuple<char,int,long,char,int>,char,int>::type,
		std::tuple<int,int,long,int,int> >::value,"replace");

static_assert(
	std::is_same<
		tinympl::remove_if< std::tuple<char,int,int[]>,std::is_array >::type,
		std::tuple<char,int> >::value,"remove_if");

static_assert(
	std::is_same<
		tinympl::remove< std::tuple<double,char,int>,char >::type,
		std::tuple<double,int> >::value,"remove");

using tinympl::int_;
typedef std::tuple< int_<3>,int_<8>,int_<0>,int_<10> > test_list0;

static_assert(tinympl::min_element<test_list0>::type::value == 2,"min_element");
static_assert(tinympl::max_element<test_list0>::type::value == 3,"max_element");

static_assert(
	std::is_same<
		tinympl::sort<test_list0>::type,
		std::tuple< int_<0>,int_<3>,int_<8>,int_<10> >
	>::value,"sort");

static_assert(
	std::is_same<
		tinympl::reverse<std::tuple<int,long,char,double> >::type,
		std::tuple<double,char,long,int> >::value,"reverse");

static_assert(
	tinympl::is_unique< std::tuple<int,long,char,int,double> >::type::value == false &&
	tinympl::is_unique< std::tuple<int,long,double,float> >::type::value == true,"is_unique");

//unique
static_assert(
	std::is_same<
		tinympl::unique<std::tuple<int,char,int,long,int> >::type,
		std::tuple<int,char,long> >::type::value,"unique");

static_assert(
	std::is_same<
		tinympl::unique<std::tuple<int,char,long> >::type,
		std::tuple<int,char,long> >::type::value,"unique");

static_assert(
	tinympl::all_of<std::tuple<int,long,short>,std::is_integral >::type::value == true &&
	tinympl::all_of<std::tuple<double,int,char>,std::is_floating_point >::type::value == false,"all_of");

static_assert(
	tinympl::any_of<std::tuple<int,long,short>,std::is_integral >::type::value == true &&
	tinympl::any_of<std::tuple<long,int,char>,std::is_floating_point >::type::value == false,"any_of");

static_assert(
	tinympl::none_of<std::tuple<double,float,std::string>,std::is_integral >::type::value == true &&
	tinympl::none_of<std::tuple<double,int,char>,std::is_floating_point>::type::value == false,"none_of");

static_assert(
	tinympl::unordered_equal<
		std::tuple<int,long,char>,
		std::tuple<int,double,long>
	>::type::value == false &&
	tinympl::unordered_equal<
		std::tuple<int,long,int,char>,
		std::tuple<char,int,int,long>
	>::type::value == true,"unordered_equal");

typedef std::tuple<int,char,long> s1;
typedef std::tuple<double,int> s2;
typedef std::tuple<std::string,float,int> s3;
typedef std::tuple<std::string,float,int,long> s4;

static_assert(
	std::is_same<
		tinympl::set_union<s1,s2>::type,
		std::tuple<int,char,long,double>
	>::type::value &&
	std::is_same<
		tinympl::set_union<s3,s2>::type,
		std::tuple<std::string,float,int,double>
	>::type::value,"set_union");

static_assert(
	std::is_same<
		tinympl::set_intersection<s1,s2>::type,
		std::tuple<int>
	>::type::value &&
	std::is_same<
		tinympl::set_intersection<s1,s4>::type,
		std::tuple<int,long>
	>::type::value,"set_intersection");

static_assert(
	std::is_same<
		tinympl::set_difference<s1,s2>::type,
		std::tuple<char,long>
	>::type::value &&
	std::is_same<
		tinympl::set_difference<s3,s2>::type,
		std::tuple<std::string,float>
	>::type::value &&
	std::is_same<
		tinympl::set_difference<s4,s1>::type,
		std::tuple<std::string,float>
	>::type::value,"set_difference");

}
