#pragma once
#include<tuple>
#include<utility>
#include<type_traits>
#include <sstream>
#include <iomanip>

// detail
namespace cfn::detail {
	struct Any { template<class T> constexpr operator T()const; };
	template<class T, class...U>
	using initable = decltype(T{ std::declval<U>()... });

	template<class, template<class...>class, class...>
	struct detector :std::false_type {};
	template<template<class...>class op, class ...args>
	struct detector<std::void_t<op<args...>>, op, args...> :std::true_type {};

	// std::experimental::is_detected
	template<template<class...>class Op, class ...Args>
	using is_detected = detector<void, Op, Args...>;

	template<class T>
	constexpr auto to_tie(T& t_) {
		using A = detail::Any;
		if constexpr (std::is_empty_v<T>) { return std::tie(); }
		/*
		#! /usr/bin/ruby
		print (1..32).reverse_each.map{|n|
			lit=("a".."zz").take(n).join(",")
			"else if constexpr(detail::is_detected<detail::initable,T#{",A"*n}>{}){auto&[#{lit}]=t_;return std::tie(#{lit});}"
		}.join("\n")
		*/
		else if constexpr(detail::is_detected<detail::initable,T,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A>{}){auto&[a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,ab,ac,ad,ae,af]=t_;return std::tie(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,ab,ac,ad,ae,af);}
		else if constexpr(detail::is_detected<detail::initable,T,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A>{}){auto&[a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,ab,ac,ad,ae]=t_;return std::tie(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,ab,ac,ad,ae);}
		else if constexpr(detail::is_detected<detail::initable,T,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A>{}){auto&[a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,ab,ac,ad]=t_;return std::tie(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,ab,ac,ad);}
		else if constexpr(detail::is_detected<detail::initable,T,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A>{}){auto&[a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,ab,ac]=t_;return std::tie(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,ab,ac);}
		else if constexpr(detail::is_detected<detail::initable,T,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A>{}){auto&[a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,ab]=t_;return std::tie(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,ab);}
		else if constexpr(detail::is_detected<detail::initable,T,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A>{}){auto&[a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa]=t_;return std::tie(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa);}
		else if constexpr(detail::is_detected<detail::initable,T,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A>{}){auto&[a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z]=t_;return std::tie(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z);}
		else if constexpr(detail::is_detected<detail::initable,T,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A>{}){auto&[a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y]=t_;return std::tie(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y);}
		else if constexpr(detail::is_detected<detail::initable,T,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A>{}){auto&[a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x]=t_;return std::tie(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x);}
		else if constexpr(detail::is_detected<detail::initable,T,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A>{}){auto&[a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w]=t_;return std::tie(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w);}
		else if constexpr(detail::is_detected<detail::initable,T,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A>{}){auto&[a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v]=t_;return std::tie(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v);}
		else if constexpr(detail::is_detected<detail::initable,T,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A>{}){auto&[a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u]=t_;return std::tie(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u);}
		else if constexpr(detail::is_detected<detail::initable,T,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A>{}){auto&[a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t]=t_;return std::tie(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t);}
		else if constexpr(detail::is_detected<detail::initable,T,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A>{}){auto&[a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s]=t_;return std::tie(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s);}
		else if constexpr(detail::is_detected<detail::initable,T,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A>{}){auto&[a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r]=t_;return std::tie(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r);}
		else if constexpr(detail::is_detected<detail::initable,T,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A>{}){auto&[a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q]=t_;return std::tie(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q);}
		else if constexpr(detail::is_detected<detail::initable,T,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A>{}){auto&[a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p]=t_;return std::tie(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p);}
		else if constexpr(detail::is_detected<detail::initable,T,A,A,A,A,A,A,A,A,A,A,A,A,A,A,A>{}){auto&[a,b,c,d,e,f,g,h,i,j,k,l,m,n,o]=t_;return std::tie(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o);}
		else if constexpr(detail::is_detected<detail::initable,T,A,A,A,A,A,A,A,A,A,A,A,A,A,A>{}){auto&[a,b,c,d,e,f,g,h,i,j,k,l,m,n]=t_;return std::tie(a,b,c,d,e,f,g,h,i,j,k,l,m,n);}
		else if constexpr(detail::is_detected<detail::initable,T,A,A,A,A,A,A,A,A,A,A,A,A,A>{}){auto&[a,b,c,d,e,f,g,h,i,j,k,l,m]=t_;return std::tie(a,b,c,d,e,f,g,h,i,j,k,l,m);}
		else if constexpr(detail::is_detected<detail::initable,T,A,A,A,A,A,A,A,A,A,A,A,A>{}){auto&[a,b,c,d,e,f,g,h,i,j,k,l]=t_;return std::tie(a,b,c,d,e,f,g,h,i,j,k,l);}
		else if constexpr(detail::is_detected<detail::initable,T,A,A,A,A,A,A,A,A,A,A,A>{}){auto&[a,b,c,d,e,f,g,h,i,j,k]=t_;return std::tie(a,b,c,d,e,f,g,h,i,j,k);}
		else if constexpr(detail::is_detected<detail::initable,T,A,A,A,A,A,A,A,A,A,A>{}){auto&[a,b,c,d,e,f,g,h,i,j]=t_;return std::tie(a,b,c,d,e,f,g,h,i,j);}
		else if constexpr(detail::is_detected<detail::initable,T,A,A,A,A,A,A,A,A,A>{}){auto&[a,b,c,d,e,f,g,h,i]=t_;return std::tie(a,b,c,d,e,f,g,h,i);}
		else if constexpr(detail::is_detected<detail::initable,T,A,A,A,A,A,A,A,A>{}){auto&[a,b,c,d,e,f,g,h]=t_;return std::tie(a,b,c,d,e,f,g,h);}
		else if constexpr(detail::is_detected<detail::initable,T,A,A,A,A,A,A,A>{}){auto&[a,b,c,d,e,f,g]=t_;return std::tie(a,b,c,d,e,f,g);}
		else if constexpr(detail::is_detected<detail::initable,T,A,A,A,A,A,A>{}){auto&[a,b,c,d,e,f]=t_;return std::tie(a,b,c,d,e,f);}
		else if constexpr(detail::is_detected<detail::initable,T,A,A,A,A,A>{}){auto&[a,b,c,d,e]=t_;return std::tie(a,b,c,d,e);}
		else if constexpr(detail::is_detected<detail::initable,T,A,A,A,A>{}){auto&[a,b,c,d]=t_;return std::tie(a,b,c,d);}
		else if constexpr(detail::is_detected<detail::initable,T,A,A,A>{}){auto&[a,b,c]=t_;return std::tie(a,b,c);}
		else if constexpr(detail::is_detected<detail::initable,T,A,A>{}){auto&[a,b]=t_;return std::tie(a,b);}
		else if constexpr(detail::is_detected<detail::initable,T,A>{}){auto&[a]=t_;return std::tie(a);}
	}


