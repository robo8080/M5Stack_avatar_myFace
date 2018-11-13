#include <M5Stack.h>
#include <Avatar.h>
#include "myEye.h"
#include "myMouth.h"
//#define USE_AQUESTALK
#ifdef USE_AQUESTALK
#include <tasks/LipSync.h>
#endif

using namespace m5avatar;

#ifdef USE_AQUESTALK
// AquesTalk License Key
// NULL or wrong value is just ignored
const char* AQUESTALK_KEY = "XXXX-XXXX-XXXX-XXXX";
#endif

Avatar avatar;

Face* myFace;

const Expression expressions[] = {
  Expression::Angry,
  Expression::Sleepy,
  Expression::Happy,
  Expression::Sad,
  Expression::Doubt,
  Expression::Neutral
};
const int expressionsSize = sizeof(expressions) / sizeof(Expression);
int idx = 0;

ColorPalette* cps[4];
const int cpsSize = sizeof(cps) / sizeof(ColorPalette*);
int cpsIdx = 0;

bool isShowingQR = false;

void setup()
{
  M5.begin();
#ifdef USE_AQUESTALK
  int iret;
  // For Kanji-to-speech mode (requires dictionary file saved on microSD)
  // See http://blog-yama.a-quest.com/?eid=970195
  // iret = TTS.createK(AQUESTALK_KEY);
  iret = TTS.create(AQUESTALK_KEY);
#endif
  M5.Lcd.setBrightness(30);
  M5.Lcd.clear();

  myFace = new Face(new myMouth(50, 100, 4, 60), new BoundingRect(150, 163),
             new myEye(23, false), new BoundingRect(93, 90),
             new myEye(23, true),  new BoundingRect(93, 230),
             new Eyeblow(32, 0, false), new BoundingRect(67, 96),
             new Eyeblow(32, 0, true), new BoundingRect(72, 230));

  cps[0] = new ColorPalette();
  cps[1] = new ColorPalette();
  cps[2] = new ColorPalette();
  cps[3] = new ColorPalette();
  cps[1]->set(COLOR_PRIMARY, TFT_YELLOW);
  cps[1]->set(COLOR_BACKGROUND, TFT_DARKCYAN);
  cps[2]->set(COLOR_PRIMARY, TFT_BLACK);
  cps[2]->set(COLOR_BACKGROUND, TFT_WHITE);
  cps[3]->set(COLOR_PRIMARY, TFT_RED);
  cps[3]->set(COLOR_BACKGROUND, TFT_PINK);

  avatar.setFace(myFace);
  avatar.init();
  avatar.setColorPalette(*cps[0]);
#ifdef USE_AQUESTALK
  avatar.addTask(lipSync, "lipSync");
#endif
}

void loop()
{
  M5.update();
  if (M5.BtnA.wasPressed())
  {
    avatar.setExpression(expressions[idx]);
    idx = (idx + 1) % expressionsSize;
  }
  if (M5.BtnB.wasPressed())
  {
    avatar.setColorPalette(*cps[cpsIdx]);
    cpsIdx = (cpsIdx + 1) % cpsSize;
  }
#ifdef USE_AQUESTALK
  if (M5.BtnC.wasPressed()) {
    // Need to initialize with createK(AQUESTALK_KEY)
    // TTS.play("こんにちは。", 80);
    TTS.play("konnichiwa", 80);
    avatar.setSpeechText("Hello");
    delay(1000);
    avatar.setSpeechText("");
  }
#endif
}
