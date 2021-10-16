#include "../src/list_item.h"


TEST(LIST_ITEM, good){
    ListItem t("list1");
    ASSERT_EQ("- list1",t.getText());
}

TEST(LIST_ITEM, Levelequal0){
    ListItem t("G");
    ASSERT_EQ(0,t.getLevel());
}

TEST(LIST_ITEM, ThrowException){
    ListItem t("G");
    ListItem n("test");
    try{
        t.add(&n);
    }catch(std::string s){
        ASSERT_EQ("method not allowed", s);
    }
}