#include "../src/text.h"

TEST(TEXT, good){
    Text t("G");
    ASSERT_EQ("G",t.getText());
}

TEST(TEXT, Levelequal0){
    Text t("G");
    ASSERT_EQ(0,t.getLevel());
}

TEST(Text, ThrowException){
    Text t("G");
    Text n("test");
    try{
        t.add(&n);
    }catch(std::string s){
        ASSERT_EQ("method not allowed", s);
    }
}