#include <stdio.h>
#include <tgbot/tgbot.h>
#include <iostream>
#include <vector>

using namespace TgBot;
using namespace std;

int get_message(char state){
    if(state == 'v'){
        return 1;
    }else{
        return 2;
    }
}

vector<string>bot_commands = {"start"};

int main() {

    Bot bot("5915788521:AAEveMQhUVx2i1FxbXdL_DY86ZcXhke0V2U");

    InlineKeyboardMarkup::Ptr keyboard(new InlineKeyboardMarkup);
    vector<InlineKeyboardButton::Ptr> buttons;
    InlineKeyboardButton::Ptr get_conf_bttn(new InlineKeyboardButton), get_help_bttn(new InlineKeyboardButton);
    
    get_conf_bttn->text = "get VPN";
    get_help_bttn->text = "get help inf";
    
    get_conf_bttn->callbackData = "VPN";
    get_help_bttn->callbackData = "HELP";
    
    buttons.push_back(get_conf_bttn);
    buttons.push_back(get_help_bttn);
    
    keyboard->inlineKeyboard.push_back(buttons);

    bot.getEvents().onCommand("start", [&bot, keyboard](Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Hi!, " + message->chat->firstName + 
            " u may get vpn file, or get help information", false, 0, keyboard);
    });

    bot.getEvents().onCallbackQuery([&bot, &keyboard](CallbackQuery::Ptr query) {
        if(query->data == "VPN"){
            bot.getApi().sendMessage(query->message->chat->id, to_string(get_message('v')));
        }else{
            bot.getApi().sendMessage(query->message->chat->id, to_string(get_message('h')));
        }
    });


    bot.getEvents().onAnyMessage([&bot](Message::Ptr message) {
        
        for(const auto& command : bot_commands){
            if("/" + command == message->text){
                return;
            }
        }

        bot.getApi().sendMessage(message->chat->id, "Sorry. I don't know u comand :(");
        //bot.getApi().sendPhoto(message->chat->id, InputFile::fromFile("./test.jpg",  "image/jpg"));
        //bot.getApi().sendDocument(message->chat->id, InputFile::fromFile("./conf_files/1.conf", "document/conf"));
    });

    try {
        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
        TgLongPoll longPoll(bot);
        while (true) {
            printf("Long poll started\n");
            longPoll.start();
        }
    } catch (TgException& e) {
        printf("error: %s\n", e.what());
    }
    return 0;
}