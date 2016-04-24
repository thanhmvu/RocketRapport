#include "gtest/gtest.h"
#include "../model/chat.h"
#include "../model/message.h"

TEST(ChatTest,testSendMessage){
    Chat test;
    Message *one = new Message;
    one->setText("Hey Amrit, I generally dislike you");
    test.sendMessage(one);
}
