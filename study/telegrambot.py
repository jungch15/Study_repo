import telegram
from telegram.ext import Updater
from telegram.ext import MessageHandler, Filters

token = '0000000000000000000000000000000000' #set token
id = '0000000000' # set id

bot = telegram.Bot(token)

# updater
updater = Updater(token=token, use_context=True)
dispatcher = updater.dispatcher
updater.start_polling()



def handler(update, context):
    user_text = update.message.text # 사용자가 보낸 메세지를 user_text 변수에 저장합니다.
    if user_text == "안녕": # 사용자가 보낸 메세지가 "안녕"이면?
        bot.send_message(chat_id=id, text="어 그래 안녕") # 답장 보내기
    elif user_text == "뭐해": # 사용자가 보낸 메세지가 "뭐해"면?
        bot.send_message(chat_id=id, text="그냥 있어") # 답장 보내기
 
echo_handler = MessageHandler(Filters.text, handler)
dispatcher.add_handler(echo_handler)
