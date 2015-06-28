# This is my Candy Crush Report !!!

**遊戲截圖**<br><br>
![image](https://github.com/bgrffqq/pd2-project3/blob/master/print.png)<br><br>
**Class 架構**<br><br>

![image](https://github.com/bgrffqq/pd2-project3/blob/master/readpic.png)<br><br>

**A. MainWindow**
<br>
MainWindow 為主要的GUI Class<br>
其中調用game class的遊戲方式<br>
主要為<br>
<br>
*void setlabel()*<br>
是用來初始化設定grid layout 和 buttons<br>
讀入game class 中的2-D array<br>
並且調用setImage來將值轉換成圖片<br>
然後使用signalMapper和connection來將每個按鈕與on_pushButton_clicked(int id)吃一個按鈕的id做連結<br>
並且on_pushButton_clicked(int id)會有兩個id之後才會動作＋清空<br>
<br>
*void play()*<br>
是用來讀入兩個按鈕<br>
首先利用isNear判斷是不是在隔壁<br>
然後判斷兩個按鈕是否代表同樣的石頭<br>
之後在利用條件判斷石頭或是炸彈並且做出動作<br>
也是在這個函式<br>
會有分數和步數的顯示<br>
並且確認過關條件checkWin函式<br>
之後在checkWin函式中<br>
判斷條件傳出score 和 星數 和成功與否傳到Result class<br>
<br><br>
**B. game**
<br>
game 中是主要的遊戲運算

*void init()*<br>
為初始化亂數分配出石頭(6種)<br><br>
*void checkline()*<br>
這個函式為判斷是否有連線(分為row , col)<br>
並且以數量去判斷出<br>
為正常的3個,炸橫排或直排4個,星星5個<br>
row+col都大等於三-> 炸彈<br>

*void rowBomb*<br>
*void colBomb*<br>
即為正常的炸法<br>
炸完之後會生成一排炸彈或是星星<br>
<br>
*void Bomb*<br>
則是炸彈的生成<br><br>
*void typeBomb*<br>
為四種炸彈的炸法<br>
<br>
*void moveDown*<br>
這個則是在炸空之後<br>
把上面的石頭drop下來<br>
並且傳入gener函式來將最上面空的重新亂數<br><br>

**C. Result**
<br>
從MainWindow show出來<br>
並且顯示出<br>
Pass / Failed<br>
Star星數<br>
Score分數<br>
<br><br>
**以上 thx for reading**

