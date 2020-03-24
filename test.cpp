//  clang++ -std=c++17 test.cpp  -lgtest -lgtest_main -lpthread
#include <gtest/gtest.h>
#include "coffin-serialize.hpp"

TEST(ToTieTest,Convert){
    struct S{
        int x = 0;
        std::string y;
        double z;
    };
    S a;
    auto t = cfn::to_tie(a);
    static_assert(std::is_same_v<std::tuple<int&,std::string&,double&>,decltype(t)>);
    ASSERT_EQ(std::tie(a.x,a.y,a.z), t);
    ASSERT_EQ(&std::get<0>(t), &a.x);
    ASSERT_EQ(&std::get<1>(t), &a.y);
}


TEST(dump,Convert){
    struct S2{
        int x = 42;
        std::string y = "foo\"\\bar";
        int z = 3;
    };
    struct S1{
        S2 a;
        int x = 0;
        S2 b;
    };
    S1 a;
    ASSERT_EQ(cfn::dump(a), R"({"":{"":42,"":"foo\"\\bar","":3},"":0,"":{"":42,"":"foo\"\\bar","":3}})");
}

TEST(datatype, Convert){
    struct A_impl{
        int x;
        std::string y;
        int z;
    };
    using A = cfn::datatype<A_impl>;
    ASSERT_TRUE((A{1,"",1} == A{1,"",1}));
    ASSERT_TRUE((A{1,"",1} < A{1,"a",1}));
    ASSERT_TRUE((A{1,"a",1} > A{1,"",1}));
    ASSERT_TRUE((A{1,"",1} <= A{1,"a",1}));
    ASSERT_TRUE((A{1,"a",1} >= A{1,"",1}));
}

template<class SelfType>
struct A_impl2{
    int x;
    std::string y;
    int z;
    SelfType id()const{return *this;}
};
TEST(datatype_with_self, Convert){
    using A = cfn::datatype_with_self<A_impl2>;
    ASSERT_EQ(typeid(A), typeid(A{}.id()));
}