	template<class T>
	std::string jslikedump(T const&x, std::enable_if_t<std::is_integral_v<T> || std::is_floating_point_v<T>>* =0){
		return std::to_string(x);
	}

	std::string jslikedump(std::string const&s) {
		std::ostringstream o;
		o <<'"';
		for (auto c: s) {
			switch (c) {
			case '"': o << "\\\""; break;
			case '\\': o << "\\\\"; break;
			case '\b': o << "\\b"; break;
			case '\f': o << "\\f"; break;
			case '\n': o << "\\n"; break;
			case '\r': o << "\\r"; break;
			case '\t': o << "\\t"; break;
			default:
				if ('\x00' <= c && c <= '\x1f') {
					o << "\\u" << std::hex << std::setw(4) << std::setfill('0') << (int)c;
				} else {
					o << c;
				}
			}
		}
		o <<'"';
		return o.str();
	}

	template<class T>
	std::string jslikedump(T const&t, std::enable_if_t<std::is_aggregate_v<T>>* =0){
		return std::apply([](auto const&...args){
			std::ostringstream os;
			os<<"{";
			std::array<std::string,sizeof...(args)> values = {detail::jslikedump(args)...};
			for(std::size_t i=0;i<values.size();++i){
				if(i!=0) os<<",";
				os << R"("")"<<":"<< values[i];
			}
			os<<"}";
			return os.str();
		},to_tie(t));
	}
}

namespace cfn {
	// aggregate -> tuple
	template<class T>
	constexpr auto to_tie(T& t_) {
		return detail::to_tie(t_);;
	}

	// aggregate -> std::string
	template<class T>
	std::string dump(T const &x){
		return detail::jslikedump(x);
	}

	// aggregate wrapper for defining utility
	// // example
	// struct A_impl{int x;std::string y;};
	// using A = cfn::datatype<A_impl>;
	template<class impl>
	struct datatype:impl {
		friend bool operator<(datatype const& lhs, datatype const& rhs){
			return cfn::to_tie(static_cast<impl const&>(lhs)) < cfn::to_tie(static_cast<impl const&>(rhs));
		}
		friend bool operator==(datatype const& lhs, datatype const& rhs){
			return cfn::to_tie(static_cast<impl const&>(lhs)) == cfn::to_tie(static_cast<impl const&>(rhs));
		}
		friend bool operator!=(datatype const& lhs, datatype const& rhs){
			return !(lhs == rhs);
		}
		friend bool operator>(datatype const& lhs, datatype const& rhs){
			return rhs < lhs;
		}
		friend bool operator<=(datatype const& lhs, datatype const& rhs){
			return !(lhs > rhs);
		}
		friend bool operator>=(datatype const& lhs, datatype const& rhs){
			return !(lhs < rhs);
		}
	};
	
	// datatype enable use selftype
	// // example
	// template<class self_type>
	// struct A_impl{ self_type clone()const{return {*this}; } };
	// using A = cfn::datatype_with_self<A_impl>;
	template<template<class self_type>class impl>
	struct datatype_with_self : datatype<impl<datatype_with_self<impl>>> {};
}
