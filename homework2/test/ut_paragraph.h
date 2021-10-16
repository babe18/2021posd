#include "../src/paragraph.h"

TEST(PARAGRAPH, getText1){
    Paragraph p(1, "title");
    ASSERT_EQ("# title\n",p.getText());
}

TEST(PARAGRAPH, getText2){
    Paragraph p(2, "title");
    ASSERT_EQ("## title\n",p.getText());
}

TEST(PARAGRAPH, getText3){
    Paragraph p(3, "title");
    ASSERT_EQ("### title\n",p.getText());
}

TEST(Paragraph, TestParagraph){
    Paragraph p(2,"title");
    p.add(new ListItem("list1"));
    ASSERT_EQ("## title\n- list1", p.getText());
    ASSERT_EQ(2, p.getLevel());
    Paragraph* p2 = new Paragraph(3,"title2");
    p2 ->add(new ListItem("list2"));
    p2 ->add(new Text("text1"));
    Paragraph* p3 = new Paragraph(4,"title3");
    p3->add(new Text("text2"));
    p.add(p2);
    p.add(p3);
    ASSERT_EQ("## title\n- list1\n### title2\n- list2\ntext1\n#### title3\ntext2", p.getText());
}

TEST(Paragraph, LevelException){
    try{
        Paragraph p(8,"title");;
    }catch(std::string s){
            ASSERT_EQ("A paragraph can only have a level between one to six", s);
    }
}

TEST(Paragraph, AddLowerOrEqualLevelParagraphShouldThrow){
    Paragraph p1 (1,"title1");
    Paragraph* p2 = new Paragraph(1,"title2");
    try{
        p1.add(p2);
    }catch(std:: string s){
        ASSERT_EQ("New paragraphs have to be higher level than the previous ones",s);
    }
    delete p2;
}

// TEST(LIST_ITEM, bad){
//     ListItem t("list1");
//     ASSERT_ANY_THROW(t.add());
// }